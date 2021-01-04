#include<bits/stdc++.h>
#define maxn 3
using namespace std;

int arr[maxn], sum=0;

int main(){
    string s; cin >> s;

    for(auto c:s){
        arr[(c-'0')%3]++;
        sum = (sum+(c-'0'))%3;
    }
    int answ = -1;
    if(sum==0){
        answ = 0;
    }
    else if((sum==1 && arr[1]>=1)||(sum==2 && arr[2]>=1)){
        answ = 1;
    }
    else if((sum==1 && arr[2]>=2)||(sum==2 && arr[1]>=2)){
        answ = 2;
    }
    if(answ>s.size()-1){
        answ = -1;
    }
    cout << answ <<'\n';
    return 0;
}