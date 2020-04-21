#============================ Configuration ========================
# -------------------------- Répertoires -------------------------
# Nom des répertoires
BIN = bin
OBJ = obj
DATA = data
DOC = doc
SRC = src

# Subduvisions du répertoire SRC
CORE_DIR = $(SRC)/core
CORE_SRC = $(wildcard $(CORE_DIR)/*.cpp)

TXT_DIR = $(SRC)/txt
TXT_SRC = $(wildcard $(TXT_DIR)/*.cpp)

SDL_DIR = $(SRC)/sdl
SDL_SRC = $(wildcard $(SDL_DIR)/*.cpp)

# Ensemble des répertoires
DIR = $(BIN) $(OBJ) $(DATA) $(DOC) $(SRC) $(CORE_DIR) $(TXT_DIR) $(SDL_DIR)

# Fichier de configuration Doxygen
CONF = Doxyfile
DOC_CONF = $(DOC)/$(CONF)
DOC_MAIN = $(DOC)/html/index.html



#----------------------------- Output ---------------------------
# Nom des exécutables
EXEC_TXT = hunter_txt.exe
TARGET_TXT = $(BIN)/$(EXEC_TXT)

EXEC_SDL = hunter_sdl.exe
TARGET_SDL = $(BIN)/$(EXEC_SDL)



#----------------------- Compilation et Edition de liens -----------
# Compileur et ses options
CC = g++
CCFLAGS = -Wall -O2 -c
ifndef RELEASE
	CCFLAGS += -ggdb
endif

# Linker et ses  options
LD = g++
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf



#-------------------- Fichiers pour la compilation -------------------
# Pour trouver les headers
INCLUDE_SDL = -I/usr/include/SDL2
INCLUDE_LOCAL = -I$(CORE_DIR) -I$(TXT_DIR) $(INCLUDE_SDL) #-I$(SRC) -I.

# Liste des fichiers objets à générer pour l'exécutable texte
OBJ_LIST_TXT = $(patsubst %.cpp, %.o, $(addprefix $(OBJ)/, $(notdir $(TXT_SRC) $(CORE_SRC))))
OBJ_LIST_SDL = $(patsubst %.cpp, %.o, $(addprefix $(OBJ)/, $(notdir $(SDL_SRC) $(CORE_SRC))))

#--------------------- Pour les echo ----------------------------------
NORM = \e[0m
RED = \e[38;5;124m
YELLOW = \e[93m
GREEN = \e[38;5;34m
BLUE = \e[38;5;45m




#=============================== Règles ===================================
#------------------- Règle par défaut ------------------------------------
# Pour tout compiler
default: init $(TARGET_TXT) $(TARGET_SDL) #$(DOC_MAIN)

# Pour initialiser le workspace
init: make_dir #$(DOC_CONF)

#-------------------- Dépendances --------------------------------
# Gérer la génération des listes de dépendences et inclusion de ces dernières
DEP_TXT := $(patsubst %.o, %.d, $(OBJ_LIST_TXT))
-include $(DEP_TXT)

DEP_SDL := $(patsubst %.o, %.d, $(OBJ_LIST_SDL))
-include $(DEP_SDL)
DEPFLAGS = -MMD -MF $(@:.o=.d)



#--------------------- Création des répertoires nécessaires -----------------
make_dir: $(DIR)

$(DIR): 
	@echo "Creating $(YELLOW)$@$(NORM) directory"
	@mkdir $@

#$(patsubst %.cpp, %.o, $(OBJ_LIST_SDL))
#----------------- Règles de compilation --------------------------------------
# Edition de liens
$(TARGET_TXT): $(patsubst %.cpp, %.o, $(OBJ_LIST_TXT))
	@echo "Linking $(BLUE)$+$(NORM) and creating executable $(GREEN)$@$(NORM)"
	@$(LD) $(LDFLAGS) $+ -o $@ $(LDFLAGS)
#  $(INCLUDE_LOCAL)
	@echo "Updating documentation"
	@$(doc_update) 

$(TARGET_SDL): $(patsubst %.cpp, %.o, $(OBJ_LIST_SDL))
	@echo "Linking $(BLUE)$+$(NORM) and creating executable $(GREEN)$@$(NORM)"
	@$(LD) $(LDFLAGS) $+ -o $@ $(LDFLAGS) 
#  $(INCLUDE_LOCAL)
	@echo "Updating documentation"
	@$(doc_update)


# Compilation des fichiers objets et génération des listes de dépendances
$(OBJ)/%.o: $(SRC)/*/%.cpp
	@echo "Compiling $(RED)$<$(NORM) and generating its dependency list"
	@$(CC) $(CCFLAGS) -o $@ $< $(DEPFLAGS) $(INCLUDE_LOCAL)



#------------------ Règles utilitaires --------------------------------------
# Supprimer les fichiers  inutiles
.PHONY: clean doc_update default make_dir init
.SILENT: doc_update

clean:
	@echo "Emptying $(YELLOW)$(OBJ)$(NORM) and $(YELLOW)$(BIN)$(NORM) directories"
	@rm -rf $(OBJ)/* $(BIN)/*  
	@echo "Removing $(YELLOW)$$(find $(DOC)/* -maxdepth 0 -type d ! -name '$(CONF)')$(NORM) directory"
	@find $(DOC)/*	 -maxdepth 0 -type d ! -name '$(CONF)' | xargs rm -rf
#@rm val*.txt

doc_update = doxygen $(DOC_CONF)

$(DOC_MAIN): README.md
	@echo "Updating documentation"
	@$(doc_update)

$(DOC_CONF):
	@echo "Generating doxygen configuration file : $@$(NORM)"
	@doxygen -g $@

valgrind_txt: default
	@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all $(BIN)/$(EXEC_TXT) > val2.txt 2>&1

valgrind_sdl: default
	valgrind --leak-check=full -v --num-callers=50 --suppressions=./valgrind_lif7.supp --show-reachable=yes $(BIN)/$(EXEC_SDL) > val.txt 2>&1
#@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all $(BIN)/$(EXEC_SDL)
