#include<bits/stdc++.h>
using namespace std;

vector<int> answ;

bool transform(int b, int a){
    bool poss = false;

    if(b<=a){
        poss = (b==a);
    }
    else if(b%10==1){
        poss = transform(b/10,a);
    }
    else if(b%2==0){
        poss = transform(b/2,a);
    }

    if(poss){
        answ.push_back(b);
    }
    return poss;
}


int main(){
    int a, b;

    cin >> a >> b;
    if(transform(b,a)){
        cout << "YES\n";

        cout << answ.size() << '\n';
        for(int i=0;i<answ.size();i++){
            cout << answ[i] << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }
    return 0;
}