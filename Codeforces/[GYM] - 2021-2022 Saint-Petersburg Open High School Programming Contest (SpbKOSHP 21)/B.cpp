#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> answ;
    set<pair<int,int>> st;

    cin >> n;
    answ.assign(n+1,0);
    for(int i=1;i<=n;i++){
        int l, r = i, bl, br;
        for(int j=i;j>=1;j--){
            if(st.find({j,i})==st.end()){
                l = j;
                break;
            }
        }
        cout << "? " << l << " " << r << endl;
        ll acm;
        cin >> acm >> bl >> br;
        st.insert({bl,br});
        for(int j=l;j<r;j++){
            acm-=answ[j];
        }
        answ[i] = acm;
    }

    cout << "!" << endl;
    for(int i=1;i<=n;i++)
        cout << answ[i] << " ";
    cout << endl;

    return 0;
}