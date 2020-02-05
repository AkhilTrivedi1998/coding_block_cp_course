#include<iostream>
#include<unordered_map>
using namespace std;
int count_k_distinct_element_subarrays(int *a,int s,int last,int k){
	int r = 0,l = 0;
	int count = 0;
	unordered_map<int,int> m;
	while(r<last){
		if(m.find(a[r]) == m.end()){
			m[a[r]] = 1;
		}
		else{
			m[a[r]] = m[a[r]]+1;
		}
		while(m.size()>k){
			m[a[l]] = m[a[l]]-1;
			if(m[a[l]] == 0)
				m.erase(a[l]);
			l++;
		}
		count += r-l+1;
		r++;
	}
	return count;
}
int main(){
	int a[] = {2,1,2,1,6};
	cout<<count_k_distinct_element_subarrays(a,0,5,2) - count_k_distinct_element_subarrays(a,0,5,1);
	return 0;
}