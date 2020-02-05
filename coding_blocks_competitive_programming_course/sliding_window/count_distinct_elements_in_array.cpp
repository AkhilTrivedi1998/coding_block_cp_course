#include<iostream>
#include<unordered_map>
using namespace std;
int count_distinct_elements(int * a, int s, int l){
	int count = 0;
	unordered_map<int,int> m;
	for(int i=s;i<=l;i++){
		if(m.find(a[i]) == m.end()){
			count++;
			m[a[i]] = 1;
		}
		else
			m[a[i]] = m[a[i]]+1;
	}
	for(auto itr:m)
		cout<<itr.first<<" "<<itr.second<<endl;
	return count;
}
int main(){
	int a[] = {2,2,2,1};
	cout<<count_distinct_elements(a,0,3);
	return 0;
}