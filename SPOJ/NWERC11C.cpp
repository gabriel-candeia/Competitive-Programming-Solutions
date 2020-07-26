#include<bits/stdc++.h>
#define N 2e5+5
using namespace std;

struct FenwickTree{
    vector<int> bit;
    int n;

    FenwickTree(int x){
        n = x;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    int cases;
    vector<int> arr(N,0);
    cin >> cases;

    while(cases--){
        int m, r, a, top;
        map<int,int> pos;    

        cin >> m >> r;

        for(int i=1;i<=m;i++){
            pos[i] = m-i+1;
            arr[i] = 1;
        }

        top = m;
        FenwickTree t(arr);
        while(r--){
            cin >> a;
            cout << m-t.sum(pos[a]) << ' ';
            t.add(pos[a],-1);
            pos[a] = ++top;
            t.add(pos[a],1);
        }
        cout << '\n';
        for(int i=1;i<=m;i++){
            arr[i] = 0;
        }
    }
    return 0;
}