#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int convert_str_to_int(string s){
	stringstream geeks(s);
	int x = 0;
	geeks>>x;
	return x;
}
int codes_of_the_string(string s){
	int n = s.size();
	if(n == 0 || n == 1)
		return 1;
	string s1 = s.substr(n-2,2);
	int m = stoi(s1);
	if(m<=26)
		return codes_of_the_string(s.substr(0,n-1)) + codes_of_the_string(s.substr(0,n-2));
	else
		return codes_of_the_string(s.substr(0,n-1));
}
int codes_of_the_string_2(string s){
	int n = s.size();
	int a[n+1];
	a[0] = 1;
	a[1] = 1;
	for(int i=2;i<=n;i++){
		string s1 = s.substr(i-2,2);
		int m = stoi(s1);
		if(m<=26)
			a[i] = a[i-1] + a[i-2];
		else
			a[i] = a[i-1];
	}
}
void codes_of_the_string_3(string s){
	int n = s.size();
	vector<string> v1;
	string s1;
	v1.push_back("");
	if(n == 0)
		cout<<v1[0]<<endl;
	vector<string> v2;
	s1 = char(96 + convert_str_to_int(s.substr(0,1)));
	v2.push_back(s1);
	if(n == 1)
		cout<<v2[0]<<endl;
	vector<string> v;
	for(int i=2;i<=n;i++){
		v.clear();
		string s2 = s.substr(i-1,1);
		string s3 = s.substr(i-2,2);
		int m = convert_str_to_int(s3);
		int k = convert_str_to_int(s2);
		s2 = char(96+k);
		if(m>0 && m<=26){
			s3 = char(96+m);
			for(int i=0;i<v1.size();i++){
				v.push_back(v1[i]+s3);
			}
			if(k>0){
                for(int i=0;i<v2.size();i++){
                    v.push_back(v2[i]+s2);
                }
            }
            v1 = v2;
			v2 = v;
		}
		else{
			if(k>0){
                for(int i=0;i<v2.size();i++){
                    v.push_back(v2[i]+s2);
                }
            }
			v1 = v2;
			v2 = v;
		}
	}
	sort(v.begin(),v.end());
	cout<<"[";
	for(int i=0;i<v.size();){
		cout<<v[i];
		i++;
		if(i<v.size())
			cout<<", ";
	}
	cout<<"]"<<endl;
}
int main(){
	string s;
	cin>>s;
	codes_of_the_string_3(s);
	return 0;
}