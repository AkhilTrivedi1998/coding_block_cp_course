#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int k;
	cin>>k;
	int a[k];
	int count = 0;
	for(int i=0;i<k;i++)
		cin>>a[i];
	int num = pow(2,k) - pow(2,k-6);
	for(int i = num;i>=63;i--){
		if(__builtin_popcount(i) == 6){
			count++;
			int j = i;
			for(int g=0;j>0;g++){
				if(j&1)
					cout<<a[g]<<" ";
				j = j/2;
			}
			cout<<endl;
		}
	}
	cout<<count<<endl;
	return 0;
}