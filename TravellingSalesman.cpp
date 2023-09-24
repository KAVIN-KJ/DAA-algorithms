//#include<bits/stdc++.h>
//using namespace std;
//int minc = INT_MAX;
//vector<int> minpath;
//int vert;
//
//
//void mincost(vector<vector<int> > &graph,vector<int> &path,vector<bool> &visited,int curr,int count,int &cost){
//	if(count==vert){
//		if(graph[curr][0]!=0&& cost<minc){
//			cost+=graph[curr][0];
//				minc = cost;
//				minpath = path;
//		}
//		return;
//	}
//	
//	for(int i=0;i<vert;i++){
//		if(!visited[i]&&graph[curr][i]!=0){
//			visited[i] = true;
//			path[count] = i;
//			int co = cost+graph[curr][i];
//			mincost(graph,path,visited,i,count+1,co);
//			visited[i] = false;
//		}
//	}
//	
//}
//
//
//void tsp(vector<vector<int> > &graph){
//	vector<int> path(vert,0);
//	vector<bool> visited(vert,false);
//	visited[0] = true;
//	int curr=0;
//	int count=1;
//	int cost=0;
//	mincost(graph,path,visited,curr,count,cost);
//	cout<<"Minimun cost : "<<minc;
//	cout<<"Path to be followed : ";
//	for(int i : minpath){
//		cout<<i<<" ->";
//	}
//}
//
//int main(){
//	cin>>vert;
//	vector<vector<int> >graph(vert,vector<int>(vert));
//	for(int i=0;i<vert;i++){
//		for(int j=0;j<vert;j++){
//			cin>>graph[i][j];
//		}
//	}
//	tsp(graph);
//}


//#include<bits/stdc++.h>
//using namespace std;
//int mincost = INT_MAX;
//vector<int> minpath;
//int v;
//
//void travel(vector<vector<int> >&graph,vector<int>&path,vector<bool>&vis,int curr,int count,int cost){
//	if(count==v&&graph[curr][0] != 0){
//		if(cost<mincost){
//			cost+=graph[curr][0];
//			mincost = cost;
//			minpath = path;
//		}
//		return;
//	}
//	for(int i=0;i<v;i++){
//		if(!vis[i]&&graph[curr][i]!=0){
//			vis[i] = true;
//			path[count] = i;
//			travel(graph,path,vis,i,count+1,cost+graph[curr][i]);
//			vis[i] = false;
//		}
//	}
//}
//
//void tsp(vector<vector<int> > &graph){
//	vector<int> path(v,0);
//	vector<bool> vis(v,false);
//	vis[0] = true;
//	int curr=0;
//	int count=1;
//	int cost=0;
//	travel(graph,path,vis,curr,count,cost);
//	cout<<"Minimum cost : "<<mincost<<endl;
//	cout<<"Path : ";
//	for(int i : path){
//		cout<<i<<" ->";
//	}
//	cout<<path[0];
//}
//
//int main(){
//	cin>>v;
//	vector<vector<int> >graph(v,vector<int>(v));
//	for(int i=0;i<v;i++){
//		for(int j=0;j<v;j++){
//			cin>>graph[i][j];
//		}
//	}
//	tsp(graph);
//}



#include<bits/stdc++.h>
using namespace std;
int n;
int mincost = INT_MAX;
vector<int> minpath;

void solve(vector<vector<int> >&graph,vector<bool> &vis,vector<int> &path,int curr,int count,int cost){
	if(count==n&&graph[curr][0]!=0){
		cost+=graph[curr][0];
		if(cost<mincost){
			mincost = cost;
			minpath = path;
		}
			return;
	}
	for(int i=1;i<n;i++){
		if(graph[curr][i]!=0&&!vis[i]){
			vis[i] = true;
			path[count] = i;
			solve(graph,vis,path,i,count+1,cost+graph[curr][i]);
			vis[i] = false;
			path[count] = 0;
		}
	}
	
}


void travel(vector<vector<int> >&graph){
	vector<bool> vis(n,false);
	vector<int> path(n,0);
	vis[0] = true;
	path[0] = 0;
	solve(graph,vis,path,0,1,0);
	cout<<"Minimum cost : "<<mincost<<endl;
	cout<<"Path : ";
	for(int i : minpath){
		cout<<i<<" ->";
	}
	cout<<path[0];
}

int main(){
	cin>>n;
	vector<vector<int> >graph(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	travel(graph);
}








