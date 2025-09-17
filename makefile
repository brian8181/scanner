# @file: makefile
# @date: Mon Sep  8 00:03:12 CDT 2025
# @version: 0.0.1

# g++ warnings
#-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -Wundef
#-fsanitize=undefined,address -Wfloat-equal -Wformat-nonliteral
#-Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch
#-Wlogical-op -Wmissing-declarations -Wmissing-field-initializers
#-Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn
#-Wnested-externs -Wpacked -Wpointer-arith -Wredundant-decls
#-Wstack-protector -Wstrict-null-sentinel -Wswitch-enum -Wwrite-strings

#CXXEXTRA=-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wno-sign-conversion -Wno-unused-parameter
#-Wno-unused-variable -Wno-unused-but-set-variable -Wno-missing-field-initializers -Wno-unknown-pragmas
#-Wno-comment -Werror -Wfatal-errors -fsanitize=address,undefined -fno-omit-frame-pointer -D_GLIBCXX_USE_CXX11_ABI=1

SHELL := bash
# .ONESHELL:
# .SHELLFLAGS := -eu -o pipefail -c
# .DELETE_ON_ERROR:
# MAKEFLAGS += --warn-undefined-variables
# MAKEFLAGS += --no-builtin-rules

# ifeq ($(origin .RECIPEPREFIX), undefined)
#   $(error This Make does not support .RECIPEPREFIX. Please use GNU Make 4.0 or later)
# endif
# .RECIPEPREFIX = >
# # Default - top level rule is what gets ran when you run just `make`
# build: out/image-id
# .PHONY: build

# Clean up the output directories; since all the sentinel files go under tmp, this will cause everything to get rebuilt
# clean:
# > rm -rf tmp
# > rm -rf out
# .PHONY: clean

APP=inflex
CXX=g++
BISON=bison
FLEX=flex
YACC = bison -y
YFLAGS =
CXXFLAGS=-std=c++20 -fPIC
FLEXFLAGS=--flex
BISONFLAGS= y -d --html --graph
BLD=build
OBJ=build
SRC=src
AST=ast

LIBS = -L/usr/local/lib/
INCLUDES = -I./build/
LDFLAGS = $(LIBS) $(INCLUDES)

ifndef RELEASE
	CXXFLAGS +=-ggdb -DDEBUG
endif

ifdef CYGWIN
	CXXFLAGS +=-DCYGWIN
	#LDFLAGS += /usr/lib/libcppunit.dll.a
endif

ifdef REFLEX
	FLEX=reflex
	CXXFLAGS +=-DREFLEX
	#LDFLAGS += /usr/local/lib/libcppunit.a /usr/local/lib/libreflex.a
	REFLEXFLAGS=-I/usr/local/include/reflex
endif

.PHONY all: help
all: ./$(BLD)/scanner # ./$(BLD)/$(APP)_test ./$(BLD)/libscanner.so ./$(BLD)/libscanner.a

$(BLD)/scanner: $(BLD)/utility.o $(BLD)/fileio.o $(BLD)/scanner.o $(BLD)/compiler.o $(BLD)/streamy.o
	$(CXX) $(CXXFLAGS) -fPIC -I$(PREFIX)/include $^ -o $@

$(BLD)/libscanner.so: ./$(BLD)/scanner.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared ./$(BLD)/scanner.o -o ./$(BLD)/libscanner.so
	-chmod 755 ./$(BLD)/libscanner.so

$(BLD)/libscanner.a: ./$(BLD)/scanner.o
	-ar rvs ./$(BLD)/libscanner.a ./$(BLD)/scanner.o
	-chmod 755 ./$(BLD)/libscanner.a

$(BLD)/libstreamy.so: $(OBJ)/fileio.o $(OBJ)/compiler.o $(BLD)/streamy.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -fPIC --shared $(OBJ)/fileio.o $(OBJ)/compiler.o $(OBJ)/streamy.o -o $(BLD)/libstreamy.so
	chmod 755 $(BLD)/libstreamy.so

$(BLD)/libstreamy.a: $(BLD)/streamy.o
	ar rvs $(BLD)/libstreamy.a $(OBJ)/streamy.o
	chmod 755 $(BLD)/libstreamy.a


$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/%.o: $(AST)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

rebuild: clean all
.PHONY: rebuild

dist:
	tar -czvf scanner.tar.gz ./src ./include ./makefile ./README.md ./LICENSE ./CHANGELOG.md
.PHONY: dist

install:
	cp ./$(BLD)/scanner ./$(prefix)/bin/scanner
.PHONY: install

uninstall:
	-rm ./$(prefix)/bin/scanner
.PHONY: uninstall

clean:
	-rm -f ./$(OBJ)/*.o
	-rm -f ./$(BLD)/*.o
.PHONY: clean

help:
	@echo  '  all         - build all'
	@echo  '  scanner          - build scanner executable'
	@echo  '  scanner.o        - build not link'
	@echo  '  scanner_test     - build cppunit test'
	@echo  '  scanner_test.o   - build cppunit test'
	@echo  '  clean                      - remove all files from build dir'
	@echo  '  install                    - copy files to usr/local'
	@echo  '  dist                       - create distribution, tar.gz'
	@echo  '  rebuild                    - clean and build all'
	@echo  '  help                       - this help message'
.PHONY: help
