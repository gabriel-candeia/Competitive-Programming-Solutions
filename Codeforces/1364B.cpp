#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    vector<int> p;

    cin >> t;
    while(t--){
        cin >> n;
        p.assign(n,0);
        vector<int> answ;

        for(int i=0;i<n;i++){
            cin >> p[i];
        }

        answ.push_back(p[0]);
        for(int i=1;i<n-1;i++){
            if((p[i]>p[i-1] && p[i]>p[i+1]) || (p[i]<p[i-1] && p[i]<p[i+1])){
                answ.push_back(p[i]);
            }
        }
        answ.push_back(p[n-1]);
        cout << answ.size() << '\n';
        for(auto x:answ){
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}