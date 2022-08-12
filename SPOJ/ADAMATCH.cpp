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

//a remains fixed while we shift b to the right
vector<ll> shiftedScalarProduct(vector<ll> a, vector<ll> b){
    int na = a.size(), nb = b.size();

    reverse(b.begin(),b.end());

    vector<ll> answ = multiply(a,b);
    for(int i=0;i<na;i++){
        answ[i] = answ[i+nb-1];
    }
    answ.resize(na);

    return answ;
}

int main(){
    int n;
    string s, t;
    cin >> s >> t;

    n = s.size();
    vector<int> answ(n);
    
    for(auto c:{'A','C','T','G'}){
        vector<ll> coefA, coefB;
        for(auto x:s)
            coefA.push_back(x==c);
        for(auto x:t)
            coefB.push_back(x==c);
        coefA = shiftedScalarProduct(coefA,coefB);
        for(int i=0;i<n;i++)
            answ[i] += coefA[i];
    }

    int mx = (*max_element(answ.begin(),answ.begin()+s.size()-t.size()+1));

    cout << t.size()-mx << "\n";
    

    return 0;
}