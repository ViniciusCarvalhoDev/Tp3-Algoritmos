#ifndef CELL
#define CELL
#include <vector> 
#include <string>

// Classe que irá armazenar as informacoes sobre cada macieira (representa uma celula da matriz)
class Cell
{
	public: 
		int valor; // Quantidade de frutos
		std::string caminho; // String que representa o caminho percorrido até chegar nesta celula
		Cell(); // Construtor vazio
		Cell(int valor, std::string caminho); // Construtor com argumentos
};

#endif