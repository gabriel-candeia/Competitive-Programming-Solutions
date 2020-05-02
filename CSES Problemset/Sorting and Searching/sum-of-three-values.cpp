#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    vector<int> arr;
    set<pair<int,int>> s;

    cin >> n >> x;
    arr.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> arr[i];
        s.insert({arr[i],i});

    }

    int i, j, k;
    for(i=0;i<n;i++){
        auto it1 = s.lower_bound({arr[i],0});
        s.erase(it1);

        for(j=0;j<n;j++){
            if(j!=i){
                auto it2 = s.lower_bound({arr[j],0});
                s.erase(it2);

                auto it3 = s.lower_bound({x-arr[i]-arr[j],0});
                if(it3!=s.end() && (*it3).first==x-arr[i]-arr[j]){
                    k  = (*it3).second;
                    goto fim;
                }

                s.insert({arr[j],j});
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;

    fim:
    cout << i+1 << ' '<< j+1 << ' ' << k+1 <<"\n";
    return 0;
}