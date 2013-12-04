#include <iostream>
#include <stdlib>
#include <cstdlib>
#include <vector>

#DEFINE A 2
#DEFINE B 4 

using namespace std;

#ifndef abtree
#define abtree

template <class T>
class Node {
	private:
		vector<Node*> childs;
		Node *father;
		vector<T> keys;
		int elements;
		
	public:
		Node (T firstkey); //YA
		~Node();
		int get_elements(); //Ya
		Node* search(T value); 
		Node* get_father(); //Ya
		bool set_child(); 
		bool insert_key(T key);
		bool set_father(Node &); //
};
#endif

template <class T>
Node<T> :: Node (T firstkey) {
	this->elements = 1;
	this->father = NULL;
	
}

template <class T>
Node<T> :: ~Node () {
}

template <class T>
int Node<T> :: get_elements(){
	return this->elements;
}

template<class T>
Node* Node<T> :: get_father(){
	return this->father;
} 

template<class T>
bool Node<T> :: set_father(Node &newfather){
	if(this->father == NULL){
		this->father = &newfather;
		
		return true;
	} else
		return false;
}

template<class T>
bool Node<T> :: insert_key(T key){
	if(this->elements < B){
		
	}
}
