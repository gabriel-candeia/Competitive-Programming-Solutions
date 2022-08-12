#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, soma = 0;
    stack<pair<int,int>> st;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;

        if(st.size()==0 || x!=st.top().first){
            st.push({x,1});
            soma++;
        }
        else if(x==st.top().first){
            st.top().second++;
            soma++;
            if(st.top().first==st.top().second){
                st.pop();
                soma-=x;
            }
        }
        cout << soma <<"\n";

    }

    return 0;
}