#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Livro.h"
#include "Leitor.h"
#include <string>

/**
 * @class Emprestimo
 * @brief Representa um empréstimo de um livro feito por um leitor.
 */
class Emprestimo {
public:
    Emprestimo(Leitor* leitor, Livro* livro, const std::string& dataEmprestimo);
    
    void registrarDevolucao(const std::string& dataDevolucao);
    bool verificarAtraso() const;
    int calcularDiasAtraso() const;
    double calcularMulta() const;

    Leitor* getLeitor() const { return leitor; }
    Livro* getLivro() const { return livro; }
    std::string getDataEmprestimo() const { return dataEmprestimo; }

private:
    Leitor* leitor;
    Livro* livro;
    std::string dataEmprestimo;
    std::string dataDevolucao;
};

#endif // EMPRESTIMO_H
