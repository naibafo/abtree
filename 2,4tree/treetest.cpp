#include <iostream>
#include <cstdlib>
#include <vector>
#include "node.hpp"
#include "tuple.hpp"
#include "abtree.hpp"

using namespace std;

int main () {
	int k = 1;
	int m = 2;
	Tuple<int, int> first (k, m);
	
	Tuple<int, int> second(m, k);
	
	m=3;
	Tuple<int, int> third (m, k);
	
	m=4;
	Tuple<int, int> fourth(m, k);

	m=5;
	Tuple<int, int> five  (m, k);
	
	

}
