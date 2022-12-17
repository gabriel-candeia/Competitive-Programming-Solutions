#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr;
    arr.assign(m,0);
    for(auto &x:arr)
        cin >> x;

    int val = 1;
    vector<int> one(m,0), answ(m,0);

    for(int i=0;i<m;i++){
        one[i] = val;
        if(arr[i]==val){
            val = val+1;
        }
        else if(arr[i]+1==val){
            val = val-1;
        }
    }
    
    vector<int> p(n+1,0), invp(n+1,0);
    for(int i=1;i<=n;i++){
        p[i] = i;
        invp[p[i]] = i;
    }

    /*for(int i=0;i<m;i++){
        cout << one[i] << " ";
    }cout<<"\n";*/

    for(int i=m-1;i>=0;i--){
        answ[i] = p[one[i]];

        /*for(int i=1;i<=n;i++)
            cout << p[i] << " ";
        cout<<"\n";
        for(int i=1;i<=n;i++)
            cout << invp[i] << " ";
        cout<<"\n";
        cout <<"\n";*/

        swap(p[arr[i]],p[arr[i]+1]);
        invp[p[arr[i]]] = arr[i];
        invp[p[arr[i]+1]] = arr[i]+1;
    }

    for(int i=0;i<m;i++){
        cout << answ[i] << "\n";
    }

    return 0;
}