#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum=0;
    vector<int> dg;

    cin >> n;
    dg.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> dg[i];
        sum += dg[i];
    }

    if(sum<2*(n-1)){
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES ";
    
    
    vector<int> leaves, internal;
    for(int i=0;i<n;i++){
        if(dg[i]-1)
            internal.push_back(i);
        else
            leaves.push_back(i);
    }
    
    cout << internal.size()-1 + min(2,(int) leaves.size()) << '\n';
    cout << n-1 <<'\n';
    if(leaves.size()){
        dg[internal.back()]--;
        cout << internal.back()+1 << " " << leaves.back()+1 << '\n';
        leaves.pop_back();
    }
    for(int i=0;i<internal.size();i++){
        if(i+1<internal.size()){
            dg[internal[i+1]]--;
            dg[internal[i]]--;
            cout << internal[i]+1 << " " << internal[i+1]+1 << '\n';
        }
        for(int j=1;j<=dg[internal[i]] && leaves.size();j++){
            cout << internal[i]+1 << " " << leaves.back()+1 << '\n';
            leaves.pop_back();
        }
    }
    return 0;
}