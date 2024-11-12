#include "LeitorComum.h"
#include <iostream>

LeitorComum::LeitorComum(const std::string& nome, int idade) : Leitor(nome, idade) {}

void LeitorComum::exibirInformacoes() const {
    std::cout << "Leitor Comum: " << nome << ", Idade: " << idade << std::endl;
}

int LeitorComum::calcularMulta(int diasAtraso) const {
    return diasAtraso * 2;
}

int LeitorComum::getPrazoEmprestimo() const {
    return PRAZO_MAXIMO;
}
