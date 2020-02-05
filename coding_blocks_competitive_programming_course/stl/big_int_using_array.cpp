#include<iostream>
using namespace std;
int main(){
	int a[1000] = {0};
	a[0] = 1;
	int n = 1;
	int har = 0;
	int k;
	for(int num=1;num<=100;num++){
		for(int i=0;a[i]!=0 || har!=0 || i<=n-1;i++){
			k = num*a[i]+har;
			a[i] = k%10;
			har = k/10;
			if(i>n-1)
				n = i+1;
		}
	}
	for(int i=999;i>=0;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}