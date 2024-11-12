#include "Reserva.h"
#include <iostream>

Reserva::Reserva(Livro* livro) : livro(livro) {}

void Reserva::adicionarReserva(Leitor* leitor) {
    filaEspera.push_back(leitor);
}

Leitor* Reserva::proximaReserva() {
    if (!filaEspera.empty()) {
        Leitor* proximo = filaEspera.front();
        filaEspera.pop_front();
        return proximo;
    }
    return nullptr;
}

void Reserva::exibirFila() const {
    std::cout << "Fila de espera para o livro: " << livro->getTitulo() << std::endl;
    for (const auto& leitor : filaEspera) {
        std::cout << "- " << leitor->getNome() << std::endl;
    }
}
