#include "Cadastro.hpp"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cctype>

//* Construtor de Player
Player::Player(const string& nickname, const string& name) : playerName(name), nickname(nickname) {}


//* Métodos de Get
string Player::getName() const{ return playerName; }
string Player::getNickname() const{ return nickname; }
pair<int,int> Player::getStats(const string& game) const{
    auto it = stats.find(game);
    if (it != stats.end()) {
        return it->second;
    }
    return {0, 0}; //* Se não encontrar, retorna 0 vitórias e 0 derrotas
}

void Player::addWin(const string& game){
    auto it = stats.find(game);
    if (it != stats.end()) {
        it->second.first++;
    } else {
        std::cout << "Jogo nao encontrado, Impossivel registrar vitoria" << std::endl;
    }
}

void Player::addLoss(const string& game){
    auto it = stats.find(game);
    if(it != stats.end()){
        it->second.second++;
    } else {
        std::cout << "Jogo nao encontrado, Impossivel registrar derrota" << std::endl;
    }
}

void Player::addGame(const string& game) {
    stats[game] = {0, 0}; // Inicializa o jogo com 0 vitórias e 0 derrotas
}

string Player::toString() const{//* Método para transformar os dados de Player em string
    stringstream ss;
    ss << "Nome: " << playerName <<"|"<< " Apelido: " << nickname << endl;
    for(auto it = stats.begin(); it != stats.end(); it++){
        ss << "Jogo: " << it->first << " | Vitorias: " << it->second.first << " | Derrotas: " << it->second.second << endl;
    }
    return ss.str();
}

//* FIM DOS MÉTODOS DA CLASSE JOGADOR

Player* Register::searchPlayer(const string& nickname){
    auto it = players.find(nickname);
    if(it == players.end()){
        // std::cout << "Jogador " << nickname <<" não encontrado, tente novamente!" << std::endl;
        return nullptr;
    }
    else{
        return &it->second;
    }
}

bool Register::registerPlayer(const string& nickname, const string& name) {
    if (searchPlayer(nickname)) {
        std::cout << "ERRO: Jogador ja cadastrado, tente novamente!" << std::endl;
        return false;
    }
    players.emplace(nickname, Player(nickname, name));
    return true;
}


bool Register::removePlayer(const string& nickname) {
    if (!searchPlayer(nickname)) {
    std::cout << "Jogador nao encontrado, tente novamente!" << std::endl;
        return false;
    }
    players.erase(nickname);
    std::cout << "Jogador " << nickname << " removido com sucesso!" << std::endl;
    return true;
}

void Register::Save(const string& file) const {
    ofstream out(file);
    if (!out) {
        cerr << "ERRO: Nao foi possivel abrir o arquivo para salvar!" << endl;
        return;
    }

    for (const auto& entry : players) {
        string nickname = entry.first;
        Player player = entry.second;
        out << player.getNickname() << " " << player.getName();
        for (const auto& statEntry : player.stats) {
            out << " " << statEntry.first << " " << statEntry.second.first << " " << statEntry.second.second;
        }
        out << "\n"; 
    }


    out.close();
}


void Register::Load(const string& file) {
    // Verifica se o arquivo existe antes de tentar abri-lo
    ifstream test(file);
    if (!test.is_open()) {
        return;
    }
    test.close(); // Fechar após verificar a existência

    ifstream in(file);
    if (!in.is_open()) {
        cerr << "ERRO: Nao foi possível abrir o arquivo para carregar!" << endl;
        return;
    }

    string nickname, name;
    while (in >> nickname >> name) {
        Player player(nickname, name);

        string game;
        int wins, losses;
        while (in >> game >> wins >> losses) {
            player.stats[game] = {wins, losses};
            if (in.peek() == '\n') break;
        }

        players[nickname] = player;
    }

    in.close();
}

//Importante atentar-se a ordem de inserção dos nomes: vitorioso e perdedor, respectivamente.
bool Register::result(const string& winnerNickname, const string& loserNickname, const string& game) {
    Player* winner = searchPlayer(winnerNickname);
    Player* loser = searchPlayer(loserNickname);
    if (!winner || !loser) {
        // std::cout << "Jogador não encontrado, tente novamente!" << std::endl;
        return false;
    }

    winner->addWin(game);
    loser->addLoss(game);
    return true;
}

void Register::printPlayers(const vector<string>& list, char a) const {
    for (const auto& entry : list) {
        for (const auto& playerEntry : players) {
            const Player& player = playerEntry.second;
            if (toupper(a) == 'A' && entry == player.getNickname()) {
                std::cout << player.toString() << std::endl;
            } else if (toupper(a) == 'N' && entry == player.getName()) {
                std::cout << player.toString() << std::endl;
            }
        }
    }
}

vector<string> Register::listPlayers(char a) const {
    vector<string> list;
    for (const auto& entry : players) {
        string nickname = entry.first;
        Player player = entry.second;
        if (toupper(a) == 'A') {
            list.push_back(player.getNickname());
        } else if (toupper(a) == 'N') {
            list.push_back(player.getName());
        } else {
            std::cout << "Opcao invalida, tente novamente!" << std::endl;
            return {};
        }
    }
    if (list.empty()) {
        cout << "Ainda nao ha jogadores cadastrados!" << endl;
    }
    sort(list.begin(), list.end());
    printPlayers(list, toupper(a));
    return list;
}





