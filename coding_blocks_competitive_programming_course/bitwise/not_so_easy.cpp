#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[8] = {2, 3, 5, 7, 11, 13, 17, 19};
		int res = 0;
		for(int i=1;i<256;i++){
			int set_bits = __builtin_popcount(i);
			int j = i;
			int mul = 1;
			for(int m=0;m<64 && j!=0;m++){
				int k = j & 1;
				if(k == 1)
					mul *= a[m];
				j = j>>1;
			}
			if(set_bits % 2 == 0)
				res -= n/mul;
			else
				res += n/mul;
		}
		cout<<res<<endl;
	}
return 0;
}