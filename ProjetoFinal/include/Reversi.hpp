#ifndef REVERSI_H
#define REVERSI_H

#include "BaseGame.hpp"
#include <iostream>
#include <utility>

/**
 * @class Reversi
 * @brief A classe Reversi, derivada da BaseGame, possui métodos para validar a entrada do usuário, gerenciar ganhadores,
 * fazer as movimentações e controlar o fluxo do jogo
 */
class Reversi : public BaseGame
{
    private:
        char currentPlayer; ///< Representa o jogador atual ('X' para preto, 'O' para branco)
        
       /**
         * @brief Verifica se uma peça pode ser capturada pelo outro jogador, considerando as regras do jogo.
         * 
         * @param row: A linha onde a captura deve ser verificada
         * @param col: A coluna onde a captura deve ser verificada
         * @param itRow: A direção na linha onde verificar
         * @param itCol: A direção na coluna onde verificar
         * @param player: O jogador que está fazendo a jogada
         * @return Retorna True se a captura for válida, caso contrário, False.
         */
        bool checkForCapture(int row, int col, int itRow, int itCol, char player);

        /**
         * @brief Inverte as peças do oponente após uma captura.
         * 
         * Inverte as peças no tabuleiro após uma jogada válida que resulta em captura, conforme as regras do jogo.
         * 
         * @param row: Linha da peça capturada.
         * @param col: Coluna da peça capturada.
         * @param itRow: Direção na linha onde a inversão deve ocorrer.
         * @param itCol: Direção na coluna onde a inversão deve ocorrer.
         * @param player: O jogador que está fazendo a jogada.
         */
        void flipPieces(int row, int col, int itRow, int itCol, char player);
    
    public:
        
        /**
         * @brief Construtor padrão para inicializar o jogo
         */
        Reversi();

        /**
         * @brief Destrutor virtual
        */
        virtual ~Reversi();

        /**
         * @brief Obtém o movimento do jogador por coordenada
        * 
        * @return Um par de inteiros representando a linha e a coluna 
        */
        pair<int, int> playerMove() override;

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
         * @brief Verifica se o jogador tem um movimento válido, se há jogada possível no tabuleiro, conforme as regras do jogo
         * 
         * @param player O jogador a ser verificado ('X' ou 'O')
         * @return Retorna True se o jogador pode fazer um movimento válido, ou False caso contrário
         */
        bool hasValidMove(char player);


        /**
         * @brief Inicializa o tabuleiro com as peças padrão do Reversi
            
         */
        void initializeBoard();

        /**
         * @brief Alterna entre os jogadores para as jogadas
         */
        void switchPlayer(); 

    /**
     * @brief Controla o fluxo principal do jogo, gerenciando a partida entre os jogadores
     * 
     * @return O símbolo do jogador vencedor ('X' ou 'O') ou um ponto ('.') no caso de empate
     */
    char playGame();

};

#endif