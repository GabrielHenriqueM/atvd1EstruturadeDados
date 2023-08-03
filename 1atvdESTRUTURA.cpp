#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIVROS 10

struct Livro {
    char titulo[100];
    char autor[100];
    int numPaginas;
};

struct Biblioteca {
    struct Livro livros[MAX_LIVROS];
    int quantidadeLivros;
};

void limparTela() {
    system("cls");
}

void lerLivro(struct Livro* livro) {
    printf("Informe o titulo do livro: ");
    scanf(" %[^\n]", livro->titulo);

    printf("Informe o nome do autor do livro: ");
    scanf(" %[^\n]", livro->autor);

    printf("Informe o numero de paginas do livro: ");
    scanf("%d", &livro->numPaginas);
}

void imprimirLivro(struct Livro livro) {
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Numero de Paginas: %d\n", livro.numPaginas);
}

void adicionarLivro(struct Biblioteca* biblioteca) {
    if (biblioteca->quantidadeLivros < MAX_LIVROS) {
        struct Livro novoLivro;
        lerLivro(&novoLivro);

        biblioteca->livros[biblioteca->quantidadeLivros] = novoLivro;
        biblioteca->quantidadeLivros++;

        printf("\nLivro adicionado com sucesso!\n");
    } else {
        printf("\nLimite maximo de livros atingido.\n");
    }
}

void imprimirBiblioteca(struct Biblioteca biblioteca) {
    printf("\nInformacoes de todos os livros na biblioteca:\n");
    for (int i = 0; i < biblioteca.quantidadeLivros; i++) {
        imprimirLivro(biblioteca.livros[i]);
        printf("\n");
    }
}

void imprimirLivroComMaiorNumPaginas(struct Biblioteca biblioteca) {
    int maiorNumPaginas = 0;
    int numLivroMaiorPaginas = 0;

    for (int i = 0; i < biblioteca.quantidadeLivros; i++) {
        if (biblioteca.livros[i].numPaginas > maiorNumPaginas) {
            maiorNumPaginas = biblioteca.livros[i].numPaginas;
            numLivroMaiorPaginas = i;
        }
    }

    printf("\nLivro com maior numero de paginas:\n");
    imprimirLivro(biblioteca.livros[numLivroMaiorPaginas]);
}

int main() {
    struct Biblioteca minhaBiblioteca;
    minhaBiblioteca.quantidadeLivros = 0;
    char opcao;

    do {
        limparTela();
        printf("\nDeseja inserir um novo livro? (S/N): ");
        scanf(" %c", &opcao);

        if (opcao == 'S' || opcao == 's') {
            adicionarLivro(&minhaBiblioteca);
        }
    } while (opcao == 'S' || opcao == 's');

    limparTela();
    imprimirBiblioteca(minhaBiblioteca);
    imprimirLivroComMaiorNumPaginas(minhaBiblioteca);

    return 0;
}
