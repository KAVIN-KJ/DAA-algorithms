//#include<bits/stdc++.h>
//using namespace std;
//
//
//int maxsqr(vector<vector<int> > &arr){
//	vector<vector<int> > dp(arr.size(),vector<int>(arr[0].size(),0));
//	int ans = 0;
//	int x,y;
//	for(int i=0;i<arr.size();i++){
//		for(int j=0;j<arr[0].size();j++){
//			if(i==0||j==0){
//				if(arr[i][j]==1)
//					dp[i][j] = 1;
//			}
//			else{
//				if(arr[i][j]==1){
//					dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
//					if(dp[i][j]>ans){
//						x=i;
//						y=j;
//						ans = dp[i][j];
//					}
//				}
//			}
//		}
//	}
//	for(int i=x;i>x-ans;i--){
//		for(int j=y;j>y-ans;j--){
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//}
//
//
//int main(){
//	int r,c;
//	cin>>r>>c;
//	vector<vector<int> > arr(r,vector<int>(c));
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cin>>arr[i][j];
//		}
//	}
////	int sqr = maxsqr(arr);
////	vector<vector<int> > sol;
////	cout<<sqr;
//maxsqr(arr);
//}











#include<iostream>
#include<vector>
using namespace std;

void maxSqr(vector<vector<int> > &arr,int r,int c){
    vector<vector<int> > dp(r,vector<int>(c));
    int x,y,ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0||j==0){
                if(arr[i][j]==1){
                    dp[i][j]=1;
                }
            }
            else{
                if(arr[i][j]==1){
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    if(dp[i][j]>ans){
                        ans = dp[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }
    }
    for(int i=x-ans;i<x;i++){
        for(int j=y-ans;j<y;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> arr(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    maxSqr(arr,r,c);
}
