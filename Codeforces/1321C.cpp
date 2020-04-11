#include<bits/stdc++.h>
using namespace std;

bool canRemove(string s, int i, int n){
    return (i!=0 && (s[i]-s[i-1]==1)) || (i!=n-1 && (s[i]-s[i+1]==1));
}

void remove(string& s, int i, int& n){
    for(int j=i;j<n;j++){
        s[j] = s[j+1];
    }
    n--;
}

int main(){
    int n;
    string s;
    int mx, cnt=0;

    cin >> n >> s;

    do{
        mx = -1;
        for(int i=0;i<n;i++){
            if(canRemove(s,i,n) && (mx==-1 || s[mx]<s[i])){                
                mx = i;
            }
        }
        if(mx>=0){ 
            cnt++;
            remove(s,mx,n); 
        }
    }while(mx!=-1);

    cout << cnt << '\n';
    return 0;
}