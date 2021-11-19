#include<bits/stdc++.h>
#define ld double
using namespace std;

pair<ld,ld> rotate(pair<ld,ld> p, ld alpha){
    return {p.first*cos(alpha)-p.second*sin(alpha),p.second*cos(alpha)+p.first*sin(alpha)};
}

int main(){
    int n;
    pair<ld,ld> a, b, c;

    cin >> n;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    c.first = (a.first+b.first)/2, c.second = (a.second+b.second)/2;
    a = {a.first-c.first,a.second-c.second};
    a = rotate(a,2*M_PI/n);
    cout << fixed << setprecision(10) << a.first+c.first << " " << a.second+c.second << '\n';
    return 0;
}

