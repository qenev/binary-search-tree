CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -O2
TARGET=bst

all: $(TARGET)

$(TARGET): main.cpp BST.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET)
