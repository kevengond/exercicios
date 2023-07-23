#include <stdio.h>
#include <string.h>

//constante com a quantidade de caracteres do maior país até agora
enum {PMAX = 15};

int main(void)
{
	//declaração de variáveis
	int i, cont;
	char bus_p[PMAX];

	//leitura dos valores e teste para a saída
	while(scanf("%[^\n]", bus_p) != EOF)
	{
		getchar();

		if (!strcmp(bus_p, "brasil") || !strcmp(bus_p, "portugal")) printf("Feliz Natal!\n");
		else if (!strcmp(bus_p, "espanha") || !strcmp(bus_p, "argentina") || !strcmp(bus_p, "chile") || !strcmp(bus_p, "mexico")) printf("Feliz Navidad!\n");
		else if (!strcmp(bus_p, "estados-unidos")||!strcmp(bus_p, "inglaterra")||!strcmp(bus_p, "australia")||!strcmp(bus_p, "antardida")||!strcmp(bus_p, "canada"))printf("Merry Christmas!\n");
		else if (!strcmp(bus_p, "italia")||!strcmp(bus_p, "libia"))printf("Buon Natale!\n");
		else if (!strcmp(bus_p, "siria")||!strcmp(bus_p, "marrocos"))printf("Milad Mubarak!\n");
		else if (!strcmp(bus_p, "alemanha"))printf("Frohliche Weihnachten!\n");
		else if (!strcmp(bus_p, "austria"))printf("Frohe Weihnacht!\n");
		else if (!strcmp(bus_p, "coreia"))printf("Chuk Sung Tan!\n");
		else if (!strcmp(bus_p, "grecia"))printf("Kala Christougena!\n");
		else if (!strcmp(bus_p, "suecia"))printf("God Jul!\n");
		else if (!strcmp(bus_p, "turquia"))printf("Mutlu Noeller!\n");
		else if (!strcmp(bus_p, "irlanda"))printf("Nollaig Shona Dhuit!\n");
		else if (!strcmp(bus_p, "belgica"))printf("Zalig Kerstfeest!\n");
		else if (!strcmp(bus_p, "japao"))printf("Merii Kurisumasu!\n");
		else printf("-- NOT FOUND --\n");
	}
}
