#include<bits/stdc++.h>
#define N int(1e5+3)
using namespace std;

int main(){
    int a[N], b[N], n, k, j;
    priority_queue<pair<int,int>> h;
    pair<int,int> u;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        h.push(make_pair(-b[i]/a[i],i));
    }

    while(k>0){
        u = h.top(); h.pop();
        j = u.second;
        int temp = a[j] - b[j]%a[j];
        b[j] += min(k,temp);
        k -= min(k,temp);
        h.push(make_pair(-b[j]/a[j],j));
    }

    cout << -h.top().first << '\n';

    return 0;
}