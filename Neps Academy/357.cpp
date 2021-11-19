#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
#define maxn int(1e5+5)
using namespace std;

int n;
vector<vector<pair<int,int>>> ft;
vector<int> arr, match;
vector<bool> ok;

void alocar(){
    ft.assign(2,vector<pair<int,int>>(n+1,{0,0}));
}

void limpar(){    
    for(int k=0;k<2;k++){
        for(int i=0;i<=n;i++){
            ft[k][i].first = ft[k][i].second = k;
        }
    }
}

int lsone(int x){
    return (x&(-x));
}

void update(int k, int i, int v){
    for(;i<=n;i+=lsone(i)){
        ft[k][i].first = min(ft[k][i].first,v);
        ft[k][i].second = max(ft[k][i].second,v);
    }
}

pair<int,int> query(int k, int i){
    pair<int,int> answ = ft[k][i];
    for(;i;i-=lsone(i)){
        answ.first = min(ft[k][i].first,answ.first);
        answ.second = max(ft[k][i].second,answ.second);
    }
    return answ;
}

void teste(){
    limpar();
    pair<int,int> p1 = {0,0}, p2 = {0,0};
    //cout << p2.first << " " << p2.second <<"\n";
    for(int i=0;i<n;i++){
        if(arr[i]-1>0)
            p1 = query(0,arr[i]-1);
        else 
            p1 = {0,0};
        if(n-arr[i]>0)
            p2 = query(1,n-arr[i]);
        else    
            p2 = {1,1};

        //cout << arr[i] <<" "<< n-arr[i] << " " << p1.first << " " << p1.second << " " << p2.first << " " << p2.second <<", ";

        if((p1.first==p1.second && p1.first==0) && (p2.first==p2.second && p2.first==1)){
            ok[arr[i]] = ok[arr[i]]&&true;
        }
        else{
            ok[arr[i]] = false;
        }

        if(i!=n-1){
            update(0,arr[i],arr[i]-match[i]);
            update(1,n+1-arr[i],arr[i]-match[i]);
        }
    }
    //cout<<"\n";
}

int main(){
    fastio();
    cin >> n;
    
    if(n==1){
        cout << 1 <<"\n";
        return 0;
    }

    arr.assign(n,0);
    match.assign(n-1,0);
    ok.assign(n+1,1);

    for(int i=0;i<n;i++)
        cin >> arr[i];

    for(int i=0;i<n-1;i++)
        cin >> match[i];

    alocar();
    teste();
    reverse(arr.begin(),arr.end());
    reverse(match.begin(),match.end());
    teste();
    
    for(int i=1;i<=n;i++)
        if(ok[i])
            cout << i << " ";
    cout<<'\n';

    return 0;
}