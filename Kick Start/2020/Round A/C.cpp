#include<bits/stdc++.h>
using namespace std;

vector<int> m;
int n, k;
bool isok(int x){
    int acm=0;
    for(int i=1;i<n;i++)
        if(m[i]-m[i-1]>x)
            acm += (m[i]-m[i-1])/x-((m[i]-m[i-1])%x==0);
    return acm <=k;
}

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        cin >> n >> k;
        m.assign(n,0);
        for(int i=0;i<n;i++)
            cin >> m[i];

        bool eq=true;
        for(int i=0;i<n;i++)
            eq = eq && (m[i]==m[0]);

        int l = 1, r = 1e9, med, answ=0;
        while(l<=r){
            med = l + (r-l)/2;
            if(isok(med)){
                answ = med;
                r = med-1;
            }
            else{
                l = med+1;
            }
        }
        if(eq)
            answ = 0;
        cout << "Case #" << ++caso << ": " << answ <<'\n';
    }

    return 0;
}