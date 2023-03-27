#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>




#define PI 3.14159265358979323846




int dziedzina(double* wskPD, double* wskKD)
{
	int n=0;
	do {
		printf("\nPodaj pocz¹tek dziedziny: ");
		scanf("%lf", wskPD);
		printf("Podaj koniec dziedziny: ");
		scanf("%lf",wskKD);
		
		
		if (*wskPD > *wskKD)
		{
			printf("\nPocz¹tek funkcji nie mo¿e byæ wiêkszy od koñca!\n\n");
		}
	} while (*wskPD > *wskKD);
	int w;
	do
	{
		printf("\nCzy chcesz okreœliæ wielkoœæ tablic wynikowych?\n1 --> TAK\n0 --> NIE\n");
		scanf("%d", &w);
		if (w == 1)
		{
			printf("Podaj wiekoœæ tablicy: ");
			scanf("%d", &n);
		}
		else if (w == 0)
		{
			
			n = (*wskKD - *wskPD)*10;
			printf("\n\nTablice ustawiono domyœlnie\nWielkoœæ tablicy = %d\n\n", n);
		}
	} while (w != 0 && w != 1);

	return n;
}
void wspolczynniki(double tab[])
{
	
	printf("Acos(Bx + C)\n");
	printf("Podaj wspó³czynnik A: ");
	scanf("%lf", tab);
	
	printf("\nPodaj wspó³czynnik B: ");
	scanf("%lf", (tab+1));
	
	printf("\nPodaj wspó³czynnik C: ");
	scanf("%lf", (tab+2));

}
void funkcja_cos(int n, double ftab[], double wynik[],double min, double max)
{
	double x, w,jump;
	int k = 0;
	double cos(x);
	jump = (max - min) / n;

	for (k = 0; k < n; k++)
	{
		x = min + k * jump;
		w = *(ftab) * (cos(*(ftab + 1) * x + *(ftab + 2)));
		printf("%lf\n", w);
		*(wynik + k) = w;
		
	}
}
	void sygn_zakl(double wf[],double zakloconywynik[], int n)
	{
		double l;
		int a = 0,whi,whi2=0,j,i,u,tmp;
	
		srand(time(NULL));
		
		for (int h=0;h<=n;h++)
		{
			zakloconywynik[a] = wf[a];
			a++;
		}
		
		
		whi=rand() % 10;
		printf("\n%d\n", whi);
		do
		{
			j = rand()%n;
			u = rand()%n;

			if (u >= j)
			{

			}
			else
			{
				tmp=u;
				u = j;
				j = tmp;
			}
			
			for (i = j; i < u; i++)
			{
		
				l = rand() % 1;
				if (l == 0)
				{
					
					zakloconywynik[i] = (double)rand() * ((wf[i] + 0.2) - (wf[i] - 0.2)) / (double)RAND_MAX + (wf[i] - 0.2);


				}
				else
				{

					zakloconywynik[i] = wf[i];


				}
				
				whi2++;
			}
		}while(whi > whi2);
		a = 0;
		printf("\n\n\nZak³ócone wyniki:\n");
		for (int h = 0; h < n; h++)
		{
			printf("%lf\n",zakloconywynik[h]);
			
		}
		
	}
	void zapis(double zmien[],int n, int c,bool q)
	{
		
		FILE* plik;
		if (q == 0)
		{
			plik = fopen("plikinfa.CSV", "w");
			fclose(plik);
		}
		plik = fopen("plikinfa.CSV", "a");
		if (plik == NULL)
		{
			printf("Nie uda³o siê otworzyæ pliku.");
			exit(1);
		}
		fseek(plik, 1, SEEK_END);
		if (c==1)
		{
			fprintf(plik, "SYGNA£_NORMALNY:\n\n");
		}
		else if (c == 2)
		{
			fprintf(plik, "SYGNA£_ZAK£ÓCONY:\n\n");
		}
		else if (c == 3)
		{
			fprintf(plik, "SYGNA£_ODFILTROWANY_MEDIANOWO:\n\n");
		}
		else if (c == 4)
		{
			fprintf(plik, "SYGNA£_ODFLITROWANY_ŒREDNI¥:\n\n");
		}
		for (int i = 0; i < n; i++)
		{
			fprintf(plik, "%lf\n", zmien[i]);
			
		}
		
		fclose(plik);
	}

	double* rozmiartab(int n)
	{
		double* wynikif;
		
		wynikif = malloc(n * sizeof(double));

		return wynikif;
	}
	void odczyt()
	{
		char x[100];
		int i;
		FILE* plik1;
		plik1 = fopen("plikinfa.CSV", "r");
		if (plik1 == NULL)
		{
			printf("Nie uda³o siê otworzyæ pliku.");
			exit(1);
		}
		char tab[100];
		int licznik = 0;
		while (fscanf(plik1, "%s", tab) != EOF)
		{
			licznik++;
		}

		rewind(plik1);
		printf("\nOdczyt:\n\n");
		for(i=0;i<licznik;i++)
		{
			fscanf(plik1, "%s", &x);
		
			printf("%s\n", x);
		}
		rewind(plik1);
		fclose (plik1);

	}
	void sortmed(double szum[], double filtr[], int n)
	{
		int k, s = 0, h = 0, g = 2;
		double tab[5];
		
		
		filtr[0] = szum[0];
		filtr[1] = szum[1];
		filtr[n - 1] = szum[n - 1];
		filtr[n] = szum[n];
		
		int j;
		
		

		for (int a = 2; a <= n-2; a++)
		{
			
			h = 0;
			for (k = s; k <= s + 4; k++)
			{
				tab[h] = szum[k];
				h++;
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (tab[j] > tab[j + 1])
					{
						double temp;

						temp = tab[j];
						tab[j] = tab[j + 1];
						tab[j + 1] = temp;

					}
				}
			}
		
				s++;
				filtr[g] = tab[2];
				g++;
			
			
		}
			printf("\n(filtr medianowy)\nZfiltrowany sygna³:\n");
		for(j=0;j<=n;j++)
		{
			printf("%lf\n",filtr[j]);

		}
		
		
	}
	void sortsr(double szum[], double filtr[], int n)
	{
		int h,k,s=0;
		double wynik;
		double tab[5];


		filtr[0] = szum[0];
		filtr[1] = szum[1];
		filtr[n-1] = szum[n-1];
		filtr[n] = szum[n];

		for(int i = 2;i<=n-2;i++)
		{
			h = 0;
			for (k = s; k <= s + 4; k++)
			{
				tab[h] = szum[k];
				h++;
			}
			wynik = (tab[0] + tab[1] + tab[2] + tab[3] + tab[4]) / 5;
			filtr[i] = wynik;
			s++;
		}
		printf("\n(filtr œredniej ruchomej)\nZfiltrowany sygna³:\n");
		for (int j = 0; j <= n; j++)
		{
			printf("%lf\n", filtr[j]);

		}
	}
	void wyswietl(double tab1[], double tab2[], double tab3[], double tab4[],int n,bool f,bool z, bool r, bool m)
	{
		int a;
		do {
			printf("1 --> Wartoœci funkcji\n2 --> Wartoœci zak³ócone funkcji\n3 --> Wartoœci funkcji odfiltrowane œredni¹ ruchom¹\n4 --> Wartoœci funkcji odflitrowane medianowo\n5 --> Wyczyszczenie konsoli\n6 --> Wyjœcie\n\nPodaj funkcjê: ");
			scanf("%d", &a);
			
			switch (a)
			{
			case 1:
				if (f != 1)
				{
					printf("\nB£¥D! Nie wygenerowano funkcji\n\n");
					break;
				}
				for (int i = 0; i < n; i++)
				{
					printf("%lf\n", tab1[i]);
				}
				break;

			case 2:
				if (z != 1)
				{
					printf("\nB£¥D! Nie zak³ócono funkcji\n\n");
					break;
				}
				for (int i = 0; i < n; i++)
				{
					printf("%lf\n", tab2[i]);
				}
				break;
			case 3:
				if (r != 1)
				{
					printf("\nB£¥D! Nie odfiltrowano funkcji\n\n");
					break;
				}
				for (int i = 0; i < n; i++)
				{
					printf("%lf\n", tab3[i]);
				}
				break;
			case 4:
				if (m != 1)
				{
					printf("\nB£¥D! Nie odfiltrowano funkcji\n\n");
					break;
				}
				for (int i = 0; i < n; i++)
				{
					printf("%lf\n", tab4[i]);
				}
				break;
			case 5:
				system("cls");
				printf("Wyczyszczono konsolê\n\n");
			default:
				break;
			}
		} while (a != 6);

	}
	

	int main()
	{
		setlocale(LC_ALL, "polish_poland");
		int a = 0, i = 0, n = 0, wybor,b,c=0;

		bool w = 0, d = 0, f = 0, z = 0, m = 0, r = 0,q=0;
		double PD, KD;
		double tab[3];
		char litera = 'k';
		double* wynikifunkcji = NULL;
		double* wynikizakl = NULL;
		double* filtrmed = NULL;
		double* filtrsr = NULL;
		printf("PRZETWARZANIE SYGNA£ÓW\n\n");
		do
		{
			printf("\n1  --> Nadanie dziedziny funkcji\n2  --> Nadanie wspó³czynników funkcji\n3  --> Generowanie funkcji\n4  --> Zak³ócenie sygna³u funkcji\n5  --> Zapis funkcji w pliku .CSV\n6  --> Odczyt funkcji z pliku\n7  --> U¿ycie filtru medianowego na funkcji\n8  --> U¿ycie filtru œredniej ruchomej na funkcji\n9  --> Wyœwietlenie wartoœci funkcji\n10 --> Wyczyszczenie konsoli\n11 --> Wyjœcie z programu\n\nWybierz dzia³anie: ");
			
			do
			{
				scanf("%s", &litera);
				if (isdigit(litera) == 0)
				{
					printf("\nWybierz dzia³anie: \n");
				}
			} while (isdigit(litera) == 0);
			wybor = atoi(&litera);


			switch (wybor)
			{
			case 1:
				n = dziedzina(&PD, &KD);
				
				d = 1;
				break;
			case 2:
				wspolczynniki(tab);
				w = 1;
				break;
			case 3:
				if (d != 1)
				{
					printf("\nB£¥D! Funkcja nie posiada dziedziny\n\n");
					break;
				}
				if (w != 1)
				{
					printf("\nB£¥D! Funkcji nie nadano wspó³czynników\n\n");
					break;
				}
				wynikifunkcji = rozmiartab(n);
				funkcja_cos(n, tab, wynikifunkcji, PD, KD);
				f = 1;
				break;
			case 4:
				if (f != 1)
				{
					printf("\nB£¥D! Nie wygenerowano funkcji\n\n");
					break;
				}
				wynikizakl = rozmiartab(n);
				sygn_zakl(wynikifunkcji, wynikizakl, n);
				z = 1;
				break;
			case 5:
				
				
				
				do
				{
					printf("Któr¹ funkcjê chcesz zapisaæ:\n\n1 --> Normalne wyniki funkcji\n2 --> Zak³ócone wyniki funkcji\n3 --> Odfiltrowane wyniki funkcji filtrem medianowym\n4 --> Odfiltrowane wyniki funkcji filtrem œredniej ruchomej\n5 --> Wyczyszczenie konsoli\n6 --> Wyjœcie\nWybierz dzia³anie: ");
					scanf("%d", &b);
					switch (b)
					{
					case 1:
						if (f == 0)
						{
							printf("\nB£¥D! Nie wygenerowano funkcji\n\n");
							break;
						}
						c = 1;
						zapis(wynikifunkcji, n,c,q);
						q = 1;
						printf("\nPomyœlnie zapisano funkcjê\n\n");
						break;
					case 2:
						if (z == 0)
						{
							printf("\nB£¥D! Nie zak³ócono funkcji\n\n");
							break;
						}
						c = 2;
						zapis(wynikizakl, n,c,q);
						q = 1;
						printf("\nPomyœlnie zapisano funkcjê\n\n");
						break;
					case 3:
						if (m == 0)
						{
							printf("\nB£¥D! Nie odfiltrowano funkcji\n\n");
							break;
						}
						c = 3;
						zapis(filtrmed, n,c,q);
						q = 1;
						printf("\nPomyœlnie zapisano funkcjê\n\n");
						break;
					case 4:
						if (r == 0)
						{
							printf("\nB£¥D! Nie odfiltrowano funkcji\n\n");
							break;
						}
						c = 4;
						zapis(filtrsr, n,c,q);
						q = 1;
						printf("\nPomyœlnie zapisano funkcjê\n\n");
						break;
					case 5:
						system("cls");
						printf("Wyczyszczono konsolê\n\n");
						break;
					}
				}while (b != 6);

				
				break;
			case 6:
				if (q != 1)
				{
					printf("\nB£¥D! Nie zapisano ¿adnej funkcji\n\n");
					break;
				}
				odczyt();
				break;
			case 7:
				if (z != 1)
				{
					printf("\nB£¥D! Nie zak³ócono funkcji\n\n");
					break;
				}
				filtrmed = rozmiartab(n);
				sortmed(wynikizakl, filtrmed, n);
				m = 1;
				break;
			case 8:
				if (z != 1)
				{
					printf("\nB£¥D! Nie zak³ócono funkcji\n\n");
					break;
				}
				filtrsr = rozmiartab(n);
				sortsr(wynikizakl, filtrsr, n);
				r = 1;
				break;
			case 9:
				wyswietl(wynikifunkcji, wynikizakl, filtrsr, filtrmed, n, f, z, r, m);
				break;
			case 10:
				system("cls");
				printf("Wyczyszczono konsolê\n\n");
				break;
			case 11:
				printf("\nProgram stworzy³ Wiktor Witaszek\n");
				free(wynikifunkcji);
				free(wynikizakl);
				free(filtrmed);
				free(filtrsr);
				exit(69);
				break;
				default:
				printf("\nB£¥D! Podano nieprawid³ow¹ liczbê\n\n");
				break;
			}
		}while(wybor != 11);
		free(wynikifunkcji);
		free(wynikizakl);
		free(filtrmed);
		free(filtrsr);
		
		
		return 0;
	}