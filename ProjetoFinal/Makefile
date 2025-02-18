CC = g++
CFLAGS = -std=c++17 -Wall
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/main

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

ifeq ($(OS),Windows_NT)
    RM = del /q
    MKDIR = mkdir
    EXT = .exe
else
    RM = rm -f
    MKDIR = mkdir -p
    EXT = 
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Alvo para testes da classe Cadastro
testCadastro: $(SRC_DIR)/Cadastro.cpp $(TEST_DIR)/CadastroTeste.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $(TEST_DIR)/testeCadastro
	@echo "Teste compilado. Para executar, rode: ./$(TEST_DIR)/testeCadastro"

clean:
	$(RM) $(OBJ_DIR)/*.o
	$(RM) $(BIN_DIR)/*
	$(RM) $(TEST_DIR)/testeCadastro
	$(RM) test_save.txt

# Certifique-se de que os diretórios existam
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

.PHONY: all clean testCadastro
