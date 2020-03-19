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

# Ensemble des répertoires
DIR = $(BIN) $(OBJ) $(DATA) $(DOC) $(SRC) $(CORE_DIR) $(TXT_DIR) 

# Fichier de configuration Doxygen
CONF = Doxyfile
DOC_CONF = $(DOC)/$(CONF)
DOC_MAIN = $(DOC)/html/index.html



#----------------------------- Output ---------------------------
# Nom des exécutables
EXEC_TXT = hunter_txt.exe
TARGET_TXT = $(BIN)/$(EXEC_TXT)



#----------------------- Compilation et Edition de liens -----------
# Compileur et ses options
CC = g++
CCFLAGS = -Wall -O2 -c
ifndef RELEASE
	CCFLAGS += -ggdb
endif

# Linker et ses  options
LD = g++
LDFLAGS = 



#-------------------- Fichiers pour la compilation -------------------
# Pour trouver les headers
INCLUDE_LOCAL = -I$(CORE_DIR) -I$(TXT_DIR) #-I$(SRC) -I.

# Liste des fichiers objets à générer pour l'exécutable texte
OBJ_LIST_TXT = $(patsubst %.cpp, %.o, $(addprefix $(OBJ)/, $(notdir $(TXT_SRC) $(CORE_SRC))))

#--------------------- Pour les echo ----------------------------------
NORM = \e[0m
RED = \e[38;5;124m
YELLOW = \e[93m
GREEN = \e[38;5;34m
BLUE = \e[38;5;45m




#=============================== Règles ===================================
#------------------- Règle par défaut ------------------------------------
# Pour tout compiler
default: init $(TARGET_TXT) $(DOC_MAIN)

# Pour initialiser le workspace
init: make_dir $(DOC_CONF)

#-------------------- Dépendances --------------------------------
# Gérer la génération des listes de dépendences et inclusion de ces dernières
DEP := $(patsubst %.o, %.d, $(OBJ_LIST_TXT))
-include $(DEP)
DEPFLAGS = -MMD -MF $(@:.o=.d)



#--------------------- Création des répertoires nécessaires -----------------
make_dir: $(DIR)

$(DIR): 
	@echo "Creating $(YELLOW)$@$(NORM) directory"
	@mkdir $@



#----------------- Règles de compilation --------------------------------------
# Edition de liens
$(TARGET_TXT): $(patsubst %.cpp, %.o, $(OBJ_LIST_TXT))
	@echo "Linking $(BLUE)$+$(NORM) and creating executable $(GREEN)$@$(NORM)"
	@$(LD) $(LDFLAGS) $+ -o $@ $(LDFLAGS) $(INCLUDE_LOCAL)
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
	@find $(DOC)/* -maxdepth 0 -type d ! -name '$(CONF)' | xargs rm -rf

doc_update = doxygen $(DOC_CONF)

$(DOC_MAIN): README.md
	@echo "Updating documentation"
	@$(doc_update)

$(DOC_CONF):
	@echo "Generating doxygen configuration file : $@$(NORM)"
	@doxygen -g $@