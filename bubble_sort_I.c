#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int main(void)
{
    int temp, a, b;
    int liczby[MAX];
    srand(time(NULL));
    for(a=0; a<MAX; a++)
    {
        liczby[a]=rand()%(MAX*2)+1;
        //printf("%d ", liczby[a]);
    }
    //printf("\n\n");
    for(a=0;a<MAX-1;a++)
        for(b=0; b<MAX-1; b++)
            if(liczby[b]>liczby[b+1])
            {
                temp=liczby[b];
                liczby[b]=liczby[b+1];
                liczby[b+1]=temp;
            }
    //for(b=0;b<MAX;b++) printf("%d ", liczby[b]);
    printf("\nProgram wykonal %i przejsc.\n",a);
    return 0;
}
