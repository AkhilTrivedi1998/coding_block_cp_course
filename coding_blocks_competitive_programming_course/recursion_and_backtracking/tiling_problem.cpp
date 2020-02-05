#include<iostream>
using namespace std;
#define mod 1000000007
int no_of_ways_of_tiling(int n,int m){
	if(n<m)
		return 1;
	return ((no_of_ways_of_tiling(n-1,m)%mod) + (no_of_ways_of_tiling(n-m,m)%mod)%mod);
}
int no_of_ways_of_tiling_2(int n,int m){
	int a[n+1];
	if(m == 0)
		return 0;
	if(n<m)
		return 1;
	for(int i=0;i<n+1;i++){
		if(i<m)
			a[i] = 1;
		else
			a[i] = (a[i-1]%mod + a[i-m]%mod)%mod;
	}
	return a[n];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cout<<no_of_ways_of_tiling_2(n,m)<<endl;
	}
	return 0;
}