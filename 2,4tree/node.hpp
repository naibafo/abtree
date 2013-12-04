#include <iostream>
#include <cstdlib>
#include <vector>

#define A 2
#define B 4 

using namespace std;

#ifndef abtreenode
#define abtreenode

template <class T>
class Node {
	private:
		vector<Node*> childs;
		Node *father;
		vector<T> keys;
		int elements;
		
		int id;
		
	public:
		Node (T firstkey); //YA
		Node (T firstkey, Node &childs, Node &child2);
		~Node(); // YA
		
		bool is_leaf();
		
		int get_elements(); //Ya
		T get_key(int index); //Ya
		
		
		bool search(T value); //YA
		Node* search_node(T value); //Ya
		bool recursive_search(T value); //Ya
		
		Node* get_father(); //Ya
		
		bool insert_key_leaf(T key); //Ya
		bool set_father(Node &); //Ya
		
		Node* set_child(); 
		Node* set_father();
		
		void write_node();
		void name_node(int ident);
		int id();
		
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
Node<T> :: Node (T firstkey, Node &child1, Node &child2) {
	this->elements = 1;

	this->father = NULL;
	
	this->keys.push_back(firstkey);
	
	this->childs.resize(2);
	
	this->childs[0] = &child1;
	
	this->childs[1] = &child2;
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
bool Node<T> :: is_leaf() {
	bool result = true;
	
	for (int i=0; i< this->elements+1; i++){
		if (this->childs[i] != NULL){
			result = false;
		}
	}
	
	return result;
}


template<class T>
bool Node<T> :: insert_key_leaf(T key){
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
		out << " " << print_vec.get_key(i) << " ";
	}
	
	out << "}";
	
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

template<class T>
bool Node<T> :: recursive_search(T value){
	if( search(value) ){
		return true;
	} else {
		if( this->is_leaf() ){
			return false;
		} else {
			return ((this->search_node(value))->recursive_search(value));
		}
	}
}

template<class T>
Node<T>* Node<T> :: search_node(T value){
	int max, min;
	
	for(int i=0; i< this->elements; i++){
		if(this->keys[i] < value) {
			min = i;
		}
	}
	cout << min << endl;
	
	return (this->childs[min+1]);
	
}

template<class T>
void Node<T> :: name_node(int ident){
	this->id = ident;
}

template<class T>
int Node<T> :: id(int ident){
	return this->id;
}







