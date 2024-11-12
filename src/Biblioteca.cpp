#include "Biblioteca.h"
#include <iostream>
#include <fstream>

void Biblioteca::registrarLivro(Livro* livro) {
    livros.push_back(livro);
}

void Biblioteca::registrarLeitor(Leitor* leitor) {
    leitores.push_back(leitor);
}

void Biblioteca::realizarEmprestimo(Leitor* leitor, Livro* livro) {
    int prazoEmprestimo = leitor->getPrazoEmprestimo();
    std::cout << "Prazo de empréstimo para " << leitor->getNome() << ": " << prazoEmprestimo << " dias.\n";
    Emprestimo novoEmprestimo(leitor, livro, "2024-10-25"); // Data fictícia
    emprestimos.push_back(novoEmprestimo);
}

void Biblioteca::devolverLivro(Emprestimo& emprestimo) {
    emprestimo.registrarDevolucao("2024-11-01"); // Data fictícia
    if (emprestimo.verificarAtraso()) {
        double multa = emprestimo.calcularMulta();
        std::cout << "Atraso detectado! Multa aplicada: " << multa << " EUR\n";
    }
}

void Biblioteca::prorrogarEmprestimo(Emprestimo& emprestimo, int diasExtras) {
    Leitor* leitor = emprestimo.getLeitor();
    if (typeid(*leitor) == typeid(LeitorEstudante) || typeid(*leitor) == typeid(LeitorProfessor)) {
        std::cout << "Prorrogação de " << diasExtras << " dias concedida.\n";
    } else {
        std::cout << "Prorrogação não permitida para este tipo de leitor.\n";
    }
}

void Biblioteca::gerarRelatorioEmprestimosPorTipo() {
    std::cout << "Relatório de Empréstimos por Tipo de Livro:\n";
    std::map<std::string, int> emprestimosPorTipo;
    for (const auto& emprestimo : emprestimos) {
        std::string tipo = emprestimo.getLivro()->getTipo();
        emprestimosPorTipo[tipo]++;
    }
    for (const auto& par : emprestimosPorTipo) {
        std::cout << par.first << ": " << par.second << " empréstimos\n";
    }
}

void Biblioteca::gerarRelatorioMultasPendentes() {
    std::cout << "Relatório de Multas Pendentes:\n";
    for (const auto& emprestimo : emprestimos) {
        if (emprestimo.verificarAtraso()) {
            double multa = emprestimo.calcularMulta();
            std::cout << emprestimo.getLeitor()->getNome() << " - Multa: " << multa << " EUR\n";
        }
    }
}

void Biblioteca::exibirHistoricoLeitor(const std::string& nomeLeitor) {
    std::cout << "Histórico de Empréstimos para " << nomeLeitor << ":\n";
    for (const auto& emprestimo : emprestimos) {
        if (emprestimo.getLeitor()->getNome() == nomeLeitor) {
            emprestimo.exibirInformacoes();
        }
    }
}

void Biblioteca::notificarAtraso() {
    for (auto& emprestimo : emprestimos) {
        if (emprestimo.verificarAtraso()) {
            std::cout << "Notificação: " << emprestimo.getLeitor()->getNome() << ", devolução atrasada.\n";
        }
    }
}

void Biblioteca::salvarDados() {
    std::ofstream arquivoLivros("data/livros.txt");
    for (const auto& livro : livros) {
        arquivoLivros << livro->getTipo() << "|" << livro->getTitulo() << "|" << livro->getAutor() << std::endl;
    }
    arquivoLivros.close();

    std::ofstream arquivoLeitores("data/leitores.txt");
    for (const auto& leitor : leitores) {
        arquivoLeitores << leitor->getNome() << "|" << leitor->getIdade() << std::endl;
    }
    arquivoLeitores.close();
}

void Biblioteca::carregarDados() {
    std::ifstream arquivoLivros("data/livros.txt");
    std::string linha;
    while (std::getline(arquivoLivros, linha)) {
        // Processar cada linha para recriar objetos de livros
    }
    arquivoLivros.close();

    std::ifstream arquivoLeitores("data/leitores.txt");
    while (std::getline(arquivoLeitores, linha)) {
        // Processar cada linha para recriar objetos de leitores
    }
    arquivoLeitores.close();
}
