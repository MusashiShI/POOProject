#ifndef RESERVA_H
#define RESERVA_H

#include "Leitor.h"
#include "Livro.h"
#include <deque>

/**
 * @class Reserva
 * @brief Classe que gerencia a fila de reservas de um livro.
 *
 * Os leitores são adicionados a uma fila de espera para o livro.
 */
class Reserva {
public:
    Reserva(Livro* livro);
    void adicionarReserva(Leitor* leitor);
    Leitor* proximaReserva();
    void exibirFila() const;

private:
    Livro* livro;
    std::deque<Leitor*> filaEspera; /**< Fila de leitores aguardando o livro */
};

#endif // RESERVA_H
