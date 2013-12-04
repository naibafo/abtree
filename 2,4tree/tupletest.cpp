#include "tuple.hpp"

int main () {
	int key1, key2;
	double obj1, obj2;
	
	cout << "Insert key1 ";
	cin >> key1;
	
	cout << "\n Insert key2 ";
	cin >> key2;
	
	cout << "\n Insert obj1 ";
	cin >> obj1;
	
	cout << "\n Insert obj2 ";
	cin >> obj2;
	
	cout << endl;
	
	Tuple<int, double> a (key1, obj1);
	Tuple<int, double> b (key2, obj2);
	
	if(a>b){
		cout << "a>b" << endl;
	} else {
		if (a==b){
			cout << "a == b" << endl;
		}else
			cout << "a < b" << endl;
		
	}
	
	cout << "a" << a;
}
