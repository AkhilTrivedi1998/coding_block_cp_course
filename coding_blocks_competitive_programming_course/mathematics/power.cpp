#include<iostream>
using namespace std;
int power(int a, int b){
	if(b == 0)
		return 1;
	else{
		int s = power(a, b/2);
		s = s * s;
		if(b % 2 == 0)
			return s;
		else
			return a * s;
	}
}
int main(){
	int n,p;
	cin>>n>>p;
	cout<<power(n,p);
	return 0;
}