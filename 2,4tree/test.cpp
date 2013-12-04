#include <iostream>
#include <cstdlib>
#include <vector>
#include "tuple.hpp"

using namespace std;

int main () {
	 
	int K = 3;
	int M = 2;
	Tuple <int, int> ab (K, M);
	
	vector< Tuple<int, int> > a;
	
	a.push_back(ab);	
	a.push_back(ab);	
	
	K = 1;
	M = 2;	
	
	Tuple <int, int> cd (K, M);
	cout << a[0] << endl;	
	cout << a[1] << endl;	
	cout << a[2] << endl;	
	
	int l =  a.size(); 
	
	cout << l << endl;
}
