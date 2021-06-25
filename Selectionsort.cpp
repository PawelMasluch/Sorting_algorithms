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


int index_min(int *t, int a, int b)
{
	int ind_min = a;
	
	REP(i,a+1,b)
	{
		if( t[i] < t[ ind_min ] )
		{
			ind_min = i;
		}
	}
	
	return ind_min;
}


void swap(int &a, int &b) // zamiana miejscami (w pamieci komputera) liczb calkowitych "a" oraz "b"
{
	int tmp = a;
	
	a = b;
	
	b = tmp;
}


void selection_sort(int *t, int a, int b) // sortujemy tablice liczb calkowitych "t" na przedziale indeksow [a,b]
{
	int ind_min;
	
	REP(i,a,b-1)
	{
		ind_min = index_min( t, i, b );
		
		swap( t[i], t[ ind_min ] );
	}	
}


void oblicz()
{
	selection_sort( t, 0, n - 1 );
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
