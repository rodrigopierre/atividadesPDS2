#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <iostream>
#include "Onibus.hpp"
#include <string>

using namespace std;

struct Empresa {

    int totalOnibus;
    struct Onibus* vetorOnibus[20];
    string vetorPlacas[20];

    Empresa();

    void limpar_heap();

    struct Onibus* adicionar_onibus(string placa, int capacidadeMaxima);

    struct Onibus* busca_onibus(string placa);

    void imprimir_estado();
};




#endif