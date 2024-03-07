#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("all_matrices.txt");

using namespace std;

//generate all square matrixes of size n with elements with n elements (just gonna use 1 to n for simplicity)
void generateMatrixes(int n, int i, int ok, int number, int *matrix)
{
	if (i == n * n)
	{
		for (int k = 0; k < n; k++)
		{
			for (int l = 0; l < n; l++)
			{
				fout << matrix[k * n + l] << " ";
			}
			fout << endl;
		}
		fout << endl;
		return;
	}
	if (ok == 0)
	{
		matrix[i] = number;
		generateMatrixes(n, i, 1, number + 1, matrix);
	}
	else
	{
		for (int k = 1; k <= n; k++)
		{
			matrix[i] = k;
			generateMatrixes(n, i + 1, 1, number, matrix);
		}
	}
}
/*
n - the size of the matrix

i - the current position in the matrix

ok - a flag that tells us if we have already placed a number in the current position

number - the number that we are going to place in the current position

matrix - the matrix that we are going to generate (well it's more of a vector but it's easier to work with it like this)

if i == n * n we have generated a matrix so we print it

if ok == 0 we place the number in the current position and call the function with the same i, number +1 and ok = 1

if ok == 1 we place all the numbers from 1 to n in the current position and call the function with i + 1 and ok = 1

the function is called recursively until we have generated all the matrixes



honestly I don't know why I used a flag to check if we have placed a number in the current position
I could have just checked if matrix[i] == 0
but if it looks stupid but it works, it ain't stupid
and sure as hell I'm not risking breaking this code, I hate backtracking as a whole, god knows I sacrified a few children to make this work
*/
