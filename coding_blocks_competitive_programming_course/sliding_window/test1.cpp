#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void fun(vector<int> v){
	v[0] = 10;
}
int main(){
	vector<int> v{1,2,5,4,3,6};
	for(auto i=v.begin();i<v.end();i++){
		cout<<(*i)<<" ";
	}
	cout<<endl<<v.size()<<endl;
	fun(v);
	v.push_back(7);
	sort(v.begin(),v.end());
	for(auto i=v.begin();i<v.end();i++){
		cout<<(*i)<<" ";
	}
	cout<<endl<<v.size()<<endl;
	auto l = max_element(v.begin(),v.end());
	cout<<(*l)<<endl;
}