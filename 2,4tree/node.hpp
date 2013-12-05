#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


#define A 2
#define B 4 

using namespace std;

#ifndef abtreenode
#define abtreenode


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Node Class
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! This class is a node for the A,B tree. Recieves a template parameter T, wich referes to
 * the class of objects contained in each node. A vector of these objects will be stored in each 
 * node. 
 */
 
template <class T>
class Node {
	private:
////////////////////////////////////////////////////////////////////////////////////////////////////
/// Node Variables
////////////////////////////////////////////////////////////////////////////////////////////////////
	public:
		vector<Node*> childs; /// A vector of Node pointers, to the childs of these node.
		Node *father; /// A pointer to the father
		vector<T> keys; /// A vector of keys. To be contained in the node. They are unique
		

		int elements; /// A counter of the amount of keys stored in the Node.
		int id; /// A number to identify each Node. Used to print the tree.

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructors / Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////

		Node (T firstkey); //YA
		Node (T firstkey, Node &childs, Node &child2);
		~Node(); // YA

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Other functions
////////////////////////////////////////////////////////////////////////////////////////////////////

		bool is_leaf(); /// A function to know if the Node if a leaf.
		
		int get_elements(); /// A function to get the number of elements
		T get_key(int index); /// A function to get the key in the given index
		
////////////////////////////////////////////////////////////////////////////////////////////////////
/// Search Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

		bool search(T value); /// This function searchs for the given T value, in the node (ie. 
		Node* search_node(T value); /// This function searchs for the child Node, in wich you should find
		bool recursive_search(T value); /// Combined with search, and search_node, searchs recursively for a key in the node and childs.
		
		Node* get_father(); /// Returns a pointer to the father
		
		bool insert_key_leaf(T key); /// Inserts a key, when the Node is a leaf, and it has space
		bool set_father(Node *); /// Sets the father, to the given Node.
		
		Node* set_father(); /// Changes the father to the given one. Returns a pointer to the old father.
		bool set_child(Node *son);
		
		string node_id(); /// Returns a string with the name "node" appended to the id number.
		
		void write_node(ofstream &myfile); /// Writes the node for printing it in a .dot diagram 
		void write_node_id(std::ofstream&); /// Writes the node label for printing a .dot diagram

		void name_node(int ident); /// Changes the id number of the node.
		int get_id(); /// Returns the id number of the node
		
		
		/// Operator overloading for printing a node.
		template <class Y>
		friend ostream& operator<< (ostream &out, Node<Y> print_vec); 
		
		/// A function to parse int's to strings
		friend string int_to_string(int a);
		
