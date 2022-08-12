#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(1e6+5)
using namespace std;

int menor[maxn];

int main(){
    fastio();
    for(int i=0;i<=maxn;i++)
        menor[i] = i;

    int t;
    cin >> t;
    while(t--){
        int n;
        vector<int> arr;
        set<int> st;

        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            arr.push_back(x);
            st.insert(x);
        }

        for(auto x:st){
            for(int i=0;i<maxn;i+=x){
                menor[i] = min(menor[i],x);
            }
        }

        ll answ = 0;
        for(auto x:arr)
            answ += menor[x];

        cout << answ <<"\n";
        for(auto x:st){
            for(int i=0;i<maxn;i+=x){
                menor[i] = i;
            }
        }
    }

    return 0;
}