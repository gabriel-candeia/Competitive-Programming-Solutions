#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<int> st;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        st.insert(x);
    }

    while(true){
        auto it = (--st.end());
        int x = (*it), y=x;
        bool flag = false;
        st.erase(it);
        for(x/=2;x && !flag;x/=2)
            if(st.find(x)==st.end())
                y = x, flag = true;
        st.insert(y);
        if(!flag) break;
    }

    for(auto x:st)
        cout << x << " ";
    cout<<'\n';

    return 0;
}