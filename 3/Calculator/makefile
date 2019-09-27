CC=g++
CXXFLAGS = -std=c++17

OBJ = main.o BZCalculator.o StreamCalculator.o Token.o TokenStream.o

calculator: $(OBJ)
	$(CC) -o $@ $^

clean:
	rm $(OBJ)
