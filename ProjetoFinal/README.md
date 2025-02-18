Nome do Projeto: Projeto Final- Jogos de Tabuleiro.

Grupo: Amanda Silveira, João Araldi, Fabrício Cezár, Rodrigo Pierre, Juan Junqueira.

1. Introdução.
2. Objetivo Educacional.
3. Estrutura e Funcionamento.
4. Dificuldades Encontradas.
5. Organização.
6. Como Executar o Programa.
7. Como rodar os testes.

---------------------------------------------------------------------------------------------------------------------------------------------------

1. Introdução: Projeto apresentado à disciplina Programação e Desenvolvimento de Software 2, desenvolvido na linguagem de programação "C++"
Consiste em três jogos de tabuleiro (Reversi, Lig4, e Jogo da Velha),com foco em reutilização, modularidade e princípios de POO.

2. Objetivo Educacional: Este projeto visa consolidar os conhecimentos apresentados em sala de aula, com ênfase em:

- Conceitos de programação orientada a objetos (POO), incluindo herança, polimorfismo e encapsulamento.
- Boas práticas de programação, como modularidade e reutilização de código.
- Uso de ferramentas de controle de versão, como Git, para colaboração eficiente.
- Aplicação de testes unitários e documentação automatizada com Doxygen.

3. Estrutura Geral: O trabalho foi elaborado com o objetivo de implementar três jogos clássicos: Reversi, Lig4 e Jogo da Velha, acompanhados por um sistema de cadastro que registra informações sobre os jogadores, como nome, apelido, número de vitórias e derrotas. Para estruturar o projeto, foram criadas seis classes principais.
Alguns princípios de POO foram aplicados e merecem destaque:

- Herança: Criamos uma classe base chamada BaseGame, que contém funcionalidades comuns aos três jogos, como o controle do tabuleiro. As classes dos jogos (Reversi, Lig4, Jogo da Velha) herdam dessa classe, o que facilita a manutenção do código e a reutilização da lógica de tabuleiro.
- Composição: No sistema de cadastro, a classe Register usa composição ao armazenar objetos da classe Player. Isso permite gerenciar as informações de cada jogador de maneira eficiente.
- Encapsulamento: As informações dos jogadores, como nome e vitórias, são guardadas dentro da classe Player, e o acesso a esses dados é feito por métodos específicos.
- Polimorfismo: A classe BaseGame define uma estrutura comum para os jogos, mas cada jogo pode sobrescrever métodos, como o playGame(), para adicionar sua própria lógica, permitindo uma adaptação de cada jogo conforme a necessidade, mesmo compartilhando a mesma interface.

Quanto às dimensões dos tabuleiros, optamos pelas seguintes, de acordo com as regras tradicionais dos jogos:

- Jogo da Velha: 3x3.
- Reversi: 8x8.
- Lig4: 6x7.

Além disso, a documentação foi desenvolvida utilizando o Doxygen, detalhando exclusivamente os arquivos de cabeçalho (.hpp) e o arquivo principal (main.cpp), seguindo uma escolha do grupo. Para ter acesso a documentação do doxygen, basta abrir o arquivo "index.html" que esta dentro da pasta html, dentro da pasta doxygen. Ou, executar o comando na raiz do projeto:

-       "xdg-open doxygen/html/index.html" (Linux)
-       "open doxygen/html/index.html" (Mac)
-       "start doxygen/html/index.html" (Windows)

Funcionamento: O funcionamento do fluxo do sistema é dividido em 3 partes:

- Cadastro de Jogadores: O sistema permite o cadastro de jogadores com nome e apelido, que são armazenados em um banco de dados simples(.txt). A classe Register oferece funções que auxiliam a mostragem desses dados e trabalho com os mesmos. O uso da composição permite que o sistema mantenha informações detalhadas sobre cada jogador (como vitórias e derrotas), acessando e manipulando os dados de forma eficiente.

- Jogos: Após o cadastro, o usuário pode escolher um jogo entre Reversi, Lig4 ou Jogo da Velha. O jogo é iniciado com a escolha dos jogadores, e a lógica de cada jogo é tratada pelas respectivas classes (Reversi, Lig4, JogoDaVelha), que herdam a funcionalidade comum da classe BaseGame.
As regras de cada jogo, como a validação dos movimentos, o controle do turno dos jogadores, e a verificação de vitória ou empate, são implementadas nas classes específicas. Durante a execução dos jogos, os movimentos são validados, e o tabuleiro é atualizado e exibido após cada jogada. Ao final de cada partida, o vencedor ou o empate é registrado, e as estatísticas dos jogadores são atualizadas automaticamente.

- Persistência de Dados: O sistema permite salvar e carregar os dados do jogo, garantindo que as informações dos jogadores, como suas estatísticas de vitórias e derrotas, sejam mantidas entre as execuções do programa. A persistência é realizada ao salvar os dados em um arquivo antes de finalizar o sistema e ao carregá-los no início da execução.

-  O tratamento de exceções foi realizado nos arquivos ExecutionSystem.cpp e na Main.cpp, por se tratarem de arquivos que controlam a execução do programa.


4. Dificuldades encontradas: O primeiro grande problema foi entender as regras do Reversi 😉.
Durante o desenvolvimento do projeto, algumas dificuldades surgiram, especialmente por se tratar de uma primeira experiência em grupo com Git.
Manter um padrão consistente nos códigos dos jogos foi um desafio, pois precisávamos garantir que a estrutura e a organização do código seguissem as mesmas convenções, o que exigiu bastante comunicação entre os membros.
Outro ponto difícil foi a implementação do sistema de persistência de dados, que envolvia salvar e carregar as informações dos jogadores e das partidas de forma eficiente. 
A documentação com o Doxygen, embora não tenha sido uma tarefa difícil, foi trabalhosa, ainda mais por ser um primeiro contato. 
Por fim, a integração de todas as partes do sistema, como o cadastro de jogadores, a lógica dos jogos e a persistência de dados, foi uma tarefa desafiadora, já que envolvia fazer com que diferentes módulos trabalhassem juntos de maneira eficiente e sem erros. 
Mas, mesmo assim, não há desafio que não possa ser superado!

5. Organização: A disposição das pastas dos arquivos está distribuida dessa forma, conforme pedido:

- ProjetoFinal/
- ├── include/         // Arquivos de cabeçalho (.hpp)
- ├── src/             // Implementações e dados (.cpp)
- │   ├── DataPlayer/  // Dados salvos dos jogadores.
- ├── tests/           // Testes unitários.
- ├── doxygen/         // Documentação Doxygen do trabalho PARA OS ARQUIVOS HPP e MAIN.cpp.
- ├── obj/             // Guarda arquivos objeto (.o ou .obj) criados durante a compilação.
- ├── modelCRC/        // CRC do trabalho.
- ├── README.md        // Este arquivo.
- ├── gitignore        // Lista arquivos e pastas que o Git deve ignorar.
- └── Makefile         // Automação da compilação.

6. Como executar o programa: Para rodar o programa, siga os seguintes passos:
- Compilar o código:
Execute o comando:
-            "make"
no terminal para compilar todos os arquivos do projeto.
- Rodar o Programa:
Após a compilação, execute o comando:
-            "bin/main"
para iniciar os jogos!


7. Os arquivos de teste estão na pasta 'tests' e da para executá-los por meio do makefile:

Para executar o teste da classe de Cadastro, no terminal, digite na raiz do projeto:
-      "make testCadastro"
e depois: 
-      "./tests/testeCadastro" 

Para limpar os arquivos criados, digite na raiz:
 -      "make clean"


