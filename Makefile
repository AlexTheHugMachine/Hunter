
BIN = bin
OBJ = obj
DATA = data
DOC = doc
SRC = src

CORE_SRC = $(SRC)/core
TXT_SRC = $(SRC)/txt

DIR = $(BIN) $(OBJ) $(DATA) $(DOC) $(SRC) $(CORE_SRC) $(TXT_SRC)

EXEC_TXT = hunter_txt.exe
TARGET_TXT = $(BIN)/$(EXEC_TXT)




CC = g++
CCFLAGS = -Wall -O2
ifndef RELEASE
	CCFLAGS += -ggdb
endif

LD = g++
LDFLAGS = 

INCLUDE_LOCAL = -I$(SRC) -I$(CORE_SRC) -I$(TXT_SRC)


default: make_dir $(TARGET_TXT)

make_dir: $(DIR)

$(DIR): 
	mkdir $@

