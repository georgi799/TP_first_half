#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


//S? se scrie o func?ie care sorteaz? în ordine cresc?toare valorile a 2 variabile pe care le prime?te ca argumente. S? se testeze func?ia, afi?ând valorile variabilelor dup? revenirea din ea.

void crescator(int *a, int *b)
{
	if (a > b) {
		int aux = *a;
		*a = *b;
		*b = aux;
	}

}

void liniePlina(int n)
{
	
	while (n--) putchar('*');
	putchar('\n');

}

void linieGoala(int n)
{
	putchar('*');
	for (n -= 2; n--;) putchar(' ');
	puts("*");
}



void desen(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || j == n - i - 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}


bool dublu(int *a, int *b, int a_size, int b_size)
{
	bool e = false;

	for (int i = 0; i < a_size; i++)
	{
		 e = false;
		for (int j = 0; j < b_size; j++)
		{
			if (*(a + i) == *(b + j))
			{
				e = true;
			}
		}
	}
	if (!e)
	{
		return false;
	}

	return true;
}



int lung_crescator(int* a, int n)
{
	int k = 1;
	int max = 0;
	
	for (int i = 0; i < n; i++)
	{

		if (*(a + i) < *(a + i + 1))
		{
			k++;

		}
	}
	if (k > max)max = k;

	printf("Cea mai mare secventa de numere consecutive este de %d itemi ", max);

}

void inserare(int* a, int* b, int a_size, int b_size, int poz)
{

}

int main()
{

	int x, y;
	int n;
	int v1[] = { 8, 7, 9, 5, 3, 6 };
	int v2[] = { 6, 7, 9 };
	
	int v1_size = sizeof(v1)/sizeof(v1[0]);
	int v2_size = sizeof(v2) / sizeof(v2[0]);
	

	printf("Dati primul numar: ");
	scanf("%d", &x);
	printf("Dati al doilea numar: ");
	scanf("%d", &y);
	int* px = &x;
	int* py = &y;
	printf("Numerele sunt %d si %d ", *px, *py);
	crescator(px, py);
	printf("\n");
	printf("Acum numerele sunt %d si %d ", *px, *py);
	
	printf("\n");

	printf("Dati un numar > 2: ");
	scanf("%d", &n);

	if (n <= 2)
	{
		printf("Valoare invalida!");
		return 1;
	}
	desen(n);
	
	bool e=dublu(v1, v2, v1_size, v2_size);
	if (e) {
		printf("Toate elementele din primul vector exista in al doilea vector.\n");
	}
	else {
		printf("Cel putin un element din primul vector nu exista in al doilea vector.\n");
	}
	
	lung_crescator(v1, v1_size);


	return 0;
}