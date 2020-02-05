#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x, y;
	cin>>x>>y;
	int a = x ^ y;
	int i = 0;
	while(a != 0){
		a = a/2;
		i++;
	}
	cout<<pow(2,i) - 1;
return 0;
}