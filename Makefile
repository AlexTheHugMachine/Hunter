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
DIR = $(BIN) $(OBJ) $(DATA) $(DOC) $(SRC) $(CORE_SRC_DIR) $(TXT_SRC_DIR) 



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
INCLUDE_LOCAL = -I$(CORE_SRC) -I$(TXT_SRC)

# Liste des fichiers objets à générer pour l'exécutable texte
OBJ_LIST_TXT = $(patsubst %.cpp, %.o, $(addprefix $(OBJ)/, $(notdir $(TXT_SRC) $(CORE_SRC))))




#=============================== Règles ===================================
#------------------- Règle par défaut ------------------------------------
# Pour tout compiler
default: make_dir $(TARGET_TXT)



#-------------------- Dépendances --------------------------------
# Gérer la génération des listes de dépendences et inclusion de ces dernières
DEP := $(patsubst %.o, %.d, $(OBJ_LIST_TXT))
-include $(DEP)
DEPFLAGS = -MMD -MF $(@:.o=.d)



#--------------------- Création des répertoires nécessaires -----------------
make_dir: $(DIR)

$(DIR): 
	mkdir $@



#----------------- Règles de compilation --------------------------------------
# Edition de liens
$(TARGET_TXT): $(patsubst %.cpp, %.o, $(OBJ_LIST_TXT))
	$(LD) $(LDFLAGS) $+ -o $@ $(LDFLAGS)

# Compilation des fichiers objets et génération des listes de dépendances
$(OBJ)/%.o: $(SRC)/*/%.cpp
	$(CC) $(CCFLAGS) -o $@ $< $(DEPFLAGS)



#------------------ Règles utilitaires --------------------------------------
# Supprimer les fichiers  inutiles
clean:
	rm -rf $(OBJ) $(BIN) $(DEP)