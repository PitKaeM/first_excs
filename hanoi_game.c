#include<stdio.h>

int nmbr=0;

void hanoi(int n, int zrodlo, int cel)
{
    int posredni=6-(zrodlo+cel);
    if(n==1)
        printf("%3i: %i -> %i\n",nmbr+=1, zrodlo, cel);
    else
    {
        hanoi(n-1, zrodlo, posredni);
        hanoi(1, zrodlo, cel);
        hanoi(n-1, posredni, cel);
    }
}

int main(void)
{
    int n;
    printf("1 - Slupek poczatkowy\n2 - Slupek posredni\n3 - Slupek docelowy\n");
    printf("Podaj liczbe klockow do ulozenia:\n");
    scanf("%i", &n);
    if(n>0)
    {
        printf("Ruchy do wykonania:\n");
        hanoi(n, 1, 3);
    }
    else
    printf("Wartosc zabroniona\n");
    return 0;
}
