CC = g++
CXXFLAGS = -std=c++17
BZNAME = GPTest

OBJ = main.o

$(BZNAME): $(OBJ)
	$(CC) -o $@ $^

run:
	./$(BZNAME)

clean:
	rm $(OBJ)
