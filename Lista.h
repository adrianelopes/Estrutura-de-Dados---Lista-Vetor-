#pragma once

#include <iostream>

class Lista
{
private:
    static const int tmax = 100;
    int dados[tmax];
    int tamanho;

public:
    Lista();

    bool listaVazia();                            // Verifica se a lista está vazia
    bool listaCheia();                            // Verifica se a lista está cheia
    int obterTamanho();                           // Obtém o tamanho da lista
    int obterElemento(int pos);                   // Obtém o elemento de uma posição
    bool modificarElemento(int pos, int valor);   // Modifica o valor de uma posição
    bool inserirElemento(int pos, int valor);     // Insere um elemento em uma posição
    bool removerElemento(int pos);                // Remove um elemento de uma posição
    void imprimirLista();                         // Exibe os elementos da lista
    void salvarLista(const std::string &arquivo); // Atualiza a lista
    void carregarLista(const std::string &arquivo);
};
