#include "../include/ExecutionSystem.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // pra system() e exit
#include <csignal> //Biblioteca usada pora capturar sinais de saída de execução forçada
#include <limits> // Biblioteca para o cin.ignore

using namespace std;

Register *globalRegisterSystem = nullptr; // Ponteiro global para acessar o sistema de cadastro

// Inicializa o manipulador de sinal
void initializeSignalHandler()
{
    signal(SIGINT, handleSignal);
}

// menu de execucao
void menu()
{
    cout << endl;
    cout << "-------------- MENU --------------" << endl;
    cout << endl;
    cout << "- Cadastrar Jogador: CJ" << endl;
    cout << "- Remover Jogador: RJ" << endl;
    cout << "- Listar Jogadores: LJ" << endl;
    cout << "- Executar partida: EP" << endl;
    cout << "- Finalizar o Sistema: FS" << endl << endl;
    cout << "INSIRA O COMANDO DESEJADO: ";
}

// limpar tela:

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Carregando algum registro de jogo anterior:

void loadGameData(Register &registerSystem)
{
    try
    {
        string folder = "src/PlayerData";
        string filename = folder + "/dataPlayer.txt";
        registerSystem.Load(filename);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao carregar dados do jogo: " << e.what() << endl;
    }
}

void saveGameData(Register &registerSystem)
{
    try
    {
        string folder = "src/PlayerData";
        string filename = folder + "/dataPlayer.txt";
        registerSystem.Save(filename);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao salvar dados do jogo: " << e.what() << endl;
    }
}

// Manipulador de sinal para capturar a interrupção (Ctrl+C)
void handleSignal(int signal)
{

    if (globalRegisterSystem != nullptr)
    {
        try
        {
            clearScreen();
            cout << endl;
            cout << "Dados salvos antes de saida forcada." << endl;
            cout << endl;
            saveGameData(*globalRegisterSystem);
        }
        catch (const exception &e)
        {
            cerr << "Erro ao salvar dados no encerramento: " << e.what() << endl;
            throw;
        }
    }
    exit(0); // Encerra o programa
}

// Checagem se a entrada é uma string não vazia:

bool validString(const string &str)
{
    if (str.empty())
    {
        return false;
    }

    return true;
}

// Registro de novo jogador:

