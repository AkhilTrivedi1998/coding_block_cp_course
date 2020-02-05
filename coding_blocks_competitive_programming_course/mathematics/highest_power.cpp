#include<iostream>
#include<cmath>
using namespace std;
int heighest_power(int i, int n){
	int power = 0;
	int j = i;
	while((n%i)==0){
		power += 1;
		i = i*j;
	}
	return power;
}
int main(){
	cout<<heighest_power(3,378);
	return 0;
}