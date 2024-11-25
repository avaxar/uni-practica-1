CXX = g++
FLAGS = -Wall
TARGET = second_max
SRC = second_max.cpp

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
