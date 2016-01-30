#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> fillVec(vector<int> a){
	
	int i;
	bool flag = true;

	cin.clear();
	fflush(stdin);

	cout << "Please enter integer values, you may enter as many as you wish to, enter any non integer value to quit.\n" << "enter integers: ";
	while((flag)){
		if (!(cin >> i)){
			flag = false;
			a.pop_back();
		}
		a.push_back(i);
	}
	return a;
}
void printVec(vector<int> a){
	int i, x;
	
	x = a.size();
	cout << "\nAfter adding the contents of each vector by index the values are: ";
	for(i = 0; i < x; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
vector<int> addVec(vector<int> a, vector<int> b){
												//2 vectors will be passed, and their values added together, 
												//their sums will be placed in a new vector and returned.
	int i, j, k, l;
	vector<int> c;
	if(a.size() < b.size()){					//If a is smaller than b, we will add only up to a
		j = a.size();							//j is the lower counter
		k = b.size();							//k is the upper limit counter
		l = 0;									//l is a flag to indicate which of the 3 cases we have, >, =, or <
	}else if(a.size() > b.size()){				//a is bigger 
		j = b.size();
		k = a.size();
		l = 1;
	}
	else{										// a = b
		j = a.size();
		k = a.size();
		l = 2;
	}
	for(i = 0; i < k; i++){						//this will run from 0 to the largest of the two vectors
		if(i < j){								//while there is an [i] index for both we will add the values, and store in c
			c.push_back(a[i] + b[i]);
		}
		if(l == 0 && i >= j){					//l = 0 case a is smaller, && i is now past the last value in a, so we copy the remains of b into c
			c.push_back(b[i]);
		}
		else if(l == 1 && i >= j){				//l = 1 case b is smaller, && i is now past the last value in b, so we copy the remains of a into c
			c.push_back(a[i]);
		}
	}
	return c;
}
int main()
{
	vector<int> a, b, c;

	a = fillVec(a);
	b = fillVec(b);
	c = addVec(a, b);
	printVec(c);

	return 0;
}