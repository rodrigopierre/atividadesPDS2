#include "Onibus.hpp"

using namespace std;

Onibus::Onibus(string placa, int capacidadeMaxima){
    this->placa = placa;
    this->capacidadeMaxima = capacidadeMaxima;
    this->lotacaoAtual = 0;
}

bool Onibus::subir_passageiros(int passageirosNovos){
    int diferenca = capacidadeMaxima - lotacaoAtual;
    if (diferenca < passageirosNovos){
        return false;
    } else {
        lotacaoAtual += passageirosNovos;
        return true;
    }
}

bool Onibus::descer_passageiros(int passageirosSaindo){
    if (lotacaoAtual < passageirosSaindo){
        return false;
    } else {
        this->lotacaoAtual -= passageirosSaindo;
        return true;
    }
}

bool Onibus::transfere_passageiros(struct Onibus* Onibus2, int passageirosTransferidos){
    if (!this->descer_passageiros(passageirosTransferidos)){
        return false;
    }
    if (!Onibus2->subir_passageiros(passageirosTransferidos)){
        return false;
    }
    return true;
}

void Onibus::imprimir_estado(){
    cout << this->placa << " (" << this->lotacaoAtual << "/" << this->capacidadeMaxima << ")" << endl;
}