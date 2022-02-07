#include <stdlib.h>
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#define N 4
#define M 6
using namespace std;

class Matrix { public: int* array; int m_width;  Matrix(int w, int h) : m_width(w), array(new int[w * h]) {} ~Matrix() { delete[] array; } int at(int x, int y) const { return array[index(x, y)]; }; int index(int x, int y) const { return x + m_width * y; } };
class Cell { public: int valor; string caminho; Cell() { this->caminho = ""; this->valor = 0; } Cell(int valor, string caminho) { this->valor = valor, this->caminho = caminho; } };

// To calculate max path in matrix
//int findMaxPath(int **mat, int linhas, int colunas )
//{
//
//    for (int i = 1; i < linhas; i++) {
//        for (int j = 0; j < colunas; j++) {
//
//            // [][][]
//            //   []
//
//            if (j > 0 && j < colunas - 1)
//                mat[i][j] += max(mat[i - 1][j],
//                    max(mat[i - 1][j - 1],
//                        mat[i - 1][j + 1]));
//
//            // [][]
//            //   []
//
//            else if (j > 0)
//                mat[i][j] += max(mat[i - 1][j],
//                    mat[i - 1][j - 1]);
//
//            //   [][]
//            //   []
//
//            else if (j < colunas - 1)
//                mat[i][j] += max(mat[i - 1][j],
//                    mat[i - 1][j + 1]);
//
//            // Store max path sum
//        }
//    }
//    int res = 0;
//    for (int j = 0; j < colunas; j++)
//        res = max(mat[linhas - 1][j], res);
//    return res;
//}

void findMaxPath(Cell** mat, int linhas, int colunas)
{

    for (int i = 1; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            // [][][]
            //   []

            if (j > 0 && j < colunas - 1)
                mat[i][j].valor += max(mat[i - 1][j].valor,
                    max(mat[i - 1][j - 1].valor,
                        mat[i - 1][j + 1].valor));

            // [][]
            //   []

            else if (j > 0)
                mat[i][j].valor += max(mat[i - 1][j].valor,
                    mat[i - 1][j - 1].valor);

            //   [][]
            //   []

            else if (j < colunas - 1)
                mat[i][j].valor += max(mat[i - 1][j].valor,
                    mat[i - 1][j + 1].valor);

            // Store max path sum
        }
    }

    int res = 0;

    for (int j = 0; j < colunas; j++)
        res = max(mat[linhas - 1][j].valor, res);

}

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

// Driver program to check findMaxPath
int main()
{
    int linhas, colunas;
    cin >> linhas >> colunas;

    /*Matrix matriz = Matrix(linhas, colunas);

    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            int numero;
            cin >> numero;
            
            matriz.array[matriz.index(i, j)] = numero;
        }
    }

    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            cout << matriz.at(i, j) << " ";
        }
        cout << '\n';
    }*/

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

        for (size_t j = 0; j < colunas; j++)
        {
            mat[0][j].caminho += std::to_string(j);
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

            for (size_t j = 0; j < colunas; j++)
            {
                mat[i - 1][j].caminho = "";
            }
        }

    }

    //for (int i = 1; i < linhas; i++) {
    //    for (int j = 0; j < colunas; j++) {

    //        // [][][]
    //        //   []

    //        if (j > 0 && j < colunas - 1)
    //            mat[i][j].valor += max(mat[i - 1][j].valor,
    //                max(mat[i - 1][j - 1].valor,
    //                    mat[i - 1][j + 1].valor));

    //        // [][]
    //        //   []

    //        else if (j > 0)
    //            mat[i][j].valor += max(mat[i - 1][j].valor,
    //                mat[i - 1][j - 1].valor);

    //        //   [][]
    //        //   []

    //        else if (j < colunas - 1)
    //            mat[i][j].valor += max(mat[i - 1][j].valor,
    //                mat[i - 1][j + 1].valor);

    //        // Store max path sum
    //    }
    //}

    int res = 0;

    for (int j = 0; j < colunas; j++)
        res = max(mat[linhas - 1][j].valor, res);

    //findMaxPath(matriz, linhas, colunas);

    return 0;
}