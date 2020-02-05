#include<iostream>
#include<unordered_map>
using namespace std;
int count_distinct_elements(int * a, int s, int l){
	int count = 0;
	unordered_map<int,int> m;
	for(int i=s;i<=l;i++){
		if(m.find(a[i]) == m.end()){
			count++;
			m[a[i]] = 1;
		}
		else
			m[a[i]] = m[a[i]]+1;
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
	int count = 0;
	for(int i=k;i<=n;i++){
		for(int j=i-1;j<n;j++){
			int l = count_distinct_elements(a,j-i+1,j);
			if(l == k){
				for(int z=j-i+1;z<=j;z++)
					cout<<a[z]<<" ";
				cout<<endl;
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}