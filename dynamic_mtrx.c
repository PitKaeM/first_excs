#include<stdio.h>
#include<stdlib.h>

int **tworz_tab(int n)
{
     int x, y;
     int **tab=malloc(n*sizeof(int*));
     if(tab==NULL) return NULL;
     for(x=0; x<n; x++)
     {
          tab[x]=malloc(n*sizeof(int));
          if(tab[x]==NULL) return NULL;
          for(y=0; y<n; y++)
               tab[x][y]=(x+1)*(y+1);
     }
     return tab;
}

int main(void)
{
     int **tab;
     int wymiar;
     int x, y;
     printf("Podaj wymiar tablicy kwadratowej: ");
     scanf("%i", &wymiar);
     tab=tworz_tab(wymiar);
     if(tab!=NULL)
     {
          for(x=0; x<wymiar; x++)
          {
               for(y=0; y<wymiar; y++) printf("%4i", tab[x][y]);
               printf("\n");
          }
          free(tab);
          tab=NULL;
     }
     free(tab);
     tab=NULL;
     return 0;
}
