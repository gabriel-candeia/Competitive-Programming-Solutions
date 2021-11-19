#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr, answ;
    priority_queue<pair<int,int>> pq;

    cin >> n;
    arr.assign(n,0); answ.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        answ[i] = x;
        pq.push(pair<int,int>{-answ[i],i});
    }

    int d, u;
    while(pq.size()){
        tie(d,u) = pq.top(), pq.pop();
        
        d = -d;

        if(d>answ[u]) continue;

        if(d+arr[u]<answ[(u+1)%n]){
            answ[(u+1)%n] = d+arr[u];
            pq.push(pair<int,int>{-answ[(u+1)%n],(u+1)%n});
        }
    }

    for(int i=0;i<n;i++)
        cout << answ[i] << "\n";

    return 0;
}