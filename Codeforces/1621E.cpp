#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct fract{
    ll a, b;
};

bool operator<(const fract &a, const fract &b){
    return a.a*b.b < a.b*b.a;
}

bool operator<=(const fract &a, const int b){
    return a.a <= a.b*b;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        vector<ll> ages;
        vector<pair<fract,vector<pair<ll,ll>>>> groups;

        cin >> n >> m;
        ages.assign(n,0);
        for(auto &x:ages)
            cin >> x;

        sort(ages.rbegin(),ages.rend());
        while(ages.size()>m)
            ages.pop_back();
        reverse(ages.begin(),ages.end());

        int cnt = 0;
        for(int i=0;i<m;i++){
            int k;
            cin >> k;
            ll sum = 0;
            vector<pair<ll,ll>> alunos;
            for(int j=0;j<k;j++){
                int x;
                cin >> x;
                alunos.push_back({x,cnt++});
                sum+=x;
            }
            groups.push_back({{sum,k},alunos});
        }

        sort(groups.begin(),groups.end());
        vector<int> eq(m,0), nxt(m,0), lst(m,0);
        for(int i=0;i<m;i++){
            if(groups[i].first <= ages[i]){
                eq[i] = 1;
            }
            if((i-1)>=0 && groups[i-1].first <= ages[i]){
                lst[i] = 1;
            }
            if((i+1)<m && groups[i+1].first <= ages[i]){
                nxt[i] = 1;
            }
        }
        
        for(int i=1;i<m;i++){
            eq[i]+=eq[i-1], lst[i]+=lst[i-1], nxt[i] += nxt[i-1];
        }
/*
        for(int i=0;i<m;i++)
            cout << ages[i] << " ";
        cout<<'\n';

        for(int i=0;i<m;i++)
            cout << groups[i].first.a << " " << groups[i].first.b <<", ";
        cout<<'\n';*/


        vector<int> resp(cnt,0);
        
        for(int i=0;i<groups.size();i++){
            for(auto alunos:groups[i].second){
                fract novaMedia = {groups[i].first.a-alunos.first,groups[i].first.b-1};
                int l = 0, r = m-1, answ = -1, med;
                while(l<=r){
                    med = (l+r)/2;
                    if(novaMedia<=ages[med]){
                        answ = med;
                        r = med-1;
                    }
                    else{
                        l = med+1;
                    }
                }
                //cout << alunos.second << " " << i << " " << answ<<"\n";
                if(answ==-1){
                    resp[alunos.second] = 0;
                    continue;
                }
                
                int ok = 1, a, b;
                if(answ<i){
                    a = answ+1, b = i;
                    ok += (lst[b]-lst[a-1]);
                    a = i+1, b = m-1;
                    ok += (eq[b]-eq[a-1]);
                    a = 0, b = answ-1;
                    if(b>=0) ok += eq[b];
                }
                else if(answ>i){
                    a = i, b = answ-1;
                    if(a>0)
                        ok += (nxt[b]-nxt[a-1]);
                    else
                        ok += (nxt[b]);
                    a = answ+1, b = m-1;
                    ok += (eq[b]-eq[a-1]);
                    a = 0, b = i-1;
                    if(b>=0) ok += eq[b];
                }
                else{
                    ok = eq[m-1] - ((groups[i].first<=ages[i])) + 1;
                }
        
                resp[alunos.second] = (ok==m);
            }
            
        }

        for(auto x:resp){
            cout << x;
        }cout<<"\n";

    }

    return 0;
}