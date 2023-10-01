//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void generate_permutations(string& str, int start, int end) {
//    if (start == end) {
//        cout << str << endl;
//        return;
//    }
//    for (int i = start; i <= end; i++) {
//        swap(str[start], str[i]);
//        generate_permutations(str, start + 1, end);
//        swap(str[start], str[i]);
//    }
//}
//int main() {
//    string input;
//    cin >> input;
//
//    int n = input.length();
//
//    generate_permutations(input, 0, n - 1);
//
//    return 0;
//}



#include<bits/stdc++.h>
using namespace std;
bool perm(string s,int st,int nd){
	if(st==nd){
		cout<<s<<endl;
		return true;
	}
	for(int i=st;i<=nd;i++){
		swap(s[i],s[st]);
		if(perm(s,st+1,nd))
		swap(s[i],s[st]);
	}
	return false;
}
int main(){
	string s;
	cin>>s;
	perm(s,0,s.size()-1);
}





