#include <iostream>
using namespace std;
template< typename T > void get( T a[], int n )
{
    std::cout << "enter " << n << " array elements: " ;
    for( int i = 0 ; i < n ; ++i ) std::cin >> a[i] ;
}

template< typename T > void sort( T a[], int n )
{
    for( int i=0 ; i<n ; ++i )
    {
        for( int j=i+1 ; j<n ; ++j )
        {
            if( a[j] < a[i] )
            {
                int temp = a[i] ;
                a[i] = a[j] ;
                a[j] = temp ;
            }
        }
    }
}

template< typename T > void display( const T a[], int n )
{
    std::cout << "the sorted array: " ;
    for( int i = 0 ; i < n ; ++i ) std::cout << a[i] << ' ' ;
    std::cout << '\n' ;
}

int main()
{
   // Demo<int> iFlag;
   // constexpr int N = 5 ;
    int array[5] = {0} ;

    display( array, 5 ) ;
    cout<<endl;
    get( array, 5 ) ;
    sort( array, 5 ) ;
    display( array, 5 ) ;
}
