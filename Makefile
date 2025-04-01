CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = main.cpp matrix.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = program

all: $(EXEC)

%.o: %.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean