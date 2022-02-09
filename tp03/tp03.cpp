#include <stdlib.h>
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include "Cell.h"

using namespace std;

// Recebe a celula atual e os tres valores possíveis de serem associados a ela
// escolhe o maior e passa o caminho percorrido pela celula anterior a essa celula atual

void AtualizaMaximo(Cell* celula, Cell *a, Cell *b, Cell * c = nullptr) {

    if (a->valor >= b->valor && c == nullptr || a->valor >= b->valor && a->valor > c->valor)
    {
        celula->caminho += a->caminho + " ";
    }
    else if (b->valor >= a->valor && c == nullptr || b->valor > a->valor && b->valor > c->valor)
    {
        celula->caminho += b->caminho + " ";
    }
    else
    {
        celula->caminho += c->caminho + " ";
    }
}


int main()
{
    int linhas, colunas;
    cin >> linhas >> colunas;

    vector<vector<Cell>> mat; // Matriz de Celulas que irá representar o problema

    for (size_t i = 0; i < linhas; i++) // For principal do programa onde os procedimentos serão executados
    {
        vector<Cell> temp; // Representa uma linha da matriz

        // Esse irá percorrer as colunas cadastrando o valor da entrada do txt para uma celula da matriz
        for (size_t j = 0; j < colunas; j++)
        {
            int numero;
            cin >> numero;

            Cell celula;
            celula.valor = numero;
            
            temp.push_back(celula);
        }

        // Atribui a linha a matriz
        mat.push_back(temp);

        // Caso essa seja a primeira linha esse laço irá cadastrar o indice de cada celula no seu respectivo caminho percorrido
        if (i < 1) {
            for (size_t j = 0; j < colunas; j++)
            {
                mat[0][j].caminho += std::to_string(j);
            }
        }

        if (i > 0) {

            //Percorre cada celula da linha e busca a celula alcançavel anterior escolhendo a que tem o maior valor
            // e chama a função AtualizaMaximo

            for (size_t j = 0; j < colunas; j++)
            {
                if (j > 0 && j < colunas - 1) {
                    mat[i][j].valor += max(mat[i - 1][j].valor, max(mat[i - 1][j - 1].valor, mat[i - 1][j + 1].valor));
                    AtualizaMaximo(&mat[i][j], &mat[i - 1][j], &mat[i - 1][j - 1], &mat[i - 1][j + 1]);
                }

                else if (j > 0) {
                    mat[i][j].valor += max(mat[i - 1][j].valor, mat[i - 1][j - 1].valor);
                    AtualizaMaximo(&mat[i][j], &mat[i - 1][j], &mat[i - 1][j - 1], nullptr);
                }

                else if (j < colunas - 1) {
                    mat[i][j].valor += max(mat[i - 1][j].valor, mat[i - 1][j + 1].valor);
                    AtualizaMaximo(&mat[i][j], &mat[i - 1][j], &mat[i - 1][j + 1], nullptr);
                }

                // Adiciona indice atual ao caminho
                mat[i][j].caminho += std::to_string(j);
            }
        }
        
        // Funçao que desaloca a linha da matriz de indice i -2 que não será mais utilizada para resolver o problema
        if (i > 1)
        {
            mat[i - 2].clear();
        }
    }

    int res = 0; // maior soma
    int index = 0; // indice da maior soma

    // For que percorre todas as colunas da ultima posição da matriz e recupoera o maior valor

    for (int j = 0; j < colunas; j++) {
        res = max(mat[linhas - 1][j].valor, res);
    }

    // For que recupera o indice do maior valor da ultima linha da matriz

    for (size_t j = 0; j < colunas; j++)
    {   
        if (mat[linhas - 1][j].valor == res )
        {
            index = j;
            break;
        }
    }
    
    //impressão dos resultados
    cout << res << endl;
    cout << mat[linhas - 1][index].caminho;

    return 0;
}