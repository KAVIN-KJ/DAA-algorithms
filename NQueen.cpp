#include<bits/stdc++.h>
using namespace std;
int n;

bool safe(vector<vector<int>>& grid, int row, int col) {
	for(int i=0;i<row;i++){
		if(grid[i][col]==1) return false;
	}
	for(int i=row,j=col;i>=0&&j>=0;i--,j--){
		if(grid[i][j]==1) return false;
	}
	for(int i=row,j=col;i>=0&&j<n;i--,j++){
		if(grid[i][j]==1) return false;
	}
	
	return true;
}



bool solve(vector<vector<int> > &grid,int row){
	if(row==n){
		return true;
	}
	for(int i=0;i<n;i++){
	if(safe(grid,row,i)){
		grid[row][i] = 1;
		
		if(solve(grid,row+1)) return true;
		
		grid[row][i] = 0;
	}
	}
	return false;
}


int main(){
	cin>>n;
	vector<vector<int> > grid(n,vector<int>(n,0));
	if(solve(grid,0)){
		for(auto i : grid){
			for(int j : i){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
	else{
		cout<<"no solution";
	}
}







