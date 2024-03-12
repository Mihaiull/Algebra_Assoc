//it's not a dirty joke, it's dirty code
#include <iostream>
#include <fstream>

std::ifstream f("associative_matrices.txt");
std::ofstream g("associative_matrices_no_duplicates.txt");
//this function checks if the operation set is associative and returns a boolean value
bool isAssociative(int n, int matrix[][5])
{
	//check if the operation set is associative
	for  (int i = 0 ; i < (n-1); i++)
		for (int j = 0; j < (n-1); j++)
			for (int k = 0; k <= (n); k++)
			{
				//std::cout << matrix[matrix[i][j]-1][k] << " " << matrix[i][matrix[j][k]] << " " << matrix[i][j] << " " << matrix[0][k] << std::endl;
				if (matrix[matrix[i][j]-1][k] != matrix[i][matrix[j][k]-1])
					return false;
			}
	return true;
}
//check

void delete_duplicates_from_file(int n, int matrix[][5])
{
	int matrix2[5][5];
	int i = 0;
	while (f >> matrix2[i][0])
	{
		for (int j = 1; j < n; j++)
		{
			f >> matrix2[i][j];
		}
		i++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			g << matrix2[i][j] << " ";
		}
		g << std::endl;
	}
}