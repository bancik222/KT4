CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SOURCES = src/main.cpp src/ChessMath.cpp
TARGET = build/a.out
DEBUG_TARGET = build/a_debug.out

.PHONY: all debug clean run help
all: $(TARGET)

$(TARGET): $(SOURCES) include/ChessMath.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) -O2 $(SOURCES) -o $@

debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(SOURCES) include/ChessMath.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) -g -O0 $(SOURCES) -o $@

run: all
	./$(TARGET) 4 4 4 8 8 8

clean:
	rm -rf build

help:
	@echo 'make | make debug | make run | make clean | make -B'
