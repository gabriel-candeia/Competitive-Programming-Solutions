#include<bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

ll r, n;
ld eps = 1e-10;

int comp(ld a, ld b){
    return ((a>b+eps) ? 1 : ((a<b-eps) ? -1 : 0));
}

ld integral(ll x){
    return r*r*asin(x*1.0/r) + x*sqrt(r*r-x*x);
}

ld area(ll x){
    return integral(x)-integral(-r);
}

/*
ld bb(ld valor){
    ld l = -r, r = r, med, answ;
    while(true){
        med = (l+r)/2;
        cout <<fixed << setprecision(20) << ">>"<< med << " " << area(med) << " " << valor << l << " "<<r << "\n";
        if(comp(area(med),valor)==0){
            return med;
        }
        else if(comp(area(med),valor)<=0){
            l = med;
        }
        else{
            r = med;
        }
    }
    return answ;
}*/

int main(){
    cin >> n >> r;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    vector<int> freq(n+1,0);
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(comp(area(arr[i].first),M_PI*r*r*j*(1.0/n))<0 && comp(area(arr[i].first),M_PI*r*r*(j-1)*(1.0/n))>0){
                freq[j]++;
                break;
            }
        }
    }

    bool ok = true;
    for(int i=1;i<=n;i++){
        if(freq[i]!=1)
            ok = false;
    }

    cout << ((ok) ? "YES" : "NO") << "\n";
    
    return 0;
}
