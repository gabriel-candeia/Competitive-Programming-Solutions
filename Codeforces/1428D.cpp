#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    
    vector<int> arr;
    vector<pair<int,int>> seq[3], answ;

    cin >> n;
    int last = n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    bool poss = true;
    for(int i=n-1;i>=0 && poss;i--){
        if(!arr[i]) continue;
        if(arr[i]==1){
            answ.push_back({i+1,last});
            seq[0].push_back({i+1,last--});
        }
        else if(arr[i]==2){
            if(seq[0].size()==0){
                poss = false;
            }
            else{
                seq[1].push_back({i+1,seq[0].back().second});
                answ.push_back({i+1,seq[0].back().second});
                seq[0].pop_back();
            }
        }
        else{
            if(seq[0].size()==0 && seq[1].size()==0 && seq[2].size()==0){
                poss = false;
            }
            else{
                pair<int,int> next;
                if(seq[2].size()){
                    next = seq[2].back();
                    seq[2].pop_back();
                }
                else if(seq[1].size()){
                    next = seq[1].back();
                    seq[1].pop_back();
                }
                else{
                    next = seq[0].back();
                    seq[0].pop_back();
                }
                answ.push_back({i+1,last});
                seq[2].push_back(answ.back());
                answ.push_back({next.first,last--});
            }
        }
    }

    if(!poss)   
        cout << -1 <<'\n';
    else{
        cout << answ.size() <<'\n';
        for(auto p:answ)
            cout << p.second << " " << p.first <<"\n";
    }

    return 0;
}