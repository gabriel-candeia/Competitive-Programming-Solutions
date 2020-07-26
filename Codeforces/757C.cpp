#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N int(1e6+5)

ll fat[N];
vector<int> x[N];
const ll mod =  1e9 + 7;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int g, t;

    fat[0] = fat[1] = 1;
    for(int i=2;i<N;i++){
        fat[i] = (i*fat[i-1])%mod;
    }
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> g;
        for(int j=0;j<g;j++){
            cin >> t;
            x[t].push_back(i);
        }
    }
    //The adjacency list X has at most 5*10^5 elements

    sort(x,x+m+1);
    ll size=1, asnw=1;
    //Since each element in x is compared at most twice we do at most 10^6 comparissions, 
    //hence this is O(n)
    for(int i=2;i<=m;i++){
        if(x[i]==x[i-1]){
            size++;
        }
        else{
            asnw = (asnw*fat[size])%mod;
            size = 1;
        }
    }
    asnw = (asnw*fat[size])%mod;
    cout << asnw << '\n';
    return 0;
}