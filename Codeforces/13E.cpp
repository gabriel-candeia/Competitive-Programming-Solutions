#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(){
    fastio();
    int n, m;
    vector<int> arr, nxt, cost;

    cin >> n >> m;
    const int block = sqrt(n);
    
    arr.assign(n,0), nxt.assign(n,0), cost.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    for(int i=n-1;i>=0;i--){
        if(i+arr[i]<n && (i+arr[i])/block == i/block)
            nxt[i] = nxt[i+arr[i]], cost[i] = cost[i+arr[i]]+1;
        else
            nxt[i] = i+arr[i], cost[i] = 1;
    }

    int op, a, b;
    while(m--){
        cin >> op;
        if(op==1){
            cin >> a;
            int answ = 0, last = a-1;
            for(;nxt[last]<n;answ+=cost[last], last=nxt[last]);
            for(;last+arr[last]<n;last+=arr[last],answ++);
            cout << last+1 << " " << answ+1 << '\n';
        }
        else{
            cin >> a >> b;
            int lim = ((a-1)/block)*block; 
            arr[a-1] = b;
            for(int i=a-1;i>=lim;i--){
                if(i+arr[i]<n && (i+arr[i])/block==i/block)
                    nxt[i] = nxt[i+arr[i]], cost[i] = cost[i+arr[i]]+1;
                else
                    nxt[i] = i+arr[i], cost[i] = 1;
            }
        }
    }

    return 0;
}