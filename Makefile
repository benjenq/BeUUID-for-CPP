CXX		  := g++

BIN		  := bin
SRC		  := src
INCLUDE	  := include
LIB		  := lib

LIBRARIES	:=
EXECUTABLE	:= main

ifeq ($(OS),Windows_NT)
	CXX_FLAGS  := -Wall -Wextra -std=c++17 -ggdb -lole32
	RM_COMMAND := del $(BIN)\*.* /s /q
	CLEAN_CMD  := cls
else
	UNAME_S    := $(shell uname -s)
	RM_COMMAND := -rm -R $(BIN)/*
	CLEAN_CMD  := clear
	ifeq ($(UNAME_S),Darwin)
		CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
	else
		CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -luuid
	endif
endif


all: $(BIN)/$(EXECUTABLE)

run: clean all
	-$(CLEAN_CMD)
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) $(CXX_FLAGS)

.PHONY : clean, clear
clean:
	-$(RM_COMMAND)

clear:
	-$(RM_COMMAND)
	-$(CLEAN_CMD)

