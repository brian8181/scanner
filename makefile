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
all: ./$(BLD)/scanner # ./$(BLD)/\*~${APP_NAME}_test~*\ ./$(BLD)/libscanner.so ./$(BLD)/libscanner.a

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

#CCSK_RULE#

.PHONY: rebuild
rebuild: clean all

.PHONY: install
install:
	cp ./$(BLD)/scanner ./$(prefix)/bin/scanner

.PHONY: uninstall
uninstall:
	-rm ./$(prefix)/bin/scanner

.PHONY: clean
clean:
	-rm -f ./$(OBJ)/*.o
	-rm -f ./$(BLD)/*.o
	-rm -f ./$(BLD)/scanner*
	-rm -f ./$(BLD)/libscanner.*
	-rm -f ./$(BLD)/libstreamy.*
	-rm -f ./*~${APP}_test~*
	-rm -f ./*~${APP}~*
	-rm -f ./$(BLD)/*~${APP}~*
	-rm -f ./$(BLD)/*~${APP}_test~*
	-rm -f ./*~
	-rm -f ./$(BLD)/*~
	-rm -f ./*.gch
	-rm -f ./$(BLD)/*.gch
	-rm -f ./*.stackdump
	-rm -f ./$(BLD)/*.stackdump
	-rm -f ./*.dSYM
	-rm -f ./$(BLD)/*.dSYM
	-rm -f ./*.exe
	-rm -f ./$(BLD)/*.exe
	-rm -f ./*.log
	-rm -f ./$(BLD)/*.log
	-rm -f ./*.out
	-rm -f ./$(BLD)/*.out
	-rm -f ./*.tar.gz
	-rm -f ./$(BLD)/*.tar.gz
	-rm -f ./*.zip
	-rm -f ./$(BLD)/*.zip
	-rm -f ./*.7z
	-rm -f ./$(BLD)/*.7z
	-rm -f ./*.rar
	-rm -f ./$(BLD)/*.rar
	-rm -f ./*.bz2
	-rm -f ./$(BLD)/*.bz2
	-rm -f ./*.xz
	-rm -f ./$(BLD)/*.xz
	-rm -f ./*.Z
	-rm -f ./$(BLD)/*.Z
	-rm -f ./*.lz
	-rm -f ./$(BLD)/*.lz
	-rm -f ./*.lzma
	-rm -f ./$(BLD)/*.lzma
	-rm -f ./*.lzo
	-rm -f ./$(BLD)/*.lzo
	-rm -f ./*.zst
	-rm -f ./$(BLD)/*.zst
	-rm -f ./*.zstd
	-rm -f ./$(BLD)/*.zstd
	-rm -f ./*.tar
	-rm -f ./$(BLD)/*.tar
	-rm -f ./*.7zip
	-rm -f ./$(BLD)/*.7zip
	-rm -f ./*.rar
	-rm -f ./$(BLD)/*.rar
	-rm -f ./*.zip
	-rm -f ./$(BLD)/*.zip
	-rm -f ./*.gz
	-rm -f ./$(BLD)/*.gz
	-rm -f ./*.tgz
	-rm -f ./$(BLD)/*.tgz
	-rm -f ./*.tbz2
	-rm -f ./$(BLD)/*.tbz2
	-rm -f ./*.txz
	-rm -f ./$(BLD)/*.txz
	-rm -f ./*.Z
	-rm -f ./$(BLD)/*.Z
	-rm -f ./*.dmg
	-rm -f ./$(BLD)/*.dmg
	-rm -f ./*.iso
	-rm -f ./$(BLD)/*.iso
	-rm -f ./*.img
	-rm -f ./$(BLD)/*.img
	-rm -f ./*.bin
	-rm -f ./$(BLD)/*.bin
	-rm -f ./*.cue
	-rm -f ./$(BLD)/*.cue
	-rm -f ./*.md5
	-rm -f ./$(BLD)/*.md5
	-rm -f ./*.sha1
	-rm -f ./$(BLD)/*.sha1
	-rm -f ./*.sha256
	-rm -f ./$(BLD)/*.sha256
	-rm -f ./*.sha512
	-rm -f ./$(BLD)/*.sha512
	-rm -f ./*.log
	-rm -f ./$(BLD)/*.log
	-rm -f ./*.out
	-rm -f ./$(BLD)/*.out
	-rm -f ./*.tmp
	-rm -f ./$(BLD)/*.tmp
	-rm -f ./*.temp
	-rm -f ./$(BLD)/*.temp
	-rm -f ./*.bak
	-rm -f ./$(BLD)/*.bak
	-rm -f ./*.old
	-rm -f ./$(BLD)/*.old
	-rm -f ./*.orig
	-rm -f ./$(BLD)/*.orig
	-rm -f ./*.rej
	-rm -f ./$(BLD)/*.rej
	-rm -f ./*.swp
	-rm -f ./$(BLD)/*.swp
	-rm -f ./*.swo
	-rm -f ./$(BLD)/*.swo
	-rm -f ./*.swn
	-rm -f ./$(BLD)/*.swn

.PHONY: help
help:
	@echo  '  all         - build all'
	@echo  '  scanner          - build scanner executable'
	@echo  '  scanner.o        - build not link'
	@echo  '  scanner_test     - build cppunit test'
	@echo  '  scanner_test.o   - build cppunit test'
	@echo  '  clean                      - remove all files from build dir'
	@echo  '  install                    - copy files to usr/local'
	@echo  '  dist                       - create distribution, tar.gz'
