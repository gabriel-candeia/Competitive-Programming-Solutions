#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    char d;
    vector<pair<int,int>> val;
    vector<int> color;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        val.clear();
        color.assign(n,2);
        for(int i=0;i<n;i++){
            cin >> d;
            val.push_back({d-'0',i});
        }
        sort(val.begin(),val.end());

        int last = -1;
        int menor2 = INT_MAX;
        for(int i=0;i<n;i++){
            if(val[i].second>last && val[i].first<=menor2){
                color[val[i].second] = 1;
                last = val[i].second;
            }
            else if(menor2==INT_MAX){
                menor2 = val[i].first;
            }
        }

        last = -1;
        bool poss = true;
        for(int i=1;i<n;i++){
            if(color[val[i].second]==2){
                if(val[i].second>last){
                    last = val[i].second;
                }
                else{
                    poss = false;
                    break;
                }   
            }
        }

        if(poss){
            for(int i=0;i<n;i++){
                cout << color[i];
            }
            cout << '\n';
        }
        else{
            cout << "-\n";
        }
    }

    return 0;
}