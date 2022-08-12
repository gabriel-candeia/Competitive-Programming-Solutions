#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

bool vogal(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int contar(string s){
    int answ = 0, n = s.size();
    for(int i=0;i<n;i++){
        if(vogal(s[i]) && (i==0 || !vogal(s[i-1]))){
            answ++;
        }
    }
    return answ;
}

int main(){
    fastio();
    int n;
    string s;
    cin >> n;
    vector<ll> arr, lim = {5,7,5};

    for(int i=0;i<n;i++){
        cin >> s;
        arr.push_back(contar(s));
        
    }

    int answ = 0;
    for(int i=0;i<n;i++){
        int acm = 0, j=i;
        for(;j<n && acm+arr[j]<=5;j++){
            acm += arr[j];
        }
        
        if(acm!=5) continue;
        acm = 0;
        for(;j<n && acm+arr[j]<=7;j++){
            acm += arr[j];
        }
        
        if(acm!=7) continue;
        acm = 0;
        for(;j<n && acm+arr[j]<=5;j++){
            acm += arr[j];
        }
        
        if(acm!=5) continue;
        answ++;
    }

    cout << answ <<"\n";

    return 0;   
}