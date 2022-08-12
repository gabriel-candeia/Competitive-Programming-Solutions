#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, q;
vector<int> a, b;
vector<int> a1, b1;
int lg[maxn];

void precomp(){
    lg[1] = 0;
    for(int i=2;i<maxn;i++)
        lg[i] = lg[i/2]+1;
}

struct table{
    vector<vector<int>> st;

    table(vector<int> &arr){
        if(arr.size()==0) return;
        int n = arr.size();
        st.assign(n,vector<int>(30,0));

        for(int i=0;i<n;i++)
            st[i][0] = arr[i];

        for(int k=1;k<30;k++)
            for(int i=0;i<n && i+(1<<k)<=n;i++){
                st[i][k] = __gcd(st[i][k-1],st[i+(1<<(k-1))][k-1]);
            }
    }

    int get(int l, int r){
        int k = lg[(r-l+1)];
        return __gcd(st[l][k],st[r-(1<<k)+1][k]);
    }


};

struct tableMin{
    vector<vector<int>> st;

    tableMin(vector<int> &arr){
        if(arr.size()==0) return;
        int n = arr.size();
        st.assign(n,vector<int>(30,0));

        for(int i=0;i<n;i++)
            st[i][0] = arr[i];

        for(int k=1;k<30;k++)
            for(int i=0;i<n && i+(1<<k)<=n;i++){
                st[i][k] = min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
            }
    }

    int get(int l, int r){
        int k = lg[(r-l+1)];
        return min(st[l][k],st[r-(1<<k)+1][k]);
    }

};


int main(){
    fastio();
    precomp();
    cin >> n >> q;
    a.assign(n,0);
    b.assign(n,0);

    for(auto &x:a)
        cin >> x;
    for(auto &x:b)
        cin >> x;

    for(int i=1;i<n;i++)
        a1.push_back(abs(a[i]-a[i-1]));
    for(int i=1;i<n;i++)
        b1.push_back(abs(b[i]-b[i-1]));

    table t1(a1), t2(b1);
    tableMin t3(a), t4(b);

    for(int i=0;i<q;i++){
        int lx, rx, ly, ry;
        cin >> lx >> rx >> ly >> ry;
        lx--, rx--, ly--,ry--;
        if(lx==rx && ly==ry){
            cout << a[lx]+b[ly] <<"\n";
        }
        else if(lx==rx){
            int menor = a[lx]+t4.get(ly,ry);
            cout << __gcd(menor,t2.get(ly,ry-1)) <<"\n";
        }
        else if(ly==ry){
            int menor = t3.get(lx,rx)+b[ly];
            cout << __gcd(menor,t1.get(lx,rx-1)) <<"\n";
        }
        else{
            int menor = t3.get(lx,rx) + t4.get(ly,ry);
            cout << __gcd(menor,__gcd(t1.get(lx,rx-1),t2.get(ly,ry-1))) <<"\n";
        }
    }


    return 0;
}