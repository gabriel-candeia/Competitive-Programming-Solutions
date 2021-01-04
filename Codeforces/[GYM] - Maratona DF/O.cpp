#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
#define maxm 65
using namespace std;

ll mat[maxn][maxn], img[maxm][maxm], pattern[maxm], window[maxn];
ll n, m, l, k;

bool match(int i){
    bool answ = true;
    for(int j=i;j<i+k;j++)
        answ = answ&&(pattern[j-i]==window[j]);
    return answ;
}

int main(){
    char c;

    cin >> n >> m >> l >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c;
            mat[i][j] = ((c=='.') ? 0 : 1);
        }
    }

    for(int i=0;i<l;i++){
        for(int j=0;j<k;j++){
            cin >> c;
            img[i][j] = ((c=='.') ? 0 : 1);
        }
    }

    if(l>n || k>m){
        cout << "-1 -1\n";
        return 0;
    }

    for(int j=0;j<k;j++){
        ll acm = 0;
        for(int i=0;i<l;i++){
            acm = 2*acm + img[i][j];
        }
        pattern[j] = acm;
    }

    for(int j=0;j<m;j++){
        ll acm = 0;
        for(int i=0;i<l;i++){
            acm = 2*acm + mat[i][j];
        }
        window[j] = acm;
    }

    pair<int,int> answ = {-1,-1};
    for(int j=0;j+k<=m;j++){
        if(match(j))
            answ = {0,j};
    }
    for(int i=l;i<n;i++){
        for(int j=0;j<m;j++){
            window[j] = window[j]^(mat[i-l][j]<<(l-1));
            window[j] = 2*window[j] + mat[i][j];
        }   
        /*for(int j=0;j<m;j++){
            cout << window[j] << " ";
        }cout<<'\n';*/
        for(int j=0;j+k<=m;j++){
            
            if(match(j))
                answ = {i-l+1,j};
        }
    }

        
    cout << answ.first << " " << answ.second <<'\n';
    return 0;
}

l = menor_possivel, r= maior_possivel
while(cmp(l,r)!=0){
    med = (l+r)/2
    if(cmp){
        ...
    }
    else{
        ;
    }
}