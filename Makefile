CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -I.

# If you have doctest as a header-only library, make sure it's in your include path
INCLUDES = -I/path/to/doctest

# Source files
SOURCES = Demo.cpp Graph.cpp Algorithms.cpp Test.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Executable names
EXECUTABLES = demo test

# Default target
all: $(EXECUTABLES)

# Build demo
demo: Demo.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) -o demo Demo.o Graph.o Algorithms.o

# Build test
test: Test.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o test Test.o Graph.o Algorithms.o

# Compile sources
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(EXECUTABLES)
