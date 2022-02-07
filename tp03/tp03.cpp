#include <stdlib.h>
#include <utility>
#include <iostream>
#include <vector>
#define N 4
#define M 6
using namespace std;

class Matrix { public: int* array; int m_width;  Matrix(int w, int h) : m_width(w), array(new int[w * h]) {} ~Matrix() { delete[] array; } int at(int x, int y) const { return array[index(x, y)]; }; int index(int x, int y) const { return x + m_width * y; } };

// To calculate max path in matrix
int findMaxPath(int **mat, int linhas, int colunas )
{

    for (int i = 1; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            // [][][]
            //   []

            if (j > 0 && j < colunas - 1)
                mat[i][j] += max(mat[i - 1][j],
                    max(mat[i - 1][j - 1],
                        mat[i - 1][j + 1]));

            // [][]
            //   []

            else if (j > 0)
                mat[i][j] += max(mat[i - 1][j],
                    mat[i - 1][j - 1]);

            //   [][]
            //   []

            else if (j < colunas - 1)
                mat[i][j] += max(mat[i - 1][j],
                    mat[i - 1][j + 1]);

            // Store max path sum
        }
    }
    int res = 0;
    for (int j = 0; j < colunas; j++)
        res = max(mat[linhas - 1][j], res);
    return res;
}

// Driver program to check findMaxPath
int main()
{
    

    int linhas, colunas;
    cin >> linhas >> colunas;

    Matrix matriz = Matrix(linhas, colunas);

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
    }

    /*vector<vector<int>> matriz;

    for (size_t i = 0; i < linhas; i++)
    {
        vector<int> temp;
        for (size_t j = 0; j < colunas; j++)
        {
            int numero;
            cin >> numero;
            temp.push_back(numero);
        }

        matriz.push_back(temp);
    }*/


   /* int* matriz = &mat1;

    cout << findMaxPath(mat1, linhas, colunas) << endl;*/
    return 0;
}