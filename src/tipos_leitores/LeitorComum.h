#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "../Leitor.h"

/**
 * @class LeitorComum
 * @brief Representa um leitor comum.
 */
class LeitorComum : public Leitor {
public:
    LeitorComum(const std::string& nome, int idade);
    void exibirInformacoes() const override;
    int calcularMulta(int diasAtraso) const override;
    int getPrazoEmprestimo() const override;

private:
    static const int PRAZO_MAXIMO = 14; // Prazo em dias
};

#endif // LEITORCOMUM_H
