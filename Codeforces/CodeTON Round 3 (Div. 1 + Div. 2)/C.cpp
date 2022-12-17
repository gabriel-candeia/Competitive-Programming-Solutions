#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a, b;

        cin >> a >> b;
        char wantA = a[0], wantB = b[0];
        bool ok = true;
        vector<pair<int,int>> answ;

        if(a[0]!=b[0]){
            answ.push_back({1,n});
            for(auto &x:a)
                x = ((x=='0') ? '1' : '0');
            wantA = a[0];
        }

        for(int i=1;i<n;i++){   
            if(a[i]==wantA && b[i]==wantB){
                continue;
            }
            else if(a[i]!=wantA && b[i]!=wantB){
                wantA = ((wantA=='0') ? '1' : '0');
                answ.push_back({1,i});
                
            }
            else{
                ok = false;
            }
        }

        if(wantA=='1'){
            answ.push_back({1,n});
        }

        if(ok){
            cout << "YES\n";
            cout << answ.size() <<"\n";
            for(auto p:answ){
                cout << p.first << " " << p.second <<"\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
    

    return 0;   
}