#include <iostream>
#include <list>
#include <memory>
using namespace std;

class Objeto {
private:
    static int contadorObjetos;
    static int proximoId;
    int id;

public:
    Objeto() : id(proximoId++) { contadorObjetos++; }
    Objeto(int idFornecido) {
        if (idFornecido < 0)
            id = idFornecido;
        else 
            id = proximoId++;
        contadorObjetos++;
    }
    ~Objeto() { contadorObjetos--; }
    int getId() const { return id; }
    static int getContadorObjetos() { return contadorObjetos; }
    const void* getEndereco() const { return this;    }
};

int Objeto::contadorObjetos = 0;
int Objeto::proximoId = 1;

int main() {
    list<shared_ptr<Objeto>> objetos;
    string comando;

    while (cin >> comando) {
        if (comando == "A") {
            auto obj = make_shared<Objeto>();
            objetos.push_back(obj);
            cout << obj->getId() << " " << obj.get() << endl;
        } else if (comando == "C") {
            int idFornecido;
            cin >> idFornecido;
            if (idFornecido < 0) {
                auto obj = make_shared<Objeto>(idFornecido);
                objetos.push_front(obj);
                cout << obj->getId() << " " << obj.get() << endl;
            } else 
                cout << "ERRO" << endl;  
        } else if (comando == "R") {
            if (!objetos.empty()) {
                auto obj = objetos.front();
                cout << obj->getId() << " " << obj.get() << endl;
                objetos.pop_front();
            } else 
                cout << "ERRO" << endl;
        } else if (comando == "N") 
            cout << Objeto::getContadorObjetos() << endl;
        else if (comando == "P") {
            int i;
            cin >> i;
            if (i < 1 || i > (int)objetos.size()) {
                cout << "ERRO" << endl;
            } else {
                auto it = objetos.begin();
                advance(it, i - 1);
                auto obj = *it;
                cout << obj->getId() << " " << obj.get() << endl;
            }
        } else if (comando == "L") {
            for (const auto& obj : objetos)
                cout << obj->getId() << " " << obj.get() << endl;
        } else if (comando == "E") 
            break;
    }
    return 0;
}
