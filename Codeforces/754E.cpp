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

int f(char c){
    return c-'a';
}

vector<int> matchingWithWildcards(const string& s, const string& t){
    int ns = s.size(), nt = t.size(), k = 0;
    vector<cd> vs, vt;

    for(auto c:s){
        double angle = (2*PI*f(c)/26.0);
        vs.push_back({cos(angle),sin(angle)});
    }
    
    for(auto c:t){
        if(c=='?'){
            vt.push_back(0);
        }
        else{
            double angle = (2*PI*f(c)/26.0);
            vt.push_back({cos(angle),-sin(angle)});
            k++;
        }
    }
    reverse(vt.begin(),vt.end());
    
    int n = 1;
    while(n < vs.size()+vt.size()) n = 2*n;
    vs.resize(n), vt.resize(n);

    fft(vs,false);
    fft(vt,false);
    for(int i=0;i<n;i++)
        vs[i] = vs[i]*vt[i];
    fft(vs,true);
    
    vector<int> answ;
    for(int i=nt-1;i<n;i++){
        answ.push_back(int(vs[i].a+1e-9)==k);
    }
    
    return answ;
}

inline int getID(char c){
  return c - 'a';
}
// Find p in text t. Wildcard character *
bitset<800> stringMatchingWithWildcards(string t, string p){
  int nt = t.size();
  int np = p.size();
  vector<cd> fa(nt), fb(np);
  for(int i=0; i<nt; i++){
    double apha = (2*PI*getID(t[i]))/26;
    fa[i] = cd(cos(apha), sin(apha));
  }
  reverse(p.begin(), p.end());
  int k = 0;
  for(int i=0; i<np; i++){
    if(p[i] != '?'){
      double apha = (2*PI*getID(p[i]))/26;
      fb[i] = cd(cos(apha), -sin(apha));
      k++;
    }else{
      fb[i] = cd(0, 0);
    }
  }
  int n = 1;
  while(n < int(nt + np) )
    n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++)
    fa[i] = fa[i]*fb[i];
  fft(fa, true);
  bitset<800> result;
  for (int i = 0; i < (nt - np+1); i++)
    result[i] = (int(fa[np-1+i].a + 1e-9) == k);
  return result;
}

int main(){
    fastio();
    int n, m, r, c;

    cin >> n >> m;
    vector<string> m1, m2;

    for(int i=0;i<n;i++){
        string s; cin >> s;
        m1.push_back(s);
    }

    cin >> r >> c;
    for(int i=0;i<r;i++){
        string s; cin >> s;
        m2.push_back(s);
    }

    for(int i=0;i<n;i++){
        string s = m1[i];
        while(m1[i].size()<r){
            m1[i]+=s;
        }
    }
    
    vector<bitset<800>> answ(n);
    for(int i=0;i<n;i++){
        auto& line = answ[i];
        line.set();
        for(int k=0;k<r;k++){
            auto ok = stringMatchingWithWildcards(m1[(i+k)%n]+m1[(i+k)%n],m2[k]);
            /*if(i==3){
                cout << m1[(i+k)%n]+m1[(i+k)%n] << "\n";
                cout << m2[k] << "\n";
                for(int j=0;j<m;j++){
                    cout << ok[j];
                }
                cout <<"\n";
            }*/
            for(int j=0;j<m;j++){
                line[j] = (ok[j] && line[j]);
            }
        }   
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << answ[i][j] << "";
        }
        cout<<"\n";
    }

    return 0;
}