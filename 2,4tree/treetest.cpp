#include <iostream>
#include <cstdlib>
#include <vector>
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
	
	Node < Tuple<int, int> > root ( first );
	
	abTree< Tuple<int, int> > tree ( first );

	tree.make_graph("mygraph.gv");
	
	tree.insert(second);
	
	tree.make_graph("mygraph1.gv");
	
	tree.insert(third);

	tree.make_graph("mygraph2.gv");
}
