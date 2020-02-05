#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout<<"enter probability"<<endl;
	float prob;
	cin>>prob;
	float l = log10(1-prob)/log10(364.0/365.0);
	float root = sqrt(1+8*l);
	float res = (1+root)/2;
	cout<<int(res+0.5)<<endl;

	return 0;
}