#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int m = 0;
	for(int i=0;i<n;i++)
		m ^= a[i];
	int sep = m & (~(m-1));
	int b[n] = {0};
	int c[n] = {0};
	int count_b = 0, count_c = 0;
	for(int i=0;i<n;i++){
		int temp = sep & a[i];
		if(temp == 0)
			b[count_b++] = a[i];
		else if(temp == sep)
			c[count_c++] = a[i];
	}
	int first = 0;
	for(int i=0;i<count_b;i++)
		first ^= b[i];
	int second = 0;
	for(int i=0;i<count_c;i++)
		second ^= c[i];
	if (first > second)
		cout<<second<<" "<<first;
	else
		cout<<first<<" "<<second;
return 0;
}