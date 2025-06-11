# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++20 -I$(shell brew --prefix sfml)/include -Iinclude
LDFLAGS = -L$(shell brew --prefix sfml)/lib -lsfml-graphics -lsfml-window -lsfml-system 
# CXXFLAGS = -std=c++20 
# LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Target executable
TARGET = run

# Source files
SRCS = $(wildcard include/*.cpp) $(wildcard src/*.cpp)

# Default target: compile and run
all: compile run

# Compile only
compile: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Run the program
run:
	./$(TARGET)

# Clean target
clean:
	rm -f $(TARGET)