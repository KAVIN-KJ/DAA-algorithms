////#include<iostream>
////using namespace std;
////
////
////
////void print(int arr[]){
////	for(int i=0;i<4;i++){
////		cout<<arr[i]<<" ";
////	}
////}
////
////bool issafe(int arr[4][4],int v,int c,int col[]){
////	for(int i=0;i<4;i++){
////		if(arr[v][i]==1 && col[i]==c){
////			return false;
////		}
////	}
////	return true;
////}
////
////bool evaluate(int arr[4][4],int v,int col[],int m){
////	if(v==4){
////		return true;
////	}
////	for(int i=1;i<=m;i++){
////		if(issafe(arr,v,i,col)){
////			col[v] = i;
////			if(evaluate(arr,v+1,col,m)) return true;
////			col[v] = 0;
////		}
////	}
////	return false;
////}
////
////
////void setcolor(int m, int graph[4][4]){
////	int col[4];
////	for(int i=0;i<4;i++){
////		col[i]=0;
////	}
////	if(!evaluate(graph,0,col,m)){
////		cout<<"Solution does not exist ";
////		return;
////	}
////	else{
////		cout<<"Solution exists : ";
////		print(col);
////	}
////	
////}
////
////
////int main(){
////	int arr[4][4];
////	for(int i=0;i<4;i++){
////		for(int j=0;j<4;j++){
////			cin>>arr[i][j];
////		}
////	}
////	int m;
////	cin>>m;
////	setcolor(m,arr);
////}
//
//
//
//#include<iostream>
//using namespace std;
//
//
//bool safe(int v,int c,int arr[4][4],int col[]){
//	for(int i=0;i<4;i++){
//		if(arr[v][i]==1 && col[i]==c){
//			return false;
//		}
//	}
//	return true;
//}
//
//bool evaluate(int v,int m,int arr[4][4],int col[]){
//	if(v==4){
//		return true;
//	}
//	for(int i=1;i<=m;i++){
//		if(safe(v,i,arr,col)){
//			col[v] = i;
//			if(evaluate(v+1,m,arr,col)){
//				return true;
//			}
//			col[v] = 0;
//		}
//	}
//	return false;
//}
//
//void print(int arr[]){
//	cout<<"Solution Exists : ";
//	for(int i=0;i<4;i++){
//		cout<<arr[i]<<" ";
//	}
//}
//
//void setcolor(int m,int arr[4][4]){
//	int col[4] = {0};
//	if(!evaluate(0,m,arr,col)){
//		cout<<"No solution exists !";
//		return;
//	}
//	print(col);
//	
//}
//
//
//int main(){
//	int arr[4][4],m;
//	for(int i=0;i<4;i++){
//		for(int j=0;j<4;j++){
//			cin>>arr[i][j];
//		}
//	}
//	cin>>m;
//	setcolor(m,arr);
//}




#include<iostream>
using namespace std;


bool safe(int v,int m,int grid[4][4],int col[]){
	for(int i=0;i<4;i++){
		if(grid[v][i]==1&&col[i]==m){
			return false;
		}
	}
	return true;
}


bool evaluate(int v,int m,int grid[4][4],int col[]){
	if(v==4){
		return true;
	}
	for(int i=1;i<=m;i++){
		if(safe(v,i,grid,col)){
			col[v] = i;
			if(evaluate(v+1,m,grid,col)){
				return true;
			}
			col[v]=0;
		}
	}
	return false;
}


void print(int arr[]){
	cout<<"Solution -> ";
	for(int i=0;i<4;i++){
		cout<<arr[i]<<" ";
	}
}

void setcolor(int m,int grid[4][4]){
	int col[4] = {0};
	if(!evaluate(0,m,grid,col)){
		cout<<"No solution exists ";
		return;
	}
	print(col);
}


int main(){
	int grid[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>grid[i][j];
		}
	}
	int m;
	cin>>m;
	setcolor(m,grid);
}




