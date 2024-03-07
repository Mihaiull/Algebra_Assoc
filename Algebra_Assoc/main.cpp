#include <iostream>
#include "generateMatrixes.h"
#include <fstream>
#include "checkAss.h"

using namespace std;

ifstream f("all_matrices.txt");
ofstream g("associative_matrices.txt");

int main()
{
	int n;
	cin >> n;
	int matrix[5][5];
	//generate all the matrixes of size n
	generateMatrixes(n, 0, 0, 1, *matrix);
	//check if the matrixes are associative
	//read the matrixes from the file
	ifstream f("all_matrices.txt");
	ofstream g("associative_matrices.txt");
	for (int x = 0; x <= pow(n, n * n); x++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				f >> matrix[i][j];
		//check associativity and print if it is
		if (isAssociative(n, matrix))
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					g << matrix[i][j] << " ";
				}
				g << endl;
			}
			g << endl;
		}
		}
	}
	
	
	return 0;
}