#include <iostream>
#include <cstdlib>
#include <vector>
#include "node.hpp"
#include "tuple.hpp"

using namespace std;

int main () {
	int k = 9;
	int m = 6;
	Tuple<int, int> first (k, m);
	
	Node< Tuple<int, int> > node1 (first);

	cout << node1 << endl;
	
	Tuple<int, int> second (m, k);
	
	bool lol = node1.insert_key(second);
	
	cout << node1 << endl;
	
	m=7;
	
	Tuple<int, int> third (m, k);
	
	lol = node1.insert_key(third);
	
	cout << node1 << endl;
	
	
	m=1;
	
	Tuple<int, int> fourth (m, k);

	Node< Tuple<int, int> > node2 (fourth);
	
	m=15;
	
	Tuple<int, int> five (m, k);

}

