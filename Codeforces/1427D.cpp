#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr, best;
    vector<vector<int>> answ;

    cin >> n;
    arr.assign(n,0);
    best.assign(n,1);
    for(auto &x:arr) cin >> x;

    for(int i=0;i<n;i++){
        int pi = -1, pj = -1;
        for(int j=0;j<n && pi==-1;j++)
            for(int k=j+1;k<n && pi==-1;k++)
                if(arr[j]==arr[k]+best[k])
                    pi = j, pj = k;
        if(pi==-1 && pj==-1) break;
        vector<int> novo;
        int x = 0;
        if(pi!=0) novo.push_back(pi), x = pi;
        novo.push_back((pj-pi)); x+= (pj-pi);
        novo.push_back(best[pj]); x+= best[pj];
        if(x!=n) novo.push_back(n-x);
        answ.push_back(novo);
        vector<int> na;
        int ptr = n;
        for(int i=novo.size()-1, x;i>=0;i--){
            x = novo[i];
            ptr-=x;
            for(int j=0;j<x;j++)
                na.push_back(arr[ptr+j]);
        }
        arr = na;

        best.assign(n,1);
        for(int i=n-2;i>=0;i--){
            if(arr[i]+1==arr[i+1])
                best[i] = best[i+1]+1;
        }
    }
    cout << answ.size() << "\n";
    for(auto arr:answ){
        cout << arr.size() << " ";  
        for(auto x:arr)
            cout << x << " ";
        cout <<'\n';
    }

    return 0;
}