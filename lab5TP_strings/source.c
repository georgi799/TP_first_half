#include<stdlib.h>
#include<stdio.h>
#include<string.h>



void extrage_pret(char linie[], char nume[], float *pret)
{
    char*cuvant=strtok(linie,",");
    strcpy(nume,cuvant);
    char *nr=strtok(NULL,",");
    *pret=atof(nr);

}


void sort(char nume[][20], int varsta[], int n) {
    char aux[20];
    int auxx;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(nume[i], nume[j]) > 0) {
                strcpy(aux, nume[i]);
                strcpy(nume[i], nume[j]);
                strcpy(nume[j], aux);
                auxx = varsta[i];
                varsta[i] = varsta[j];
                varsta[j] = auxx;

            }
        }
    }
}


void afisare(char cuv[][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("Nume[%d]= %s\n", i, cuv[i]);
    }
}

void citire(char cuv[][20]) {
    int n = 0;
    do {
        printf("nume[%d]= ", n);
        scanf("%20s", cuv[n]);


    } while (strcmp(cuv[n++], ".") != 0);
}


void count_v(char cuv[][20], int n) {
    int count = 0;
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        count = 0;
        for (int j = 0; j < strlen(cuv[i]); j++)
            if (strchr("AEIOUaeiou", cuv[i][j]) != NULL)
                count++;


        if (count > max)max = count;
    }
    printf("%d", max);
}


void ex1() {
    char cuv[100][20];
    int n = 0;
    int vocale;


    printf("Dati cuvinte pana la .\n");

    do {
        printf("C[%d]= ", n);
        scanf("%20s", cuv[n]);

    } while (strcmp(cuv[n++], ".") != 0);

    printf("Cuvintele sunt: \n");
    for (int i = 0; i < n - 1; i++) {
        printf("C[%d]= %s\n", i, cuv[i]);
    }
    count_v(cuv, n);
}


void ex2() {
    char nume[100][20];
    int varsta[100];
    int n = 0;
    int k = 0;
    int poz;

    printf("Dati nume si varsta pana la .");
    do {

        printf("Nume[%d]= \t", n);
        scanf("%20s", nume[n]);

        if (strcmp(nume[n], ".") == 0)
            break;

        printf("Varsta[%d]= ", n);
        scanf("%d", &varsta[n]);
        n++;

    } while (1);

    printf("Afisari: \n");
    for (int i = 0; i < n; i++) {
        printf("Nume[%d] = %s\t", i, nume[i]);
        printf("Varsta[%d]= %d\n", i, varsta[i]);
    }

    sort(nume, varsta, n);
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        printf("Nume[%d] = %s\t", i, nume[i]);
        printf("Varsta[%d]= %d\n", i, varsta[i]);
    }

}

void ex3() {
    char linie[100][200];
    int n = 0;

    printf("Dati linii:\n ");

    fgets(linie[0], sizeof(linie), stdin);

    while (1) {
        printf("Linie %d: ", n);
        fgets(linie[n], sizeof(linie), stdin);

        if (strcmp(linie[n], "\n") == 0)
            break;

        n++;
    }
    int i,j;
    for (i = 0, j = 1 ; j < n ; i++,j++) {
        int ok = 1;
        for (int z = 0; z < strlen(linie[j]); z++) {

            if (strchr(linie[i], linie[j][z]) == NULL) {
                printf("Nu s-a gasit intre linia %d si %d\n", i, j);
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            printf("Se afla intre %d si %d\n", i, j);
        }
    }


}

void ex4()
{
    char linie[100][200];

    int n=0;
    float pret[100];
    char produs[100][200];
    printf("Dati linii: ");
    fgets(linie[0], sizeof(linie), stdin);

    while(1)
    {
        printf("Linie %d= ", n);
        fgets(linie[n], sizeof(linie), stdin);

        if(strcmp(linie[n],"\n")==0)
            break;

        extrage_pret(linie[n], produs[n],&pret[n]);
    n++;
    }
    for(int i=0;i<n;i++){

        printf("%s\t", produs[i]);
        printf("%f", pret[i]);
        printf("\n");
    }
}

int main() {
    int tasta;

    do {
        printf("Dati exercitiul: ");
        scanf("%d", &tasta);

        switch (tasta) {

            case 0:
                exit(0);

            case 1: {
                ex1();
                break;
            }

            case 2: {
                ex2();
                break;
            }

            case 3: {
                ex3();
                break;
            }

            case 4:
            {
                ex4();
                break;
            }
        }

    } while (tasta != 0);
    return 0;
}