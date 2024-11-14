#include "Emprestimo.h"
#include <iostream>

Emprestimo::Emprestimo(Leitor* leitor, Livro* livro, const std::string& dataEmprestimo)
    : leitor(leitor), livro(livro), dataEmprestimo(dataEmprestimo), dataDevolucao("") {}

void Emprestimo::registrarDevolucao(const std::string& dataDevolucao) {
    this->dataDevolucao = dataDevolucao;
}

bool Emprestimo::verificarAtraso() const {
    return calcularDiasAtraso() > 0;
}

int Emprestimo::calcularDiasAtraso() const {
    int diasAtraso = 5; // Exemplo de cálculo fictício para atraso
    return diasAtraso;
}

double Emprestimo::calcularMulta() const {
    int diasAtraso = calcularDiasAtraso();
    return diasAtraso * leitor->calcularMulta(diasAtraso);
}
