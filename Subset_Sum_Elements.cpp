
#include<bits/stdc++.h>
using namespace std;

bool Subset(vector<int>&arr,vector<int>&subset,int trgt,int n){
	if(trgt==0) return true;
	
	if(trgt<0||n<=0) return false;
	
	if(Subset(arr,subset,trgt,n-1)) return true;
	
	subset.push_back(arr[n-1]);
	if(Subset(arr,subset,trgt-arr[n-1],n-1)) return true;
	subset.pop_back();
	return false;
}


int main(){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
	cin>>arr[i];
}
int t;
cin>>t;
vector<int> subset;
	if(Subset(arr,subset,t,n)){
		cout<<"Found a subset with given sum: ";
		for(int i=0;i<subset.size();i++){
			cout<<subset[i];
			if(i<subset.size()-1){
				cout<<" + ";
			}
		}
		cout<<" = "<<t<<"\n";
	}
	else{
		cout<<"No subset";
	}
}



// 	TO PRINT ALL THE POSSIBLE SUBSETS

#include<bits/stdc++.h>
using namespace std;

bool subsets(vector<int>&arr,vector<int>&sbset,int n,
int trgt,vector<vector<int> >&result){
if(trgt==0){
	result.push_back(sbset);
	return true;
}
if(trgt<0||n<=0){
	return false;
}

subsets(arr,sbset,n-1,trgt,result);

sbset.push_back(arr[n-1]);

subsets(arr,sbset,n-1,trgt-arr[n-1],result);

sbset.pop_back();
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int trgt;
	cin>>trgt;
	vector<int> sbset;
	vector<vector<int> > result;
	if(subsets(arr,sbset,n,trgt,result)){
	for(auto j : result){
		for(int i=0;i<j.size();i++){
			cout<<j[i];
			if(i<j.size()-1){
				cout<<" + ";
			}
		}
		cout<<" = "<<trgt<<"\n";
	}
	}
	else{
		cout<<"No possible subsets ";
	}
}






















