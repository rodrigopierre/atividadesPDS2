#include "../include/BaseGame.hpp"
#include <iostream>
#include <vector>

using namespace std;

// ** Construtor inicializando o tabuleiro & Destrutor
BaseGame::BaseGame(int _rows, int _cols): rows(_rows), cols(_cols), board(_rows, vector<char>(_cols, '.')) {}
BaseGame::~BaseGame() {}

// ** Mostrar o tabuleiro
void BaseGame::displayBoard() {
    for (int _rows = 0; _rows < rows; ++_rows) {
        for (int _cols = 0; _cols < cols; ++_cols) {
            cout << "| " << board[_rows][_cols] << " ";
        }
        cout << "|" << endl;
        cout << string(cols * 4 + 1, '-') << endl;
    }
}

// ** Limpar o tabuleiro
void BaseGame::resetGame(){
    for (auto& row : board) {
        fill(row.begin(), row.end(), '.');
    }
}
