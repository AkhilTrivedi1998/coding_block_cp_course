#include<iostream>
using namespace std;
int count_binary_strings(int n,int k){
	if(n == 0)
		return 1;
	if(k == 0)
		return count_binary_strings(n-1,0)+count_binary_strings(n-1,1);
	if(k == 1)
		return count_binary_strings(n-1,0);
}
int count_binary_strings_2(int n){
	int a[n+1][2];
	a[0][0] = 1;
	a[0][1] = 1;
	for(int i=1;i<n+1;i++){
		a[i][0] = a[i-1][0]+a[i-1][1];
		a[i][1] = a[i-1][0];
	}
	return a[n][0];
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<count_binary_strings_2(n)<<endl;
	}
	return 0;
}