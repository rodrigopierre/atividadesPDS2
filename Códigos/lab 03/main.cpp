#include <iostream>
#include <string>
#include <sstream>
#include "Empresa.hpp"
#include "Onibus.hpp"

using namespace std;

int main(){
    
    struct Empresa minhaEmpresa;

    while (true){
       string line, placa, placa2;
       char caracter;
       int numPessoas, lotacao;
       getline(cin, line);

        if (line [0] == 'C'){
            istringstream ss(line);
            ss >> caracter >> placa >> lotacao;

            if (minhaEmpresa.adicionar_onibus(placa, lotacao) == nullptr){
                cout << "ERRO : onibus repetido" << endl;
            } else {
                cout << "novo onibus cadastrado" << endl;
            }
        }


        if (line [0] == 'S'){
            istringstream ss(line);
            ss >> caracter >> placa >> numPessoas;

            struct Onibus* onibus = minhaEmpresa.busca_onibus(placa);
            if (onibus == nullptr){
                cout << "ERRO : onibus inexistente" << endl;
                continue;
            }

            if (!onibus->subir_passageiros(numPessoas)){
                cout << "ERRO : onibus lotado" << endl;
            } else {
                cout << "passageiros subiram com sucesso" << endl;
            }
        }


        if (line [0] == 'D'){
            istringstream ss(line);
            ss >> caracter >> placa >> numPessoas;

            struct Onibus* onibus = minhaEmpresa.busca_onibus(placa);
            if (onibus == nullptr){
                cout << "ERRO : onibus inexistente" << endl;
                continue;
            }
            if (!onibus->descer_passageiros(numPessoas)){
                cout << "ERRO : faltam passageiros" << endl;
            } else {
                cout << "passageiros desceram com sucesso" << endl;
            }
        }


        if (line [0] == 'T'){
            if (line.length() < 2) { break; }
            istringstream ss(line);
            ss >> caracter >> placa >> placa2 >> numPessoas;

            struct Onibus* onibus1 = minhaEmpresa.busca_onibus(placa);
            if (onibus1 == nullptr){
                cout << "ERRO : onibus inexistente" << endl;
                continue;
            }
            struct Onibus* onibus2 = minhaEmpresa.busca_onibus(placa2);
            if (onibus2 == nullptr){
                cout << "ERRO : onibus inexistente" << endl;
                continue;
            }
            
            if (!onibus1->transfere_passageiros(onibus2, numPessoas)){
                cout << "ERRO : transferencia cancelada" << endl;
            } else {
                cout << "transferencia de passageiros efetuada" << endl;
            }
        }


        if (line [0] == 'I'){
            minhaEmpresa.imprimir_estado();
        }
    }
    minhaEmpresa.limpar_heap();
}