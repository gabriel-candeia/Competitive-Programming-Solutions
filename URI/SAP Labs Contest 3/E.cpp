#include<bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

const ld eps = 1e-8;

ld fgcd(ld a, ld b){
   if (a < b) return fgcd(b, a);
   if (fabs(b) < eps) return a;
   else return (fgcd(b, a - floor(a / b) * b));
}

int main(){
    int n;
    ld t;
    vector<ld> arr;

    cin >> n >> t;
    t *= 60;
    for(int i=0;i<n;i++){
        ld a, b;
        cin >> a >> b;
        arr.push_back(10*a*b);
    }

    ld lcm = arr[0];
    for(int i=1;i<n;i++){
        lcm = (lcm*arr[i])/fgcd(lcm,arr[i]);
    }

    if(lcm<=t){
        cout << "APROVADO\n";
    }
    else{
        cout << "REPROVADO\n";
    }
    return 0;
}