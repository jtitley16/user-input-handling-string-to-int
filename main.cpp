#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
	string str;
	string str1;
	string str2;
	string s;
	int i, x, temp;
	vector<int> a;
	
	i = 0;
	while((getline(cin, s, ' '))){
		i++;
		temp = std::stoi (s,nullptr,0);
		a.push_back(temp);
	}
	x = a.size();
	for(i = 0; i < x; i++){
		cout << a[i]+1 << " ";
	}
	return 0;
}