#ifndef LEITOR_H
#define LEITOR_H

#include <string>

/**
 * @class Leitor
 * @brief Classe base abstrata para diferentes tipos de leitores.
 */
class Leitor {
public:
    Leitor(const std::string& nome, int idade);
    virtual ~Leitor() = default;

    virtual void exibirInformacoes() const = 0;
    virtual int calcularMulta(int diasAtraso) const = 0;
    virtual int getPrazoEmprestimo() const = 0;

    std::string getNome() const { return nome; }
    int getIdade() const { return idade; }

protected:
    std::string nome;
    int idade;
};

#endif // LEITOR_H
