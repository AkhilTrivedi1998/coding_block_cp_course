#include<iostream>
using namespace std;
int main(){
	int q;
	cin>>q;
	int a[2][q];
	for(int i=0;i<q;i++){
		cin>>a[0][i]>>a[1][i];
	}
	int n[q] = {0};
	for(int i=0;i<q;i++){
		for(int j=a[0][i];j<=a[1][i];j++){
			int temp = j;
			while(temp != 0){
				temp = temp & (temp - 1);
				n[i]++;
			}
		}
	}
	for(int i=0;i<q;i++)
		cout<<n[i]<<endl;
return 0;
}