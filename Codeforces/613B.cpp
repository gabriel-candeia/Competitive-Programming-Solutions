#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, A, cf, cm, m;
vector<ll> soma;
vector<pair<ll,int>> arr;

ll cost(ll val){
    auto it = upper_bound(arr.begin(),arr.end(),pair<ll,int>{val,0});
    int j = distance(arr.begin(),it)-1;
    return ((j+1)*val - soma[j]);
}

ll bb(){
    ll l = 0, r = A, med, answ;
    while(l<=r){
        med = l + (r-l)/2;
        if(cost(med)<=m){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
        return answ;
}

int main(){
    cin >> n >> A >> cf >> cm >> m;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr.push_back({a,i});
    }

    ll base = 0;
    sort(arr.begin(),arr.end());
    while(arr.size() && arr.back().first==A) arr.pop_back(), base++;
    
    ll acm = 0, best = 0, bestMin = 0, posBest = arr.size();
    if(arr.size()==0){ 
        best = base*cf + cm*A;
    }
    else{
        soma.push_back(arr[0].first);
        for(int i=1;i<arr.size();i++) 
            soma.push_back(soma.back()+arr[i].first);
        
        acm = base*cf;
        for(int i=arr.size();i>=0;i--){
            ll menor = ((i==0) ? A : bb());
            ll temp = acm + menor*cm;
            if(temp>best){
                best = temp;
                posBest = i;
                bestMin = menor;
            }
            //cout << i << " " << menor*cm << " " << " "<< acm<<"\n";
            if(i>0 && A-arr[i-1].first <= m){
                m -= (A-arr[i-1].first);
                acm += cf;
                arr.pop_back();
            }
            else{
                break;
            }
        }
    }

    vector<int> answ(n,-1);
    for(int i=0;i<posBest;i++){
        answ[arr[i].second] = max(bestMin,arr[i].first);
    }

    for(int i=posBest;i<arr.size();i++){
        answ[arr[i].second] = A;
    }

    for(int i=0;i<n;i++){
        if(answ[i]==-1){
            answ[i] = A;
        }
    }

    cout << best << "\n";
    for(auto x:answ)
        cout << x << " ";
    cout<<"\n";

    return 0;
}