#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int b[64] = {0};
	for(int i=0;i<n;i++){
		int m = a[i];
		int j = 0;
		while(m != 0){
			int k = m & 1;
			m = m>>1;
			if(k == 1)
				b[j] += 1;
			j++;
		}
	}
	int res = 0;
	for(int i=0;i<64;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	for(int i=0;i<64;i++){
		if(b[i] % 3 == 1){
			res += pow(2, i);
		}
	}
	cout<<res<<endl;


return 0;
}