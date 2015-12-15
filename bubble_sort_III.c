//najwydajniejsza wersja algorytmu sortujacego metoda babelkowa,
//jaka udalo mi sie skonstruowac
//w mojej opinii zbudowany algorytm nie posiada juz opcji
//do dalszej optymalizacji
//program mysialby zostac oparty o bardziej wydajny algorytm sortujacy
//aby osiagnac lepsze wyniki
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int main(void)
{
    int temp, a, b, zamiana, licz;
    int liczby[MAX];
    srand(time(NULL));
    for(a=0; a<MAX; a++)
    {
        liczby[a]=rand()%(MAX*2)+1;
        printf("%d ", liczby[a]);
    }
    printf("\n\n");
    for(a=MAX-1;a>0;a--)
    {
        zamiana=0;
        for(b=0; b<a; b++)
            if(liczby[b]>liczby[b+1])
            {
                temp=liczby[b];
                liczby[b]=liczby[b+1];
                liczby[b+1]=temp;
                zamiana=1;
            }
        if(zamiana==0) break;
    }
    for(b=0;b<MAX;b++) printf("%d ", liczby[b]);
    printf("\nProgram wykonal %i przejsc.\n",MAX-a);
    return 0;
}
