CXX = g++
FLAGS = -Wall
TARGET = reversal
SRC = reversal.cpp

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(TARGET)

test: $(TARGET)_test
	./$(TARGET)_test

$(TARGET)_test: $(SRC)
	$(CXX) ${FLAGS} -g ${SRC} -o ${TARGET}_test -DTEST

clean:
	rm -f $(TARGET) ${TARGET}_test
