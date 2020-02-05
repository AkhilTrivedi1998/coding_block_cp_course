#include<iostream>
#include<vector>
using namespace std;
int max_differance(vector<int> v){
	int max;
	int n = v.size();
	vector<int> v1(n,0);
	for(int i=1;i<n;i++){
		max = 0;
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				if((v[i]-v[j])>max)
					max = v[i] - v[j];
			}
		}
		v1[i] = max;
	}
	max = 0;
	for(int i=0;i<n;i++){
		if(max<v1[i])
			max = v1[i];
	}
	return max;
}
int max_differance_2(vector<int> v,int s,int l){
	int n = v.size();
	vector<int> v1(n,0);
	vector<int> v2(n,0);
	int min = 1000,max = -1;
	for(int i=s;i<=l;i++){
		if(v[i]<min){
			min = v[i];
		}
		v1[i] = min;
	}
	for(int i=l;i>=s;i--){
		if(v[i]>max){
			max = v[i];
		}
		v2[i] = max;
	}
	max = 0;
	for(int i=s;i<=l;i++){
		if((v2[i]-v1[i])>max)
			max = v2[i]-v1[i];
	}
	return max;
}
int main(){
	vector<int> v{2, 3, 10, 6, 4, 8, 1};
	cout<<max_differance_2(v,3,6)<<endl;
	return 0;
}