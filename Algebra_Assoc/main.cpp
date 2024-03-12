#include <iostream>
#include "generateMatrixes.h"
#include <fstream>
#include "checkAss.h"

using namespace std;
ofstream number("size.txt");

int main()
{
	int n;
	cin >> n;
	int matrix[5][5];
	//generate all the matrixes of size n
	generateMatrixes(n, 0, 0, 1, *matrix, 0);
	//read the matrixes from the file
	ifstream f("all_matrices.txt");
	ofstream g("associative_matrices.txt");
	number << n;
	long diana = pow(n, n * n);
	for (int x = 0; x < diana; x++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				f >> matrix[i][j];
				//print the matrix in for testing purposes
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		//check associativity and print if it is
		if (isAssociative(n, matrix))
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					g << matrix[i][j] << " ";
				}
				g << "\n";
			}
			g << "\n";
		}
	}
//del the first matrix from associative matrices
	
	
	return 0;
}