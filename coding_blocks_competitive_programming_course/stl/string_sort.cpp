#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool comparator(string a, string b){
	if(a.find(b) == 0)
		return true;
	if(b.find(a) == 0)
		return false;
	else
		return a<b;
}
int main(){
	int n;
	char ch;
	cin>>n;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	string s[n];
	for(int i=0;i<n;i++)
		getline(cin,s[i]);
	sort(s,s+n,comparator);
	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;
	return 0;
}