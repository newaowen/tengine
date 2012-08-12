#compile tool
SHELL:=/bin/bash

CC=g++

INCLUDE_DIR=-Iinclude 
LIBS=-lSDL -lSDLmain
CFLAGS=-Wall -o3

SRC_DIR=src
BUILD_DIR=build
BIN_DIR=bin

all : subsystem 
subsystem:
	@cd $(SRC_DIR) && $(MAKE)	


