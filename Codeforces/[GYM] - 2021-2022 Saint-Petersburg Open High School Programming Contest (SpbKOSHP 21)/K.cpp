#include<bits/stdc++.h>
#define ld long double
using namespace std;

ld base, t;
const ld eps = 1e-8;

int comp(ld a, ld b){
    return ((a<b-eps) ? -1 : (a>b+eps ? 1 : 0));
}

ld performance(ld x){
    if(comp(x,t/3)>=0){
        return 100.0;
    }
    else if(comp(x,t/6)>=0){
        return base + (6*x-t)*(100-base)/t;
    }
    else{
        return 6*x*base/t;
    }
}

ld bb(ld l, ld r){
    ld m1, m2, cmp1, cmp2;
    while(true){
        m1 = l + (r-l)/3;
        cmp1 = performance(m1)*(t-m1);

        m2 = r - (r-l)/3;
        cmp2 = performance(m2)*(t-m2);
        
        if(comp(m1,m2)==0){
            //cout << cmp1 << " " << m1 << " " << l << " " << r << "\n";
            return cmp1;
        }
        else if(comp(cmp1,cmp2)==1){
            r =  m2;
        }
        else{
            l = m1;
        }
    }
    return -1;
}

int main(){

    cin >> base >> t;
    //cout << performance(4) <<"\n";
    cout << fixed << setprecision(10) << max(bb(0,t/6),bb(t/6,t/3)) <<"\n";
    
    return 0;
}