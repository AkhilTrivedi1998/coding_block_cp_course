#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;
int main(){
	string s;
	cout<<"enter string"<<endl;
	getline(cin,s);
	stringstream iss(s);
	string word;
	unordered_map<string,int> s1;
	int distinct_count = 0,count = 0;
	while(iss>>word) {
		if(s1.find(word) == s1.end()){
			s1[word] = 1;
			distinct_count++;
			count++;
		}
		else{
			s1[word] = s1[word] + 1;
			count++;
		}
	}
	for(auto itr:s1){
		cout<<itr.first<<" "<<itr.second<<endl;
	}
	cout<<"number of words : "<<count<<" number of distinct words : "<<distinct_count;
	return 0;
}
