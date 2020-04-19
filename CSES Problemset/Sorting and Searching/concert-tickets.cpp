#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, t;
    multiset<int> h;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> t;
        h.insert(t);
    }

    for(int i=0;i<m;i++){
        cin >> t;
        if(h.size()){
            auto it = h.lower_bound(t);
            if(it==h.end()){
                it--;
            }
            if(it!=h.begin() && *it > t){
                it--;
            }
            if(*it<=t){
                cout << *it << '\n';
                h.erase(it);
            }
            else{
                cout << -1 <<'\n';
            }
        }
        else{
            cout << -1 <<'\n';
        }
    }

    return 0;
}