#include <bits/stdc++.h>

using namespace std;

#define maxn  int(1e4+10)

vector<int> zero, one;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int tmin = 1000000000, dmin;
    for(int i = 0, t, d; i < n; i++){
        cin >> t >> d;
        if(d&1) one.emplace_back(t);
        else zero.emplace_back(t);
        if(t < tmin){
            tmin = t;
            dmin = d;
        }
    }
    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());
    int l = 0, r = 0, ta = tmin, da, dp = 2;
    while(l < zero.size() || r < one.size()){

        if(l < zero.size() && dp == 0 && zero[l] <= ta){
            da = 0;
        }else if(r < one.size() && dp == 1 && one[r] <= ta){
            da = 1;
        }else if(l < zero.size() && r < one.size()){
            da = (zero[l] < one[r] ? 0 : 1);
        }else if(l < zero.size()){
            da = 0;
        }else{
            da = 1;
        }
            
        ta += 10*(da != dp);

        if(l < zero.size() && !da){
            ta = max(ta, zero[l++]+10);
        }else if(r < one.size() && da){
            ta = max(ta, one[r++]+10);
        }
        dp = da;
    }

    cout << ta << "\n";
    return 0;
}
