#include<cstdio>
#include<new>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int *t; // tablica liczb calkowitych

int n; // liczba elementow w tablicy "t"


void wczytaj() // wczytanie danych wejsciowych
{
	scanf( "%d", &n );
	
	t = new int [n];
	
	REP(i,0,n-1)
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


void quicksort(int *t, int a, int b) // sortujemy tablice liczb calkowitych "t" na przedziale indeksow [a,b]
{
	if( b - a + 1 >= 2 ) // jesli liczba elementow do sortowania wynosi co najmniej 2
	{
		int i = a + 1;
		
		int j = b;
		
		int pivot = t[a];
		
		while( i <= j )
		{
			while( i <= b  &&  t[i] <= pivot )
			{
				++i;
			}
			
			while( j >= a + 1  &&  t[j] > pivot )
			{
				--j;
			}
			
			if( i < j )
			{
				swap( t[i], t[j] );
				
				++i;
				
				--j;
			}
		}
		
		--i; // teraz indeks "i" oznacza miejsce, gdzie w wynikowej tablicy znajdzie sie "pivot"
		
		swap( t[a], t[i] ); // teraz pivot, czyli t[a], jest na pozycji "i"
		
		quicksort( t, a, i - 1 ); // wywolujemy sie rekurencyjnie dla lewej czesci
		
		quicksort( t, i + 1, b ); // wywolujemy sie rekurencyjnie dla prawej czesci
	}
}


void oblicz()
{
	quicksort( t, 0, n - 1 );
}


void wypisz()
{
	REP(i,0,n-1)
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



*/
