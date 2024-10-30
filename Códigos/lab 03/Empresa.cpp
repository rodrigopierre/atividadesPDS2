#include "Empresa.hpp"
#include "Onibus.hpp"

using namespace std;

Empresa::Empresa(){
    this->totalOnibus = 0;
    for (int i = 0; i < 20; i++){
        this->vetorOnibus[i] = nullptr;
    }
}


struct Onibus* Empresa::adicionar_onibus(string placa, int capacidadeMaxima){
    for (int i = 0; i < 20; i++){
        if (vetorPlacas[i] == placa){
            //placa já existe
            return nullptr;
        }
        if (vetorOnibus[i] != nullptr){
            continue;
        }

        struct Onibus* onibus = new Onibus(placa, capacidadeMaxima);
        this->totalOnibus++;
        vetorOnibus[i] = onibus;
        vetorPlacas[i] = placa;
        return onibus;
    }
    return nullptr;
}



struct Onibus* Empresa::busca_onibus(string placa){
    for (int i = 0; i < 20; i++){
        if (vetorPlacas[i] == placa){
            return vetorOnibus[i];
        }
    }
    return nullptr;
}


void Empresa::imprimir_estado(){
    for (int i = 0; i < 20; i++){
        if (vetorOnibus[i] == nullptr){ break; }
        vetorOnibus[i]->imprimir_estado();
    }
}

void Empresa::limpar_heap() {
    for (int i = 0; i < totalOnibus; i++) {
        delete vetorOnibus[i];
    }
}