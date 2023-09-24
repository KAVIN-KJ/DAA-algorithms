#include <bits/stdc++.h>
using namespace std;

int V;

bool safe(vector<vector<int> > &graph, vector<int> &path, int curr, int v) {
    if (graph[path[v - 1]][curr] == 0) {
        return false;
    }
    for (int i = 0; i < curr; i++) {
        if (path[i] == curr) {
            return false;
        }
    }
    return true;
}

bool hamiltonianutil(vector<vector<int> > &graph, vector<int> &path, int curr) {
    if (curr == V) {
        if (graph[path[curr - 1]][path[0]] == 1) {
            return true;
        }
		 else {
            return false;
        }
    }
    for (int i = 1; i < V; i++) {
        if (safe(graph, path, curr, i)) {
            path[curr] = curr;
            if (hamiltonianutil(graph, path, curr + 1)) {
                return true;
            }
            path[curr] = -1; // Backtrack
        }
    }
    return false;
}

void hamiltonian(vector<vector<int> > &graph) {
    vector<int> path(V, -1);
    path[0] = 0;
    if (!hamiltonianutil(graph, path, 1)) {
        cout << "No solution exists" << endl;
        return;
    } else {
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl;
    }
}

int main() {
    cin >> V;
    vector<vector<int> > graph(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    hamiltonian(graph);
    return 0;
}


//*********************************************************************

//#include<bits/stdc++.h>
//using namespace std;
//int V;
//
//
//bool hamutil(vector<vector<int> > &graph,vector<int> &path,vector<bool> &visited,int v){
//	if(path.size()==v){
//		if(graph[path[v-1]][0]==1){
//			return true;
//		}
//		else{
//			return false;
//		}
//	}
//	
//	for(int av=1;av<V;av++){
//		if(visited[av]==false){
//			visited[av] = true;
//			path[av] = av;
//			if(hamutil(graph,path,visited,v+1)){
//				return true;
//			}
//			path[av] = -1;
//			visited[av] = false;
//		}
//	}
//	return false;
//	
//}
//
//
//void hamilton(vector<vector<int> > &graph){
//	vector<int> path(V);
//	vector<bool> visited(V, false);
//	path[0] = 0;
//	visited[0] = true;
//	if(hamutil(graph,path,visited,1)){
//		cout<<"Solution found ! \n";
//		for(int i : path){
//			cout<<i<<" ";
//		}
//		cout<<path[0]<<" \n";
//	}
//	else{
//		cout<<"No solution exists !";
//	}
//}
//
//
//int main(){
//	cin>>V;
//	vector<vector<int> > graph(V, vector<int>(V));
//	for(int i=0;i<V;i++){
//		for(int j=0;j<V;j++){
//			cin>>graph[i][j];
//		}
//	}
//	hamilton(graph);
//}

//*****************************************************************************


//#include<bits/stdc++.h>
//using namespace std;
//int n;
//
//bool solve(vector<vector<int> > &graph, vector<int> &path, vector<bool> &vis,int v){
//	if(v==n){
//		if(graph[path[v-1]][0]==1){
//			return true;
//		}
//		else{
//			return false;
//		}
//	}
//	for(int i=1;i<n;i++){
//		if(!vis[i]){
//			vis[i] = true;
//			path[v] = i;
//			if(solve(graph,path,vis,v+1)) return true;
//			vis[i] = false;
//			path[v] = -1;
//		}
//	}
//	return false;
//}
//
//
//void hamilton(vector<vector<int> > &graph){
//	vector<int> path(n,-1);
//	vector<bool> vis(n,false);
//	path[0] = 0;
//	vis[0] = true;
//	if(solve(graph,path,vis,1)){
//		cout<<"Solution exists : ";
//		for(int i=0;i<n;i++){
//			cout<<path[i]<<" ";
//		}
//		cout<<path[0]<<endl;
//	}
//	else{
//		cout<<"No solution ";
//	}
//}
//
//int main(){
//	cin>>n;
//	vector<vector<int> >graph(n, vector<int>(n));
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cin>>graph[i][j];
//		}
//	}
//	hamilton(graph);
//}













