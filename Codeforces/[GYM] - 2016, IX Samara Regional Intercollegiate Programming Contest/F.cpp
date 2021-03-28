#include<bits/stdc++.h>
#define ld long double
using namespace std;

ld eps = 1e-9;
pair<ld,ld> p1, p2, vp1, vp2;
int cmp(ld a, ld b, ld eps){
    return ((a>b+eps) ? 1 : ((a+eps<b) ? -1 : 0));
}

ld dist(ld t){
    ld x = (p1.first-p2.first+t*(vp1.first-vp2.first)), y = (p1.second-p2.second+t*(vp1.second-vp2.second)); 
    return sqrt(x*x+y*y);
}

int main(){
    

    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> vp1.first >> vp1.second;
    cin >> vp2.first >> vp2.second;

    ld l = 0, r = 1e14, m1, m2, cmp1, cmp2, answ=-1;
    while(cmp(l,r,1e-12)==-1){
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;
        cmp1 = dist(m1);
        cmp2 = dist(m2);
        if(cmp(cmp1,cmp2,1e-8)==0){
            answ = cmp1;
            break;
        }
        else if(cmp(cmp1,cmp2,1e-8)==1){
            l = m1;
        }
        else{
            r = m2;
        }
    }

    if(answ==-1)
        answ = cmp1;

    cout  << fixed << setprecision(15) <<  answ <<'\n';
    return 0;
}