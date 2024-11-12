#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "../Leitor.h"

/**
 * @class LeitorComum
 * @brief Representa um leitor comum.
 *
 * A classe `LeitorComum` é uma subclasse de `Leitor`, com prazos e cálculo de multas específicos.
 */
class LeitorComum : public Leitor {
public:
    /**
     * @brief Construtor da classe LeitorComum.
     * @param nome Nome do leitor.
     * @param idade Idade do leitor.
     */
    LeitorComum(const std::string& nome, int idade);

    /**
     * @brief Exibe informações do leitor comum.
     */
    void exibirInformacoes() const override;

    /**
     * @brief Calcula a multa para o leitor comum.
     * @param diasAtraso Número de dias de atraso na devolução.
     * @return Valor da multa calculada.
     */
    int calcularMulta(int diasAtraso) const override;

    /**
     * @brief Retorna o prazo máximo de empréstimo para o leitor comum.
     * @return Prazo máximo em dias.
     */
    int getPrazoEmprestimo() const override;

private:
    static const int PRAZO_MAXIMO = 14; /**< Prazo de empréstimo para leitor comum */
};

#endif // LEITORCOMUM_H
