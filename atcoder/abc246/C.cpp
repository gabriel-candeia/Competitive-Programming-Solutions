#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    int k, x;
    priority_queue<int> pq;

    cin >> n >> k >> x;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() && k){
        int u = pq.top();
        pq.pop();
        if(u>x){
            int d = min(k,u/x);
            u = u - d*x;
            k -= d;
            pq.push(u);
        }
        else{
            k--;
        }
    }

    ll answ = 0;
    while(pq.size()){
        answ += pq.top(), pq.pop();
    }

    cout << answ <<"\n";

    return 0;
}