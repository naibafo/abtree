#include <iostream>
#include <cstdlib>
#include <vector>
#include "node.hpp"
#include <sstream>


#define A 2
#define B 4 

using namespace std;

#ifndef abtree
#define abtree

////////////////////////////////////////////////////////////////////////////////////////////////////
/// abTree class
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! Contains a rooted a,b Tree. For each tree, all the nodes are stored in a vector of nodes, (No order
 * needed). Then each node has the 
 */
template <class T>
class abTree {
	public:
////////////////////////////////////////////////////////////////////////////////////////////////////
/// Variables
////////////////////////////////////////////////////////////////////////////////////////////////////

		vector< Node<T> > nodes;
		Node<T>* root;
		int depth;
		
////////////////////////////////////////////////////////////////////////////////////////////////////
/// Functions
////////////////////////////////////////////////////////////////////////////////////////////////////
		
////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////

		abTree( Node<T> root); /// Creates a tree, with the given root Node.
		
////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods 
////////////////////////////////////////////////////////////////////////////////////////////////////

		bool insert (T key); /// Inserts the given value in the tree
		void make_graph(const char* file); /// Creates a DOT output file, for creating a DOT graph representing the tree
		bool search (T key); /// Searchs for the value in the tree, if it is contained in the tree, it returns true.


};
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
abTree<T> :: abTree( Node<T> root){
	this->nodes.push_back(root);
	this->depth = 0;
	this->root = &this->nodes[0];
	
	int i=0;
	this->nodes[0].name_node(i);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Insert
////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
bool abTree<T> :: insert( T value) {
	if (! this->search (value)){
		 
		if ( this->root->is_leaf() && (this->root->get_elements() < B-1)){
			return this->root->insert_key_leaf(value);
		} else {
			
			if( this->root->is_leaf() ){	
			
				this->root->keys.push_back(value);
				
				this->root->elements++;
				//We order the vector
				for(int i=1; i< this->root->elements; ++i) {
					for(int j=0; j< this->root->elements -i; j++) {
						if (this->root->keys[j] > this->root->keys[j+1]) {
							T temp = this->root->keys[j];
							this->root->keys[j] = this->root->keys[j+1];
							this->root->keys[j+1] = temp;
						}   
					}
				}
				
				//Now initialize two tuples in order to not loose them
				T newFather = this->root->keys[2];
				T newSon = this->root->keys[3];
				
				this->root->keys.pop_back();
				this->root->keys.pop_back();
				
				this->root->elements -= 2;
				
				Node<T> father (newFather);
				Node<T> son (newSon);
				
				this->nodes.push_back(father);
				
				this->nodes.push_back(son);
				
				
				this->root->set_father( &(this->nodes[1]));
				
				this->nodes[2].set_father( &(this->nodes[1]) );
			
				this->nodes[1].set_child( &(this->nodes[0] ));
				
				this->nodes[1].set_child( &(this->nodes[2]) );
				
				this->root = &this->nodes[1];
				
				return true; 

			}
			
			return false;
		} 
	} else {
		return false;
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Make Graph
////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void abTree<T> :: make_graph(const char* file){
	ofstream myfile;
	myfile.open (file);
	myfile << "graph tree { \n";
	
	myfile << "node [shape = record,height=.1]; \n";
	
	this->root->write_node_id(myfile);

	this->root->write_node(myfile);
	
	myfile << "\n }";
	myfile.close();
	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//// Search
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool abTree<T> :: search (T value) {
	return (this->root->recursive_search(value));
} 


