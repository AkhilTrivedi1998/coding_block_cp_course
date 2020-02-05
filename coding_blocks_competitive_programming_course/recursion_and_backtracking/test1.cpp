#include<iostream>
using namespace std;
int main(){
	int n = 3;
	int a[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			a[i][j] = 2;
		}
	}
	for(int i=0;i<=n;i++)
		a[0][i] = 1;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			a[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum = 0;
			for(int k=0;k<=i;k++)
				sum += a[k][j-1];
			a[i][j] = sum;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
}