CC = g++
CFLAGS = -Iinclude -Wall -std=c++11
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
EXECUTABLE = vpl_execution

all: $(BUILD_DIR) $(OBJ_LIST) $(OBJ_MAIN) $(EXECUTABLE)

$(BUILD_DIR)/list.o: $(SRC_DIR)/list.cpp $(INCLUDE_DIR)/list.hpp $(INCLUDE_DIR)/node.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/list.cpp -o $(BUILD_DIR)/list.o

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(EXECUTABLE): $(BUILD_DIR)/list.o $(BUILD_DIR)/main.o
	$(CC) $(BUILD_DIR)/list.o $(BUILD_DIR)/main.o -o $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXECUTABLE)
