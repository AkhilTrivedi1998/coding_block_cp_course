#include<iostream>
#include<map>
using namespace std;
map<pair<int, int>,int> m;
int main(){
	if(m[make_pair(0,2)])
		cout<<"hello";
	else{
		m[make_pair(0,2)] = 1;
		cout<<"hi";
	}
	if(m[make_pair(0,2)])
		cout<<"hello";
	else{
		m[make_pair(0,2)] = 1;
		cout<<"hi";
	}
	return 0;
}