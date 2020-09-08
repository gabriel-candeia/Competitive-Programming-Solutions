#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;

    cin >> t;
    while(t--){
        set<int> s;
        cin >> n;
        while(n--){
            cin >> x;
            if(x)
                s.insert(x);
        }

        cout << s.size() <<'\n';
    }
    return 0;
}\