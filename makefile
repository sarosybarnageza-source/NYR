# Fordító és flagek
CXX = g++
# A -fno-pie és -no-pie segít elkerülni a "relocation against read-only section" hibát
CXXFLAGS = -std=c++11 -Wall -Wextra -DMEMTRACE -g -Imemtrace_gtest -fno-pie
LDFLAGS = -no-pie

TARGET = nyr

# Minden létező forrásfájl
SOURCES = main.cpp \
          rendszer.cpp \
          gyerek.cpp \
          date.cpp \
          berlet.cpp \
          memtrace_gtest/memtrace.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

# Kifejezetten figyelünk arra, hogy minden .cpp-t ugyanazokkal a flagekkel fordítsunk
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
	rm -f memtrace_gtest/*.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run