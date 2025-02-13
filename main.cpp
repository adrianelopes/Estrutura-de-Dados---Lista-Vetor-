#include <iostream>
#include <cstdlib>
#include "Lista.h"

using namespace std;

int main(int argc, char *argv[])
{
    Lista lista;
    std::string arquivo = "lista.txt";

    lista.carregarLista(arquivo);

    if (argc < 2)
    {
        cout << "Uso: ./programa <operacao> [parametros]\n";
        return 1;
    }

    string operacao = argv[1];
    cout << "argv: " << argv[1] << endl;

    if (operacao == "criar")
    {
        cout << "Lista criada com sucesso.\n";
    }
    else if (operacao == "inserir")
    {
        if (argc < 4)
        {
            cout << "Uso: ./programa inserir <valor> <posicao>\n";
        }
        int valor = atoi(argv[2]);
        int pos = atoi(argv[3]);

        if (lista.inserirElemento(pos, valor))
        {
            cout << "Elemento " << valor << " inserido na posição " << pos << ".\n";
        }
        else
        {
            cout << "Falha ao inserir elemento.\n";
        }
    }
    else if (operacao == "remover")
    {
        if (argc < 3)
        {
            cout << "Uso: ./programa remover <posicao>\n";
            return 1;
        }
        int pos = atoi(argv[2]);

        if (lista.removerElemento(pos))
        {
            cout << "Elemento na posição " << pos << " removido.\n";
        }
        else
        {
            cout << "Falha ao remover elemento.\n";
        }
    }
    else if (operacao == "modificar")
    {
        if (argc < 4)
        {
            cout << "Uso: ./programa modificar <posicao> <novo_valor>\n";
            return 1;
        }
        int pos = atoi(argv[2]);
        int novo_valor = atoi(argv[3]);

        if (lista.modificarElemento(pos, novo_valor))
        {
            cout << "Elemento na posição " << pos << " modificado para " << novo_valor << ".\n";
        }
        else
        {
            cout << "Falha ao modificar elemento.\n";
        }
    }
    else if (operacao == "obter")
    {
        if (argc < 3)
        {
            cout << "Uso: ./programa obter <posicao>\n";
            return 1;
        }
        int pos = atoi(argv[2]);
        int valor = lista.obterElemento(pos);
        cout << "Elemento na posição " << pos << ": " << valor << "\n";
    }
    else if (operacao == "tamanho")
    {
        if (argc < 2)
        {
            cout << "Uso: ./programa tamanho\n";
            return 1;
        }

        int n = lista.obterTamanho();

        cout << "Tamanho: " << n << "\n";
    }
    else if (operacao == "imprimir")
    {
        lista.imprimirLista();
    }
    else
    {
        cout << "Operação desconhecida.\n";
    }

    lista.salvarLista(arquivo);

    return 0;
}
