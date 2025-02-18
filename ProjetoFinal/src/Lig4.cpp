#include "../include/Lig4.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>


using namespace std;

Lig4::Lig4() : BaseGame(6, 7), currentPlayer('X') {}

Lig4::~Lig4() {
}

pair<int, int> Lig4::playerMove() {
    int col;
    cout << "Jogador " << currentPlayer << ", escolha uma coluna (0 a " << cols - 1 << "): ";
    cin >> col;
    // Valida entrada não-inteira
    if (cin.fail()) {
        cin.clear(); // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
        col = -1; // Define um valor inválido
    } else if (col >= 0 && col < cols) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta qualquer coisa após o primeiro número
        }
    cout << endl;
    return {0, col}; // Apenas a coluna importa
}

bool Lig4::validateMove(int row, int col) {

        cout<<endl;
    if (row != 0) {
        cout << "ERRO: apenas a linha inicial eh permitida no Lig4!" << endl;
        cout<<endl;
        return false;
    }
    if (col < 0 || col >= cols || board[0][col] != '.') {
        cout << "ERRO: jogada invalida!" << endl;
        cout<<endl;
        return false;
    }
    return true;
}

void Lig4::makeMove(int row, int col, char player) {
    for (int r = rows - 1; r >= 0; --r) {
        if (board[r][col] == '.') {
            board[r][col] = player;
            break;
        }
    }
}
bool Lig4::checkDraw() {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (board[r][c] == '.') {
                return false; 
            }
        }
    }
    return true; 
}
bool Lig4::checkWinner(char player) {
    // Horizontal
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c <= cols - 4; ++c) {
            if (board[r][c] == player && board[r][c + 1] == player &&
                board[r][c + 2] == player && board[r][c + 3] == player) {
                return true;
            }
        }
    }

    // Vertical
    for (int c = 0; c < cols; ++c) {
        for (int r = 0; r <= rows - 4; ++r) {
            if (board[r][c] == player && board[r + 1][c] == player &&
                board[r + 2][c] == player && board[r + 3][c] == player) {
                return true;
            }
        }
    }

    // Diagonal (descendo)
    for (int r = 0; r <= rows - 4; ++r) {
        for (int c = 0; c <= cols - 4; ++c) {
            if (board[r][c] == player && board[r + 1][c + 1] == player &&
                board[r + 2][c + 2] == player && board[r + 3][c + 3] == player) {
                return true;
            }
        }
    }

    // Diagonal (subindo)
    for (int r = 3; r < rows; ++r) {
        for (int c = 0; c <= cols - 4; ++c) {
            if (board[r][c] == player && board[r - 1][c + 1] == player &&
                board[r - 2][c + 2] == player && board[r - 3][c + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

char Lig4::playGame() {
    resetGame();
    displayBoard();
    cout<<endl;
    while (true) {
        pair<int, int> move = playerMove();  

        int row = move.first; 
        int col = move.second; 

        if (!validateMove(row, col)) {
            continue;
        }

        makeMove(row, col, currentPlayer);
        displayBoard();
        cout<<endl;

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