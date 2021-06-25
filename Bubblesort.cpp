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


void bubblesort(int *t, int a, int b) // sortujemy tablice liczb calkowitych "t" na przedziale indeksow [a,b]
{
	REP(k,1,b-a) // robimy tyle obiegow wewnetrznej petli, ile wynosi dlugosc przedzialu, pomniejszona o jeden
	{
		REP(i,a,b-1)
		{
			if( t[i] > t[ i + 1 ] )
			{
				swap( t[i], t[ i + 1 ] );
			}
		}
	}	
}


void oblicz()
{
	bubblesort( t, 0, n - 1 );
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
