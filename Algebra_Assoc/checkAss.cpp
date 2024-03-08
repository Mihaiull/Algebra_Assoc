//it's not a dirty joke, it's dirty code
#include <iostream>
//this function checks if the operation set is associative and returns a boolean value
bool isAssociative(int n, int matrix[][5])
{
	//check if the operation set is associative
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n-1; k++)
			{
				if (matrix[matrix[i][j]][k] != matrix[i][matrix[j][k]])
				{
					std::cout << matrix[i][j] << " " << matrix[j][k] << " " << matrix[i][matrix[j][k]] << " " << matrix[matrix[i][j]][k] << matrix[1][k] <<"\n";
					return false;
				}
			}
		}
	}
	return true;
}
//check