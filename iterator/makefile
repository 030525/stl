.PHONY: all clean 
.DEFAULT_GOAL := all

TEMP=BUILD
TARGET=main
CXX=g++
CXXFLAGS=-g -std=c++17 -Wall -O2
LDFLAGS= 

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,$(TEMP)/%.o,$(SRC))


all:$(TEMP) $(TARGET)

$(TEMP):
	mkdir $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TEMP)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
	rm -r $(TEMP)