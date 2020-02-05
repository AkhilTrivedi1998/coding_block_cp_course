#include<iostream>
#include<string>
using namespace std;
int count(string s,int k_const){
	int max=0,l=0,r,j,k;
	while(1){
		r = l;
		k = k_const;
		while(r<s.size()){
			if(s[r] != s[l]){
				if(k == k_const)
					j = r;
				k--;
				if(k<0){
					r--;
					break;
				}
			}
			r++;
		}
		if(max<(r-l+1))
			max = r-l+1;
		if(r == s.size())
			break;
		l = j;
	}
	return max;
}
int main(){
	int k;
	cin>>k;
	string s;
	cin>>s;
	cout<<count(s,k)<<endl;
	return 0;
}