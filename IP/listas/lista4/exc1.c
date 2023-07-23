#include <stdio.h>

int main(void)
{
	//declaração de variáveis
	int i, j;
	double num[2][2], det;
	
	//leitura da metriz
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%lf", &num[i][j]);
		}
	}
	
	//cálculod do teterminante de uma matriz quadrada de ordem 2
	det = (num[0][0] * num[1][1]) - (num[0][1] * num[1][0]);

	printf("%.2lf\n", det);
}
					
