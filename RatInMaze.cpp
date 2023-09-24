//#include<bits/stdc++.h>
//using namespace std;
//int n;
//
//
//bool safe(vector<vector<int> >&grid,vector<vector<int> >&sol,int x,int y){
//	return (x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==1&&sol[x][y]==0);
//}
//
//
//bool solve(vector<vector<int> >&grid,vector<vector<int> >&sol,int x,int y){
//	if(x==n-1&&y==n-1){
//		sol[x][y] = 1;
//		return true;
//	}
//	if(safe(grid,sol,x,y)){
//		sol[x][y] = 1;
//		
//		if(solve(grid,sol,x+1,y)){
//			return true;
//		}
//		if(solve(grid,sol,x,y+1)){
//			return true;
//		}
//		sol[x][y] = 0;
//		return false;
//	}
//	return false;
//}
//
//
//int main(){
//	cin>>n;
//	vector<vector<int> > grid(n,vector<int>(n));
//	vector<vector<int> > sol(n,vector<int>(n,0));
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cin>>grid[i][j];
//		}
//	}
//	if(solve(grid,sol,0,0)){
//		for(auto i : sol){
//			for(int j : i){
//				printf("%-4d",j);
//			}
//			cout<<"\n";
//		}
//	}
//	else{
//		cout<<"No solution ";
//	}
//}






#include<bits/stdc++.h>
using namespace std;
int n;


bool safe(vector<vector<int> > &grid,vector<vector<int> > &sol,int x,int y){
	return (x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==1&&sol[x][y]==0);
}


bool solve(vector<vector<int> > &grid,vector<vector<int> > &sol,int x,int y){
	if(x==n-1&&y==n-1){
		sol[x][y] = 1;
		return true;
	}
	if(safe(grid, sol, x, y)){
		sol[x][y] = 1;
		
		if(solve(grid, sol, x+1, y)) return true;
		
		if(solve(grid, sol, x, y+1)) return true;
		
		sol[x][y] = 0;
		return false;		
	}
	return false;
}


int main(){
	cin>>n;
	vector<vector<int> >grid(n,vector<int>(n));
	vector<vector<int> > sol(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	if(solve(grid,sol,0,0)){
		for(auto i : sol){
			for(int j : i){
				cout<<j<<" ";
			}
			cout<<"\n";
		}
	}
	else{
		cout<<"No solution ";
	}
}
