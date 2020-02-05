#include<iostream>
#include<map>
#include<set>
#include<string>
#define mod 1000000007
using namespace std;
set<string> s3;
map<pair<int,string>,int> m;
void sub_count(string s,int n,string s1){
	if(m[make_pair(n,s1)])
		return;
	if(n == s.size()){
		s3.insert(s1);
		return;
	}
	string s4 = s1 + s[n];
	sub_count(s,n+1,s4);
	sub_count(s,n+1,s1);
	m[make_pair(n,s1)] = 1;
}
int main(){
	string s;
	cin>>s;
	sub_count(s,0,"");
	cout<<s3.size()<<endl;
	for(auto i:s3)
		cout<<i<<" ";
	return 0;
}