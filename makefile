# @file: makefile
# @date: Mon Sep  8 00:03:12 CDT 2025
# @version: 0.0.1

APP = scanner
CXX = g++
CC = gcc
LEX = reflex
LEX = flex
YACC = bison -y
YACC = bison
YFLAGS =
CXXFLAGS = -std=c++20 -fPIC
CCFLAGS =
FLEXFLAGS = --flex
BISONFLAGS = -y -d --html --graph
BLD = build
OBJ = build
SRC = src
AST = ast
TST = test

FMT_RESET=\e[0m
FMT_RED='\e[31m'
FMT_GREEN=\e[32m
FMT_YELLOW='\e[33m'
FMT_BLUE='\e[34m'
FMT_CYAN='\e[36m'


# LIBS = -L/usr/local/lib/
# INCLUDES = -I./build/
# LDFLAGS = -lfmt $(LIBS) $(INCLUDES)

ifndef RELEASE
	CXXFLAGS +=-ggdb -DDEBUG
endif

ifdef CYGWIN
	CXXFLAGS +=-DCYGWIN
	#LDFLAGS += /usr/lib/libcppunit.dll.a
	LDFLAGS=/usr/local/lib/libfmt.a
else
	LDFLAGS=/usr/local/lib64/libfmt.a
endif

ifdef REFLEX
	FLEX=reflex
	CXXFLAGS +=-DREFLEX
	#LDFLAGS += /usr/local/lib/libcppunit.a /usr/local/lib/libreflex.a
	REFLEXFLAGS=-I/usr/local/include/reflex
endif

.PHONY all: help
all: $(BLD)/scanner $(BLD)/libscanner.a $(BLD)/parser.tab.c #$(BLD)/parser # $(BLD)/libscanner.so  # $(BLD)/$(APP)_test

$(BLD)/scanner: $(BLD)/parser.tab.c $(BLD)/parser.tab.h $(BLD)/fileio.o $(OBJ)/scanner.o $(BLD)/scanner.h $(BLD)/Lexer.o $(BLD)/Lexer.hpp $(BLD)/utility.o
	$(CXX) $(CXXFLAGS) -fPIC -I./$(BLD) $(BLD)/fileio.o $(OBJ)/scanner.o $(BLD)/Lexer.o $(BLD)/utility.o $(LDFLAGS) -o $@

# parser # USING C COMPLIER ON CPP! BUT IT BUILDS?
$(BLD)/parser: $(BLD)/parser.tab.h $(BLD)/parser.tab.c
	@echo -e "$(FMT_GREEN)\nBuilding \"parser\"$(FMT_RESET) ...\n"
	$(CC) $(CCFLAGS) -Ibuild $^ -lfl -o $@

$(BLD)/parser.tab.c $(BLD)/parser.tab.h: $(SRC)/parser.y
	@echo -e "$(FMT_GREEN)\nGenerate \"parser.tab.c\"$(FMT_RESET) ...\n"
	$(YACC) -Wcounterexamples --header $^ -o $@

$(BLD)/libscanner.so: ./$(OBJ)/scanner.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared ./$(BLD)/scanner.o -o ./$(BLD)/libscanner.so
	-chmod 755 ./$(BLD)/libscanner.so

$(BLD)/libscanner.a: ./$(OBJ)/scanner.o
	-ar rvs ./$(BLD)/libscanner.a ./$(BLD)/scanner.o
	-chmod 755 ./$(BLD)/libscanner.a

$(BLD)/rpcalc: $(SRC)/rpcalc.y
	$(YACC) $^ -o $@

$(BLD)/calc: $(BLD)/scanner.h $(BLD)/calc.tab.c $(OBJ)/scanner.o
	$(CXX) $(OBJ)/scanner.o $(BLD)/calc.tab.c -o $(BLD)/calc

$(OBJ)/scanner.o: $(BLD)/calc.tab.h $(SRC)/scanner.h $(SRC)/scanner.c
	$(CXX) -I./build -c $(SRC)/scanner.c -o $@

$(BLD)/calc.tab.c $(BLD)/calc.tab.h: $(SRC)/calc.y
	$(YACC) --header -o $(BLD)/calc.tab.c -d $(SRC)/calc.y

$(SRC)/lexer.o:
	$(CXX)  -c $(SRC)/lexer.h $(SRC)/lexer.cpp -o $@


# copy header files
$(BLD)/scanner.h: $(SRC)/scanner.h
	cp $^ $@


# $(BLD)/config.hpp $(BLD)/constants.hpp $(BLD)/utility.hpp $(BLD)/fileio.hpp $(BLD)/scanner.h $(BLD)/Lexer.hpp: $(SRC)/config.hpp $(SRC)/constants.hpp $(SRC)/utility.hpp $(SRC)/fileio.hpp $(SRC)/scanner.h $(SRC)/Lexer.hpp
# 	cp $(SRC)/*.hpp $(BLD)/

$(BLD)/%.hpp: $(SRC)/%.hpp
	cp $< $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -I./$(BLD) -c -o $@ $<

.PHONY: all rebuild dist install uninstall clean help

rebuild: clean all

dist:
	tar -czvf scanner.tar.gz ./src ./include ./makefile ./README.md ./LICENSE ./CHANGELOG.md

install:
	cp ./$(BLD)/scanner ./$(prefix)/bin/scanner

uninstall:
	-rm ./$(prefix)/bin/scanner

clean:
	@echo -e "$(FMT_GREEN)cleaning ...$(FMT_RESET)"
	-rm -f ./$(OBJ)/*
	-rm -f ./$(BLD)/*

help:
	@echo  '  all              - build all'
	@echo  '  scanner          - build scanner executable'
	@echo  '  scanner.o        - build not link'
	@echo  '  libscanner.a     - build cppunit test'
	@echo  '  scanner_test     - build cppunit test'
	@echo  '  scanner_test.o   - build cppunit test'
	@echo  '  clean            - remove all files from build dir'
	@echo  '  install          - copy files to usr/local'
	@echo  '  dist             - create distribution, tar.gz'
	@echo  '  rebuild          - clean and build all'
	@echo  '  help             - this help message'
