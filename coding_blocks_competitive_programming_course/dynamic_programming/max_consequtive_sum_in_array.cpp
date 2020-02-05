#include<iostream>
using namespace std;
int max_consequtive_sum(int *a,int n,int k){
	int b;
	int sum = 0;
	int max = 0;
	for(int i=0;i<k;i++)
		sum += a[i];
	b = sum;
	max = b;
	for(int i=k;i<n;i++){
		b = b - a[i-k] + a[i];
		if(max<b)
			max = b;
	}
	return max;
}
int main(){
	int a[] = {1,4,2,10,23,3,1,0,20};
	int n = sizeof(a)/sizeof(int);
	cout<<max_consequtive_sum(a,n,4)<<endl;
	return 0;
}