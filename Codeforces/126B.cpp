#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            z[i] = min(z[i-l],r-i+1);
        }
        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int main(){
    string s, r;
    int temp, n;
    vector<int> z,mx;
    cin >> s;

    n = s.size();
    z = z_function(s);

    mx.push_back(0);
    for(int i=1;i<n;i++){
        mx.push_back(max(mx.back(),z[i]));
    }

    /*
    for(int i=0;i<n;i++){
        printf("%.2d ",mx[i]);
    }
    cout << endl;

    for(int i=0;i<n;i++){
        printf("%.2d ",z[i]);
    }
    cout << endl;*/

    int answ=-1;
    for(int i=n-1;i>0;i--){
        /*
            if the suffix of s started at position i is also a suffix (i+z[i]==n) 
            AND
            the string initiated at some j<i matches some preffix of s with size least z[i] (mx[i-1]>=z[i])
            THEN
            the string initiated at j must contain the suffix initiated at i as a preffix.
        */
        if(i+z[i]==n && mx[i-1]>=z[i]){
            answ = i;
        }
    }

    if(answ==-1){
        cout << "Just a legend\n";
    }
    else{
        for(int i=0;i<z[answ];i++){
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}