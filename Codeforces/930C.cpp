#include<bits/stdc++.h>
using namespace std;

vector<int> lis(vector<int>& cnt, int m){
    int answ=1;
    vector<int> best(m+10,0);
    set<pair<int,int>> s;
    s.insert({-1,0});
    for(int i=1;i<=m;i++){
        auto it = s.upper_bound({cnt[i],m+10});
        auto prev = it; prev--;
        best[i] = best[(*prev).second]+1;
        if(it!=s.end()){
            s.erase(it);
        }
        s.insert({cnt[i],i});
    }
    return best;
}

int main(){
    int n, m, l, r;
    cin >> n >> m;
    
    vector<int> cnt(m+10,0);

    for(int i=0;i<n;i++){
        cin >> l >> r;
        cnt[l]++;
        cnt[r+1]--;
    }

    for(int i=1;i<=m;i++){
        cnt[i]+=cnt[i-1];
    }   

    for(int i=1;i<=m;i++){
        cnt[i] = max(cnt[i],0);
    }
    vector<int> b1, b2;
    b1 = lis(cnt,m);
    int answ=1, temp;
    for(int i=1;i<=m/2;i++){
        temp = cnt[i];
        cnt[i] = cnt[m-i+1];
        cnt[m-i+1] = temp;
    }
    b2 = lis(cnt,m);
    
    for(int i=1;i<=m;i++){
        answ = max(answ,b1[i]+b2[m-i+1]-1);
    }

    cout << answ << '\n';
    return 0;
}