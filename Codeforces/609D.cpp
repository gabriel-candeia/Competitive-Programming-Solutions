#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a, b;
vector<pair<ll,ll>> dol, pou;
ll n, m, k, s, x, y, s1, s2;

ll min(ll a,ll b){
    return (a<b) ? a : b;
}

bool check(int med){
    ll t1 = a[med], t2 = b[med], cnt=0, acm=s, next;
    s1 = 0; s2 = 0;

    while(s1<dol.size() && s2<pou.size() && cnt<k){
        next = min(t1*dol[s1].first,t2*pou[s2].first);
        if(next<=acm){
            acm-=next;
            cnt++;
            if(t1*dol[s1].first < t2*pou[s2].first){
                s1++;
            }
            else{
                s2++;
            }
        }
        else{
            break;
        }
    }

    while(s1<dol.size() && acm>=t1*dol[s1].first && cnt<k){
        cnt++;
        acm-=t1*dol[s1].first;
        s1++;
    }


    while(s2<pou.size() && acm>=t2*pou[s2].first && cnt<k){
        cnt++;
        acm-=t2*pou[s2].first;
        s2++;
    }

    return (cnt>=k);
}

int main(){
    cin >> n >> m >> k >> s;
    a.assign(n+1,0); b.assign(n+1,0);

    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i) a[i] = min(a[i],a[i-1]);
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(i) b[i] = min(b[i],b[i-1]);
    }
    for(int i=0;i<m;i++){
        cin >> x >> y;   
        if(x==1){
            dol.push_back({y,i});
        }
        else{
            pou.push_back({y,i});
        }
    }
    sort(dol.begin(),dol.end());
    sort(pou.begin(),pou.end());

    int l=0,r=n-1,med=0,answ=-1;
    while(l<=r){
        med = l + (r-l)/2;
        if(check(med)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    if(answ==-1){
        cout << -1 <<'\n';
    }
    else{
        check(answ);
        int d1=0, d2=0;
        cout << answ+1 << '\n';

        while(a[d1++]!=a[answ]);
        while(b[d2++]!=b[answ]);

        for(int i=0;i<s1;i++){
            cout << dol[i].second+1 << " " << d1 << "\n";
        }

        for(int i=0;i<s2;i++){
            cout << pou[i].second+1 << " " << d2 << "\n";
        }
    }

    return 0;
}
