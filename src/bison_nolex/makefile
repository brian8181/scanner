# File Name:   lex/calc2/makefile
# Modify Date: Fri Apr 12 11:26:14 PM CDT 2024
# Version:     0.0.1

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
SRC = .
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

all: $(BLD)/scanner

$(BLD)/scanner: $(BLD)/parser.tab.c $(BLD)/parser.tab.h $(BLD)/fileio.o $(OBJ)/scanner.o $(BLD)/scanner.hpp $(BLD)/Lexer.o $(BLD)/Lexer.h $(BLD)/utility.o $(BLD)/ast.o
	$(CXX) $(CXXFLAGS) -fPIC -I./$(BLD) -I"/home/brian/src/boost_1_89_0" $(BLD)/fileio.o $(OBJ)/scanner.o $(BLD)/Lexer.o $(BLD)/utility.o $(LDFLAGS) -o $@

$(BLD)/parser.tab.c $(BLD)/parser.tab.h: $(SRC)/parser.y
	@echo -e "$(FMT_GREEN)\nGenerate \"parser.tab.c\"$(FMT_RESET) ...\n"
	$(YACC) -Wcounterexamples --header $^ -o $@

# $(BLD)/calc: $(BLD)/lexer.h $(BLD)/calc.tab.c $(OBJ)/lexer.o
# 	$(CC) $(OBJ)/lexer.o $(BLD)/calc.tab.c -o $(BLD)/calc

# $(OBJ)/lexer.o: $(BLD)/calc.tab.h $(SRC)/lexer.h $(SRC)/lexer.c
# 	$(CC) -c $(SRC)/lexer.c -o $@

$(OBJ)/scanner.o: $(BLD)/calc.tab.h $(SRC)/scanner.hpp $(SRC)/scanner.cpp
	$(CXX) -I./build -I"/home/brian/src/boost_1_89_0" -c $(SRC)/scanner.cpp -o $@

# $(BLD)/calc.tab.c: $(SRC)/calc.y
# 	$(YACC) --header -o $(BLD)/calc.tab.c -d $(SRC)/calc.y

# copy header files
$(BLD)/lexer.h: $(SRC)/lexer.h
	cp $^ $@

# copy header files
$(BLD)/%.h : $(SRC)/%.h
	cp $^ $@

$(BLD)/%.hpp: $(SRC)/%.hpp
	cp $< $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(ROOT)/build -I"/home/brian/src/boost_1_89_0" -c $< -o $@


.PHONY: clean
clean:
	-rm -rf $(BLD)/*

.PHONY: help
help:
	@echo
	@echo '** Syntax **'
	@echo calc num+num[+num]...
	@echo
	@echo '** Make Targets **'
	@echo 'all - builds calc & dependencies'
	@echo "$(BLD)/calc - builds calc & dependencies"
	@echo "$(BLD)/calc.yy.c - complies calc.l"
	@echo "$(BLD)/calc.tab.c - complies calc.y"
	@echo
