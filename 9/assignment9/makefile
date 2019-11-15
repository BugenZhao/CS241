CC = g++
CXXFLAGS = -std=c++17
BZNAME = GE

OBJ = main.o

$(BZNAME): $(OBJ)
	$(CC) -o $@ $^

run:
	./$(BZNAME)

clean:
	rm $(OBJ)
