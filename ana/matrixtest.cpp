#include <stdio.h>

// void createMatrix(int matrix[][]){
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		for (int j = 0; j < 10; ++j)
// 		{
// 			matrix[i][j] = j;
// 		}
		
// 	}
// }

void createMatrix(int (*matrix)[11]){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			matrix[i][j] = j;
		}
		// matrix[0][i] = i;
	}
}

void drawMatrix(int (*matrix)[11]){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
		// printf("%d", matrix[0][i]);
	}
}

// void drawMatrix(int matrix[][]){
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		for (int j = 0; j < 10; ++j)
// 		{
// 			printf("%d", matrix[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

int main(int argc, char const *argv[])
{
	int matrix[10][11] = {0,};
	createMatrix(matrix);
	drawMatrix(matrix);

	return 0;
}