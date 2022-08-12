#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<ll> arr, inv, rem, maxinv;

ll combine(int l, int med, int r, int ht){
    ll acm = 0;
    vector<int> left(arr.begin()+l,arr.begin()+med+1), right(arr.begin()+med+1,arr.begin()+r+1);
    int n1 = 0, n2 = 0, ptr = l;

    while(n1<left.size() && n2<right.size()){
        if(right[n2]<left[n1]){
            arr[ptr++] = right[n2++];
            acm += (left.size()-n1);
        }
        else{
            arr[ptr++] = left[n1++];
        }
    }

    while(n1<left.size()){
        arr[ptr++] = left[n1++];
    }

    while(n2<right.size()){
        arr[ptr++] = right[n2++];
    }

    map<int,int> aux;
    for(auto x:left)
        aux[x]++;
    for(auto y:right)
        rem[ht] += aux[y];

    return acm;
}

void solve(int l, int r, int ht){
    if(l!=r){
        int med = (l+r)/2;
        solve(l,med,ht+1);
        solve(med+1,r,ht+1);
        inv[ht] += combine(l,med,r,ht);
    }
}

int main(){
    fastio();
    int n;
    cin >> n;
    arr.assign((1<<n),0);
    for(auto &x:arr)
        cin >> x;

    inv.assign(21,0);
    rem.assign(21,0);
    solve(0,(1<<n)-1,0);

    /*for(int i=0;i<=n;i++)
        cout << inv[i] << " ";
    cout<<"\n";*/
    
    vector<ll> size(21,0), qtd(21,0);
    maxinv.assign(21,0);

    size[0] = (1<<n), qtd[0] = 1;
    for(int i=1;i<21;i++){
        size[i] = size[i-1]/2;
        qtd[i] = 2*qtd[i-1];   
    }

    for(int i=0;i<21;i++){
        maxinv[i] = qtd[i]*((size[i]*size[i])/4)-rem[i];
    }
    
    int m;
    cin >> m;
    while(m--){
        int q;
        cin >> q;
        q = n-q;
        for(int i=q;i<=n;i++){
            //cout << inv[i] << " " << " " << qtd[i]*((size[i]*size[i])/4);
            inv[i] = maxinv[i] - inv[i];
            //cout << inv[i] << "|";
        }//cout<<"\n";
        
        ll acm = 0;
        for(int i=0;i<=n;i++)
            acm += inv[i];
        cout << acm <<"\n";
    }

    return 0;
}