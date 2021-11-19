//same as 786C but using sqrt decomposition

#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int answ[maxn], arr[maxn], freq[maxn], nxt[maxn], last[maxn], aux[maxn], n;

int add(int x){
    return ((++freq[arr[x]])==1);
}

int erase(int x){
    return ((--freq[arr[x]])==0);
}

int brute(int k){
    int cnt = 0, answ = 1;
    memset(freq,0,sizeof(freq));

    for(int l=0,r=0;r<n;r++){
        cnt += add(r);
        if(cnt>k){
            answ++;
            while(l<r)
                cnt -= erase(l++);
        }
    }

    return answ;
}

int main(){
    cin >> n;
    const int block = sqrt(n);

    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    for(int i=1;i<=sqrt(n)+1;i++){
        answ[i] = brute(i);
    }

    for(int i=0;i<maxn;i++) aux[i] = n+1;
    for(int i=n-1;i>=0;i--){
        nxt[i] = aux[arr[i]];
        aux[arr[i]] = i;
    }

    for(int i=0;i<maxn;i++) aux[i] = -2;
    for(int i=0;i<n;i++){
        last[i] = aux[arr[i]];
        aux[arr[i]] = i;
    }

    vector<int> ptr, cnt;
    ptr.push_back(0), cnt.push_back(-1);
    for(int i=0;i<n;i++){
        if(i%block==0)
            ptr.push_back(min(i+block,n)), cnt.push_back(0);
        cnt[cnt.size()-1] += (nxt[i]>=ptr.back());
    }

    
    for(int k=sqrt(n)+2;k<=n;k++){
        int lst=0, curr = 1, prox = 2;
        while(prox<ptr.size()){
            while(ptr[curr]<n && cnt[curr]+(last[ptr[curr]]<ptr[lst])<=k){
                cnt[curr] += (last[ptr[curr]]<ptr[lst]);
                cnt[prox] -= (nxt[ptr[curr]]>=ptr[prox]);
                ptr[curr]++;
                if(ptr[curr]==ptr[prox]) prox++;
            }       
            lst = curr, curr = prox, prox++;
        }
        for(int i=ptr.size()-1;i>=0;i--){
            for(int j=i;j<ptr.size()-1 && cnt[j]==0;j++)
                swap(cnt[j],cnt[j+1]), swap(ptr[j],ptr[j+1]);
            if(cnt.back()==0) cnt.pop_back(), ptr.pop_back();
        }
        answ[k] = ptr.size()-1;
    }    

    for(int i=1;i<=n;i++)
        cout << answ[i] << " ";
    cout<<'\n';

    return 0;
}