#include "../include/JogoDaVelha.hpp"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

JogoDaVelha::~JogoDaVelha() {
}
// Exibir o tabuleiro
void JogoDaVelha::displayBoard() {
    cout << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << " " << (board[i][j] == ' ' ? '.' : board[i][j]);
            if (j < cols - 1) cout << " |";
        }
        cout << "\n";
        if (i < rows - 1) cout << string((cols * 4) - 1, '-') << "\n";
    }
    cout << "\n";
}



JogoDaVelha::JogoDaVelha() : BaseGame(3, 3), currentPlayer('X') {}


pair<int, int> JogoDaVelha::playerMove() {
    int row, col;
    cout << "Jogador " << currentPlayer << ", escolha uma linha (0 a " << rows - 1 << ") e uma coluna (0 a " << cols - 1 << "): ";
    cin >> row;
    cin>> col;
    cout<<endl;
    return {row, col};
}

bool JogoDaVelha::validateMove(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != '.') {
        cout << "ERRO: Jogada invalida!"<<endl;
        cout<<endl;
        return false;
    }
    return true;
}

void JogoDaVelha::makeMove(int row, int col, char player) {
    board[row][col] = player;
}
bool JogoDaVelha::checkDraw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == '.') {
                return false; 
            }
        }
    }
    return true; 
}

bool JogoDaVelha::checkWinner(char player) {
    // Verificar linhas e colunas
    for (int i = 0; i < rows; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Verificar diagonais
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

char JogoDaVelha::playGame() {
    resetGame();
    displayBoard();
    cout<<endl;
    while (true) {
        pair<int, int> move = playerMove();  

        int row = move.first;  
        int col = move.second; 

        if (!validateMove(row, col)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        makeMove(row, col, currentPlayer);
        displayBoard();

        if (checkWinner(currentPlayer)) {
            return currentPlayer;
        }
        if (checkDraw()) {
            cout<<endl;
            cout<<"O jogo empatou!"<<endl;
            cout<<endl;
            return '.'; 
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

}
