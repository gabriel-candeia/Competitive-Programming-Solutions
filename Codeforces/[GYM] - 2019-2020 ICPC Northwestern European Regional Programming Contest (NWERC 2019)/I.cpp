#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define maxn 1000100

int n, s, l, r, ant;
int v[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];        
    }
    pair<int,int> answ;
    /*
    for(int i = 1; i < n; i++){
        if(v[i] >= v[i+1] && l == 0){
            l = i;
            s += 1;
            ant = v[i];
        }else if(v[i] < v[i+1] && l != 0){
            if(v[i] == ant){
                l = s = r = 0;
            }else if(v[i+1] < ant){
                cout << "impossible\n";
                return 0;
            }else{
                r = i;
            }
        }else if(v[i] > v[i+1] && r != 0){
            cout << "impossible\n";
            return 0;
        }
    }
    if(v[n] == ant && r == 0){
        l = s = r = 0;
    }else if(l != 0 && r == 0){
        r = n;
    }
    if(s == 0){
        cout << "1 1\n";
    }else{
        cout << l << " " << r << "\n";        
    }*/
    l = r = -1;
    for(int i=1;i<=n;i++){
        int ptr = i;
        while(ptr<=n && v[ptr]>=v[ptr+1])
            ptr++;
        ptr -= (ptr>n);
        if(v[ptr]!=v[i]){
            l = i; r = ptr;
            break;
        }
    }

    if(l==-1)
        l = r = 1;

    for(int i=0;i<(r-l+1)/2;i++)
        swap(v[i+l],v[r-i]);

    bool ok = true;
    for(int i=1;i<n;i++)
        if(v[i]>v[i+1])
            ok = false;

    if(ok){
        cout << l << " " << r<<'\n';
    }
    else{
        cout << "impossible\n";
    }

    return 0;
}