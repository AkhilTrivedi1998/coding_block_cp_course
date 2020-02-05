#include<bits/stdc++.h>
using namespace std;

int findUniqueNumber(int *a,int n){
	int c[64] = {0};
	for(int i=0;i<n;i++){
		int m = a[i];
		for(int j=0;j<64;j++){
			c[j] += m&1;
			m = m>>1;
		}
	}
	int num = 0;
	for(int j=0;j<64;j++){
		c[j] %= 3;
		num += c[j]*pow(2,j);
	}
	return num;
}

int main(){
	int a[] = {4,9,9,9,4,12,3,4,3,6,3,6,6};
	int n = sizeof(a)/sizeof(int);
	//cout<<sizeof(int)<<endl;
	cout<<findUniqueNumber(a,n);


return 0;
}