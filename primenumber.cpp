#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
	int count=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			count++;
		}
	}
	return (count<=2);
}

int main(){
	int sum,n,st;
	vector<int> nums(n);
	cin>>sum>>n>>st;
	for(int i=2;i<=sum;i++){
		if(isprime(i)){
			nums.push_back(i);
		}
	}
	while(true){
		int ind=st+1;
		for(int i=st+1;i<=sum;i++){
			if(nums[ind]+nums[i]==sum){
				cout<<nums[ind]<<" "<<nums[i];
				return 0;
			}
		}
		ind++;
	}
}
