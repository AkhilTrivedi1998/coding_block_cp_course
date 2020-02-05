#include<iostream>
using namespace std;
void subarry_with_spacific_sum(int *a,int n,int sum){
	int r = 0,l = 0;
	int s = 0;
	while(r<n){
		while(s>sum){
			s = s - a[l];
			l++;
			if(l>r)
				r = l;
		}
		if(s == sum){
			cout<<l<<" to "<<r-1<<endl;
			return;
		}
		s += a[r];
		r++;
	}
	cout<<"no subarray found"<<endl;
}
int subarry_with_spacific_sum_approach_2(int *a,int s,int l,int sum,int rq_sum){
	if(sum == rq_sum){
		cout<<s<<" to "<<l<<endl;
		return 1;
	}
	if(s == l)
		if(a[s] == rq_sum){
			cout<<s<<" to "<<l<<endl;
			return 1;
		}
		else
			return 0;
	return subarry_with_spacific_sum_approach_2(a,s+1,l,sum - a[s],rq_sum) || subarry_with_spacific_sum_approach_2(a,s,l-1,sum - a[l],rq_sum);
}
void subarry_with_spacific_sum_approach_3(int *a,int n,int rq_sum){
	int arr2[n][n];
	for(int i=0;i<n;i++)
		arr2[i][i] = a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			arr2[i][j] = arr2[i][j-1] + arr2[j][j];
			if(arr2[i][j] == rq_sum){
				cout<<i<<" to "<<j<<endl;
				return;
			}
		}
	}
	cout<<"no subarray found"<<endl;
}
int main(){
	int arr[] = {1, 4, 20, 3, 10, 5}; 
	int sum = 33;
	subarry_with_spacific_sum(arr,6,sum);
	int arr1[] = {10, 2, -2, -20, 10};
	int sum1 = -10;
	subarry_with_spacific_sum_approach_2(arr1,0,5,0,sum1);
	subarry_with_spacific_sum_approach_3(arr1,5,sum1);
	return 0;
}