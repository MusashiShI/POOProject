#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include "Livro.h"
#include "Leitor.h"
#include "Emprestimo.h"
#include "Reserva.h"
#include "Multa.h"

class Biblioteca {
public:
    void registrarLivro(Livro* livro);
    void registrarLeitor(Leitor* leitor);
    void realizarEmprestimo(Leitor* leitor, Livro* livro);
    void devolverLivro(Emprestimo& emprestimo);
    void prorrogarEmprestimo(Emprestimo& emprestimo, int diasExtras);
    void gerarRelatorioEmprestimosPorTipo();
    void gerarRelatorioMultasPendentes();
    void exibirHistoricoLeitor(const std::string& nomeLeitor);
    void notificarAtraso();
    void salvarDados();
    void carregarDados();

    // Novas funções de busca
    Livro* buscarLivro(const std::string& titulo);
    Leitor* buscarLeitor(const std::string& nome);
    Emprestimo* buscarEmprestimo(const std::string& tituloLivro);

private:
    std::vector<Livro*> livros;
    std::vector<Leitor*> leitores;
    std::vector<Emprestimo> emprestimos;
    std::vector<Reserva> reservas;
};

#endif // BIBLIOTECA_H
