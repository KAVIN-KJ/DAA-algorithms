#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	x = abs(x);
	y = abs(y);
	if(x%2==0&&y&2==0||x%2!=0&&y&2!=0){
		cout<<max(x,y)/2<<endl;
	}
	else{
		cout<<max(x,y)/2 + 1<<endl;
	}
}
