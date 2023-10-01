#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int lps(string s1,string s2,int n1,int n2){
	if(n1==0||n2==0){
		return 0;
	}
	if(dp[n1-1][n2-1]!=-1){
		return dp[n1-1][n2-1];
	}
	if(s1[n1-1]==s2[n2-1]){
		return dp[n1][n2] = 1 + lps(s1,s2,n1-1,n2-1);
	}
	else{
		return dp[n1][n2] = max(lps(s1,s2,n1-1,n2),lps(s1,s2,n1,n2-1));
	}
}

int main(){
	int n1,n2;
	memset(dp,-1,sizeof(dp));
	string str;
	cin>>str;
	string rev = str;
	reverse(rev.begin(),rev.end());
	n1 = str.length();
	n2 = rev.length();
	int nu = lps(str,rev,n1,n2);
	cout<<nu;
}


// USING DYNAMIC PROGRAMMING


#include<bits/stdc++.h>
using namespace std;

int lps(string s1,string s2){
    int r = s1.length();
    int c = s2.length();
    int l=0;
    int dp[r+1][c+1];
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                l = max(dp[i][j],l);
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return l;
}


int main(){
    string s1;
    cin>>s1;
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    cout<<lps(s1,s2);
}
