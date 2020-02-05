#include<iostream>
#include<map>
using namespace std;
int main(){
	map<int,bool> m;
	m.insert(make_pair(5,true));
	if(!m[6])
		cout<<"hello"<<endl;
	else
		cout<<"hi"<<endl;
	return 0;
}