#ifndef BASEGAME_HPP
#define BASEGAME_HPP

#include <vector>
#include <string>


using namespace std;
/** 
 * @class BaseGame
 * @brief Classe abstrata para ser base de todas as outras classes de jogos,
 * armazenando linha, coluna e o tabuleiro.
    
*/
class BaseGame{
    
    protected:

        int rows; ///< linhas do tabuleiro
        int cols;///< colunas do tabuleiro
        vector<vector<char>> board; //<< Matriz do tabuleiro


    public:

    /**
     * @brief construtor da classe baseGame inicializando as linhas e colunas
     * @param _rows: linhas do tabuleiro
     * @param _cols: colunas do tabuleiro
     */
    BaseGame (int _rows, int _cols);

    /**
     * @brief Destrutor virtual de BaseGame
     */
    virtual ~BaseGame();

    /** 
     * @brief Exibe o tabuleiro
    */
    virtual void displayBoard();

    /**
     *  @brief Pega jogada do usuário 
     * @return Retorna par de inteiros da jogada do jogador
     */
    virtual pair<int, int> playerMove() = 0;

    /** 
     * @brief Validar o movimento
     * @param row: linha da jogada
     * @param col: coluna da jogada
     * @return retorna True se a jogada for válida e false se não
    */
    virtual bool validateMove(int row, int col) = 0;

    /** 
     * @brief Aplica o movimento do jogador
     * @param row: linha da jogada
     * @param col: coluna da jogada
     * @param player: Caractere representando o jogador ( 'X' ou 'O').
    */
    virtual void makeMove(int row, int col, char player)= 0;

    /** 
     * @brief Confere a finalização do jogo
     * @param player: Caractere representando o jogador ( 'X' ou 'O').
     * @return Retorna true se jogador venceu e false se não
    */
    virtual bool checkWinner(char player) = 0;    

    /** 
     * @brief Limpa o tabuleiro para o estado inicial
    */
    virtual void resetGame();
};


#endif 