void registerCommand(string nickname, string name, Register &registerSystem)
{

    try
    {
        if (!validString(nickname) || !validString(name))
        {
            throw invalid_argument("ERRO: O apelido e o nome devem ser válidos!");
        }

        if (registerSystem.registerPlayer(nickname, name))
        {
            cout << "Jogador " << nickname << " registrado com sucesso!" << endl;
            Player *player = registerSystem.searchPlayer(nickname);
            player->addGame("LIG4");
            player->addGame("REVERSI");
            player->addGame("VELHA");
        }
    }
    catch (const invalid_argument &e)
    {
        cerr << "Argumento inválido: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}

// EXECUÇÃO DE PARTIDA:

// - Execução de cada jogo
void velhaExecution(string nicknameOne, string nicknameTwo, Register &registerSystem)
{

    try
    {
        JogoDaVelha velha;
        clearScreen();

        cout << "--- INICIANDO O JOGO: Jogo da Velha ---" << endl;
        cout << endl;
        cout << endl;
        cout << ". REGRAS DO JOGO:" << endl;
        cout << "O jogo eh disputado em um tabuleiro 3x3. Cada Jogador ira escolher uma posicao para marcar 'X' ou 'O', se o Jogador alinhar 3 simbolos 'O' ou 3 simbolos 'X' na diagonal, vertical ou horizontal, ele ganha." << endl;
        cout << endl;
        cout << ". MODO DE JOGADAS: " << endl;
        cout << " O jogador inserira primeiro o numero respectivo a coluna escolhida, apertara 'espaco' ou 'enter' e inserira o numero da coluna. Ao final das duas entradas, o jogador aperta 'enter' para enviar. As entradas devem ser numeros inteiros entre 0 e 2." << endl;
        cout << endl;
        cout << ". " << nicknameOne << " voce sera o 'X' e " << nicknameTwo << " voce sera o 'O'" << endl;
        cout << endl;
        cout << endl;
        char winner = velha.playGame();

        // Registrar o resultado do jogo no sistema de cadastro
        if (winner == 'X')
        {

            registerSystem.result(nicknameOne, nicknameTwo, "VELHA");
            cout << endl;
            cout << "Parabens! Jogador " << nicknameOne << " venceu!" << endl;
            cout << endl;
        }
        else if (winner == 'O')
        {
            registerSystem.result(nicknameTwo, nicknameOne, "VELHA");
            cout << "Parabens! Jogador " << nicknameTwo << " venceu!" << endl;
            cout << endl;
        }
        else if (winner == '.')
        {
            return;
        }
    }
    catch (const exception &e)
    {
        cerr << "Erro durante o jogo da velha: " << e.what() << endl;
    }
}

void lig4Execution(string nicknameOne, string nicknameTwo, Register &registerSystem)
{
    try
    {
        Lig4 lig4;
        clearScreen();
        cout << "--- INICIANDO O JOGO: Lig4 ---" << endl;
        cout << endl;
        cout << endl;
        cout << ". REGRAS DO JOGO:" << endl;
        cout << "O jogador tem que alinhar diagonalmente, horizontalmente ou verticalmente 4 pecas consecutivas no tabuleiro. Os jogadores alternam em turno para soltar as pecas em uma coluna, sendo que a peca ocupa o ponto mais baixo possivel na coluna." << endl;
        cout << endl;
        cout << ". MODO DE JOGADAS: " << endl;
        cout << " O jogador inserira primeiro o numero respectivo a coluna escolhida, apertara 'espaco' ou 'enter' e inserira o numero da coluna. Ao final das duas entradas, o jogador aperta 'enter' para enviar. As entradas devem ser numeros inteiros entre 0 e 6." << endl;
        cout << endl;
        cout << endl;
        cout << ". " << nicknameOne << " voce sera o 'X' e " << nicknameTwo << " voce sera o 'O'" << endl;
        cout << endl;
        char winner = lig4.playGame();

        // Registrar o resultado do jogo no sistema de cadastro
        if (winner == 'X')
        {
            registerSystem.result(nicknameOne, nicknameTwo, "LIG4");
            cout << endl;
            cout << "Parabens! Jogador " << nicknameOne << " venceu!" << endl;
            cout << endl;
        }
        else if (winner == 'O')
        {
            registerSystem.result(nicknameTwo, nicknameOne, "LIG4");
            cout << endl;
            cout << "Parabens! Jogador " << nicknameTwo << " venceu!" << endl;
            cout << endl;
        }
        else if (winner == '.')
        {
            return;
        }
    }
    catch (const exception &e)
    {
        cerr << "Erro durante o jogo lig4: " << e.what() << endl;
    }
}

void reversiExecution(string nicknameOne, string nicknameTwo, Register &registerSystem)
{
    try
    {
        Reversi reversi;
        clearScreen();

        cout << "--- INICIANDO O JOGO: Reversi ---" << endl;
        cout << endl;
        cout << endl;
        cout << ". REGRAS DO JOGO:" << endl;
        cout << "O jogo tem o objetivo de conquistar o maior numero de pecas no tabuleiro. Cada jogador sera o 'X' ou o 'O' e se alternam inserindo as pecas nos locais validos. Cada peca deve ser posicionada em local que pode capturar outras do adversario, ou seja, tem que posicionar na horizontal, vertical ou diagonal de alguma peca sua ja existente, tal que tenha pecas do adversario entre elas.";
        cout << " Caso nao tenha mais nenhuma jogada possivel para um jogador, passa a vez para o outro, se nenhum possuem entradas validas, o jogo acaba. " << endl;
        cout << endl;
        cout << ". MODO DE JOGADAS: " << endl;
        cout << " O jogador inserira o numero da coluna que deseja posicionar a peca e apertara 'enter' para enviar a jogada. A jogada tem que ser um numero inteiro entre 0 e 7." << endl;
        cout << endl;
        cout << endl;
        cout << ". " << nicknameOne << " voce sera o 'X' e " << nicknameTwo << " voce sera o 'O'" << endl;
        cout << endl;
        char winner = reversi.playGame();

        // Registrar o resultado do jogo no sistema de cadastro
        if (winner == 'X')
        {
            registerSystem.result(nicknameOne, nicknameTwo, "REVERSI");
            cout << endl;
            cout << "Parabens! Jogador " << nicknameOne << " venceu!" << endl;
            cout << endl;
        }
        else if (winner == 'O')
        {
            registerSystem.result(nicknameTwo, nicknameOne, "REVERSI");
            cout << endl;
            cout << "Parabens! Jogador " << nicknameTwo << " venceu!" << endl;
            cout << endl;
        }
        else if (winner == '.')
        {
            return;
        }
    }
    catch (const exception &e)
    {
        cerr << "Erro durante o jogo reversi: " << e.what() << endl;
    }
}

void playerRegistration(string &nicknameOne, string &nicknameTwo, Register &registerSystem)
{
    cout << "Digite o apelido do Jogador 1: ";
    cin >> nicknameOne;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o apelido do Jogador 2: ";
    cin >> nicknameTwo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Player *playerOne = registerSystem.searchPlayer(nicknameOne);
    Player *playerTwo = registerSystem.searchPlayer(nicknameTwo);
    // chacagem se as entradas são válidas:
    if (!validString(nicknameOne) || !validString(nicknameTwo))
    {
        throw invalid_argument("ERRO: O apelido dos jogadores devem ser válidos!");
    }

    if (!playerOne && !playerTwo)
    {
        throw invalid_argument("Jogadores nao encontrados. Cadastre-os primeiro.");
        
    }
    if (!playerOne)
    {
        throw invalid_argument("ERRO: Jogador " + nicknameOne + " nao foi encontrado. Cadastre-o primeiro.");
       
    }

    if (!playerTwo)
    {
        throw invalid_argument("ERRO: Jogador " + nicknameTwo + " nao foi encontrado. Cadastre-o primeiro.");
    }
}

// - Escolha do jogo e jogadores:
void setUpGame(Register &registerSystem)
{

    try
    {
        char game;
        string nicknameOne;
        string nicknameTwo;

        cout << "Digite o jogo que deseja jogar: 'R' - Reversi, 'L' - Lig4 ou 'V' - Jogo da velha: ";
        cin >> game;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        game = toupper(game); // padronização
        cout << endl;
        // chamando cada jogo;
        if (game == 'R')
        {
            playerRegistration(nicknameOne, nicknameTwo, registerSystem);
            reversiExecution(nicknameOne, nicknameTwo, registerSystem);
        }
        else if (game == 'L')
        {
            playerRegistration(nicknameOne, nicknameTwo, registerSystem);
            lig4Execution(nicknameOne, nicknameTwo, registerSystem);
        }
        else if (game == 'V')
        {
            playerRegistration(nicknameOne, nicknameTwo, registerSystem);
            velhaExecution(nicknameOne, nicknameTwo, registerSystem);
        }
        else
        {
            throw invalid_argument("ERRO: Jogo invalido! Tente novamente, digite R, L ou V");
        }
    }
    catch (const invalid_argument &e)
    {
        cerr << "Argumento invalido: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Erro inesperado, tente novamente : " << e.what() << endl;
    }
}
