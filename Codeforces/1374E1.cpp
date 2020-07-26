#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, t, a, b;
    vector<int> both, alice, bob;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> t >> a >> b;
        if(a&&b){
            both.push_back(t);
        }
        else if(a){
            alice.push_back(t);
        }
        else if(b){
            bob.push_back(t);
        }
    }

    sort(both.begin(),both.end());
    sort(bob.begin(),bob.end());
    sort(alice.begin(),alice.end());    
    bool poss = ((both.size()+min(bob.size(),alice.size())>=k));


    if(poss){
        int ptr = min(min((int)bob.size(),(int)alice.size()),k);
        int lim = min((int)both.size(),k);
        int sb=0, sa=0, acm=0, answ, ptr2 = k-ptr;
        for(int i=0;i<ptr;i++){
            sb+=bob[i];
        }
        for(int i=0;i<ptr;i++){
            sa+=alice[i];
        }
        for(int i=0;i<ptr2;i++){
            acm+=both[i];
        }
        answ = acm+sb+sa;
        for(int i=ptr2;i<lim;i++){
            sb-=bob[--ptr];
            sa-=alice[ptr];
            acm+=both[ptr2++];
            answ = min(answ,acm+sb+sa);
        }
        cout << answ << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}