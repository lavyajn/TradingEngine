# Compiler and Flags
CXX = g++
# Since Makefile is now INSIDE engine/, the path to include is just 'include'
CXXFLAGS = -std=c++20 -g -Wall -Wextra -Iinclude

# Local Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Files
# 1. Logic files from src/
ENGINE_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# 2. Entry point in the current (engine/) directory
MAIN_SRC = main.cpp

SOURCES = $(MAIN_SRC) $(ENGINE_SOURCES)

# Generate object file paths
# This creates obj/main.o and obj/OrderPool.o etc.
OBJECTS = $(OBJ_DIR)/main.o $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(ENGINE_SOURCES))

TARGET = $(BIN_DIR)/engine

# Default Rule
all: $(TARGET)

# Link
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "------------------------------------------------"
	@echo "Build Successful: $(TARGET)"
	@echo "Run with: ./bin/engine"
	@echo "------------------------------------------------"

# Compile engine/src/*.cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Compile the main.cpp from the current folder
$(OBJ_DIR)/main.o: main.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Engine build cleaned."

.PHONY: all clean