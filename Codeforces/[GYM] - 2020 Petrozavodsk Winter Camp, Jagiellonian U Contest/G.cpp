#include<bits/stdc++.h>
#define ld double
#define ll long long
#define ii pair<int, int>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<array<int,3>> p;
        vector<array<pair<int,int>,4>> answ;

        cin >> n;
        for(int k=0;k<2;k++){
            for(int i=0,x,y;i<n;i++){
                cin >> x >> y;
                p.push_back({x,y,k});
            }
        }

        
        int ht = -101;

        sort(p.begin(),p.end());
        vector<array<int,3>> st;
        for(int i=0;i<2*n;i++){
            if(st.size()==0 || st.back()[2]==p[i][2])
                st.push_back(p[i]);
            else{
                auto a = st.back(), b = p[i];
                if(a[2]==0) swap(a,b);
                answ.push_back({ii{a[0],a[1]},ii{a[0],ht},ii{b[0],ht},ii{b[0],b[1]}});
                ht--;
                st.pop_back();
            }
        }

        for(auto x:answ){
            cout << x.size() << "\n";
            for(auto y:x){
                cout << y.first << " " << y.second <<'\n';
            }
        }
        
    }

    return 0;
}