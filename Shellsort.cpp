#include<cstdio>
#include<new>


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


int *t; // tablica liczb calkowitych

int n; // liczba elementow w tablicy "t"


void wczytaj() // wczytanie danych wejsciowych
{
	scanf( "%d", &n );
	
	t = new int [n];
	
	REP(i,0,n-1,1)
	{
		scanf( "%d", &t[i] );
	}
}


void swap(int &a, int &b) // zamiana miejscami (w pamieci komputera) liczb calkowitych "a" oraz "b"
{
	int tmp = a;
	
	a = b;
	
	b = tmp;
}


int h(int n) // wyznaczenie pierwszego odstepu w ciagu odstepow, dla sortowania Shella ; n - dlugosc ciagu do posortowania
{
	int wyn = 1;
	
	while( wyn < n )
	{
		wyn = 3*wyn + 1;
	}
	
	wyn /= 9;
	
	if( wyn == 0 )
	{
		++wyn;
	}
	
	return wyn;
}


void insertionsort(int *t, int a, int b, int h) // sortujemy tablice liczb calkowitych "t" na przedziale indeksow [a,b], startujemy od indeksu "a", kazdy nastepny indeks wiekszy o " h"
{
	int ind, val;
	
	REP(i,a,a+h-1,1) // kazdy poczatek podciagu
	{
		REP(j,i,b,h) // sortujemy dany podciag przez wstawianie ; szukamy miejsca dla elementu t[j]
		{
			val = t[j];
			
			ind = j - h;
			
			while( ind >= i  &&  t[ ind ] > val )
			{
				swap( t[ ind ], t[ ind + h ] );
				
				ind -= h;
			}
			
			ind += h;
			
			t[ ind ] = val;
		}
	}		
}


void Shellsort(int *t, int a, int b) // sortujemy tablice liczb calkowitych "t" na przedziale indeksow [a,b]
{
	int H = h( b - a + 1 ); // pierwszy odstep w ciagu odstepow
	
	while( H > 0 )
	{
		insertionsort( t, a, b, H );
		
		H /= 3;
	}		
}


void oblicz()
{
	Shellsort( t, 0, n - 1 );
}


void wypisz()
{
	REP(i,0,n-1,1)
	{
		printf( "%d ", t[i] );
	}
	
	printf( "\n" );
	
	delete [] t;
}


void solve()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	solve();
	
	return 0;
}


/*

Test 1:
5
7 4 8 1 6

Test 2:
8
89 73 -728 93 -384 -28 83478 -99

Test 3:
8
9 7 64 7 -18 9 -48 6

Test 4:
10
7 6 3 1 9 1 5 1 9 7

Test 5:
7
489 485 -394 -3948 38 -9000 -3847348



*/
