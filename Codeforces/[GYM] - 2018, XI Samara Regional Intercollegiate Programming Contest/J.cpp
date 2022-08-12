#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    map<int,int> freq;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    ll acm = 0, answ = 0;
    for(auto p:freq){
        acm += (p.second/2);
    }

    cout << acm/2 <<"\n";

    return 0;
}