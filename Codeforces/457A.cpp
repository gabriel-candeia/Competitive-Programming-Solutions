#include<bits/stdc++.h>
#define N 1e6
using namespace std;

void modify(vector<int>& s){
    int temp=0;
    for(int i=N-3;i>=0;i--){
        temp = min(s[i],s[i+1]);
        s[i+2] += temp;
        s[i]-=temp;
        s[i+1]-=temp;
    }
}

int main(){
    string in;
    vector<int> s(N,0), t(N,0);

    cin >> in;
    for(int i=0;i<in.size();i++){
        s[i] = in[in.size()-i-1]-'0';
    }
    cin >> in;
    for(int i=0;i<in.size();i++){
        t[i] = in[in.size()-i-1]-'0';
    }
    
    int eq = 0;
    for(int i=N-1;i>=0;i--){
        if(s[i]>t[i]){
            eq = 1;
            break;
        }
        else if(s[i]<t[i]){
            eq = -1;
            break;
    }
        }

    cout << ((eq==0) ? "=" : ((eq==1) ? ">" : (eq==-1) ? "<" : "x")) << '\n';

    return 0;
}