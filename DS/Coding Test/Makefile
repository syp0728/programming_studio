CC = g++
SRC = q1.cpp q2.cpp q3.cpp q4.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp 
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(EXEC)