#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int freq[maxn], best[maxn], pref[maxn];

int main(){
    int n;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    int one=maxn, zero=maxn+1;
    for(int i=maxn-1;i>=0;i--){
        best[i] = min(one+1,zero);
        if(freq[i]==0) zero = i, best[i] = -1;
        if(freq[i]==1) one = i;
    }

    pref[0] = freq[0];
    for(int i=1;i<maxn;i++){
        pref[i] = freq[i]+pref[i-1];
    }

    int maior=best[0], pos=0;
    for(int i=1;i<maxn;i++){
        if(best[i]==-1) continue;
        int valor;
        if(best[i]==maxn) valor = pref[maxn-1]-pref[i-1];
        else valor = pref[best[i]-1] - pref[i-1];
        if(valor>maior) maior = valor, pos = i;
    }

    vector<int> left, right;
    for(int i=pos;i<best[pos];i++){
        left.push_back(i), freq[i]--;
        while(freq[i]--){
            right.push_back(i);
        }        
    }


    reverse(right.begin(),right.end());
    cout << left.size()+right.size() <<"\n";
    for(auto x:left)
        cout << x << " ";
    for(auto x:right)
        cout << x << " ";
    cout <<"\n";

    return 0;
}