//#include<bits/stdc++.h>
//using namespace std;
//int n = 9;
//
//
//bool isafe(int i,int j,int num,vector<vector<int> >&grid){
//	for(int x=0;x<n;x++){
//		if(grid[i][x]==num||grid[x][j]==num){
//			return false;
//		}
//	}
//	int rs = i - i%3;
//	int cs = j - j%3;
//	for(int r=rs;r<rs+3;r++){
//		for(int c=cs;c<cs+3;c++){
//			if(grid[r][c] == num){
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//
//bool solve(vector<vector<int> > &graph){
//	int i,j;
//	bool nul = false;
//	for(i=0;i<n;i++){
//		for(j=0;j<n;j++){
//			if(graph[i][j]==0){
//				nul = true;
//				break;
//			}
//		}
//		if(nul){
//			break;
//		}
//	}
//	if(!nul){
//		return true;
//	}
//	for(int num=1;num<=9;num++){
//		if(isafe(i,j,num,graph)){
//			graph[i][j] = num;
//			if(solve(graph)) return true;
//			graph[i][j] = 0;
//		}
//	}
//	return false;
//}
//
//
//void print(vector<vector<int> >&graph){
//	for(auto i : graph){
//		for(auto j : i){
//			printf("%-4d",j);
//		}
//		cout<<"\n\n";
//	}
//}
//
//int main(){
//	vector<vector<int> >grid(n,vector<int>(n));
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cin>>grid[i][j];
//		}
//	}
//	if(solve(grid)){
//		print(grid);
//	}
//	else{
//		cout<<"No solution exists";
//	}
//}






#include<iostream>
#include<vector>
using namespace std;
int n=9;




bool safe(int i,int j,int nu,vector<vector<int> >&graph){
	for(int x=0;x<n;x++){
		if(graph[i][x]==nu||graph[x][j]==nu){
			return false;
		}
	}
	int row = i - i%3;
	int col = j - j%3;
	for(int r=row;r<row+3;r++){
		for(int c=col;c<col+3;c++){
			if(graph[r][c]==nu){
				return false;
			}
		}
	}
	return true;
}



bool solve(vector<vector<int> >&graph){
	int i,j;
	bool nul=false;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(graph[i][j]==0){
				nul=true;
				break;
			}
		}
		if(nul){
			break;
		}
	}
	if(!nul){
		return true;
	}
	for(int nu=1;nu<=n;nu++){
		if(safe(i,j,nu,graph)){
			graph[i][j] = nu;
			if(solve(graph)) return true;
			graph[i][j] = 0;
		}
	}
	return false;
}

void print(vector<vector<int> >&graph){
	for(auto i : graph){
		for(int j : i){
			printf("%-4d",j);
		}
		cout<<"\n\n";
	}
}
int main(){
		vector<vector<int> >graph(n,vector<int>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>graph[i][j];
			}
		}
		if(solve(graph)){
			print(graph);
		}
		else{
			cout<<"No solution ";
		}
}















