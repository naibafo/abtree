#include <iostream>
#include <cstdlib>
#include <vector>
#include "node.hpp"

#define A 2
#define B 4 

using namespace std;

#ifndef abtree
#define abtree

template <class T>
class abTree {
	public:
		vector< Node<T> > nodes;
		Node<T>* root;
		int depth;
		
		abTree( Node<T> root);
		void insert (T key);
		void make_graph(const char* file);
		bool search (T key);
};
#endif

template <class T>
abTree<T> :: abTree( Node<T> root){
	this->nodes.push_back(root);
	this->depth = 0;
	this->root = this->nodes[0];
	
	int i=0;
	this->nodes[0].name_node(i);
}

template <class T>
abTree<T> :: insert( T value) {

}

template <class T>
void abTree<T> :: make_graph(const char* file){
	ofstream myfile;
	myfile.open (file);
	myfile << "graph { \n";
	
	myfile << "node [shape = record,height=.1]; \n";
	
	for(int i=0; i < this->root.get_elements()+1; i++){
		
	}
	// Aqui llamar el que es para cada nodo, recursivo.
	myfile << "\n }";
	myfile.close();
	return;
}

template <class T>
bool abTree<T> :: search (T value) {
	return (this->root->recursive_search(value));
} 


