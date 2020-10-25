#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n, x;
    vector<int> a, pos;

    cin >> n;
    a.assign(8,0);
    pos.assign(8+1,0);
    for(int i=0;i<8;i++){
        a[i] = i+1;
        pos[i+1] = i;
    }

    for(int i=0;i<n;i++){
        cin >> x;
        
        swap(a[pos[x]-1],a[pos[x]]);
        pos[a[pos[x]]] = pos[x];
        pos[x]--;
    }

    for(auto x:a){
        cout <<  x << " ";
    }cout<<'\n';

    return 0;
}