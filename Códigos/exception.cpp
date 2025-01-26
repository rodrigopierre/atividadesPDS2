#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class NegativeResultException : public exception {
private:
    int valor;
public:
    NegativeResultException(int valor) : valor(valor) {}
    int getValor() const {
        return valor;
    }
    const char* what() const noexcept override {
        return "Erro: Resultado Negativo.";
    }
};

int main() {
    vector<int> vetor = {-20, -10, 0, 10, 20};
    try {
        int indice;
        cin >> indice;

        if (indice < 0 || indice >= vetor.size())
            throw out_of_range("Erro: Parametro invalido");
        int valor = vetor.at(indice);

        if (valor < 0) {
            throw NegativeResultException(valor);
        } else if (valor == 0) {
            throw logic_error("Erro: O resultado nao deve ser zero.");
        } else {
            cout << valor << endl;
        }
    }
    catch (const NegativeResultException& e) {
        cout << e.what() << endl;
        cout << e.getValor() << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
