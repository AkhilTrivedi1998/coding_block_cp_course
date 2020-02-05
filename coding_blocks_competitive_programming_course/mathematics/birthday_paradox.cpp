#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double p;
	const long double d = 364.0 / 365.0;
	cin>>p;
	long double m = (2*log10(1-p))/log10(d);
	double  n = ((1+sqrt(1+4*m))/2);
	cout<<n;
	return 0;
}