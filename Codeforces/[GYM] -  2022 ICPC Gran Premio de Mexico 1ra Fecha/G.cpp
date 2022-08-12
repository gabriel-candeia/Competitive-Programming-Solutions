#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0)
#define ld long double
using namespace std;

typedef pair<ld,ld> pt;
const ld inf = 1e17;
const ld eps = 1e-8;
vector<pair<ld,pt>> v;

int comp(ld x, ld y){
  return ((y-x > eps) ? 1 : ((x-y > eps) ? -1 : 0));
}

pt operator-(const pt& a, const pt& b){
    return {a.first-b.first,a.second-b.second};
}

pt operator+(const pt& a, const pt& b){
    return {a.first+b.first,a.second+b.second};
}

pt operator*(const pt& a, const ld b){
    return {a.first*b,a.second*b};
}

ld operator!(const pt& a){
    return a.first*a.first+a.second*a.second;
}

ld calc(const pt& x){
  ld answ = 0;
  for(auto [c,pt]:v){
    answ = max(answ,c*(sqrt(!(pt-x))));
  }
  return answ;
}

ld solve(ld x){
  ld l = -1e4, r = 1e4, answ=inf, m1, m2, c1, c2;
  while(comp(l,r)>0){
    m1  = l + (r-l)/3;
    c1 = calc({x,m1});
    m2 = r - (r-l)/3;
    c2 = calc({x,m2});
    answ = min({answ,c1,c2});

    if(comp(c1,c2)>=0){
      r = m2;
    }
    else{
      l = m1;
    }
  }
  return answ;
}

int main(){
  fastio();
  int n;
  cin >> n;

  pt curr;
  for(int i = 0; i < n; ++i){
    int x, y, c;
    cin >> x >> y >> c;
    v.push_back({c,{x,y}});
  }

  ld l = -1e4, r = 1e4, answ=inf, m1, m2, c1, c2;
  while(comp(l,r)>0){
    m1  = l + (r-l)/3;
    c1 = solve(m1);
    m2 = r - (r-l)/3;
    c2 = solve(m2);
    answ = min({answ,c1,c2});

    if(comp(c1,c2)>=0){
      r = m2;
    }
    else{
      l = m1;
    }
  }
  //cout << m1 << " " << m2 <<"\n";
  cout << fixed << setprecision(16) << answ  << '\n';

  return 0;
}