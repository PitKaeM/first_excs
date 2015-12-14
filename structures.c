#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Zesp {
     float Re;
     float Im;
};

void drukuj(struct Zesp Z)
     {printf("%.2f%+.2fi\n", Z.Re, Z.Im);}

struct Zesp dodaj(struct Zesp z1, struct Zesp z2)
{
     struct Zesp suma;
     suma.Re=z1.Re+z2.Re;
     suma.Im=z1.Im+z2.Im;
     return suma;
}
struct Zesp odejmij(struct Zesp z1, struct Zesp z2)
{
     struct Zesp roznica;
     roznica.Re=z1.Re-z2.Re;
     roznica.Im=z1.Im-z2.Im;
     return roznica;
}

struct Zesp mnozenie(struct Zesp z1, struct Zesp z2)
{
     struct Zesp mnoz;
     mnoz.Re=z1.Re*z2.Re-z1.Im*z2.Im;
     mnoz.Im=z1.Im*z2.Re+z1.Re*z2.Im;
     return mnoz;
}

struct Zesp dzielenie(struct Zesp z1, struct Zesp z2)
{
     struct Zesp dziel;
     float dzielnik;
     dzielnik=z2.Re*z2.Re+z2.Im*z2.Im;
     dziel.Re=(z1.Re*z2.Re+z1.Im*z2.Im)/dzielnik;
     dziel.Im=(z1.Im*z2.Re-z1.Re*z2.Im)/dzielnik;
     return dziel;
}

float modu(struct Zesp z1)
{
     float modul;
     modul=sqrt(z1.Re*z1.Re+z1.Im*z1.Im);
     return modul;
}

struct Zesp sprzez(struct Zesp z1)
{
     z1.Im=-1*z1.Im;
     return z1;
}

int main(void)
{
     struct Zesp suma, roznica, pomnoz, podziel, sprzezenie, z1, z2;
     float bezwzgledna;
     char znak;
     printf("Podaj pierwsza liczbe zespolona:\n");
     scanf("%f %fi", &z1.Re, &z1.Im);
     printf("Podaj druga liczbe zespolona:\n");
     scanf("%f %fi", &z2.Re, &z2.Im);
     printf("Suma podanych liczb: ");
     suma=dodaj(z1, z2);
     drukuj(suma);
     printf("Roznica: ");
     roznica=odejmij(z1, z2);
     drukuj(roznica);
     printf("Wynik pomnozenia tych liczb: ");
     pomnoz=mnozenie(z1, z2);
     drukuj(pomnoz);
     printf("Wynik podzielenia: ");
     podziel=dzielenie(z1, z2);
     drukuj(podziel);
     bezwzgledna=modu(z1);
     printf("Wartosc bezwzgledna pierwszej liczby: %.2f\n", bezwzgledna);
     printf("Sprzezenie pierwszej liczby: ");
     sprzezenie=sprzez(z1);
     drukuj(sprzezenie);
     return 0;
}
