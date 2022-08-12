#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct complex_t {
  double a {0.0}, b {0.0};
  complex_t(){}
  complex_t(double na) : a{na}{}
  complex_t(double na, double nb) : a{na}, b{nb} {}
  const complex_t operator+(const complex_t &c) const {
    return complex_t(a + c.a, b + c.b);
  }
  const complex_t operator-(const complex_t &c) const {
    return complex_t(a - c.a, b - c.b);
  }
  const complex_t operator*(const complex_t &c) const {
    return complex_t(a*c.a - b*c.b, a*c.b + b*c.a);
  }
  const complex_t operator/(const int &c) const {
    return complex_t(a/c, b/c);
  }
};

using cd = complex_t;
const double PI = acos(-1);
void fft(vector<cd> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j)
      swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i+j], v = a[i+j+len/2] * w;
        a[i+j] = u + v;
        a[i+j+len/2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (invert){
    for (cd &x : a)
      x = x / n;
  }
}
typedef int ll;
vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while(n < int(a.size() + b.size()) )
    n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++)
    fa[i] = fa[i]*fb[i];
  fft(fa, true);
  vector<ll> result(n);
  for (int i = 0; i < n; i++)
    result[i] = ll(fa[i].a + 0.5);
  return result;
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
    fastio();
    string st, ss;
    vector<ll> t, s, vt, vs;

    cin >> st >> ss;

    for(auto &c:st)
      t.push_back(c-'a');

    for(auto &c:ss)
      s.push_back(c-'a');


    vector<int> freq((1<<6),0);
    for(int msk=0;msk<(1<<6);msk++)
      for(auto c:s)
        freq[msk] += (((1<<c)&msk)!=0);
    /*for(auto c:s)
      cout << c << " ";
    cout<<"\n";*/

    vector<vector<ll>> coef(1<<6);
    vt.assign(st.size(),0);
    vs.assign(ss.size(),0);
    for(int msk = 0; msk<(1<<6); msk++){
      for(int i=0;i<t.size();i++)
        vt[i] = (((1<<t[i])&msk)!=0);
      for(int i=0;i<s.size();i++)
        vs[i] = (((1<<s[i])&msk)!=0);
      coef[msk] = shiftedScalarProduct(vt,vs);
    }

    const int inf = 10;
    vector<vector<int>> dp(1<<6,vector<int>(t.size(),inf));

    for(int i=0;i<t.size()-s.size()+1;i++){
      for(int msk=1;msk<(1<<6);msk++){
        if(coef[msk][i]==freq[msk]){ // tem que ser igual a frequência dos caracteres de msk em s
          dp[msk][i] = __builtin_popcount(msk)-1;
        }
        for(int j=(msk-1)&msk; j!=0;j=(j-1)&msk){
          dp[msk][i] = min(dp[msk][i],dp[j][i]+dp[msk^j][i]);
        }
      }
    }

    //cout << freq[(1<<0)+(1<<1)+(1<<3)] << " " << coef[(1<<0)+(1<<1)+(1<<3)][0] <<"\n";

    for(int i=0;i<t.size()-s.size()+1;i++){
      cout << dp[(1<<6)-1][i] << " ";
    }cout<<"\n";

    return 0;
}