#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include <iostream>

using namespace std;

struct Onibus {

    string placa;
    int capacidadeMaxima;
    int lotacaoAtual;

    Onibus(string placa, int capacidadeMaxima);

    bool subir_passageiros(int passageirosNovos);

    bool descer_passageiros(int passageirosSaindo);

    bool transfere_passageiros(struct Onibus* Onibus2, int passageirosTransferidos);

    void imprimir_estado();

};


#endif