#****************************
#****************************

#**A Modifier**#

#****************************

OS	= LINUX
#OS	= WIN32

#COMPIL = C
COMPIL = CPP

PROGRAM = IASimulation

#****************************
#****************************
#****************************


ifeq ($(COMPIL),C)
	EXT = c
	CC = gcc
	LD = gcc
else
	EXT = cpp
	CC = g++
	LD = g++
endif

#*******

OBJ_DIR = obj
SRC_DIR = src/*
BIN_DIR = bin



INCLUDE_DIR = -I/usr/include/ -I./includes
LIB_DIR = -L/usr/include/

ifeq ($(OS),WIN32)
	LIBS =
else
	LIBS =  #-lsqlite3
			#-lSDL2
			#-lSDL2_ttf
			#-lSDL2_image
			#-L/usr/X11R6/lib
			#-lGL
			#-lGLU
			#-lglut
endif


DEFINE = -D$(OS) -DPROGRAM_NORMAL
LDFLAGS = $(LIB_DIR) $(LIBS)
CFLAGS 	= $(DEFINE) -Wall -pedantic -ansi -ggdb -g -std=c++11 -O2


#*******



SRCS := $(wildcard $(SRC_DIR)/*.$(EXT))
OBJ := $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.$(EXT)=.o)))


#****************************
#******     REGLES     ******
#****************************

$(BIN_DIR)/$(PROGRAM): $(OBJ)
	$(LD) $+ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(EXT)
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@


###############################

default: $(BIN_DIR)/$(PROGRAM)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(PROGRAM) $(BIN_DIR)/test.$(PROGRAM)

all:
	make clean
	make default

allrun:
	make clean
	make default
	./$(BIN_DIR)/$(PROGRAM)

run : $(BIN_DIR)/$(PROGRAM)
	./$(BIN_DIR)/$(PROGRAM)

valgrind : $(BIN_DIR)/$(PROGRAM)
	valgrind ./$(BIN_DIR)/$(PROGRAM)

valgAll : $(BIN_DIR)/$(PROGRAM)
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes ./$(BIN_DIR)/$(PROGRAM)