#include<iostream>
#include<string>
#include<unordered_map>
#define inf 100000
using namespace std;
int window_complete(unordered_map<char,int> m1){
	int k = 1;
	for(auto i:m1){
		if(i.second > 0){
			k = 0;
			break;
		}
	}
	return k;
}
int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	unordered_map<char,int> m;
	for(int i=0;i<s2.size();i++){
		if(m.find(s2[i]) == m.end())
			m[s2[i]] = 1;
		else
			m[s2[i]] = m[s2[i]] + 1;
	}
	int min_win = inf,r1 = -1,l1 = -1;
	int r = 0,l = 0,start = 1,k;
	while(r<s1.size()){
		if(m.find(s1[r]) != m.end()){
			m[s1[r]] = m[s1[r]] - 1;
			k = window_complete(m);
			while(k == 1){
				while(m.find(s1[l]) == m.end())
					l++;
				if(min_win>r-l+1){
					min_win = r-l+1;
					l1 = l;
					r1 = r;
				}
				m[s1[l]] = m[s1[l]] + 1;
				l++;
				k = window_complete(m);
				if(k != 1){
					while(m.find(s1[l]) == m.end() || m[s1[l]] < 0){
						if(m.find(s1[l]) != m.end())
							m[s1[l]] = m[s1[l]] + 1;
						l++;
					}
				}
			}
		}
		r++;
	}
	if(r1 != -1 && l1 != -1){
		for(int i=l1;i<=r1;i++){
			cout<<s1[i];
		}
	}
	else
		cout<<"No string";
	return 0;
}