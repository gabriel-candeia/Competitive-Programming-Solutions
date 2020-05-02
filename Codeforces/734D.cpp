#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<pair<ll,char>>& arr, char target){
    int i=0, n = arr.size();
    for(i=0;i<arr.size() && arr[i].second!='K';i++);

    if((i!=0 && arr[i-1].second!=target) || (i!=n-1 && arr[i+1].second!=target)){
        return true;
    }

    return false;
}

int main(){
    ll n, x, y, a, b;
    vector<pair<ll,char>> col(1,{0,'K'}), lin(1,{0,'K'}), diag1(1,{0,'K'}), diag2(1,{0,'K'});
    char tipo;
    bool flag = false;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;
    while(n--){
        cin >> tipo >> x >> y;
        if(x==a){
            lin.push_back({y-b,tipo});
        }
        if(y==b){
            col.push_back({x-a,tipo});
        }
        if(x+y==a+b){
            diag1.push_back({x-a,tipo});
        }
        if(x-y==a-b){
            diag2.push_back({x-a,tipo});
        }
    }

    sort(lin.begin(),lin.end());
    sort(col.begin(),col.end());
    sort(diag1.begin(),diag1.end());
    sort(diag2.begin(),diag2.end());

    flag = (check(lin,'B') || check(col,'B') || check(diag1,'R') || check(diag2,'R'));
    cout << ((flag) ? "YES" : "NO") << '\n';

    return 0;
}   