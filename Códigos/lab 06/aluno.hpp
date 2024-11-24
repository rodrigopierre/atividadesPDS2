#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>

class Aluno {
private:
    std::string nome;
    int matricula;
    std::vector<int> notas;

public:
    Aluno(const std::string& nome, int matricula);

    void adicionarNota(int nota);
    double calcularMedia() const;
    int notaMaxima() const;
    int notaMinima() const;
    const std::string& getNome() const;
    int getMatricula() const;
    const std::vector<int>& getNotas() const;
    bool operator<(const Aluno& outro) const;
};

#endif
