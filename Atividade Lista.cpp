#include <stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *inicio, *fim;
    int n;

    Lista() {
        inicio = fim = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (inicio == NULL);
    }

    void inserirInicio(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        novo->prox = inicio;
        inicio = novo;
        if (vazia()) {
            fim = novo;
        }
        n++;
    }

    void inserirFinal(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        novo->prox = NULL;
        if (vazia()) {
            inicio = novo;
        } else {
            fim->prox = novo;
        }
        fim = novo;
        n++;
    }

    void imprimir() { // O(n)
        No *aux = inicio;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
        if (!vazia()) {
            No *aux = inicio;
            inicio = inicio->prox;
            delete aux;
            n--;
            if (inicio == NULL) {
                fim = NULL;
            }
        }
    }

    void removerFinal() { // O(n)
        if (!vazia()) {
            if (inicio == fim) {
                delete inicio;
                inicio = fim = NULL;
            } else {
                No *penultimo = inicio;
                while (penultimo->prox != fim) {
                    penultimo = penultimo->prox;
                }
                delete fim;
                fim = penultimo;
                fim->prox = NULL;
            }
            n--;
        }
    }

    void receber(int limite) {
        for (int i = 10; i <= limite; i++) {
            inserirFinal(i);
        }
    }

    void deletarItem(int valor) { // O(n)
        No *anterior = NULL;
        No *atual = inicio;

        while (atual != NULL) {
            if (atual->valor == valor) {
                if (anterior == NULL) {
                    // O item a ser excluído é o primeiro da lista
                    inicio = atual->prox;
                } else {
                    anterior->prox = atual->prox;
                }
                if (atual == fim) {
                    fim = anterior;
                }
                delete atual;
                n--;
                break; // item encontrado e excluído
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
};

int main() {
    Lista l;
    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(10);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(0);
    l.receber(20);
    l.imprimir();

    return 0;
}
