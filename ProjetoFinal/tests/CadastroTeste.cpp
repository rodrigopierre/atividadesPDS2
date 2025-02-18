#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Cadastro.hpp"
#include "doctest.h"

//Testes para a classe Player
TEST_CASE("Testando a Classe Player"){
    Player player("Araldi", "João_Araldi");

    //Teste Get
    CHECK(player.getName() == "João_Araldi");
    CHECK(player.getNickname() == "Araldi");

    //Stats para jogo que não existe
    auto stats= player.getStats("Programador de PDS2");
    CHECK(stats.first == 0);
    CHECK(stats.second == 0);

    //Adicionando jogo e atualizando os status
    player.addGame("Futebol");
    CHECK(player.getStats("Futebol").first == 0);
    CHECK(player.getStats("Futebol").second == 0);

    player.addWin("Futebol");
    CHECK(player.getStats("Futebol").first == 1);

    player.addLoss("Futebol");
    player.addLoss("Futebol");
    CHECK(player.getStats("Futebol").second == 2);

    std::string expected = "Nome: João_Araldi| Apelido: Araldi\nJogo: Futebol | Vitorias: 1 | Derrotas: 2\n";
    CHECK(player.toString() == expected);
}

//Testes para a classe Register
TEST_CASE("Testando a classe Register"){
    Register reg;

    CHECK(reg.registerPlayer("Araldi", "João_Araldi")==true);
    CHECK(reg.registerPlayer("Araldi", "João_Araldi")==false);//Não registra o mesmo jogador duas vezes

    //Testando a busca de Jogadores
    reg.registerPlayer("Chaimo", "Luiz_Chaimowithz");
    Player* jogador = reg.searchPlayer("Chaimo");
    CHECK(jogador!=nullptr);
    CHECK(jogador->getName() == "Luiz_Chaimowithz");

    //Testando a busca de Jogadores que não existem
    CHECK(reg.searchPlayer("João")==nullptr);

    //Testando remoção de Jogadores
    CHECK(reg.removePlayer("Chaimo")==true);
    CHECK(reg.removePlayer("Chaimo")==false);//Não remove jogador que não existe

    //Testando registro de resultado de partidas
    reg.registerPlayer("random", "Aleatório");
    Player* joao = reg.searchPlayer("Araldi");
    Player* aleatorio = reg.searchPlayer("random");
    joao->addGame("Futebol");
    aleatorio->addGame("Futebol");

    CHECK(reg.result("Araldi", "random", "Futebol")==true);

    CHECK(joao->getStats("Futebol").first == 1);
    CHECK(joao->getStats("Futebol").second == 0);
    CHECK(aleatorio->getStats("Futebol").first == 0);
    CHECK(aleatorio->getStats("Futebol").second == 1);

    // Testando persistência de dados (Save e Load)
    reg.Save("test_save.txt");

    Register newReg;
    newReg.Load("test_save.txt");

    CHECK(newReg.searchPlayer("Araldi") != nullptr);
}