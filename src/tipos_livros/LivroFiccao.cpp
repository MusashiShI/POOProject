#include "LivroFiccao.h"
#include <iostream>

LivroFiccao::LivroFiccao(const std::string& titulo, const std::string& autor, const std::string& genero)
    : Livro(titulo, autor), genero(genero) {}

void LivroFiccao::exibirInformacoes() const {
    std::cout << "Ficção: " << titulo << ", Autor: " << autor << ", Gênero: " << genero << std::endl;
}

std::string LivroFiccao::getTipo() const {
    return "Ficcao";
}
