#include<bits/stdc++.h>
using namespace std;

int n;
set<set<int>> subsets;

void subsetsum(vector<int>& prime, int trgt, int i, set<int>& set) {
    if(trgt==0){
        if(set.size()==n){
        subsets.insert(set);
        }
        return;
    }
    if(trgt<0||i<=0){
        return;
    }
    set.insert(prime[i-1]);
    subsetsum(prime,trgt-prime[i-1],i-1,set);
    set.erase(prime[i-1]);
    subsetsum(prime,trgt,i-1,set);
}

bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int s, p;
    cin >> s >> n >> p;
    vector<int> prime;
    set<int> set;
    for (int i = p + 1; i <= 1000; i++) {
        if (isprime(i)) {
            prime.push_back(i);
        }
    }
    subsetsum(prime, s, prime.size(), set);

    cout << n << " Prime numbers greater than " << p << " with sum = " << s << " are :\n";
    for (auto subset : subsets) {
        for (int num : subset) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

