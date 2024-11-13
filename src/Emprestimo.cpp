#include "Emprestimo.h"
#include <iostream>
#include <fstream>

Livro* Biblioteca::buscarLivro(const std::string& titulo) {
    for (auto& livro : livros) {
        if (livro->getTitulo() == titulo) {
            return livro;
        }
    }
    return nullptr; // Retorna nullptr se o livro não for encontrado
}

Leitor* Biblioteca::buscarLeitor(const std::string& nome) {
    for (auto& leitor : leitores) {
        if (leitor->getNome() == nome) {
            return leitor;
        }
    }
    return nullptr; // Retorna nullptr se o leitor não for encontrado
}

Emprestimo* Biblioteca::buscarEmprestimo(const std::string& tituloLivro) {
    for (auto& emprestimo : emprestimos) {
        if (emprestimo.getLivro()->getTitulo() == tituloLivro) {
            return &emprestimo;
        }
    }
    return nullptr; // Retorna nullptr se o empréstimo não for encontrado
}

Emprestimo::Emprestimo(Leitor* leitor, Livro* livro, const std::string& dataEmprestimo)
    : leitor(leitor), livro(livro), dataEmprestimo(dataEmprestimo), dataDevolucao("") {}

void Emprestimo::registrarDevolucao(const std::string& dataDevolucao) {
    this->dataDevolucao = dataDevolucao;
}

bool Emprestimo::verificarAtraso() const {
    return calcularDiasAtraso() > 0;
}

int Emprestimo::calcularDiasAtraso() const {
    int diasAtraso = 5; // Exemplo para cálculo fictício
    return diasAtraso;
}

double Emprestimo::calcularMulta() const {
    int diasAtraso = calcularDiasAtraso();
    return diasAtraso * leitor->calcularMulta(diasAtraso);
}

