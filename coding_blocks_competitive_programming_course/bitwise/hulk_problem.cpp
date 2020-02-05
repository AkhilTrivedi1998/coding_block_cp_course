#include<bits/stdc++.h>
using namespace std;

int no_of_set_bits(int n){
	int m = 0;
	while(n!=0){
		n = n & (n-1);
		m++;
	}
	return m;
}

int main(){
	cout<<"enter the level to jump"<<endl;
	int n;
	cin>>n;
	cout<<"Minimum number of jumps is "<<no_of_set_bits(n);


return 0;
}