#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int answ1=0, answ2=0;
    map<int,int> freq;

    
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x:a)
        cin >> x;
    for(auto &x:b)
        cin >> x;

    for(int i=0;i<n;i++){
        answ1+=(a[i]==b[i]);
        freq[a[i]]++;
    }
    for(int i=0;i<n;i++){
        answ2+=freq[b[i]];
    }

    cout << answ1 << "\n" << answ2-answ1 <<"\n";

    return 0;
}