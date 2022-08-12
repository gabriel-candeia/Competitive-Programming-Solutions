#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e6+5)
using namespace std;


ll somas[maxn];
int lsone(int x){
    return x&(-x);
}

int main(){
    srand(time(NULL));
    int n;
    vector<ll> selected;
    set<ll> st;

    cin >> n;
    for(int i=0, fst=n;i<21;i++, fst+=n+abs(rand())%n){
        cout << "? ";
        for(int j=fst;j<fst+n;j++){
            cout << j << " ";
        }
        cout << endl;
        int novo;
        cin >> novo;
        selected.push_back(novo);
    }

    for(int i=0;i<20;i++){
        somas[1<<i] = selected[i];
    }

    for(int i=0;i<maxn;i++){
        somas[i] = somas[i^lsone(i)] + somas[lsone(i)];
        if(somas[i]!=0)
            st.insert(somas[i]);
    }
    
    vector<ll> nxtQuery;
    auto it = st.begin();
    for(int i=0;i<n;i++){
        nxtQuery.push_back(selected.back()+*it);
        it++;
    }

    cout << "? ";
    for(auto x:nxtQuery){
        cout << x << " ";
    }
    cout << endl;
    ll target, m, k, aux;
    cin >> target;

    vector<ll> valores;
    aux = target-selected.back();
    for(int i=maxn-1;i>0;){
        if(aux==0) break;
        if(somas[i]==aux){
            aux -= somas[lsone(i)];
            valores.push_back(somas[lsone(i)]);
            i = i^lsone(i);   
        }
        else{
            i--;
        }
    }

    valores.push_back(selected.back());
    m = valores.size(), k = 1;
    cout << "! " << m << " " << k << endl;
    for(auto x:valores)
        cout << x << " ";
    cout << endl;
    cout << target << endl;


    return 0;   
}