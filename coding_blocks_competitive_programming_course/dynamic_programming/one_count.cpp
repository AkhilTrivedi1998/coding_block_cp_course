#include<iostream>
using namespace std;
int max_one_count(int *a,int s,int l,int k){
	if(s>=l)
		return 0;
	int max_count = 0;
	if(a[s]==1 && k==0){
		int i = s;
		while(a[i]!=0 && i!=l){
			if(a[i]==1)
				max_count++;
			i++;
		}
		return max(max_count,max_one_count(a,i,l,k));
	}
	else if(a[s]==1 && k!=0){
		int i = s;
		while(i!=l && a[i]!=0){
			if(a[i]==1)
				max_count++;
			i++;
		}
		max_count = max(max_count,max_one_count(a,i+1,l,k));
		if(i!=l && a[i]==0){
			a[i]=1;
			max_count = max(max_count,max_one_count(a,s,l,k-1));
		}
		if(i!=l && a[i]==1)
			a[i]=0;
		return max_count;
	}
	else if(a[s]==0 && k!=0){
		max_count = max_one_count(a,s+1,l,k);
		a[s]=1;
		max_count = max(max_count,max_one_count(a,s,l,k-1));
		a[s]=0;
		return max_count;
	}
	else if(a[s]==0 && k==0){
		int i = s;
		while(a[i]!=1 && i!=l)
			i++;
		return max_one_count(a,i,l,k);
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<max_one_count(a,0,n,k);
	return 0;
}