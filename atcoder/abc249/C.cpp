#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<string> arr;

int teste(int msk){
    vector<int> freq(30,0);
    for(int i=0;i<arr.size();i++){
        if(msk&1)
            for(auto c:arr[i])
                freq[c-'a']++;
        msk/=2;
    }
    int qtd = 0;
    for(auto c:freq)
        qtd += c==k;
    return qtd;
}

int main(){

    cin >> n >> k;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }

    int answ = 0;
    for(int msk=1;msk < (1<<n);msk++){
        answ = max(answ,teste(msk));
    }

    cout << answ <<"\n";

    return 0;
}