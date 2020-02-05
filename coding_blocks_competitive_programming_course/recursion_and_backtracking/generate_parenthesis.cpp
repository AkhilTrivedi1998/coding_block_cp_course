#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int generate_parenthesis_util(int n,int m){
	if(m == 0)
		return 1;
	else if(n<m)
		return 0;
	else{
		int sum = 0;
		for(int i=0;i<=m;i++)
			sum += generate_parenthesis_util(n-1,i);
		return sum;
	}
}
int generate_parenthesis_util_2(int n){
	int a[n+1][n+1];
	for(int i=0;i<=n;i++)
		a[0][i] = 1;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			a[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum = 0;
			for(int k=0;k<=i;k++)
				sum += a[k][j-1];
			a[i][j] = sum;
		}
	}
	return a[n][n];
}
void generate_parenthesis_util_3(int n){
	unordered_map<pair<int,int>,vector<string>> m;
	string s = "(";
	for(int i=0;i<=n;i++){
		m.push_back(make_pair(make_pair(0, i),vector<string>()));
		
	}

}
int generate_parenthesis(int n){
	return generate_parenthesis_util_2(n);
}
int main(){
	cout<<generate_parenthesis(3)<<endl;
	return 0;
}