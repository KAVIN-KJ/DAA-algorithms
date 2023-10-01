#include<bits/stdc++.h>
using namespace std;
int r,c;

void solve(vector<vector<int>> &grid){
	
}


int main(){
	cin>>r>>c;
	vector<vector<int>> grid(c,vector<int>(r));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>grid[i][j];
		}
	}
	solve(grid);
}
