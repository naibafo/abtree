#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "tuple.hpp"
#include "abtree.hpp"

using namespace std;


int main () {
	int k = 1;
	int m = 6;
	Tuple<int, int> first (k, m);
	
	Node< Tuple<int, int> > node1 (first);
	
	abTree< Tuple<int, int> > tree (node1);
	
	m=2;
	Tuple<int, int> second (m, k);
	
	m=3;
	Tuple<int, int> third (m, m);
	
	m=4;
	Tuple<int, int> fourth (m, m);
	
	tree.make_graph("test1.gv");
	
	tree.insert(second);
	
	tree.make_graph("test2.gv");
	
	tree.insert(third);
	
	tree.make_graph("test3.gv");
	
	tree.insert(fourth);
	
	tree.make_graph("test4.gv");
	
	
	
	
}
