#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll count(int x){
    vector<int> digits;
    while(x){
        digits.push_back(x&1);
        x/=2;
    }
    reverse(digits.begin(),digits.end());
    ll answ = 0, odd=1;
    for(int i=1;i<digits.size();i++){
        answ += (1ll<<(i-1));
        if(i>=2) answ += ((i/2+i%2)-1)*(1ll<<(i-2));
    }
    for(int i=1;i<digits.size();i++){
        if(digits[i]==1){
            int sz = digits.size()-(i+1);
            answ += odd*(1ll<<sz);
            if(sz>0 && (i+1)%2==0){
                answ += (sz/2+sz%2)*(1ll<<(sz-1));
            }
            if(sz>0 && (i+1)%2==1){
                answ += ((sz-1)/2+(sz-1)%2)*(1ll<<(sz-1));
            }
        }
        if(i%2==0) odd+=digits[i]==1;
    }
    answ += odd;
    return answ;
}

int bb(int n){
    int l = 1, r = n, med, answ;
    while(l<=r){
        med = l + (r-l)/2;
        if(count(med)>=n){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << bb(x) <<'\n';
    }

    return 0;
}