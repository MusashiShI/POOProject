#ifndef MULTA_H
#define MULTA_H

/**
 * @class Multa
 * @brief Calcula o valor da multa de acordo com os dias de atraso e o tipo de leitor.
 */
class Multa {
public:
    Multa(int diasAtraso, double taxaPorDia, double desconto = 0);
    double calcularMulta() const;

private:
    int diasAtraso;
    double taxaPorDia;
    double desconto; /**< Desconto aplicado para determinados tipos de leitor */
};

#endif // MULTA_H
