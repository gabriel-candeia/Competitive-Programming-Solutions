#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<int> h, s;

void read(){
    cin >> n >> x;

    h.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }

    s.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
}

int solve(){
    vector<int> pages(x+1,0);

    for(int i=0;i<n;i++){
        for(int j=x; j>=1; j--){
            if(j>=h[i]){
                pages[j] = max(pages[j],pages[j-h[i]]+s[i]);
            }
        }
    }

    return pages[x];
}

int main(){

    read();
    cout << solve() << '\n';

    return 0;
}