#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(4e5+1)
#define ll long long
using namespace std;

const ll base = 31, mod = 1e9+7;
ll st[4*maxn], pot[maxn];
string s = "";

void precomp(){
    pot[0] = 1;
    for(int i=1;i<maxn;i++){
        pot[i] = (pot[i-1]*31)%mod;
    }
}

ll build(int p, int l, int r){
    if(l==r){
        return st[p] = s[l]-'a'+1;
    }
    int med = (l+r)/2;
    return st[p] = (build(2*p,l,med)*pot[r-med] + build(2*p+1,med+1,r))%mod;
}

ll update(int p, int l, int r, int i, char v){
    if(l==r){
        return st[p] = (v-'a'+1);
    }
    int med = (l+r)/2;
    if(i<=med){
        return st[p] = (update(2*p,l,med,i,v)*pot[r-med] + st[2*p+1])%mod;
    }
    return st[p] = (st[2*p]*pot[r-med] + update(2*p+1,med+1,r,i,v))%mod;
}

ll get(int p, int l, int r, int i, int j){
    if(j<l || r<i){
        return 0;
    }
    if(i<=l && r<=j){
        return st[p];
    }
    int med = (l+r)/2;
    return (get(2*p,l,med,i,j)*pot[max(min(j,r)-max(i,med+1)+1,0)] + get(2*p+1,med+1,r,i,j))%mod;
}

int main(){
    fastio();
    precomp();
    int n, q;
    vector<int> start, size;

    cin >> n >> q;
    for(int i=0;i<n;i++){
        string s1;
        cin >> s1;
        start.push_back(s.size());
        size.push_back(s1.size());
        s += s1;
        reverse(s1.begin(),s1.end());
        s += s1;
    }
    
    int tam = s.size();
    build(1,0,tam-1);
    while(q--){
        int op, i, j, l1, r1, l2, r2;
        char c;
        cin >> op;
        
        if(op==1){
            cin >> i >> j >> c;
            i--;
            update(1,0,tam-1,start[i]+2*size[i]-j,c);
            update(1,0,tam-1,start[i]+j-1,c);
        }
        else if(op==2){
            cin >> i >> j >> l1 >> r1 >> l2 >> r2;
            i--, j--;
            ll q1 = get(1,0,tam-1,start[i]+l1-1,start[i]+r1-1);
            ll q2 = get(1,0,tam-1,start[j]+l2-1,start[j]+r2-1);
            if(q1==q2){
                cout << "equal" <<"\n";
            }
            else{
                cout << "different" <<"\n";
            }
        }
        else{
            cin >> i >> j >> l1 >> r1 >> l2 >> r2;
            i--, j--;
            ll q1 = get(1,0,tam-1,start[i]+l1-1,start[i]+r1-1);
            ll q2 = get(1,0,tam-1,start[j]+l2-1,start[j]+r2-1);
            q1 = (q1*pot[r2-l2+1]+q2)%mod;
            ll q3 = get(1,0,tam-1,start[j]+2*size[j]-r2,start[j]+2*size[j]-l2);
            ll q4 = get(1,0,tam-1,start[i]+2*size[i]-r1,start[i]+2*size[i]-l1);
            q3 = (q3*pot[r1-l1+1] + q4)%mod;
            
            if(q3==q1){
                cout << "cool" <<"\n";
            }
            else{
                cout << "not so cool" <<"\n";
            }
        }
    }

    return 0;
}