#include "Lista.h"
#include <iostream>
#include <fstream>

using namespace std;

Lista::Lista()
{
    tamanho = 0;
}

void Lista::salvarLista(const std::string &arquivo)
{
    std::ofstream out(arquivo);
    if (!out)
    {
        std::cout << "Erro ao abrir arquivo para salvar!\n";
        return;
    }
    out << tamanho << "\n";
    for (int i = 0; i < tamanho; i++)
    {
        out << dados[i] << " ";
    }
    out.close();
}

void Lista::carregarLista(const std::string &arquivo)
{
    std::ifstream in(arquivo);
    if (!in)
    {
        return; // Se o arquivo não existir, inicia uma lista vazia
    }
    in >> tamanho;
    for (int i = 0; i < tamanho; i++)
    {
        in >> dados[i];
    }
    in.close();
}

bool Lista::listaVazia()
{
    if (tamanho == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Lista::listaCheia()
{
    if (tamanho == tmax)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Lista::obterTamanho()
{
    return tamanho;
}

int Lista::obterElemento(int posicao)
{
    int dado = 0;
    if ((posicao > tamanho) || (posicao <= 0))
    {
        cout << "Posição inexistente" << endl;
    }
    else
    {

        dado = dados[posicao - 1];
    }

    return dado;
}

bool Lista::modificarElemento(int posicao, int valor)
{
    if ((posicao > tamanho) || (posicao <= 0))
    {
        cout << "Posição inexistente " << endl;
        return false;
    }
    else
    {
        dados[posicao - 1] = valor;
        return true;
    }
}

bool Lista::inserirElemento(int posicao, int valor)
{
    if (listaCheia() || (posicao > tamanho + 1) || (posicao <= 0))
    {
        cout << "Posição inexistente " << endl;
        return false;
    }
    else
    {
        for (int i = tamanho - 1; i >= posicao; i--)
        {
            dados[i + 1] = dados[i];
        }

        cout << "Valor: " << valor << " tamanho: " << tamanho << endl;
        cout << "Posicao: " << posicao << endl;

        dados[posicao - 1] = valor;
        tamanho++;
        cout << "Tamanho depois: " << tamanho << endl;
        return true;
    }
}

bool Lista::removerElemento(int posicao)
{
    int dado;
    if ((posicao > tamanho) || (posicao < 1))
    {
        cout << "Posição inexistente " << endl;
        return false;
    }
    else
    {
        dado = dados[posicao - 1];
        for (int i = posicao - 1; i < tamanho - 1; i++)
        {
            dados[i] = dados[i + 1];
        }
        tamanho--;
        return true;
    }
}

void Lista::imprimirLista()
{
    if (listaVazia())
    {
        cout << "A lista está vazia." << endl;
    }

    for (int i = 0; i < tamanho; i++)
    {
        cout << dados[i] << " ";
    }
    cout << endl;
}