#include <iostream>
#include <cstdlib>


using namespace std;

#ifndef tuple
#define tuple

template <class T, class N>
class Tuple {
	public:
		T key;
		N object;
		bool empty;
		Tuple (T newKey, N object);
		Tuple ();
		Tuple (const Tuple &copy);
		~Tuple ();
		
		bool operator<(Tuple const &reference);
		bool operator>(Tuple const &reference);
		bool operator== (Tuple const &reference);
		
		template <class Y, class O>
		friend ostream& operator<< (ostream &out, Tuple<Y,O> print_vec);
};
#endif


template <class T, class N>
Tuple<T,N> :: Tuple (T newKey, N newObject){
	this->key = newKey;
	this->object = newObject;
	this->empty = false;
}

template <class T, class N>
Tuple<T,N> :: Tuple (){
	this->empty = true;
}

template <class T, class N>
Tuple<T,N> :: ~Tuple (){
}

template <class T, class N>
Tuple<T,N> :: Tuple (const Tuple &copy){
	this->key = copy.key;
	this->object = copy.object;
}

template <class T, class N>
bool Tuple<T,N> :: operator<(Tuple const &reference){
	return (this->key < reference.key);
}

template <class T, class N>
bool Tuple<T,N> :: operator>(Tuple const &reference){
	return (this->key > reference.key);
}

template <class T, class N>
bool Tuple<T,N> :: operator==(Tuple const &reference){
	return (this->key == reference.key);
}

template <class Y, class O>
ostream& operator<< (ostream &out, Tuple<Y,O> print_vec){
	
	out << "(" << print_vec.key << "," << print_vec.object << ")";
	
	return out;

}
