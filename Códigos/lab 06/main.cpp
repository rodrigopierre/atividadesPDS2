#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "aluno.hpp"

void imprimirRelatorio(const std::vector<Aluno>& alunos) {
    for (const auto& aluno : alunos) {
        std::cout << aluno.getMatricula() << " " << aluno.getNome();
        for (int nota : aluno.getNotas())
            std::cout << " " << nota;
        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2)
                  << aluno.calcularMedia() << " "
                  << aluno.notaMaxima() << " "
                  << aluno.notaMinima() << std::endl;
    }
}

int main() {
    std::vector<Aluno> alunos;

    while (true) {
        std::string nome;
        std::getline(std::cin, nome);
        if (nome == "END") break;
        int matricula;
        std::cin >> matricula;
        Aluno aluno(nome, matricula);
        int nota;
        while (std::cin >> nota && nota != -1) 
            aluno.adicionarNota(nota);
        std::cin.ignore();
        alunos.push_back(aluno);
    }

    std::sort(alunos.begin(), alunos.end());
    imprimirRelatorio(alunos);

    return 0;
}
