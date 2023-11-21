#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Livro {
    string nome;
    string autor;
    string data; // Data opcional
};

class Biblioteca {
private:
    vector<Livro> livros;

public:
    void adicionarLivro() {
        Livro novoLivro;
        cout << "Digite o nome do livro: ";
        cin.ignore();
        getline(cin, novoLivro.nome);

        cout << "Digite o nome do autor: ";
        getline(cin, novoLivro.autor);

        cout << "Digite a data de publicacao (opcional): ";
        getline(cin, novoLivro.data);

        livros.push_back(novoLivro);
        cout << "Livro adicionado com sucesso!\n\n";
    }

    void exibirMensagemCentralizada(const string& mensagem) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

        int larguraConsole = consoleInfo.dwSize.X;

        int tamanhoMensagem = mensagem.length();

        int larguraLinha = larguraConsole - 4; // Largura do quadro

        // Desenhar linha superior do quadro
        cout << '+' << string(larguraLinha, '-') << '+' << endl;

        // Imprimir parte superior do quadro (espaço em branco)
        cout << "|";
        cout << setw(larguraLinha) << setfill(' ') << " " << '|' << endl;

        // Imprimir texto centralizado com bordas
        cout << "|";
        cout << setw((larguraLinha - tamanhoMensagem) / 2) << setfill(' ') << " ";
        cout << mensagem;
        cout << setw((larguraLinha - tamanhoMensagem) / 2 + (larguraLinha - tamanhoMensagem) % 2) << setfill(' ') << " ";
        cout << '|' << endl;

        // Imprimir parte inferior do quadro (espaço em branco)
        cout << "|";
        cout << setw(larguraLinha) << setfill(' ') << " " << '|' << endl;

        // Desenhar linha inferior do quadro
        cout << '+' << string(larguraLinha, '-') << '+' << endl;
    }

    void exibirLivrosFormatados() {
        if (livros.empty()) {
            exibirMensagemCentralizada("Nenhum livro na biblioteca.");
            return;
        }

        for (const auto& livro : livros) {
            string infoLivro = "Nome: " + livro.nome + " | Autor: " + livro.autor + " | Data: " + livro.data;
            exibirMensagemCentralizada(infoLivro);
        }
    }

    void pesquisarLivroPorNome(const string& nome) {
        bool encontrado = false;
        for (const auto& livro : livros) {
            if (livro.nome == nome) {
                string infoLivro = "Nome: " + livro.nome + " | Autor: " + livro.autor + " | Data: " + livro.data;
                exibirMensagemCentralizada(infoLivro);
                encontrado = true;
            }
        }
        if (!encontrado) {
            exibirMensagemCentralizada("Livro nao encontrado.");
        }
    }

    void pesquisarLivroPorAutor(const string& autor) {
        bool encontrado = false;
        for (const auto& livro : livros) {
            if (livro.autor == autor) {
                string infoLivro = "Nome: " + livro.nome + " | Autor: " + livro.autor + " | Data: " + livro.data;
                exibirMensagemCentralizada(infoLivro);
                encontrado = true;
            }
        }
        if (!encontrado) {
            exibirMensagemCentralizada("Livro nao encontrado.");
        }
    }

    // Outras funções, como deletar livro, atualizar dados, etc.
    // ...

};

int main() {
    Biblioteca biblioteca;
    int opcao;

    do {
        cout << "=== Sistema Organizador de Bibliotecas ===\n";
        cout << "1. Adicionar Livro\n";
        cout << "2. Listar Livros\n";
        cout << "3. Pesquisar por Nome do Livro\n";
        cout << "4. Pesquisar por Autor\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            biblioteca.adicionarLivro();
            break;
        case 2:
            biblioteca.exibirLivrosFormatados();
            break;
        case 3:
        {
            string nomePesquisa;
            cout << "Digite o nome do livro a ser pesquisado: ";
            cin.ignore();
            getline(cin, nomePesquisa);
            biblioteca.pesquisarLivroPorNome(nomePesquisa);
        }
        break;
        case 4:
        {
            string autorPesquisa;
            cout << "Digite o nome do autor a ser pesquisado: ";
            cin.ignore();
            getline(cin, autorPesquisa);
            biblioteca.pesquisarLivroPorAutor(autorPesquisa);
        }
        break;
        // Adicionar outras opções de acordo com as funções da Biblioteca
        }
    } while (opcao != 5);

    return 0;
}
