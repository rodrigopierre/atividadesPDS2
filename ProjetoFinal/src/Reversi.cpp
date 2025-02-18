#include "../include/Reversi.hpp"
#include <limits>
#include <sstream>


using namespace std;

Reversi::Reversi() : BaseGame(8, 8)
{
    initializeBoard();
    currentPlayer = 'X';
}
Reversi::~Reversi() {
}

void Reversi::initializeBoard()
{
    resetGame();
    board[3][3] = 'O';
    board[3][4] = 'X';
    board[4][3] = 'X';
    board[4][4] = 'O';
}

pair<int, int> Reversi::playerMove()
{
    int row, col;
    cout << "Jogador " << currentPlayer << ", escolha a linha e a coluna para mover (0-7): ";

    while (true) {
        string input;
        getline(cin, input);
        istringstream stream(input);

        if (stream >> row >> col) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                return {row, col};
            } else {
                cout << "ERRO: Coordenadas fora do tabuleiro! Tente novamente (0-7)." << endl<<endl;
            }
        } else {
            cout << "ERRO: Entrada inválida! Insira duas coordenadas inteiras separadas por espaço." <<endl<< endl;
        }

        cout << "Jogador " << currentPlayer << ", escolha a linha e a coluna para mover (0-7): ";
    }
}


bool Reversi::validateMove(int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout << "ERRO: Jogada fora do tabuleiro! Tente novamente." << endl;
        cout<<endl;
        return false;
    }
    if (board[row][col] != '.') {
        cout << "ERRO: Esta posicao ja esta ocupada! Tente novamente." << endl;
        cout<<endl;
        return false;
    }
    for(int itRow = -1; itRow <= 1; itRow++){
        for(int itCol = -1; itCol <= 1; itCol++){
            if(itRow != 0 || itCol != 0){
                if(checkForCapture(row, col, itRow, itCol, currentPlayer)){
                    return true;
                }
            }
        }
    }
    return false;
}

void Reversi::makeMove(int row, int col, char player)
{
    board[row][col] = player;
    for(int itRow = -1; itRow <= 1; itRow++){
        for(int itCol = -1; itCol <= 1; itCol++){
            if(itRow != 0 || itCol != 0){
                if(checkForCapture(row, col, itRow, itCol, player)){
                    flipPieces(row, col, itRow, itCol, player);
                }
            }
        }
    }
}

bool Reversi::hasValidMove(char player)
{
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (board[row][col] == '.') {
                if (validateMove(row, col)) {
                    return true; 
                }
            }
        }
    }
    return false;  
}

bool Reversi::checkWinner(char player)
{
    int countPlayer = 0, countOpponent = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == player){
                countPlayer++;
            } else if(board[i][j] != '.'){
                countOpponent++;
            }
        }
    }
    return countPlayer > countOpponent;
}

bool Reversi::checkForCapture(int row, int col, int itRow, int itCol, char player)
{
    int i = row + itRow;
    int j = col + itCol;
    bool hasOpponentPiece = false;
    while(i >= 0 && i < 8 && j >= 0 && j < 8){
        if(board[i][j] == '.'){
            return false;
        }
        if(board[i][j] == player){
            return hasOpponentPiece;
        }
        hasOpponentPiece = true;
        i += itRow;
        j += itCol;
    }
    return false;
}

void Reversi::flipPieces(int row, int col, int itRow, int itCol, char player) 
{
    int i = row + itRow;
    int j = col + itCol;
    while(i >= 0 && i < 8 && j >= 0 && j < 8 && board[i][j] != player){
        board[i][j] = player;
        i += itRow;
        j += itCol;
    }
}

void Reversi::switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

char Reversi::playGame()
{
    initializeBoard();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    displayBoard();
    cout << endl;
    int totalMoves = 0;
    while (true) {
        if (!hasValidMove(currentPlayer)) { 
            cout << "Jogador " << currentPlayer << " não tem movimentos válidos. Passando a vez!" << endl;
            cout << endl;
            cout<<endl;
            switchPlayer();  
            if (!hasValidMove(currentPlayer)) {  
                break;  
            }
            continue;
        }

        pair<int, int> move = playerMove();  
        int row = move.first;  
        int col = move.second; 

        while (!validateMove(row, col)) {
            cout<<endl;
            cout << "ERRO: Movimento invalido! Nao ha capturas possiveis. Tente novamente." << endl <<endl;
            pair<int, int> newMove = playerMove();  
            row = newMove.first;  
            col = newMove.second; 
        }

        makeMove(row, col, currentPlayer);
        cout << endl;
        displayBoard();
        cout<<endl;
        totalMoves++;

        if (totalMoves == rows * cols || (!hasValidMove('X') && !hasValidMove('O'))){
            break;  
        }

        switchPlayer();  
    }

    if (checkWinner('X')) {
        return 'X';  
    } else if (checkWinner('O')) {
        return 'O';  
    } else {
        return '.';  
    }
}