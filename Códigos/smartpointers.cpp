#include <iostream>
#include <memory>

using namespace std;

class Teste {
public:
    int valor;
    Teste(int v) : valor(v) {
        cout << "Construtor " << valor << endl;
    }

    Teste() : valor(0) {
        cout << "Construtor " << valor << endl;
    }

    ~Teste() {
        cout << "Destrutor " << valor << endl;
    }
};

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            Teste* ptr = new Teste(i);
            unique_ptr<Teste> uniquePtr(new Teste(i));
        }
    } else {
        shared_ptr<Teste> sharedPtr(new Teste(0));
        for (int i = 1; i <= n; i++) {
            shared_ptr<Teste> sharedPtr2 = sharedPtr;
            sharedPtr2->valor = i;
        }
        cout << sharedPtr.use_count() << endl;
    }

    return 0;
}
