#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<conio.h>

int variabila_global=10;

void schimbare(double* a, double* b)
{
    double aux;
    aux = *a;
    *a = *b;
    *b = aux;


}

int checkPalindrom(int *v, int n){
    int i, j;
    printf("n: %d\n", n);
    for (i=0,j = n-1; i < n; i++, j--)
        printf("COMPARING %d %d \n", *(v + i), *(v + j));
    if (*(v + i) != *(v + j)) {
        printf("%d IS DIFF FROM %d", *(v + i), *(v + j));
        return -1;
    }


    return 0;


}

void ex1()
{

    double x = 0.5, y = -2.1;
    double *p1 = &x;
    double *p2 = &y;
    printf("Valorile sunt x = %f si y = %f", *p1, *p2);
    schimbare(p1, p2);
    printf(" \n ");
    printf("Valorile acum sunt x = %f si y = %f ", *p1, *p2);




}

void ex2()
{
    int variabila_locala=11;

    printf("Adresa de memorie a variabilei globale este: %p , iar adresa de memorie a variabilei locale este: %p ", (void*)&variabila_global, (void*)&variabila_locala);
    if (&variabila_global < &variabila_locala)
    {
        printf("Variabila globala este situata prima in memoria calculatorului!");
    }
    else
    {
        printf("Variabila locala este situata prima in memoria calculatorului!");
    }
}

void ex3()
{
    long x = 10;
    long y = 20;

    long* px = &x;
    long* py = &y;

    printf("Adresa de memorie a lui x este: %p , iar a lui y este: %p", (void*)&x, (void*)&y);
    printf("\n");
    if (px + 1 * sizeof(long) == py || py + 1 * sizeof(long) == px)
    {
        printf("Adresele se afla consecutiv in memorie!");
    }
    else printf("Adresele nu se afla consecutiv in memorie.");
}


void ex4()
{
    int n;
    int nr;
    int* v;
    int k = 0;

    do {
        printf("Dati un numar > 0 si <=10.");
        scanf("%d", &n);
        if (n < 0 || n>10)
        {
            printf("Valoare invalida");
        }
    } while (n < 0 || n>10);

    v = (int*)malloc(sizeof(int) * n);

    printf("Dati valori: ");
    for (int i = 0; i < n; i++)
    {
        printf(" v[%d]= ", i);
        scanf("%d", &nr);
        *(v + i) = nr;


    }

    int* end = v + n;
    for (int* p = v; p !=end; p++)
    {
        for (int* d = p + 1; d !=end; d++)
        {
            if (*p == *d)
            {
                k++;

            }
        }
    }
    printf("Au fost: %d duplicate", k);
}


void ex5()
{
    int v[10];
    int nr;
    int n;
    int aux;
    int r = 0;

    do {
        printf("Dati un numar > 0 si <=10.");
        scanf("%d", &n);
        if (n < 0 || n>10)
        {
            printf("Valoare invalida");
        }
    } while (n < 0 || n>10);

    printf("Dati valori: ");
    for (int i = 0; i < n; i++)
    {
        printf(" v[%d]= ", i);
        scanf("%d", v+i );
    }

    if (!checkPalindrom(v, n))
        printf("PALINDROM");
}



void ex6()
{
    int k = 0;
    int nr;
    int v[10];
    int last;

    while (k< 10)
    {
        printf("Dati valori: ");
        scanf("%d", &nr);
        if (nr == 0)break;
        *(v + k) = nr;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        printf("v[%d] = %d \n", i, *(v + i));
    }
    last = *(v + k - 1);
    for (int i = k - 1; i >= 0; i--)
    {
        *(v + i) = *(v + i - 1);
    }
    *v = last;
    printf("\n");
    printf("Elementele dupa prima rotatie: \n");
    for (int i = 0; i < k; i++)
    {
        printf("v[%d] = %d \n", i, *(v + i));
    }
}

void ex7()
{
    int n, nr;
    int v[10];
    int k = 1;
    int max;

    do {
        printf("Dati un numar > 0 si <=10.");
        scanf("%d", &n);
        if (n < 0 || n>10)
        {
            printf("Valoare invalida");
        }
    } while (n < 0 || n>10);

    printf("Dati valori: ");

    for (int i = 0; i < n-1; i++)
    {
        printf(" v[%d]= ", i);
        scanf("%d", v + i);
    }
    max = *v;
    for (int i = 0; i < n; i++)
    {

        if (*(v + i) < *(v + i + 1))
        {
            k++;

        }
    }
    if (k > max)max = k;

    for (int i = 0; i < k; i++)
    {
        printf("v[%d] = %d \n", i, *(v + i));
    }
    printf("Cea mai mare secventa de numere consecutive este de %d itemi ", max);

}

int main()
{
    int tasta;

    do {
        printf("0) Iesire \n\n 1) Se considera doua variabile: double x=0.5, y=-2.1. Folosind doar pointeri, fara sa se acceseze direct valorile variabilelor, sa se interschimbe cele doua valori si sa se afiseze. \n\n 2) Se considera doua variabile intregi, una globala si alta locala. Sa se specifice care dintre ele este situata prima in memoria calculatorului. \n\n 3) Se cosidera doua variabile locale: long x,y. Sa se specifice daca ele sunt situate consecutiv in memorie, fara niciun spatiu intre ele, indiferent de ordinea lor (x,y sau y,x). Programul va fi conceput in asa fel încat sa functioneze pentru orice dimensiune a tipului long. \n\n 4) Se citeste de la tastatura un intreg 0<n<=10 si apoi n valori intregi. Sa se afiseze cate duplicate exista in tablou. Programul nu va folosi deloc operatorul de indexare. \n Exemplu: {3,1,1,2,3,5,3,2} => 4 \n\n 5) Se citeste de la tastatura un intreg 0<n<=10 si apoi n valori reale. Sa se afiseze daca toate elementele din vector alcatuiesc un palindrom (secventa de la stanga la dreapta este aceeasi cu secventa de la dreapta la stanga, ex: {2, 8, 1, 8, 2}). Programul nu va folosi deloc operatorul de indexare. \n\n 6) Se citesc de la tastatura maxim 10 valori intregi, pana la intalnirea valorii 0, care nu face parte din secventa. Sa se roteasca la dreapta seria cu o pozitie, a.i. ultima valoare sa ajunga prima, iar toate celelalte sa fie deplasate cu o pozitie la dreapta. Se va afisa noua serie. Programul nu va folosi deloc operatorul de indexare. \n Exemplu: {5, -1, 2, 4} => {4, 5, -1, 2} \n\n 7) Se citeste de la tastatura un intreg 0<n<=10 si apoi n valori reale. Sa se afiseze din cate secvente strict crescatoare de dimensiune maxima este alcatuit sirul. O secventa poate fi formata dintr-un singur element. Programul nu va folosi deloc operatorul de indexare. \n Exemplu: {5,1,1,7} => 3");

        printf("\n\n");
        printf("Dati numarul exercitiului: ");
        scanf(" %d", &tasta);
        printf(" \n");



        switch (tasta) {

            case 0:
                exit(0);

            case 1: {

                ex1();
                getch();
                break;
            }

            case 2: {

                ex2();
                getch();
                break;
            }

            case 3: {

                ex3();
                getch();
                break;
            }

            case 4: {

                ex4();
                getch();
                break;
            }

            case 5: {

                ex5();
                getch();
                break;


            }
            case 6: {

                ex6();
                getch();
                break;
            }

            case 7: {
                ex7();
                getch();
                break;
            }

        }
    }while(tasta!=0);
    return 0;
}
