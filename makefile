# @file: makefile
# @date: Mon Sep  8 00:03:12 CDT 2025
# @version: 0.0.1

APP = inflex
CXX = g++
LEX = reflex
LEX = flex
YACC = bison -y
YACC = bison
YFLAGS =
CXXFLAGS = -std=c++20 -fPIC
FLEXFLAGS = --flex
BISONFLAGS = -y -d --html --graph
BLD = build
OBJ = build
SRC = src
AST = ast

LIBS = -L/usr/local/lib/
INCLUDES = -I./build/
LDFLAGS = -lfmt $(LIBS) $(INCLUDES)

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

$(BLD)/scanner: $(BLD)/parser.tab.c $(BLD)/parser.tab.h $(BLD)/fileio.o $(OBJ)/scanner.o $(BLD)/scanner.hpp $(BLD)/Lexer.o $(BLD)/Lexer.hpp $(BLD)/utility.o
	$(CXX) $(CXXFLAGS) -fPIC -I./$(BLD) $(BLD)/fileio.o $(OBJ)/scanner.o $(BLD)/Lexer.o $(BLD)/utility.o $(LDFLAGS) -o $@

# parser # USING C COMPLIER ON CPP! BUT IT BUILDS?
$(BLD)/parser: $(BLD)/parser.tab.h $(BLD)/parser.tab.c
	@echo -e "\nBuilding \"lexer & parser\" ...\n"
	$(CC) $(CCFLAGS) -Ibuild $^ -lfl -o $@

$(BLD)/parser.tab.c $(BLD)/parser.tab.h: $(SRC)/parser.y
	@echo -e "\nGererating \"parser\" ...\n"
	$(YACC) -Wcounterexamples --header $^ -o $@

$(BLD)/libscanner.so: ./$(OBJ)/scanner.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared ./$(BLD)/scanner.o -o ./$(BLD)/libscanner.so
	-chmod 755 ./$(BLD)/libscanner.so

$(BLD)/libscanner.a: ./$(OBJ)/scanner.o
	-ar rvs ./$(BLD)/libscanner.a ./$(BLD)/scanner.o
	-chmod 755 ./$(BLD)/libscanner.a

# $(BLD)/config.hpp $(BLD)/constants.hpp $(BLD)/utility.hpp $(BLD)/fileio.hpp $(BLD)/scanner.hpp $(BLD)/Lexer.hpp: $(SRC)/config.hpp $(SRC)/constants.hpp $(SRC)/utility.hpp $(SRC)/fileio.hpp $(SRC)/scanner.hpp $(SRC)/Lexer.hpp
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
