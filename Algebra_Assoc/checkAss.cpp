//it's not a dirty joke, it's dirty code

//this function checks if the operation set is associative and returns a boolean value
bool isAssociative(int n, int matrix[][5])
{
	//check if the operation set is associative
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				int a = matrix[i][j];
				int b = matrix[j][k];
				if (matrix[a][k] != matrix[i][b])
				{
					return false;
				}
			}
		}
	}
	return true;
}
