#include<iostream>
#include<vector>
#include<map>
#define mod 1000000007
using namespace std;
map<pair<int, int>,int> m;
vector<int> v;
int money_change(int amount,int n){
	if(m[make_pair(amount,n)])
		return m[make_pair(amount,n)];
	if(amount == 0)
		return 1;
	if(amount < 0)
		return 0;
	if(n == v.size())
		return 0;
	m[make_pair(amount,n)] = (money_change(amount - v[n],n)%mod + money_change(amount,n+1)%mod)%mod;
	return m[make_pair(amount,n)];
}
int main(){
	int t,n,amount,k;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>k;
			v.push_back(k);
		}
		cin>>amount;
		cout<<money_change(amount,0)<<endl;
		v.clear();
		m.clear();
	}
	return 0;
}