#ifndef LIG4_HPP
#define LIG4_HPP

#include "BaseGame.hpp" 
#include <utility>                 


/**
 * @class Lig4
 * @brief A classe Lig4 representa o jogo Lig4, derivada de BaseGame, contendo
 * métodos para lidar com jogadas, checando ganhadores e controlando o fluxo de jogo e de jogadas.
 */
class Lig4 : public BaseGame {

    char currentPlayer;///< Indica o jogador atual ('X' ou 'O')

public:

    /**
     * @brief Construtor padrão para inicializar o jogo
     */
    Lig4();

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Lig4();  

    /**
     * @brief Obtém o movimento do jogador por coordenada
     * 
     * @return Um par de inteiros representando a linha e a coluna 
     * @note Nesse caso, como as peças são empilhadas, só a coluna que o jogador deseja que importa na escolha
     */
    std::pair<int, int> playerMove() override;

    /**
     * @brief Valida se o movimento inserido é válido conforme as regras do jogo
     * 
     * @param row: Linha do movimento
     * @param col: Coluna do movimento
     * @return Retorna True se o movimento for válido, ou False caso contrário
     */
    bool validateMove(int row, int col) override;
    
    /**
     * @brief Aplica o movimento no tabuleiro, atualizando o tabuleiro com o símbolo do jogador atual ('X' ou 'O').
     * 
     * @param row: Linha do movimento
     * @param col: Coluna do movimento
     * @param player: Jogador que está fazendo a jogada
     */
    void makeMove(int row, int col, char player) override;

    /**
     * @brief Verifica se um jogador venceu o jogo, conforme as regras do jogo
     * 
     * @param player: Jogador a ser verificado ('X' ou 'O')
     * @return Retorna True se o jogador venceu, ou False caso contrário
     */
    bool checkWinner(char player) override;
    
    /**
     * @brief Verifica se o jogo terminou em empate, conforme as regras do jogo.
     * 
     * @return Retorna True se o jogo terminou em empate, ou False caso contrário
     */
    bool checkDraw();

    /**
     * @brief Controla o fluxo principal do jogo, gerenciando a partida entre os jogadores
     * 
     * @return O símbolo do jogador vencedor ('X' ou 'O') ou um ponto ('.') no caso de empate
     */
    char playGame();
};

#endif // LIG4_HPP
