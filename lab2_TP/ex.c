#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

void citire(int *v, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("v[%d]= ", i);
        scanf("%d", v+i);
    }
}

void afisare(int *v, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nv[%d]= %d ", i, *(v+i));
    }
}

void ex1(){
//    Se cere de la tastatură un întreg 0<n<=100, iar apoi n valori reale.
//    Se cere să se elimine toate duplicatele și să se afișeze valorile rămase.

int n;
int *v;


printf("Dati n: ");
scanf("%d", &n);

    if(n<0||n>100)
    {
        printf("\nValoare invalida. Va rog dati in intervalul [1,100]");
    }
    v=(int*)malloc(sizeof(int)*n);
    printf("\nDati valori: \n");
    for(int i=0;i<n;i++)
    {
        printf("v[%d]= ", i);
        scanf("%d", v+i);
    }
    //cautam duplicate
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(*(v+i)==*(v+j))
            {
                printf("Am gasit duplicate pe indexul: %d si %d, elementul: %d \n", i, j, *(v+i));
            }
        }
    }


}

void ex2()
{
//    Se cer de la tastatură maxim 100 valori întregi, până la întâlnirea valorii 0, care nu va face parte din șirul introdus.
//    Se cere să se extragă în două tablouri diferite valorile pare și cele impare, iar apoi să se afișeze fiecare dintre aceste tablouri
//    în ordine inversă.

    int n=0;
    int np=0;
    int ni=0;
    int *v;
    int *vp;
    int *vi;

    v=(int*)malloc(sizeof(int)*n);

   printf("Dati valori pana la 0: ");
    while(n<MAX)
    {

        printf("v[%d]= ", n);
        scanf("%d", v+n);
        if(*(v+n)==0)break;


        n++;
    }
    np=ni=0;
    vi=(int*)malloc(sizeof(int)*ni);
    vp=(int*)malloc(sizeof(int)*np);

    for(int i=0;i<n;i++)
    {
        if(*(v+i)%2==0)*(vp+np++)=*(v+i);
        else *(vi+ni++)=*(v+i);
    }

    //afisari
//    for(int i=0;i<n;i++)
//    {
//        printf("\nv[%d]= %d ", i, *(v+i));
//    }


    printf("Ordine originala ale celor 3 vectori: ");
    afisare(v,n);
    printf("\n");
    afisare(vp,np);
    printf("\n");
    afisare(vi,ni);

}

void ex3()
{
//    Se cere de la tastatură un întreg 0<n<=10, iar apoi n valori întregi.
//    Apoi se cere un întreg 0<m<=10, iar apoi m valori întregi.
//    În final se cere în întreg 0<=pos<=10.
//    Se cere să se insereze prima serie de valori în interiorul celei de a doua serii,
//    începând de la poziția pos și să se afișeze seria rezultată.

    int n;
    int *v;
    int *v2;
    int m;

    printf("Dati n: ");
    scanf("%d", &n); //size of v1

    v=(int*)malloc(sizeof(int)*n);  //alocare memorie primul vector

    printf("\nDati valori: \n"); //valori v1
    for(int i=0;i<n;i++)
    {
        printf("v[%d]= ", i);
        scanf("%d", v+i);
    }
    printf("\n Dati m: ");
    scanf("%d", &m);  //size of v2

    v2=(int*)malloc(sizeof(int)*m); //alocare memorie v2

    printf("\n Dati valori pentru al doilea vector: "); //valori v2

    for(int j=0;j<m;j++)
    {
        printf("v2[%d]= ", m);
        scanf("%d", v2+j);
    }

    afisare(v,n);
    printf("\n");
    afisare(v2,m);

    int poz;
    int aux;

    printf("Dati pozitia: ");
    scanf("%d", &poz);
    aux=poz;

    for(int i=0;i<n;i++)
    {
        *(v2+poz++)=*(v+i);
    }
    m=m+aux;

    printf("\n");
    afisare(v2,m);
}

void ex4()
{
//    Se cere de la tastatură un întreg 0<n<=10, iar apoi n valori întregi distincte.
//    Apoi se cere un întreg 0<m<=10, iar apoi m valori întregi distincte. Pornind de la cele două serii se cere să se afișeze:
//    Reuniunea lor - toate elementele care există cel puțin într-o serie, luate câte o singură dată
//    Intersecția lor - toate elementele comune

    int n;
    int *v;

    printf("Dati n: ");
    scanf("%d", &n);
    v=(int*)malloc(sizeof(int)*n);
    citire(v,n);


    int m;
    int *v2;

    printf("Dati m: ");
    scanf("%d", &m);
    v2=(int*)malloc(sizeof(int)*m);
    citire(v2,m);

    printf("Vectorii sunt: ");
    afisare(v,n);
    printf("\n");
    afisare(v2,m);
    printf("\n");
    printf("Reuniune: \n");

    int poz=n;
    int aux=poz;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++){
           if(*(v2+j)==*(v+i))
           {

               continue;


           }
           *(v+poz++)=*(v2+j);



       }
    }
    n=n+aux;
    afisare(v,n);



}

void swap(char nume[][20], int *varsta, int n )
{
    char aux[20];
    int auxx;

    for(int i=0;i<n-1;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            if(strcmp(nume[i], nume[j])>0){
                strcpy(aux, nume[i]);
                strcpy(nume[i],nume[j]);
                strcpy(nume[j],aux);
                auxx=varsta[i];
                varsta[i]=varsta[j];
                varsta[j]=auxx;
            }
        }
    }
}
void afisaree(char nume[][20], int *varsta, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Nume[%d]= %s \t", i, nume[i]);
        printf("Varsta[%d]= %d\n", i, varsta[i]);

    }
}

void ex5()
{
    char nume[100][20];
    int varsta[100];
    int n=0;

    do
    {
        printf("Nume[%d]= ", n);
        scanf("%s", nume[n]);
        if(strcmp(nume[n], ".")==0)break;
        printf("Varsta[%d]= ", n);
        scanf("%d", &varsta[n]);
        n++;

    }while(1);

    printf("\n");
    afisaree(nume,varsta,n);
    swap(nume,varsta,n);
    printf("\n\n");
    afisaree(nume,varsta,n); //varsta si nume fiind array nu trebuie pasati prin adresa (&)
    int prima;
    for(int i=0;i<n;i++)
    {
        prima=varsta[0];
    }
    printf("Varsta a persoanei prime alfabetic este: %d", prima);





}



int main()
{
    int tasta;

    do {
    printf("Alegeti exercitiul dorit: ");
    scanf("%d", &tasta);


        switch(tasta)
        {
            case 0: exit(0);
            case 1: {
                ex1();
                break;
            }
            case 2: {
                ex2(); break;
            }
            case 3: {
                ex3(); break;
            }
            case 4:
            {
                ex4();break;
            }

            case 5: {
                ex5();
                break;
            }
        }

    }while(tasta!=0);
    return 0;

}