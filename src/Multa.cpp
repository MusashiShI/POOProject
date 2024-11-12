#include "Multa.h"

Multa::Multa(int diasAtraso, double taxaPorDia, double desconto)
    : diasAtraso(diasAtraso), taxaPorDia(taxaPorDia), desconto(desconto) {}

double Multa::calcularMulta() const {
    return diasAtraso * taxaPorDia * (1 - desconto);
}
