#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>
#include <math.h>
#include <iomanip>

using namespace std ;

template<class Type> 
void Swap( Type * leftItem, Type * rightItem ) {
	
	Type temp = *leftItem ;
	*leftItem = *rightItem ;
	*rightItem = temp ;
	
} // Basic::Swap()

void CreateFile( int begin, int end, int repeat ) ;
string IntToString( int num ) ;

int main() {
	
	CreateFile( 1, 5000, 0 ) ;
	
} // main()

void CreateFile( int begin, int end, int repeat ) {
	
	srand( time(0) ) ;
	
	vector<int> vv ;
	
	for ( int r = 0 ; r < repeat + 1 ; r++ ) {
		for ( int i = begin ; i < end + 1 ; i++ ) {
			vv.push_back( i ) ;
		} // for
	} // for	
	
	srand( time(0) ) ;
	
	int g = vv.size() + 1 ;
	
	for ( int i = 1 ; i < g ; i++ ) {
		int j = rand() % ( g - i ) + i ;
		Swap( &vv[j-1], &vv[i-1] ) ;
	} // for
	
	ofstream file( "input.txt" ) ;
	
	file << "Input" << "[" << begin << "-" << end << "]" << ( repeat != 0 ? "x" + IntToString( repeat + 1 ) : "" ) << endl ;
	
	for ( int i = 0 ; i < vv.size() ; i++ ) {
		cout << vv[i] << endl ;
		file << vv[i] << endl ;
	} // for
	
	cout << "size = " << vv.size() << endl ;
	
	file.close() ;
	
} // CreateFile()

string IntToString( int num ) { // ±NintÂà´«¦¨string
	
	string temp = "", temp2 = "" ;
	
	if ( num < 0 ) {
		num *= (-1) ;
		temp2 += '-' ;
	} // if	
	
	do {
		temp += (char)( num % 10 + '0' ) ;
		num /= 10 ;
	} while ( num != 0 ) ;
	
	for ( int i = temp.length() - 1 ; i >= 0 ; i-- )
		temp2 += temp[i] ;
	
	return temp2 ;
	
} // IntToString()
















