#include <bits/stdc++.h>

using namespace std;


#define maxn 100100

int n;
array<int, 3> v[maxn];

int main(){
    int meta;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i+1;
        meta = v[i][0];
    }
    sort(v, v+n);
    int i = 0, rec = 1, id, auxr = 1; bool ok = true;
    vector<int> ans;
    while(i < n && rec < meta && ok){
        ok = false;
        for(int j = i; j < n; j++){
            if(v[j][0] <= rec){
                if(v[j][1] > auxr){
                    auxr = v[j][1];
                    id = v[j][2]; 
                }
            }else{
                rec = auxr;
                i = j;
                ok = true;
                ans.emplace_back(id);
                break;
            }
        } 
    }
    if(rec >= meta){
        ans.emplace_back(n);
        cout << ans.size() << "\n";
        for(int sla:ans){
            cout << sla << " ";
        }        
        cout << "\n";
    }else{
        cout << "No such luck\n";
    }
    return 0;
}