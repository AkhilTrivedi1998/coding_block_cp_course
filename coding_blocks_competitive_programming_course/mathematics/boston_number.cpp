#include<iostream>
#include<cmath>
using namespace std;
int sum_of_digits(int n, int power){
	int sum = 0;
	while(n!=0){
		int r = n % 10;
		sum += r;
		n = n/10;
	}
	return sum*power;
}
int isPrime(int n){
	if(n <= 1)
		return 0;
	if(n <= 3)
		return 1;
	if(n%2==0 || n%3==0)
		return 0;
	for(int i=5;i*i<=n;i=i+6){
		if(n%i==0 || n%(i+2)==0)
			return 0;
	}
	return 1;
}
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
	int n;
	cin>>n;
	int s = sum_of_digits(n, 1);
	int s1 = 0;
	for(int i=2;n!=1;i++){
		int m = isPrime(i);
		if(m==1){
			int k = n%i;
			if(k == 0){
				int h = heighest_power(i, n);
				s1 += sum_of_digits(i, h);
				n = n/pow(i, h);
			}
		}
	}
	if(s == s1)
		cout<<1;
	else
		cout<<0;
	return 0;
}