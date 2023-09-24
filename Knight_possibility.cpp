#include<bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
vector<vector<int>> board;
int movex[] = {2, 1, -1, -2, -2, -1, 1, 2};
int movey[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool safe(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

void solve(int x, int y, int move) {
    if (move == n * n) {
        cnt++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + movex[i];
        int ny = y + movey[i];
        if (safe(nx, ny)) {
            board[nx][ny] = move;
            solve(nx, ny, move + 1);
            board[nx][ny] = -1;
        }
    }
}

int main() {
    cin >> n;
    int x, y;
    cin >> x >> y;
    board.assign(n, vector<int>(n, -1));
    board[x-1][y-1] = 0;
    solve(x-1, y-1, 1);
    if (cnt > 0) {
        cout << cnt;
    } else {
        cout << "-1";
    }
    return 0;
}


// You are using GCC
//#include<iostream>
//using namespace std;
//int board[100][100];
//int count=0;
//int x[]={2,1,-1,-2,-2,-1,1,2};
//int y[]={1,2,2,1,-1,-2,-2,-1};
//bool issafe(int x,int y,int n)
//{
//    return(x>=0 && y>=0 && x<n && y<n && board[x][y]==-1);
//}
//void isknight(int n,int si,int si2,int move)
//{
//    if(move == n*n)
//    {
//        count++;
//        return;
//    }
//    for(int i=0;i<8;i++)
//    {
//        int nextx=si+x[i];
//        int nexty=si2+y[i];
//        if(issafe(nextx,nexty,n))
//        {
//            board[nextx][nexty]=move;
//            isknight(n,nextx,nexty,move+1);
//            board[nextx][nexty]=-1;
//        }
//    }
//}
//int main()
//{
//    int n,si,si2;
//    cin>>n>>si>>si2;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            board[i][j]=-1;
//        }
//    }
//    board[si-1][si2-1]=0;
//    isknight(n,si-1,si2-1,1);
//    if(count>0)
//    {
//        cout<<count;
//    }
//    else
//    {
//        cout<<-1;
//    }
//}
