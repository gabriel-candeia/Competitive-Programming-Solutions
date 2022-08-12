#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;
 
typedef long long ll;
typedef complex<long double> cd;
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
 
vector<ll> multiply(vector<ll>& a, vector<ll>& b){
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
        c[i] = roundl(vc[i].real());
 
    return c;
}

vector<ll> solve(deque<ll> a, deque<ll> b){
    ll acm = 0, n = a.size();
    vector<ll> answ;
    while(a.size() && b.size()){
        ll x1 = a.front()*b.back(), x2 = a.back()*b.front();
        if(x1>x2){
            swap(a,b), swap(x1,x2);
        }
        if(x1>0){
            break;
        }
        a.pop_front(), b.pop_back();
        acm += x1, answ.push_back(acm);
    }
    if(a.size()==0)
        return answ;
    
    if(a[0]<0)
        reverse(a.begin(),a.end()), reverse(b.begin(),b.end());

    vector<ll> va(a.begin(),a.end()), vb(b.begin(),b.end());
    va = multiply(va,vb);

    for(int i=0;i<va.size();i++){
        answ.push_back(acm+va[i]);
    }
    answ.resize(n);

    return answ;
}

int main(){
    fastio();
    int n;
    deque<ll> a, b;

    cin >> n;

    for(int i=0, x; i<n; i++){
        cin >> x;
        a.push_back(x);
    }

    for(int i=0, x; i<n; i++){
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());


    auto v1 = solve(a,b);
    for(auto &x:a)    
        x = -x;
    reverse(a.begin(),a.end());
    auto v2 = solve(a,b);

    for(int i=0;i<n;i++){
        cout << v1[i] << " " << -v2[i] <<"\n";
    }

    return 0;
}