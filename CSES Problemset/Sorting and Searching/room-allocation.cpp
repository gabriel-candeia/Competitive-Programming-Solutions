#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, cnt=0, answ=0;
    vector<pair<int,int>> p;
    vector<int> room;
    set<int> freerooms;

    cin >> n;
    room.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        p.push_back({a,-(i+1)});
        p.push_back({b,+(i+1)});
        freerooms.insert(i+1);
    }

    sort(p.begin(),p.end());

    for(auto x:p){
        if(x.second<0){
            //find largest clique
            cnt++;

            //find rooms
            room[-x.second-1] = (*freerooms.begin());
            freerooms.erase(freerooms.begin());
        }
        else{
            //find largest clique
            cnt--;

            //find room
            freerooms.insert(room[x.second-1]);
        }
        answ = max(answ,cnt);
    }

    cout << answ << '\n';
    for(int i=0;i<n;i++){
        cout << room[i] <<' ';
    }
    cout <<'\n';

    return 0;
}