//Program symulujacy klasyczna gre w kolko-krzyzyk.
//Poza funkcja glowna, program zawiera 5 funkcji odpowiedzialnych za zerowanie,
//wyswietlanie tablicy, obsluge ruchow graczy oraz sprawdzanie stanu gry.
//Jest tez funkcja wyboru trybu gry oraz funkcja ruchu komputera.
//Wszystkie uzyte funkcje operuja na tablicy zadeklarowanej globalnie.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char gamemtrx[3][3];

void clr_matrix(void)            //funkcja wypelniajaca tablice gry spacjami
{
   int x, y;
   for(x=0; x<3; x++)
      for(y=0; y<3; y++)
         gamemtrx[x][y]=' ';
}

void show_matrix(void)           //funkcja wyswietlajaca zawartosc tablicy
{
   int x, y;
   putchar('\n');
   for(x=0; x<3; x++)
   {
      for(y=0; y<3; y++)
      {
         printf(" %c ", gamemtrx[x][y]);
         if(y<2) putchar('|');
      }
      putchar('\n');
      if(x<2) printf("---|---|---\n");
   }
   putchar('\n');
}

int select_opponent(void)        //funkcja wyboru tryby rozgrywki(wybor przeciwnika)
{
   int choice;
   printf("Wybierz przeciwnika:\n");
   printf("wprowadz 'a' dla gry dwuosobowej,\n");
   printf("wprowadz 'b' dla gry z komputerem,\n");
   printf("aby zatwierdzic nacisnij Enter.\n");
   choice=getchar();
   while(choice<'a'||choice>'b')
   {
      while(getchar()!='\n')
         continue;
      printf("Prosze wprowadzic a lub b, po czym nacisnac Enter: ");
      choice=getchar();
   }
   while(getchar()!='\n')
         continue;
   return choice;
}

void plr1_turn(void)             //funkcja obslugujaca ruch gracza pierwszego
{
   int a, b;
   printf("Ruch gracza nr 1. ");
   printf("Podaj wspolrzedne Twojego ruchu: ");
   scanf("%i %i", &a, &b);
   while(((a||b)<1||(a||b)>3)||gamemtrx[a-1][b-1]!=' ')
   {
      printf("Podales nieprawidlowe dane, sproboj ponownie: ");
      scanf("%i %i", &a, &b);
   }
   gamemtrx[a-1][b-1]='x';
}

void plr2_turn(void)             //funkcja obslugujaca ruch gracza drugiego
{
   int a, b;
   printf("Ruch gracza nr 2. ");
   printf("Podaj wspolrzedne Twojego ruchu: ");
   scanf("%i %i", &a, &b);
   while(((a||b)<1||(a||b)>3)||gamemtrx[a-1][b-1]!=' ')
   {
      printf("Podales nieprawidlowe dane, sproboj ponownie: ");
      scanf("%i %i", &a, &b);
   }
   gamemtrx[a-1][b-1]='o';
}

void comp_turn(void)             //funkcja ruchu komputera (algorytm losowy)
{
   int a, b, seed;
   seed=time(NULL);
   srand(seed);
   printf("Ruch komputera.");
   a=rand()%3;
   b=rand()%3;
   while(gamemtrx[a][b]!=' ')
   {
      a=rand()%3;
      b=rand()%3;
   }
   gamemtrx[a][b]='o';
}

int check_game(void)             //funkcja sprawdzajaca czy jest zwuciezca
{
   int x, y;
   //spradza rzedy
   for(x=0; x<3; x++)
      if(gamemtrx[x][0]==gamemtrx[x][1]&&gamemtrx[x][0]==gamemtrx[x][2]&&gamemtrx[x][0]!=' ')
         if(gamemtrx[x][0]=='x')
            return 1;
         else return 2;
   //sprawdza kolumny
   for(y=0; y<3; y++)
      if(gamemtrx[0][y]==gamemtrx[1][y]&&gamemtrx[0][y]==gamemtrx[2][y]&&gamemtrx[0][y]!=' ')
         if(gamemtrx[0][y]=='x')
            return 1;
         else return 2;
   //sprawdza skosy
   if(gamemtrx[0][0]==gamemtrx[1][1]&&gamemtrx[0][0]==gamemtrx[2][2]&&gamemtrx[0][0]!=' ')
      if(gamemtrx[0][0]=='x')
         return 1;
      else return 2;
   if(gamemtrx[2][0]==gamemtrx[1][1]&&gamemtrx[2][0]==gamemtrx[0][2]&&gamemtrx[2][0]!=' ')
      if(gamemtrx[2][0]=='x')
         return 1;
      else return 2;
   //brak zwyciezcy
   return 0;
}

int main(void)
{
   int check, moves, game=1, mode;

   clr_matrix();                          //czesc wstepna, tekst powitalny oraz instrukcja
   printf("\t\tWitam w grze kolko-krzyzyk!\n\n");
   printf("Aby postwic znak nalezy podac wspolrzedne pustej komorki, z zakresu od 1 do 3.\n");
   printf("Na przyklad, wpisanie 1 2 postawi znak w drugiej kolumnie pierwszego rzedu:\n");
   gamemtrx[0][1]='#';
   show_matrix();

   while(game)                            //petla odpowiedzialna za cykl gry, nastepuje w niej
   {                                      //wybor trybu, wlasciwa obsluga gry oraz informacja
      mode=select_opponent();             //o mozliwosci ropoczecia gry od nowa lub zakonczeniu
      if(mode=='a')
      {
         printf("\nWybrano tryb dwuosobowy.\n");
         printf("Gracz nr 1. stawia krzyzyki, gracz nr 2. stawia kolka.\n");
      } else {
         printf("\nWybrano tryb gry z komputerem.\n");
         printf("Gracz nr 1. stawia krzyzyki, komputer stawia kolka.\n");
      }
      check=0;
      moves=1;
      clr_matrix();
      show_matrix();
      while(!check&&moves<=9)             //algorytm gry kolko-krzyzyk
      {
         if(moves%2)
            plr1_turn();
         else
            if(mode=='a')
               plr2_turn();
            else
               comp_turn();
         moves++;
         show_matrix();
         check=check_game();
      }
      if(check==1)
         printf("\t!Wygrywa gracz nr 1!\n");
      else if(check==2)
         printf("\t!Wygrywa gracz nr 2!\n");
      else
         printf("\t!Remis!\n");
      show_matrix();
      printf("Aby zagrac ponownie wpisz 1 i nacisnij Enter, wpisz 0 (zero) aby zakonczyc program.\n");
      scanf("%i", & game);                //zapytanie o chec ponownej gry
   }
   return 0;
}

