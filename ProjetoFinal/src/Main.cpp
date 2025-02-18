#include <iostream>
#include <string>
#include "../include/Cadastro.hpp"
#include "../include/ExecutionSystem.hpp"
#include <limits>

using namespace std;

int main()
{

    string entry;                           ///< Armazena a entrada do usuário
    Register registerSystem;                ///< Instância do sistema de registro de jogadores
    globalRegisterSystem = &registerSystem; ///< Inicializa o ponteiro global
    try
    {
        loadGameData(registerSystem); ///< Carrega dados do jogo previamente salvo

        initializeSignalHandler(); ///< Inicializa o manipulador de sinal

        do
        {
            menu();       ///< Exibe o menu para o usuário
            cin >> entry; ///< Recebe a entrada do usuário
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            for (char &c : entry)
            {
                c = std::toupper(c); // Padroniza a entrada para maiúsculo
            }
            cout << endl;

            if (entry == "CJ")
            {
                cout << "Digite o apelido e o nome do jogador: ";
                string nickname;
                string name;
                cin >> nickname >> name;
                cout << endl;
                registerCommand(nickname, name, registerSystem); ///< Registra o jogador
                cout << endl;
            }
            else if (entry == "LJ")
            {
                char sequence;
                cout << "Digite 'A' se deseja listar por apelido ou 'N' se por nome: ";
                cin >> sequence;
                cout << endl;
                registerSystem.listPlayers(sequence); ///< Lista jogadores de acordo com a opção selecionada
                cout << endl;
            }
            else if (entry == "RJ")
            {
                string nickname;
                cout << "Digite o apelido do jogador que você deseja remover: ";
                cin >> nickname;
                cout << endl;
                registerSystem.removePlayer(nickname); ///< Remove o jogador do sistema
                cout << endl;
            }
            else if (entry == "EP")
            {
                setUpGame(registerSystem); ///< Configura e inicia o jogo desejado
                cout << endl;
            }
            else if (entry == "FS")
            {
                cout << "Finalizando o sistema!" << endl; ///< Finaliza o loop e o sistema
                cout << endl;
                break;
            }
            else
            {
                cout << "Comando invalido! Tente novamente" << endl;
                cout << endl;
            }

        } while (entry != "FS");

        saveGameData(registerSystem); ///< Salva os dados do jogo no final
    }
    catch (const invalid_argument &e)
    {
        cerr << "Argumento invalido: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Erro inesperado, tente novamente: " << e.what() << endl;
    }
    return 0;
}
