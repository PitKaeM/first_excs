#include <stdio.h>
#include <stdlib.h>

int *podaj_tab(int ilosc)
{
     int *wskaznik;
     int a;
     wskaznik=malloc(ilosc *sizeof(int));
     if(wskaznik==NULL) return NULL;
     for(a=0; a<ilosc; a++)
          *(wskaznik+a)=(2*a)+1;
     return wskaznik;
}
int main(void)
{
     int *tablica;
     int ilosc, i;
     printf("Podaj ilosc elementow tablicy:\n");
     scanf("%i", &ilosc);
     tablica=podaj_tab(ilosc);
     if(tablica)
     {
          printf("Zawartosc elementow tablicy:\n");
          for(i=0; i<ilosc; i++)
               printf("%2i: %i\n", i, *(tablica+i));
          free(tablica);
          tablica=NULL;
     }
     return 0;
}
