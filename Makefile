CXX = g++
CXXFLAGS = -std=c++14 -I./include
SRC = src/hashtable/HashTable.cpp src/Utils.cpp src/main.cpp
TARGET = crossref

all: $(TARGET)

$(TARGET) : $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(TARGET)
	./tests/run_tests.sh

clean:
	rm -f $(TARGET)