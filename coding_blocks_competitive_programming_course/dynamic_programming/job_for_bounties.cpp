#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
bool check(string s){
	int n = s.size();
	int  i = 0;
	stack<char> s1;
	while(i<n){
		if(s[i] == '(')
			s1.push(s[i]);
		else if(s[i] == ')' && (!s1.empty())){
			s1.pop();
		}
		else
			return false;
		i++;
	}
	return true;
}
int count(string s){
	int n = s.size();
	vector<int> v1(n+1,0);
	vector<int> v2(n+1,0);
	if(s[0] == '(')
		v1[1] = 1;
	else
		v2[1] = 1;
	for(int i=1;i<n;i++){
		if(s[i] == '('){
			v1[i+1] = v1[i] + 1;
			v2[i+1] = v2[i];
		}
		else{
			v2[i+1] = v2[i] + 1;
			v1[i+1] = v1[i];
		}
	}
	int l=0,r=0,max_val=0,x,y,k=0;
	while(l<n-1){
		while(s[l] != '(' && l<(n-1))
			l++;
		if(l<(n-1)){
			r = l+1;
			while(r<n){
				while(s[r] != ')' && r<n)
					r++;
				if(r<n){
					int i = v1[r+1] - v1[l];
					int j = v2[r+1] - v2[l];
					if(i == j){
						if(check(s.substr(l,r))){
							if(max_val<(r-l+1)){
								max_val = r-l+1;
								x = l;
								y = r;
								k = 1;
							}
						}
					}
					r++;
				}
			}
			if(k != 1)
				l++;
			else
				l = y+1;
			k = 0;
		}
	}
	cout<<x<<" and "<<y<<endl;
	for(int i = x;i<=y;i++)
		cout<<s[i]<<" ";
	cout<<endl;
	return max_val;
}
int main(){
	string s;
	cin>>s;
	cout<<count(s)<<endl;
	return 0;
}