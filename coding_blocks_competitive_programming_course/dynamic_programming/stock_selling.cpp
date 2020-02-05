#include<iostream>
#include<vector>
using namespace std;
int b[100][100][2];
int max_profit(vector<int> a,int n,int k,int i){
	if(b[n][k][i] != 0)
		return b[n][k][i];
	if(k == 0)
		return 0;
	if(n == a.size())
		return 0;
	if(i == 0){
		b[n][k][i] = max(max_profit(a,n+1,k,1)-a[n],max_profit(a,n+1,k,0));
		return b[n][k][i];
	}
	if(i == 1){
		b[n][k][i] = max(max_profit(a,n+1,k-1,0)+a[n],max_profit(a,n+1,k,1));
		return b[n][k][i];
	}
}
int main(){
	int t,k,n;
	vector<int> v;
	cin>>t;
	while(t--){
		cin>>k>>n;
		for(int i=0;i<n;i++){
			int j;
			cin>>j;
			v.push_back(j);
		}
		cout<<max_profit(v,0,k,0)<<endl;
		v.clear();
		fill((int *)b,(int *)b + (sizeof(b)/sizeof(int)),0);
	}
	return 0;
}