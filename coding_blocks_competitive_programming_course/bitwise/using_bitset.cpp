#include<iostream>
#include<bitset>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	string s[t][2];
	string l[t];
	for(int i=0;i<t;i++){
		cin>>s[i][0]>>s[i][1];
		int len = s[i][0].length();
		l[i] = ( bitset<100>(s[i][0]) ^ bitset<100>(s[i][1]) ).to_string().substr(100 - len, 100);
	}
	for(int i=0;i<t;i++)
		cout<<l[i]<<endl;
return 0;
}