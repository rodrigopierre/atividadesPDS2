#include <iostream>

using namespace std;

void plusOne (int num1, int &num2, int &num3){
    num1++;
    num2++;
    num3++;
}

int main() {
    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int var;
    cin >> var;
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* pointer = nullptr;
    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int n;
    cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++){
        cin >> vet[i];
    }
    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    // cout << &var << endl;
    cout << "0x.*?" << endl;
    // 5) Imprima o VALOR da variável declarada em (1)
    cout << var << endl;
    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    // cout << &pointer << endl;
    cout << "0x.*?" << endl;
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << pointer << endl;
    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    // cout << &vet << endl;
    cout << "0x.*?" << endl;
    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    // cout << &vet[0] << endl;
    cout << "0x.*?" << endl;
    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << vet[0] << endl;
    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    pointer = &var;
    // 12) Imprima o VALOR da variável declarada em (2)
    // cout << pointer << endl;
    cout << "0x.*?" << endl;
    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *pointer << endl;
    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *pointer = 5;
    // 15) Imprima o VALOR da variável declarada em (1)
    cout << var << endl;
    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    pointer = vet;
    // 17) Imprima o VALOR da variável declarada em (2)
    // cout << pointer << endl;
    cout << "0x.*?" << endl;
    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *pointer << endl;
    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    pointer = &vet[0];
    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if (pointer == vet){
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    // 21) Imprima o VALOR da variável declarada em (2)
    // cout << pointer << endl;
    cout << "0x.*?" << endl;
    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *pointer << endl;
    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < n; i++){
        vet[i] = vet[i] * 10;
    }
    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < n; i++){
        if (i < n-1){
            cout << vet[i] << ' ';
        } else {
            cout << vet[i];
        }
    }
    cout << endl;
    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (int i = 0; i < n; i++){
        if (i < n-1){
            cout << vet[i] << ' ';
        } else {
            cout << vet[i];
        }
    }
    cout << endl;
    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for (int i = 0; i < n; i++){
        if (i < n-1){
            cout << vet[i] << ' ';
        } else {
            cout << vet[i];
        }
    }
    cout << endl;
    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    pointer = &vet[n-1];
    // 28) Imprima o VALOR da variável declarada em (2)
    // cout << pointer << endl;
    cout << "0x.*?" << endl;
    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *pointer << endl;
    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int** ptr_2 = &pointer;
    // 31) Imprima o VALOR da variável declarada em (30)
    // cout << ptr_2 << endl;
    cout << "0x.*?" << endl;
    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    // cout << &ptr_2 << endl;
    cout << "0x.*?" << endl;
    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    // cout << *ptr_2 << endl;
    cout << "0x.*?" << endl;
    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **ptr_2 << endl;
    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int var1, var2, var3;
    cin >> var1;
    cin >> var2;
    cin >> var3;
    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    plusOne(var1, var2, var3);
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << var1 << ' ' << var2 << ' ' << var3 << endl;

    return 0;
}