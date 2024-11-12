#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Livro.h"

/**
 * @class LivroFiccao
 * @brief Representa um livro de ficção.
 */
class LivroFiccao : public Livro {
public:
    LivroFiccao(const std::string& titulo, const std::string& autor, const std::string& genero);
    void exibirInformacoes() const override;
    std::string getTipo() const override;

private:
    std::string genero;
};

#endif // LIVROFICCAO_H
