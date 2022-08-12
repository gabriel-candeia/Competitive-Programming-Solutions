#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<int> arr, pos;

    cin >> n;
    arr.assign(2020,0);
    pos.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> pos[i];
        arr[pos[i]] = i;
    }
    
    int x;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> x;
        if(pos[x]==2019 || arr[pos[x]+1]!=0){
            continue;
        }
        
        arr[pos[x]] = 0;
        pos[x]++;
        arr[pos[x]] = x;
    }

    for(int i=1;i<=n;i++)
        cout << pos[i] << "\n";

    return 0;
}