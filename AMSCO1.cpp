#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>


using namespace std;

#define MAXK 33
#define MAXN 2222
char arr[MAXK] , barr[MAXN] ;
char carr[MAXK][MAXN] ;

int klenn , tlenn, flagg;

int main( )
{
	freopen("Text/AMSCO1.txt","r",stdin);


	int i , j , k , l ;

	while( scanf("%s %s",arr,barr)!=EOF )
	{
		klenn = strlen( arr ) ;
		tlenn = strlen( barr ) ;


		for( i = 0 ; i < klenn ; i++ )
		{
			carr[i][0] = '\0' ;
		}

		for( i = k = 0 , flagg = 2 ; k < klenn && i < tlenn ; k++ )
		{
			l = 0 ;
			while( carr[k][l] != '\0' )
			{
				l++ ;
			}

			for( j = 0 ; j < flagg ; j++ )
			{
				carr[k][l++] = barr[i++] ;

				if( i == tlenn )
				{
					break ;
				}
			}

			carr[k][l] = '\0' ;

			flagg^=3;

			if( k == klenn - 1 )
			{
				k = -1 ;
			}
		}


		for( i = 1 ; i <= klenn ; i++ )
		{
			j = 0 ;

			while( i != ( int ) ( arr[j] - 48 ) )
			{
				j++ ;
			}

			for( k = 0 ; carr[j][k] != '\0' ; k++ )
			{
				printf("%c",carr[j][k]) ;
			}
		}
		printf("\n") ;
	}

	return 0 ;
}
