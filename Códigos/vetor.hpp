#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>

template <typename T>
class Vetor {
private:
    T* elementos; 
    int tamanhoMaximo; 
    int numeroElementos; 

public:
    explicit Vetor(int n) : tamanhoMaximo(n), numeroElementos(0) {
        elementos = new T[n];
    }

    Vetor(const Vetor& outro) : tamanhoMaximo(outro.tamanhoMaximo), numeroElementos(outro.numeroElementos) {
        elementos = new T[tamanhoMaximo];
        for (int i = 0; i < numeroElementos; i++)
            elementos[i] = outro.elementos[i];
    }

    void Imprime() const {
        for (int i = 0; i < numeroElementos; i++) {
            std::cout << elementos[i];
            if (i < numeroElementos - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    ~Vetor() {
        delete[] elementos;
    }

    T GetElemento(int i) const {
        if (i >= 0 && i < numeroElementos)
            return elementos[i];
        return T();
    }

    void AdicionaElemento(const T& x) {
        if (numeroElementos < tamanhoMaximo)
            elementos[numeroElementos++] = x;
    }

    void SetElemento(int i, const T& x) {
        if (i >= 0 && i < numeroElementos)
            elementos[i] = x;
    }
};

#endif
