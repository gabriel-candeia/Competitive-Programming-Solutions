#include<bits/stdc++.h>
using namespace std;
const int INF = int(1e5)+69420;

int main(){
    int n, mex=0;
    vector<int> a, b;
    stack<int> free;
    vector<bool> visited;
    bool poss = true;

    cin >> n;
    a.assign(n,0);
    b.assign(n,-1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        free.push(i);
        if(mex<=a[i] && free.size()>=a[i]-mex){
            while(a[i]-mex){
                b[free.top()] = mex++;
                free.pop();
            }
        }
        else{
            poss = false;
            break;
        }
    }

    while(free.size()){
        b[free.top()] = INF;
        free.pop();
    }

    if(poss){
        for(int i=0;i<n;i++){
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}