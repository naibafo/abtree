#include <iostream>
#include <cstdlib>
#include <vector>
#include "tuple.hpp"
#include "abtree.hpp"

using namespace std;

int main () {
	int k = 9;
	int m = 6;
	Tuple<int, int> first (k, m);
	
	Node< Tuple<int, int> > node1 (first);

	node1.name_node(k);
	cout << node1 << endl;
	
	Tuple<int, int> second (m, k);
	
	bool lol = node1.insert_key_leaf(second);
	
	cout << node1 << endl;
	
	m=7;
	
	Tuple<int, int> third (m, k);
	
	lol = node1.insert_key_leaf(third);
	
	cout << node1 << endl;
	
	
	m=333;
	
	Tuple<int, int> fourth (m, k);

	Node< Tuple<int, int> > node2 (fourth);
	node2.id = 222;
	
	m=15;
	
	Tuple<int, int> five (m, k);
	
	Node< Tuple<int, int> > node3 (five, node1, node2);
	m=1000;
	node2.name_node(m);

	abTree< Tuple<int, int> > tree (node3);
	
	tree.make_graph("test.gv");
	
	
	m=150;
	
	Tuple<int, int> ten (m, k);
	
	bool isit = tree.search(five);
	
	cout << isit << endl;
	
	isit = tree.search(ten);
	
	cout << isit << endl;
}

