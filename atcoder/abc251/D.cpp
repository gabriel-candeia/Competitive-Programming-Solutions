#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;

    vector<int> answ;
    for(int pot=1, iter = 0;iter<3;pot = pot*100, iter++){ 
        for(int i=0;i<100;i++){
            answ.push_back((i+1)*pot);
        }
    }


    /*vector<int> ok(1e6+5,false);
    for(int i=0;i<answ.size();i++){
        ok[answ[i]] = 1;
        for(int j=i+1;j<answ.size();j++){
            ok[answ[i]+answ[j]] = 1;
            for(int k=j+1;k<answ.size();k++){
                ok[answ[i]+answ[j]+answ[k]] = 1;
            }
        }
    }

    for(int i=1;i<=1e6;i++){
        if(ok[i]==false){
            cout << i << "\n";
            return 0;
        }
    }*/


    cout << answ.size() <<"\n";
    for(int i=0;i<answ.size();i++){
        cout << answ[i] <<" ";
    }cout <<"\n";


    return 0;
}