		/// A function to make the DOT diagram for the subtree with the node as a root.
		void make_graph(const char* file);
};
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructors / Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// GET'S
////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// OTHERS
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Node<T> :: set_father(Node *newfather){
	if(this->father == NULL){
		this->father = newfather;
		
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

template<class T>
bool Node<T> :: set_child(Node *son){
	for(int i=0; i<this->elements+1; i++){
		if(this->childs[i] == NULL){
			this->childs[i] = son;
		}
	}
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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// SEARCHs
////////////////////////////////////////////////////////////////////////////////////////////////////


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
	int min;
	
	for(int i=0; i< this->elements; i++){
		if(this->keys[i] < value) {
			min = i;
		}
	}
	
	return (this->childs[min+1]);
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// DOT PRINTING FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void Node<T> :: name_node(int ident){
	this->id = ident;
}

template<class T>
int Node<T> :: get_id(){
	return this->id;
}

/// Parses the given int to string.
/// \param int a: int to parse
string int_to_string(int a){
	stringstream ss;
	ss << a;
	string str = ss.str();
	
	return str;
}

/*! Write_node_id: writes this in the code 
* \param ofstream &myfile: The oftream object with the loaded file to write.
* In resume writes something like this in the file:
* 	node(id) [label = "<f0> (tuple1) | <f1> (tuple2)  | <f2> (tuple3) "];
* That in dot languaje is the declaration of the node. Also (id) is substituded with the
* id number of the node, and (tuple#) is the value of the key's given.
*/
template<class T>
void Node<T> :: write_node_id(ofstream &myfile){
	string fst = "node";
	
	string nodeid;
	
	if(this->get_id() != -1218002944){
		nodeid = int_to_string(this->get_id());
	} else {
		int random_integer = rand(); 
		
		nodeid = int_to_string(random_integer);
		
		this->name_node( random_integer);
	}
	string tup1 = this->keys[0].toString();
	
	string tup2;
	if(elements > 1){
	 tup2 = this->keys[1].toString();
	} else {
	 tup2 = "";
	}
	
	string tup3;
	if(elements > 2){
	 tup3 = this->keys[2].toString();
	} else {
	 tup3 = "";
	}
	
	
	fst.append(nodeid);
	
	fst.append("[label = \"<f0> ");
	
	fst.append(tup1);
	
	fst.append("| <f1>");
	
	fst.append(tup2);
	
	fst.append("|<f2> ");
	
	fst.append(tup3);
	
	fst.append("\" ]; \n");
	
	
	myfile << fst;
	
	return;
}


/*! node_id()
 * Returns the name of the node, ie:
 * 	node(id).
 * \return A string with the name
*/
template<class T>
string Node<T> :: node_id(){
	string result =  "node";
	string str = int_to_string( this->id );
	
	result.append( str );
	
	return result;
}

/*! make_graph(const char* file)
 * Writes the code recursively for generating a DOT diagram for the subtree given by the node that
 * calls the function as a root.
 */
template <class T>
void Node<T> :: make_graph(const char* file){
	ofstream myfile;
	myfile.open (file);
	myfile << "graph tree { \n";
	
	myfile << "node [shape = record,height=.1]; \n";
	
	this->write_node_id(myfile);
	
	if( ! this->is_leaf() ){
		//Paso recursivo para escribir los nombres de los nodos hijos.
		for(int i=0; i < this->get_elements()+1; i++){
			(this->childs[i])->write_node_id(myfile);
		}
		// Luego los enlaces
		for(int i=0; i< this->get_elements()+1; i++){
			string name1 = this->node_id();
			string name2 = this->childs[i]->node_id();
			
			name2.append("\":f1; \n");
			
			string result = "\"";
			
			if(i==0){
				result.append(name1);
				
				result.append("\" :f0 -- \"");
			}
			if(i==1 || i==2){
				result.append(name1);
				
				result.append("\" :f1 -- \"");
			}
			
			if(i==3){
				result.append(name1);
				
				result.append("\" :f2 -- \"");
			}
			
			result.append(name2);
			
			myfile << result;
		}
		
		for(int i=0; i< this->get_elements()+1; i++){
			this->childs[i]->write_node(myfile);
		}
	}
	
	
	myfile << "\n }";
	myfile.close();
	return;
}


/*! write_node(ofstream &myfile)
 *  Writes recursively the declaration of each of the childs nodes, and the father-child relations
 * for this Node, and then does it recursively for its childs.
 */

template <class T>
void Node<T> :: write_node(ofstream &myfile){
	if( ! this->is_leaf() ){
		//Paso recursivo para escribir los nombres de los nodos hijos.
		for(int i=0; i < this->get_elements()+1; i++){
			(this->childs[i])->write_node_id(myfile);
		}
		// Luego los enlaces
		for(int i=0; i< this->get_elements()+1; i++){
			string name1 = this->node_id();
			string name2 = this->childs[i]->node_id();
			
			name2.append("\":f1; \n");
			
			string result = "\"";
			
			if(i==0){
				result.append(name1);
				
				result.append("\" :f0 -- \"");
			}
			if(i==1 || i==2){
				result.append(name1);
				
				result.append("\" :f1 -- \"");
			}
			
			if(i==3){
				result.append(name1);
				
				result.append("\" :f2 -- \"");
			}
			
			result.append(name2);
			
			myfile << result;
		}
		
		for(int i=0; i< this->get_elements()+1; i++){
			(this->childs[i])->write_node(myfile);
		}
	}
}

		



