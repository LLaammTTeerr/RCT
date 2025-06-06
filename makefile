# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O3

# SFML 3 configuration
SFML_INCLUDE = -I/usr/local/include
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Project directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable name
TARGET = $(BIN_DIR)/app

# Default target
all: debug

# Debug build
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build
release: CXXFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)

# Create bin directory and link the application
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $^ -o $@ $(SFML_LIBS)

# Create object directory and compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -I$(INC_DIR) -c $< -o $@

# Create necessary directories
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the application
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all debug release clean run