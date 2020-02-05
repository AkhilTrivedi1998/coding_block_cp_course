#include<iostream>
#include<map>
#define ll long long
using namespace std;

map<ll,ll> m;

ll exchanging_coins(ll n){
	if(m[n])
		return m[n];
	if(n<12){
		m[n] = n;
		return n;
	}
	else{
		m[n/2] = exchanging_coins(n/2);
		m[n/3] = exchanging_coins(n/3);
		m[n/4] = exchanging_coins(n/4);
		return m[n/2] + m[n/3] + m[n/4];
	}
}
int main(){
	ll n;
	cin>>n;
	cout<<exchanging_coins(n)<<endl;
	return 0;
}