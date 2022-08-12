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

vector<ll> multiply(vector<int> a, vector<int> b){
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
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<int> a, b;
        cin >> n;
        a.assign(n+1,0), b.assign(n+1,0);
        for(auto &x:a)
            cin >> x;
        for(auto &x:b)
            cin >> x;
        auto c = multiply(a,b);
        for(auto x:c)
            cout << x << " ";
        cout<<"\n";
    }
    return 0;
}