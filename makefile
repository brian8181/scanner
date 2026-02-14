# @file: makefile
# @date: Mon Sep  8 00:03:12 CDT 2025
# @version: 0.0.1

APP = scanner
CXX = g++
CC = gcc
#LEX = reflex
LEX = flex
#YACC = bison -y
YACC = bison
YFLAGS =
CXXFLAGS = -g -std=c++20 -fPIC -DLEX_TEST -DCYGWIN
CCFLAGS = -g -DLEX_TEST -DCYGWIN
#LDFLAGS += /usr/lib/libcppunit.dll.a
LDFLAGS=/usr/local/lib/libfmt.a
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

all: $(BLD)/scanner


$(BLD)/scanner: $(BLD)/parser.tab.c $(BLD)/parser.tab.h $(SRC)/fileio.cpp $(SRC)/scanner.cpp $(SRC)/scanner.hpp $(SRC)/tokens.hpp $(SRC)/Lexer.cpp $(BLD)/Lexer.hpp $(SRC)/utility.cpp $(BLD)/ast.o
	$(CXX) $(CXXFLAGS) -fPIC -I./$(BLD) -I"/home/brian/src/boost_1_89_0" $(SRC)/fileio.cpp $(SRC)/scanner.cpp $(SRC)/Lexer.cpp $(SRC)/utility.cpp $(LDFLAGS) -o $@


$(BLD)/parser.tab.c $(BLD)/parser.tab.h: $(SRC)/parser.y
	@echo -e "$(FMT_GREEN)\nGenerate \"parser.tab.c\"$(FMT_RESET) ...\n"
	$(YACC) -Wcounterexamples --header $^ -o $@

# copy header files
$(BLD)/%.h : $(SRC)/%.h
	cp $^ $@

$(BLD)/%.hpp: $(SRC)/%.hpp
	cp $< $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(ROOT)/build -I"/home/brian/src/boost_1_89_0" -c $< -o $@


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
	@echo  '  clean            - remove all files from build dir'
	@echo  '  install          - copy files to usr/local'
	@echo  '  rebuild          - clean and build all'
	@echo  '  help             - this help message'
