#include "aluno.hpp"
#include <algorithm>
#include <numeric>

Aluno::Aluno(const std::string& nome, int matricula)
    : nome(nome), matricula(matricula) {}

void Aluno::adicionarNota(int nota) {
    notas.push_back(nota);
}

double Aluno::calcularMedia() const {
    if (notas.empty()) return 0.0;
    return std::accumulate(notas.begin(), notas.end(), 0.0) / notas.size();
}

int Aluno::notaMaxima() const {
    if (notas.empty()) return 0;
    return *std::max_element(notas.begin(), notas.end());
}

int Aluno::notaMinima() const {
    if (notas.empty()) return 0;
    return *std::min_element(notas.begin(), notas.end());
}

const std::string& Aluno::getNome() const {
    return nome;
}

int Aluno::getMatricula() const {
    return matricula;
}

const std::vector<int>& Aluno::getNotas() const {
    return notas;
}

bool Aluno::operator<(const Aluno& outro) const {
    return nome < outro.nome;
}
