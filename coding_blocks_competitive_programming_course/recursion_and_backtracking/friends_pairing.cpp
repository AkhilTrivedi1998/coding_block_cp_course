#include<iostream>
using namespace std;
int friends_pairing_count(int n){
	if(n == 0 || n == 1)
		return 1;
	return friends_pairing_count(n-1)+ (n-1)*friends_pairing_count(n-2);
}
int friends_pairing_count_2(int n){
	int a[n+1];
	a[0] = 1;
	a[1] = 1;
	for(int i=2;i<=n;i++)
		a[i] = a[i-1] + (i-1)*a[i-2];
	return a[n]; 
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<friends_pairing_count_2(n)<<endl;
	}
	return 0;
}