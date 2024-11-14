#include "Biblioteca.h"
#include <iostream>
#include <fstream>

void Biblioteca::registrarLivro(Livro* livro) {
    livros.push_back(livro);
}

void Biblioteca::registrarLeitor(Leitor* leitor) {
    leitores.push_back(leitor);
}

Livro* Biblioteca::buscarLivro(const std::string& titulo) {
    for (auto& livro : livros) {
        if (livro->getTitulo() == titulo) {
            return livro;
        }
    }
    return nullptr;
}

Leitor* Biblioteca::buscarLeitor(const std::string& nome) {
    for (auto& leitor : leitores) {
        if (leitor->getNome() == nome) {
            return leitor;
        }
    }
    return nullptr;
}

Emprestimo* Biblioteca::buscarEmprestimo(const std::string& tituloLivro) {
    for (auto& emprestimo : emprestimos) {
        if (emprestimo.getLivro()->getTitulo() == tituloLivro) {
            return &emprestimo;
        }
    }
    return nullptr;
}

// Outras implementações da Biblioteca como relatórios, empréstimos e devoluções
