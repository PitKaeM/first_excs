#include<stdio.h>
#include<stdlib.h>
#define ROW 4
#define COL 4

int main(void)
{
    int liczby[ROW][COL]={
    {3,4,12,10},
    {6,7,9,4},
    {20,8,30,3},
    {3,15,16,3}
    };
    int *place[7];
    int nmin;
    int a, b, ilosc=0;
    //srand(time(NULL));
    /*for(a=0;a<ROW;a++)
        for(b=0;b<COL;b++)
            liczby[a][b]=rand();
    */
    nmin=liczby[0][0];
    for(a=0;a<ROW;a++)
    {
        for(b=0;b<COL;b++)
        {
            if(liczby[a][b]<nmin)
            {
                nmin=liczby[a][b];
                ilosc=1;
                place[0]=&liczby[a][b];
                //printf("")
            } else if(liczby[a][b]==nmin)
            {
            place[ilosc]=&liczby[a][b];
            ilosc++;
            }
            printf("%4i",liczby[a][b]);
        }
        putchar('\n');
    }
    printf("Najmniejsza liczba tej macierzy to %i, jest ich %i\nIch indeksy:",nmin, ilosc);
    for(a=0;a<ilosc;a++) printf(" %6p ",place[a]);
    return 0;
}
