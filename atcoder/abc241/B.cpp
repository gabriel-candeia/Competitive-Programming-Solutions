#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    bool ok = true;
    map<int,int> freq;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        ok = (ok && freq[x]);
        freq[x]--;
    }
    
    if(ok){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }


    return 0;
}