#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, acm;
    vector<int> r1, r2;

    cin >> n;
    if(n%4!=3 && n%4!=0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    acm = n*(n+1)/4;
    for(int i=n;i>=1;i--){
        if(acm>=i){
            acm-=i;
            r1.push_back(i);
        }
        else{
            r2.push_back(i);
        }
    }

    cout << r1.size() << '\n';
    for(auto i:r1){
        cout << i << ' ';
    }
    cout << '\n';

    cout << r2.size() << '\n';
    for(auto i:r2){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}