//#include <iostream>
//#include <vector>
//using namespace std;
//const int N = 8; 
////const int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
////const int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};
//const int moveX[] = {1, -1, 1, -1, 2, -2, 2, -2};
//const int moveY[] = {2, 2, -2, -2, 1, 1, -1, -1};
//bool isValid(int x, int y, vector<vector<int> >& board) {
//    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
//}
//bool knightTour(vector<vector<int> >& board, int x, int y, int moveCount) {
//     if (moveCount == N * N)
//        return true;
//    for (int i = 0; i < 8; i++) {
//        int nextX = x + moveX[i];
//        int nextY = y + moveY[i];
//        if (isValid(nextX, nextY, board)) {
//            board[nextX][nextY] = moveCount;
//            if (knightTour(board, nextX, nextY, moveCount + 1))
//                return true; 
//            board[nextX][nextY] = -1;
//        }
//    }
//
//    return false; 
//}
//
//int main() {
//    vector<vector<int> > grid;
//    for(int i=0;i<N;i++){
//    	vector<int> temp;
//    	for(int i=0;i<N;i++){
//    		temp.push_back(-1);
//		}
//		grid.push_back(temp);
//	}
//    int startX = 0;
//    int startY = 0;
//    int moveCount = 0;
//    grid[startX][startY] = moveCount;
//    if (knightTour(grid, startX, startY, moveCount + 1)) {
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                cout << grid[i][j] << "\t";
//            }
//            cout << endl;
//        }
//    } else {
//        cout << "No solution exists!" << endl;
//    }
//
//    return 0;
//}



//#include<bits/stdc++.h>
//#define n 8
//const int movex[] = {2,1,-1,-2,-2,-1,1,2};
//const int movey[] = {1,2,2,1,-1,-2,-2,-1};
//using namespace std;
//
//bool isValid(int x, int y, vector<vector<int> >& grid) {
//    return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == -1);
//}
//
//bool solve(vector<vector<int> >& grid, int x, int y, int move) {
//    if (move == n * n) {
//        return true; // All squares have been visited
//    }
//
//    for (int i = 0; i < 8; i++) {
//        int nx = x + movex[i];
//        int ny = y + movey[i];
//        if (isValid(nx, ny, grid)) {
//            grid[nx][ny] = move;
//            if (solve(grid, nx, ny, move + 1)) {
//                return true; // If a valid move leads to a solution, return true
//            }
//            grid[nx][ny] = -1; // If no solution is found, backtrack
//        }
//    }
//
//    return false;
//}
//
//int main() {
//    vector<vector<int> > grid(n, vector<int>(n, -1));
//
//    int startX = 0;
//    int startY = 0;
//
//    grid[startX][startY] = 0; // Mark the initial square
//
//    if (solve(grid, startX, startY, 1)) {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                printf("%-4d", grid[i][j]);
//            }
//            cout << endl << endl;
//        }
//    } else {
//        cout << "No solution exists!" << endl;
//    }
//
//    return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
int n;
int tot=0;
int movex[] = {2,1,-1,-2,-2,-1,1,2};
int movey[] = {1,2,2,1,-1,-2,-2,-1};
bool issafe(int x,int y,vector<vector<int> >&grid){
	return (x>=0&&y>=0&&x<n&&y<n&&grid[x][y]==-1);
}

bool solve(int x,int y,vector<vector<int> >&grid,int move){
	if(move==n*n){
		tot++;
		return true;
	}
	for(int i=0;i<8;i++){
		int nx = x+movex[i];
		int ny = y+movey[i];
		if(issafe(nx,ny,grid)){
			grid[nx][ny] = move;
			if(solve(nx,ny,grid,move+1)){
				tot++;
				return true;
			}
			grid[nx][ny]=-1;
		}
	}
	return false;
}

void print(vector<vector<int> >& grid){
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid.size();j++){
			printf("%-4d",grid[i][j]);
		}
		cout<<"\n\n";
	}
}
int main(){
	cin>>n;
	vector<vector<int> > grid(n,vector<int>(n,-1));
	int x=0;
	int y=0;
	int move=0;
	grid[x][y] = 0;
	if(solve(x,y,grid,move+1)){
		print(grid);
	}
	else{
		cout<<"No solution exists !";
	}
}


















