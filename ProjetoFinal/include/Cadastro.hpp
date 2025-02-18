#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <string>
#include <map>
#include <vector>

using namespace std;

/**
 * @class Player
 * @brief A classe player armazena informações do jogador, como o nome, o apelido
 * e as estatísticas de jogos.
 */

class Player
{

protected:
    string playerName; ///< Nome do jogador
    string nickname;///< Apelido do jogador 

public:
    map<string, pair<int, int>> stats;///<  Estatísticas dos jogos
    
    /**
     * @brief Construtor padrão
     */
    Player() = default;

    /**
     * @brief Construtor que inicializa o jogador com um apelido e nome
     * @param nickname: Apelido do jogador
     * @param name: Nome do jogador
     */
    Player(const string &nickname, const string &name);

    /**
     * @brief Obtém o nome do jogador
     * @return Nome do jogador
     */
    string getName() const;


    /**
     * @brief Obtém o apelido do jogador
     * @return Apelido do jogador
     */
    string getNickname() const;

    /**
     * @brief Obtém as estatísticas de um jogo específico
     * @param game: Nome do jogo
     * @return quantidade de vitórias e derrotas do jogo.
     */
    pair<int, int> getStats(const string &game) const;

    /**
     * @brief Adiciona uma vitória às estatísticas de um jogo
     * @param game: Nome do jogo
      * @note Esse método não é chamado diretamente, é usado por outro método como um auxiliar
     */
    void addWin(const string &game);

    /**
     * @brief Adiciona uma derrota às estatísticas de um jogo
     * @param game: Nome do jogo
     * @note Esse método não é chamado diretamente, é usado por outro método como um auxiliar
     */
    void addLoss(const string &game);

    /**
     * @brief Registra um jogo nas estatísticas do jogador, caso ainda não exista
     * @param game Nome do jogo
     */
    void addGame(const string &game);
    
    /**
     * @brief Converte as informações do jogador para uma string 
     * @return String com as informações do jogador
     */
    string toString() const;
};



/**
 * @class Register
 * @brief A classe Register é para cadastrar, buscar, remover e listar
 * jogadores, salvando as informações em um arquivo, e carregando as informações dele também.
 */
class Register
{
protected:
    map<string, Player> players; ///< Mapa de jogadores

 /**
     * @brief Imprime os jogadores listados no console
     * @param list Vetor de apelidos de jogadores
     * @param a:  Letra inicial usada como filtro
     * @note Usa o método listPlayers.
     */
    void printPlayers(const vector<string> &list, char a) const;

public:

    /**
     * @brief Busca um jogador pelo apelido
     * @param nickname: Apelido do jogador
     * @return Ponteiro para o jogador, ou nullptr se não for encontrado
     */
    Player *searchPlayer(const string &nickname);

    /**
     * @brief Registra um novo jogador
     * @param nickname: Apelido do jogador
     * @param name: Nome do jogador
     * @return Retorna True se o jogador foi registrado com sucesso, ou False se já existe
     */
    bool registerPlayer(const string &nickname, const string &name);
    
    /**
     * @brief Remove um jogador pelo apelido
     * @param nickname: Apelido do jogador a ser removido
     * @return Retorna True se o jogador foi removido, ou False se não foi encontrado
     */
    bool removePlayer(const string &nickname);

    /**
     * @brief Salva os dados dos jogadores em um arquivo
     * @param filename: Nome do arquivo de destino dos dados dos jogadores
     */
    void Save(const string &filename) const;

    /**
     * @brief Carrega os dados dos jogadores de um arquivo
     * @param filename: Nome do arquivo de onde vai ser carregado os dados dos jogadores
     */
    void Load(const string &filename);

    /**
     * @brief Lista os apelidos dos jogadores que começam com uma letra específica
     * @param a: Letra inicial para ser filtrada
     * @return Vetor de apelidos que atendem ao filtro
     * @note Esse método não é chamado diretamente, é usado por outro método como um auxiliar
     */
    vector<string> listPlayers(char a) const;
    
   

    /**
     * @brief Registra o resultado de uma partida entre dois jogadores
     * @param winnerNickname Apelido do jogador vencedor
     * @param loserNickname Apelido do jogador perdedor
     * @param game Nome do jogo
     * @return Retorna True se o resultado foi registrado com sucesso, ou False caso contrário
     * @note Usa o método addWin e o metodo addLoss
     */    bool result(const string &winnerNickname, const string &loserNickname, const string &game);
};

#endif