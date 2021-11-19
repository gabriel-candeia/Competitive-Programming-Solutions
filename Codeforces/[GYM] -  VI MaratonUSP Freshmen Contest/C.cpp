#include<bits/stdc++.h>
using namespace std;

int q, n;
vector<array<int,10>> cards;
array<int,10> freq;
vector<int> original;

bool teste(int msk){
    array<int,10> temp;
    for(int j=0;j<10;j++) temp[j] = 0;
    
    for(int i=0;i<q;i++){
        if((msk&(1<<i))==0)continue;
        for(int j=0;j<10;j++)
            temp[j] += cards[i][j];
    }

    for(int j=0;j<10;j++)
        if(freq[j]<temp[j])
            return false;
    return true;
}

int main(){

    cin >> q >> n;
    original.assign(q,0);
    cards.assign(q,array<int,10>());

    for(int j=0;j<10;j++) freq[j] = 0;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        original[i] = x;
        for(int j=0;j<10;j++) cards[i][j] = 0;
        if(x==0) cards[i][x]++;
        for(;x;x/=10) cards[i][x%10]++;
    }
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }
    
    int answ = 0;
    for(int msk=0;msk<(1<<q);msk++){
        if(teste(msk) && __builtin_popcount(msk)>__builtin_popcount(answ)){
            answ = msk;
        }
    }

    cout << __builtin_popcount(answ) << "\n";
    for(int i=0;i<q;i++, answ/=2){
        if(answ%2)
            cout << original[i] << " ";
    }cout<<'\n';

    return 0;
}