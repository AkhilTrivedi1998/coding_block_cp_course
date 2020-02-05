#include<iostream>
#include<string>
#include<map>
using namespace std;

map<pair<int,int>,bool> m;

bool wildcard_matching(string s1,string s2,int n1,int n2){
	if(m.find(make_pair(n1,n2)) != m.end())
		return m[make_pair(n1,n2)];
	if((n1 == s1.size()) && (n2 == s2.size())){
		m[make_pair(n1,n2)] = true;
		return true;
	}
	else if((n1 == s1.size()) || (n2 == s2.size())){
		m[make_pair(n1,n2)] = false;
		return false;
	}
	if(s2[n2] == '*'){
		m[make_pair(n1,n2)] = wildcard_matching(s1,s2,n1+1,n2) || wildcard_matching(s1,s2,n1+1,n2+1) || wildcard_matching(s1,s2,n1,n2+1);
		return m[make_pair(n1,n2)];
	}
	else if(s2[n2] == '?'){
		m[make_pair(n1,n2)] = wildcard_matching(s1,s2,n1+1,n2+1);
		return m[make_pair(n1,n2)]; 
	}
	else{
		if(s1[n1] != s2[n2]){
			m[make_pair(n1,n2)] = false;
			return false;
		}
		else{
			m[make_pair(n1,n2)] = wildcard_matching(s1,s2,n1+1,n2+1);
			return m[make_pair(n1,n2)];
		}
	}
}
bool wildcard_matching_2(string s1,string s2){

}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	if(wildcard_matching(s1,s2,0,0))
		cout<<"MATCHED";
	else
		cout<<"NOT MATCHED";
	return 0;
}