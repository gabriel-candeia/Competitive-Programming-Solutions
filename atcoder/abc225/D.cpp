#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n, q;
    vector<int> last, next;

    cin >> n >> q;
    last.assign(n+1,-1);
    next.assign(n+1,-1);

    while(q--){
        int op, x, y;
        cin >> op;
        if(op==1){
            cin >> x >> y;
            last[x] = y;
            next[y] = x;
        }
        else if(op==2){
            cin >> x >> y;
            last[x] = -1;
            next[y] = -1;
        }
        else{
            cin >> x;
            for(;next[x]!=-1;x = next[x]);
            vector<int> answ;
            for(;x!=-1;x = last[x])
                answ.push_back(x);
            cout << answ.size() << " ";
            for(auto x:answ)
                cout << x << " ";
            cout <<"\n";
        }
    }


    return 0;
}