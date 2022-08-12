#include<bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

ld var;

ld calcula(ld x){
	return -exp(-(x*x)/(2*(var*var)));
}

int main(){
    vector<ld> arr(6,0), pref(6,0);
    ld pontos = (20*21)/2;
    vector<ld> coef = {50,25,pontos/20,3*pontos/20,pontos/20,2*pontos/20};

    for(auto &x:arr)
        cin >> x;
    cin >> var;
    
    for(int i=0;i<6;i++){
        pref[i] = calcula(arr[i]);
    }

    ld answ = (pref[0]-calcula(0))*coef[0];
    for(int i=1;i<6;i++){
        answ += (pref[i]-pref[i-1])*coef[i];
    }

    cout << fixed << setprecision(10) << answ <<"\n";

    return 0;
}