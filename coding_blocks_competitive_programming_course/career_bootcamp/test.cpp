#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;
int main(){
	map<string, int> m1;
	unordered_map<string, int> m2;
	set<int> s1;
	unordered_set<int> s2;
	m1["bcd"] = 2;
	m1["ab"] = 3;
	m2["bcd"] = 2;
	m2["ab"] = 3;
	for(auto i:m1){
		cout<<i.first<<" "<<i.second<<endl;
	}
	for(auto i:m2){
		cout<<i.first<<" "<<i.second<<endl;
	}
	s1.insert(2);
	s1.insert(2);
	s2.insert(2);
	s2.insert(1);
	for(auto i:s1){
		cout<<i<<endl;
	}
	for(auto i:s2){
		cout<<i<<endl;
	}
	return 0;
}