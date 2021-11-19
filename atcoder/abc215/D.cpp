#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

ll prime[maxn], freq[maxn];

void precomp(){
    for(int i=2;i<maxn;i++){
        if(prime[i]==0){
            for(int j=i;j<maxn;j+=i){
                prime[j] = i;
            }
        }
    }
}

int main(){
    int n, m;
    vector<int> arr;
    set<int> st;
    precomp();

    cin >> n >> m;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    
    for(auto x:arr){
        for(int j=x;j>1;j/=prime[j]){
            st.insert(prime[j]);
        }
    }
    
    for(auto x:st){
        for(int j=0;j<maxn;j+=x){
            freq[j] = 1;
        }
    }

    int answ = 0;
    for(int i=1;i<=m;i++)
        answ += (1-freq[i]);

    cout << answ << "\n";

    for(int i=1;i<=m;i++){
        if(freq[i]==0){
            cout << i << "\n";
        }
    }

    return 0;
}