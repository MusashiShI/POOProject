#ifndef LIVRO_H
#define LIVRO_H

#include <string>

/**
 * @class Livro
 * @brief Classe base abstrata para tipos de livros.
 */
class Livro {
public:
    Livro(const std::string& titulo, const std::string& autor);
    virtual ~Livro() = default;
    
    virtual void exibirInformacoes() const = 0;
    virtual std::string getTipo() const = 0;
    
    std::string getTitulo() const { return titulo; }
    std::string getAutor() const { return autor; }

protected:
    std::string titulo;
    std::string autor;
};

#endif // LIVRO_H
