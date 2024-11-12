#ifndef LEITOR_H
#define LEITOR_H

#include <string>

/**
 * @class Leitor
 * @brief Classe base abstrata para os leitores da biblioteca.
 *
 * A classe `Leitor` representa atributos comuns para leitores e define métodos virtuais
 * para exibir informações e calcular multas.
 */
class Leitor {
public:
    /**
     * @brief Construtor da classe Leitor.
     * @param nome Nome do leitor.
     * @param idade Idade do leitor.
     */
    Leitor(const std::string& nome, int idade);

    /**
     * @brief Exibe informações do leitor.
     * Método virtual puro a ser implementado nas subclasses.
     */
    virtual void exibirInformacoes() const = 0;

    /**
     * @brief Calcula a multa para o leitor.
     * @param diasAtraso Número de dias de atraso na devolução.
     * @return Valor da multa calculada.
     */
    virtual int calcularMulta(int diasAtraso) const = 0;

    /**
     * @brief Retorna o prazo máximo de empréstimo para o leitor.
     * @return Prazo máximo em dias.
     */
    virtual int getPrazoEmprestimo() const = 0;

protected:
    std::string nome; /**< Nome do leitor */
    int idade;        /**< Idade do leitor */
};

#endif // LEITOR_H
