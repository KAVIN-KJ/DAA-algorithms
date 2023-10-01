#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2){
	int maxl=0;
	int m = s1.length()+1;
	int n = s2.length()+1;
	int dp[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0||j==0){
				dp[i][j] = 0;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				maxl = max(dp[i][j],maxl);
			}
			else{ 
				dp[i][j] = 0;
			}
		}
	}
	return maxl;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<"LCS : "<<lcs(s1,s2);
}
