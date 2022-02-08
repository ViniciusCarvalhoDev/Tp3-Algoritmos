#include <stdlib.h>
#include <utility>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cell { public: int valor; string caminho; Cell() { this->caminho = ""; this->valor = 0; } Cell(int valor, string caminho) { this->valor = valor, this->caminho = caminho; } };

void AtualizaMaximo(Cell* celula, Cell *a, Cell *b, Cell * c = nullptr) {

    if (a->valor >= b->valor && c == nullptr || a->valor >= b->valor && a->valor > c->valor)
    {
        celula->caminho += a->caminho;
        //a->caminho = "";
    }
    else if (b->valor >= a->valor && c == nullptr || b->valor > a->valor && b->valor > c->valor)
    {
        celula->caminho += b->caminho;
       // b->caminho = "";
    }
    else
    {
        celula->caminho += c->caminho;
        //c->caminho = "";
    }
}

template<typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}

// Driver program to check findMaxPath
int main()
{
    int linhas, colunas;
    cin >> linhas >> colunas;
    vector<vector<Cell>> mat;

    for (size_t i = 0; i < linhas; i++)
    {
        vector<Cell> temp;
        for (size_t j = 0; j < colunas; j++)
        {
            int numero;
            cin >> numero;

            Cell celula;
            celula.valor = numero;
            
            temp.push_back(celula);
        }

        mat.push_back(temp);

        if (i < 1) {
            for (size_t j = 0; j < colunas; j++)
            {
                mat[0][j].caminho += std::to_string(j);
            }
        }

        if (i > 0) {
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

                mat[i][j].caminho += std::to_string(j);
            }
        }
        
        if (i > 2)
        {
            mat[i - 2].clear();
        }
    }

    int res = 0;

    for (int j = 0; j < colunas; j++)
        res = max(mat[linhas - 1][j].valor, res);

    return 0;
}