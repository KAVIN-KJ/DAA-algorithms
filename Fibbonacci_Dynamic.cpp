

//***********FIND N'TH FIBONACCI ELEMENT USING RECURSION***********************
/*
#include<iostream>
#include<vector>
using namespace std;
int fibb(int n){
	if(n<=1){
		return n;
	}
	return fibb(n-1)+fibb(n-2);
}
int main(){
	int n;
	cin>>n;
	cout<<fibb(n);
}
*/
//********* USING DYNAMIC PROGRAMMING***************

#include<iostream>
#include<vector>
using namespace std;
void fibb(int n){
	vector<int>fib(n+1);
	fib[0] = 0;
	fib[1] = 1;
	for(int i=2;i<=n;i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	cout<<"Nth fibonacci element is : "<<fib[n]<<endl;
	for(auto i : fib){
		cout<<i<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	fibb(n);
}

