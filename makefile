CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -DMEMTRACE -g -Iinclude -Ilib
LDFLAGS = -no-pie

# Mappák meghatározása
SRC_DIR = src
INC_DIR = include
LIB_DIR = lib/memtrace_gtest
OBJ_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/nyr

# Források keresése több mappában
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(LIB_DIR)/memtrace.cpp
# Objektumok listája (a build mappába irányítva)
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SOURCES)))

# Alapértelmezett cél
all: directories $(TARGET)

# Könyvtárak létrehozása, ha nem léteznek
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# Linkelés
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

# Fordítás (VPATH segít megtalálni a forrásokat a mappákban)
vpath %.cpp $(SRC_DIR) $(LIB_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(TARGET)

.PHONY: all clean run directories