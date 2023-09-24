//#include<bits/stdc++.h>
//using namespace std;
//
//int subset(vector<int> &nums,int trgt, int i){
//	if(trgt==0){
//		return 1;
//	}
//	if(trgt<0||i<0){
//		return 0;
//	}
//	int incl = subset(nums,trgt-nums[i],i-1);
//	int excl = subset(nums,trgt,i-1);
//	
//	return incl+excl;
//}
//
//int main(){
//	int n;
//	cin>>n;
//	vector<int> nums;
//	for(int i=0;i<n;i++){
//		int nu;
//		cin>>nu;
//		nums.push_back(nu);
//	}
//	int trgt;
//	cin>>trgt;
//	cout<<subset(nums,trgt,n-1);
//}



#include<iostream>
using namespace std;

int subset(int arr[],int t,int i){
	if(t==0){
		return 1;
	}
	else if(t<0||i<0){
		return 0;
	}
	int in = subset(arr,t-arr[i],i-1);
	int out = subset(arr,t,i-1);
	return in+out;
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int trgt;
	cin>>trgt;
	cout<<"The number of subsets are : "<<subset(arr,trgt,n-1);
}



