#include<bits/stdc++.h>
using namespace std;

int n, k;
const int mod = 10;
vector<int> answ;

bool teste(vector<int> a, vector<int> b){
    vector<int> c(b.size(),0);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            c[i+j] = (c[i+j] + a[i]*a[j])%mod;
        }
    }

    for(int i=0;i<b.size();i++)
        if(b[i]!=c[i])
            return false;
    return true;
}

bool menor(vector<int> a, vector<int> b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    return a < b;
}

bool solve(int pos, vector<int> curr, const vector<int>& digitos){
    /*cout << pos << " ";
    for(auto x:curr)
        cout << x << " ";
    cout<<"\n";*/

    if(pos==k){
        bool testex = teste(curr,digitos);
        if(testex){
            if(answ.size()==0 || menor(curr,answ)){
                answ = curr;
            }
        }
        return testex;
    }   
    
    int acm = 0, temp;
    for(int i=1;i<pos;i++){
        if(i==pos-i)
            acm = (acm + curr[i]*curr[pos-i])%mod;
        else
            acm = (acm + curr[i]*curr[pos-i])%mod;
    }

    temp = ((digitos[pos]-acm)%mod+mod)%mod;

    /*if(pos==3 && curr[0]==2 && curr[1]==1){
        cout << "=> " << acm << " " << temp  << "\n";
    }*/

    for(int i=0;i<10;i++){
        if((2*curr[0]*i)%10 == temp){
            curr.push_back(i);
            if(solve(pos+1,curr,digitos)) return true;

            curr.pop_back();
        }
    }

    return false;
}

int main(){
    string s;
    vector<int> digitos;

    cin >> s;
    n = s.size();
    
    for(auto c:s)
        digitos.push_back(c-'0');
    
    k = -1;
    if(n%2==1)
        k = (n+1)/2;

    reverse(digitos.begin(),digitos.end());
    bool ok = false;
    if(k!=-1){
        for(int i=0;i<10;i++){
            if((i*i)%10 == digitos[0]){
                ok = solve(1,{i},digitos) || ok;
                //cout << "opa" << i << " " << digitos[0] << "\n";
            }
        }
    }

    if(ok){
        reverse(answ.begin(),answ.end());
        for(auto x:answ)
            cout << x;
        cout<<"\n";
    }
    else{
        cout << -1 <<"\n";
    }

    return 0;
}
/*
12
12

 24
12
 44

 112
 112

00224
01120
11200
12544

1112
1112

0002224
0011120
0111200
1112000
1236544

2n-1

4 = 2*2
4 = 2*1+2*1
5 = 2*1+2*1+1*1
  = 2*1 + 2*1

b[0] = a[0]*a[0]
b[1] = a[1]*a[0] + a[0]*a[1]
b[2] = a[2]*a[0] + a[0]*a[2] + a[1]*a[1]
b[3] = a[3]*a[0] + a[0]*a[3] + a[2]*a[1] + a[1]*a[2]
*/

