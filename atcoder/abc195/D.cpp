#include<bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> boxes;
vector<pair<int,int>> items;

int teste(int l, int r){
    vector<int> arr;
    for(int i=0;i<m;i++){
        if(l<=i && i<=r) continue;
        arr.push_back(boxes[i]);
    }

    sort(arr.begin(),arr.end());
    priority_queue<int> pq;
    int answ = 0;
    for(int i=0, j=0;i<arr.size();i++){
        for(;j<n && items[j].first<=arr[i];j++)
            pq.push(items[j].second);
        if(pq.size())
            answ += pq.top(), pq.pop();
    }
    return answ;
}

int main(){
    cin >> n >> m >> q;

    items.assign(n,{0,0});
    for(auto &x:items)
        cin >> x.first >> x.second;

    boxes.assign(m,0);
    for(auto &x:boxes)
        cin >> x;
    sort(items.begin(),items.end());

    int l, r;
    for(int i=0;i<q;i++){
        cin >> l >> r;
        l--, r--;
        cout << teste(l,r) << '\n';
    }

    return 0;
}