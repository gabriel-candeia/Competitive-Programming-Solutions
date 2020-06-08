#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    vector<int> a, first, last, lastnonzero;
    bool exist=false;

    cin >> n >>q;
    a.assign(n,0);

    first.assign(q+1,-1);
    last.assign(q+1,0);

    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==q){
            exist = true;
        }
    }

    if(!exist){
        for(int i=0;i<n;i++){
            if(a[i]==0){
                a[i] = q;
                break;
            }
        }
    }

    int t=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            lastnonzero[i] = t;
        }
        else{
            t = a[i];
            if(first[a[i]]==-1){
                first[a[i]] = i;
            }
            last[a[i]] = i;
        }
    }
    
    stack<int> st;
    bool poss = true;
    for(int i=0;i<n;i++){
        if(a[i]==0 && st.size()){
            a[i] = st.top();
        }
        else if(a[i]==0){
            a[i] = lastnonzero[i];
        }
        if(st.size() && a[i]<st.top()){
            poss = false;
            break;
        }
        if(i==first[a[i]]){
            st.push(a[i]);
        }
        if(i==last[a[i]]){
            st.pop();
        }
    }

    if(poss){
        cout << "YES\n";
        for(int i=0;i<n;i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}