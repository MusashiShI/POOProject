#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Biblioteca.h"
#include "tipos_livros/LivroFiccao.h"
#include "tipos_leitores/LeitorComum.h"

void limparTela() {
    // Limpa a tela no terminal
    std::cout << "\033[2J\033[1;1H";
}

void efeitoDigitacao(const std::string& texto, int delay = 50) {
    // Animação de digitação
    for (const char& c : texto) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << std::endl;
}

void carregando(const std::string& acao) {
    // Simula carregamento
    std::cout << acao;
    for (int i = 0; i < 3; ++i) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << std::endl;
}

void exibirMenu() {
    limparTela();
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║            🌟  Sistema de Biblioteca 🌟           ║\n";
    std::cout << "╠════════════════════════════════════════════════════╣\n";
    std::cout << "║ 1. 📚 Registrar Livro                             ║\n";
    std::cout << "║ 2. 🧑 Registrar Leitor                            ║\n";
    std::cout << "║ 3. 📖 Realizar Empréstimo                         ║\n";
    std::cout << "║ 4. 🔄 Devolver Livro                              ║\n";
    std::cout << "║ 5. ⏳ Prorrogar Empréstimo                         ║\n";
    std::cout << "║ 6. 📊 Gerar Relatório de Empréstimos por Tipo     ║\n";
    std::cout << "║ 7. 💸 Gerar Relatório de Multas Pendentes         ║\n";
    std::cout << "║ 8. 🔍 Exibir Histórico de Empréstimos             ║\n";
    std::cout << "║ 9. 🚨 Notificar Atrasos                           ║\n";
    std::cout << "║10. 💾 Salvar Dados                                ║\n";
    std::cout << "║11. 📂 Carregar Dados                              ║\n";
    std::cout << "║ 0. ❌ Sair                                        ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
    std::cout << "Escolha uma opção: ";
}

void iniciarSistema() {
    limparTela();
    efeitoDigitacao("Iniciando o Sistema de Biblioteca", 70);
    carregando("Carregando dados");
    limparTela();
}

int main() {
    Biblioteca biblioteca;
    int opcao;

    iniciarSistema();

    do {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: {
                limparTela();
                std::string titulo, autor, genero;
                std::cout << "Digite o título do livro: ";
                std::getline(std::cin, titulo);
                std::cout << "Digite o autor: ";
                std::getline(std::cin, autor);
                std::cout << "Digite o gênero: ";
                std::getline(std::cin, genero);
                Livro* livro = new LivroFiccao(titulo, autor, genero);
                biblioteca.registrarLivro(livro);
                carregando("Registrando livro");
                break;
            }
            case 2: {
                limparTela();
                std::string nome;
                int idade;
                std::cout << "Digite o nome do leitor: ";
                std::getline(std::cin, nome);
                std::cout << "Digite a idade: ";
                std::cin >> idade;
                Leitor* leitor = new LeitorComum(nome, idade);
                biblioteca.registrarLeitor(leitor);
                carregando("Registrando leitor");
                break;
            }
            case 3: {
                limparTela();
                std::string nomeLeitor, tituloLivro;
                std::cout << "Digite o nome do leitor: ";
                std::getline(std::cin, nomeLeitor);
                std::cout << "Digite o título do livro: ";
                std::getline(std::cin, tituloLivro);
                Leitor* leitor = biblioteca.buscarLeitor(nomeLeitor);
                Livro* livro = biblioteca.buscarLivro(tituloLivro);
                if (leitor && livro) {
                    biblioteca.realizarEmprestimo(leitor, livro);
                    carregando("Processando empréstimo");
                } else {
                    std::cout << "❌ Leitor ou Livro não encontrado.\n";
                }
                break;
            }
            case 4: {
                limparTela();
                std::string tituloLivro;
                std::cout << "Digite o título do livro para devolver: ";
                std::getline(std::cin, tituloLivro);
                Emprestimo* emprestimo = biblioteca.buscarEmprestimo(tituloLivro);
                if (emprestimo) {
                    biblioteca.devolverLivro(*emprestimo);
                    carregando("Processando devolução");
                } else {
                    std::cout << "❌ Empréstimo não encontrado.\n";
                }
                break;
            }
            case 5: {
                limparTela();
                std::string tituloLivro;
                int diasExtras;
                std::cout << "Digite o título do livro para prorrogar: ";
                std::getline(std::cin, tituloLivro);
                std::cout << "Digite a quantidade de dias de prorrogação: ";
                std::cin >> diasExtras;
                Emprestimo* emprestimo = biblioteca.buscarEmprestimo(tituloLivro);
                if (emprestimo) {
                    biblioteca.prorrogarEmprestimo(*emprestimo, diasExtras);
                    carregando("Prorrogando empréstimo");
                } else {
                    std::cout << "❌ Empréstimo não encontrado.\n";
                }
                break;
            }
            case 6:
                limparTela();
                biblioteca.gerarRelatorioEmprestimosPorTipo();
                break;
            case 7:
                limparTela();
                biblioteca.gerarRelatorioMultasPendentes();
                break;
            case 8: {
                limparTela();
                std::string nomeLeitor;
                std::cout << "Digite o nome do leitor: ";
                std::getline(std::cin, nomeLeitor);
                biblioteca.exibirHistoricoLeitor(nomeLeitor);
                break;
            }
            case 9:
                limparTela();
                biblioteca.notificarAtraso();
                break;
            case 10:
                limparTela();
                biblioteca.salvarDados();
                carregando("Salvando dados");
                break;
            case 11:
                limparTela();
                biblioteca.carregarDados();
                carregando("Carregando dados");
                break;
            case 0:
                limparTela();
                efeitoDigitacao("Encerrando o sistema...", 50);
                break;
            default:
                std::cout << "❌ Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}
