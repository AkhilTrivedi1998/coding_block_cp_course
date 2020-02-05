#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n, l;
	cin>>n;
	vector<int> v1;
	for(int i=0;i<n;i++){
		cin>>l;
		v1.push_back(l);
	}
	vector<int> v2;
	for(int i=0;i<n;i++){
		cin>>l;
		v2.push_back(l);
	}
	int p1 = 0,p2 = 0;
	vector<int> v3;
	while(p1<v1.size() && p2<v2.size()){
		if(v1[p1]<=v2[p2]){
			v3.push_back(v1[p1]);
			p1++;
		}
		if(v2[p2]<v1[p1]){
			v3.push_back(v2[p2]);
			p2++;
		}
	}
	if(p1 == v1.size()){
		while(p2 != v2.size()){
			v3.push_back(v2[p2]);
			p2++;
		}
	}
	if(p2 == v2.size()){
		while(p1 != v1.size()){
			v3.push_back(v1[p1]);
			p1++;
		}
	}
	cout<<v3[(v3.size()-1)/2];
	return 0;
}






