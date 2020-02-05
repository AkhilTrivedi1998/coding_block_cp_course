#include<iostream>
#include<vector>
#include<algorithm>
#define inf 100000
using namespace std;
int min_k_equal_elements(int *a,int s,int l,int k,vector<int> v){
	if(v.size() == k){
		auto max1 = max_element(v.begin(),v.end());
		int rq_count = 0;
		for(auto i = v.begin();i<v.end();i++){
			rq_count += (*max1) - (*i);
		}
		return rq_count;
	}
	if(s == l)
		return inf;
	int l2 = min_k_equal_elements(a,s+1,l,k,v);
	v.push_back(a[s]);
	int l1 = min_k_equal_elements(a,s+1,l,k,v);
	return min(l2,l1);
}
int min_k_equal_elements_2(vector<int>v,int k){
	sort(v.begin(),v.end());
	int sum = 0;
	int min_val;
	for(int i=0;i<k;i++){
		sum += v[k-1]-v[i];
	}
	min_val = sum;
	for(int i=k;i<v.size();i++){
		sum = sum + v[i-k] - v[i-1];
		sum = (k-1)*(v[k] - v[k-1])+sum;
		if(sum<min_val)
			min_val = sum;
	}
	return min_val;
}
int main(){
	int arr[] = {3, 10, 9, 1};
	int k = 3;
	vector<int> v,v1;
	cout<<min_k_equal_elements(arr,0,4,k,v)<<endl;
	int arr1[] = {5, 3, 10, 5};
	int k1 = 2;
	cout<<min_k_equal_elements(arr1,0,4,k1,v1)<<endl;
	vector<int>v2{3,10,9,1};
	cout<<min_k_equal_elements_2(v2,k)<<endl;
	vector<int>v3{5,3,10,5};
	cout<<min_k_equal_elements_2(v3,k1)<<endl;
	return 0;
}





