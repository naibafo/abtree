#include <iostream>
#include <cstdlib>
#include <vector>

#define A 2
#define B 4 

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
		~Node(); // YA
		
		int get_elements(); //Ya
		T get_key(int index); //Ya
		bool search(T value); 
		Node* get_father(); //Ya
		bool set_child(); 
		bool insert_key(T key); //Maso
		bool set_father(Node &); //Maso
		
		template <class Y>
		friend ostream& operator<< (ostream &out, Node<Y> print_vec);
};
#endif

template <class T>
Node<T> :: Node (T firstkey) {
	this->elements = 1;

	this->father = NULL;
	
	this->keys.push_back(firstkey);
	
	this->childs.resize(2);
	
	for(int i=0; i<2; i++){
		this->childs[i] = NULL;
	}
}

template <class T>
Node<T> :: ~Node () {
}

template <class T>
T Node<T> ::get_key(int index){
	return this->keys[index];
}

template <class T>
int Node<T> :: get_elements(){
	return this->elements;
}

template<class T>
Node<T>* Node<T> :: get_father(){
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
	if((this->elements < B-1) &&  !(this->search(key))){
		
		this->elements++;
		
		this->keys.push_back(key);
		
		this->childs.resize(this->elements+1);
	
		for(int i=0; i<this->elements+1; i++){
			this->childs[i] = NULL;
		}
		
		for(int i=1; i<this->elements; ++i) {
			for(int j=0; j<this->elements-i; j++) {
				if (this->keys[j] > this->keys[j+1]) {
					T temp = this->keys[j];
					this->keys[j] = this->keys[j+1];
					this->keys[j+1] = temp;
				}   
			}
		}
		
		return true;		
	} else
		return false;
}

template <class Y>
ostream& operator<< (ostream &out, Node<Y> print_vec){	
	out << "{ ";
	
	for(int i=0; i<print_vec.get_elements() ; i++){
		out << "-" << print_vec.get_key(i) << "-";
	}
	
	out << ")";
	
	return out;

}

template<class T>
bool Node<T> :: search(T value) {
	
	bool result = false;
	
	for(int i=0; i<this->elements; i++){
		if( this->keys[i] == value ){
			result = true;
		}
	}
	
	return result;
}
