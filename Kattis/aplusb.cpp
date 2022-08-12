#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd>& a, bool inv){
    int n = a.size();
    if(n==1) 
        return;

    vector<cd> a0(n/2), a1(n/2);
    for(int i=0;2*i<n;i++){
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
        
    fft(a0,inv);
    fft(a1,inv);

    double ang = ((!inv) ? 2*PI/n : -2*PI/n);
    cd w(1), wn(cos(ang),sin(ang));

    for(int i=0;2*i<n;i++){
        a[i] = a0[i] + w*a1[i];
        a[i+n/2] = a0[i] - w*a1[i];
        if(inv)
            a[i]/=2, a[i+n/2]/=2;
        w *= wn;
    }
}

vector<ll> multiply(vector<ll> a, vector<ll> b){
    int n = 1;
    vector<ll> c(a.size()+b.size()-1);

    while(n<a.size()+b.size()) 
        n<<=1;
    
    a.resize(n), b.resize(n);
    vector<cd> va(a.begin(),a.end()), vb(b.begin(),b.end()), vc(n);
    fft(va,false), fft(vb,false);

    for(int i=0;i<n;i++)
        vc[i] = va[i]*vb[i];

    fft(vc,true);

    for(int i=0;i<c.size();i++)
        c[i] = round(vc[i].real());

    return c;
}

int main(){
    int mn=50000, mx = -50000, n;
    vector<ll> coef;
    map<ll,ll> freq;

    cin >> n;
    for(int i=0, x;i<n;i++){
        cin >> x, freq[x]++;
        mn = min(mn,x), mx = max(mx,x);
    }

    ll f0 = freq[0];
    freq[0] = 0;
    mn = min(mn,0);

    coef.assign(mx-mn+1,0);
    for(auto &p:freq){
        coef[p.first-mn] = p.second;
    }
    
    auto answ = multiply(coef,coef);

    
    for(auto &p:freq){
        answ[p.first-mn+p.first-mn]-=p.second;
    }

    ll acm = 0;

    if(f0){
        for(auto &p:freq){
            if(p.first!=0)
                acm += (p.second*(p.second-1)*f0)*2;
        }
        acm += f0*(f0-1)*(f0-2);
    }
    freq[0] = f0;
    
    for(int i=max(0,-mn);i<answ.size();i++){
        acm += (answ[i]*freq[i+2*mn]);
        /*if(answ[i]!=0)
            cout << i+2*mn <<" "<< answ[i] <<" "<< i+2*mn << " " << freq[i+2*mn]<< "\n";*/
    }

    cout << acm <<"\n";

    return 0;
}