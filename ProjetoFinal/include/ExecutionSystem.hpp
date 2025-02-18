#ifndef EXECUTIONSYSTEM_HPP
#define EXECUTIONSYSTEM_HPP

#include "Cadastro.hpp"
#include "BaseGame.hpp"
#include "JogoDaVelha.hpp"
#include "Lig4.hpp"
#include "Reversi.hpp"
#include <cstdlib> ///< para system()
#include <csignal> ///< Biblioteca usada para capturar sinais de saída de execução forçada

using namespace std;

extern Register* globalRegisterSystem;  ///< Ponteiro global para acessar o sistema de cadastro

/**
 * @brief Função que salva os dados do jogo quando o programa é interrompido (Ctrl+C)
 * @param signal: índice de sinal
 */
void handleSignal(int signal);

/**
 * @brief Inicializa o manipulador de sinal
 */
void initializeSignalHandler();

/**
 * @brief Exibe o menu principal com as opções que o usuário pode explorar
 */
void menu();

/**
 * @brief Carrega os dados dos jogadores de um arquivo
 * 
 * @param registerSystem Objeto do tipo Register para gerenciar os dados dos jogadores
 */
void loadGameData(Register& registerSystem);

/**
 * @brief Carrega os dados dos jogadores em um arquivo
 * 
 * @param registerSystem Objeto do tipo Register com os dados que precisam ser salvos
 */
void saveGameData(Register& registerSystem);

/**
 * @brief Valida se é uma string válida
 * 
 * @param str String a ser validada
 * @return Retorna True se a string for válida, ou False caso contrário
 */
bool validString(const string& str);

/**
 * @brief Registra um novo jogador no sistema
 * 
 * @param nickname: Apelido do jogador
 * @param name: Nome do jogador
 * @param registerSystem: Objeto do tipo Register onde o jogador será armazenado
 */
void registerCommand(string nickname, string name, Register& registerSystem);

/**
 * @brief Executa o jogo Reversi entre dois jogadores cadastrados
 * 
 * @param nicknameOne: Apelido do primeiro jogador
 * @param nicknameTwo: Apelido do segundo jogador
 * @param registerSystem: Objeto do tipo Register para atualizar os resultados da partida nas estatísticas
 */
void reversiExecution(string nicknameOne, string nicknameTwo, Register& registerSystem);

/**
 * @brief Executa o jogo Lig4 entre dois jogadores cadastrados
 * 
 * @param nicknameOne: Apelido do primeiro jogador
 * @param nicknameTwo: Apelido do segundo jogador
 * @param registerSystem: Objeto do tipo Register para atualizar os resultados da partida nas estatísticas
 */
void lig4Execution(string nicknameOne, string nicknameTwo, Register& registerSystem);

/**
 * @brief Executa o jogo da velha entre dois jogadores cadastrados
 * 
 * @param nicknameOne: Apelido do primeiro jogador
 * @param nicknameTwo: Apelido do segundo jogador
 * @param registerSystem: Objeto do tipo Register para atualizar os resultados da partida nas estatísticas
 */
void velhaExecution(string nicknameOne, string nicknameTwo, Register& registerSystem);

/**
 * @brief Configura uma partida entre dois jogadores
 * 
 * @param registerSystem Objeto do tipo Register que gerencia os jogadores
 */
void setUpGame(Register& registerSystem);

/**
 * @brief Limpa a tela do console
 */
void clearScreen();

/**
 * @brief Faz a entrada dos nomes dos jogadores e o tratamento e checagem de erro deles *
 *  
 * @param nicknameOne: Apelido do primeiro jogador
 * @param nicknameTwo: Apelido do segundo jogador
 * @param registerSystem: Objeto do tipo Register para atualizar os resultados da partida nas estatísticas
 */
void playerRegistration(string& nicknameOne, string& nicknameTwo, Register &registerSystem);

#endif
