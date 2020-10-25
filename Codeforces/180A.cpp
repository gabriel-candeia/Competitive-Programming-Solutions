#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, x;
    map<int,int> mp;
    vector<vector<int>> ls;

    cin >> n >> m;
    ls.assign(m+1,vector<int>());
    for(int i=1;i<=m;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> x;
            mp[x] = i;
            ls[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!mp[i]){
            ls[0].push_back(i);        
        }
    }
    
    int pos = 1; k=0;
    string answ = "";
    for(int i=1;i<=m;i++){
        for(auto &p:ls[i]){
            if(p!=pos){
                if(mp[pos]){
                    for(auto &x:ls[mp[pos]]){
                        if(x==pos){
                            answ += to_string(x) + " " + to_string(ls[0][0]) + '\n';
                            swap(mp[x],mp[ls[0][0]]);
                            swap(x,ls[0][0]);
                            break;
                        }
                    }
                    k++;
                }
                for(auto &x:ls[0]){
                    if(x==pos){
                        answ += to_string(p) + " " + to_string(x) + '\n';
                        swap(mp[x],mp[p]);
                        swap(x,p);
                        break;
                    }
                }
                k++;
            }
            pos++;
        }
    }

    cout << k << '\n';
    cout << answ;

    return 0;
}