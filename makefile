CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRC = main.cpp Lista.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp Lista.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	./$(EXEC)
