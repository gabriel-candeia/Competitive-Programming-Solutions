#include<bits/stdc++.h>
using namespace std;

bool prefix(string &a, string &b){
    if(a.size()>b.size()) return 0;
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

int solve(string &a, string &b){
    if(b.size()>a.size() || (b.size()==a.size() && b>a)) return 0;
    int x = a.size()-b.size()+(b<=a);
    if(prefix(b,a)==false){
        b+= string(x,'0');
        return x;
    }
    else{
        string add = "";
        bool need = true;
        for(int i=b.size();i<a.size();i++){
            if(a[i]=='9' || need==false){
                add += "0";
            }
            else if(need){
                add += string(1,a[i]+1);
                need = false;
            }
        }
        if(need==true)
            add += "0";
        b+=add;
        return add.size();
    }
}

int main(){
    int t, caso=0, n;

    cin >> t;
    while(t--){
        cin >> n;   
        vector<string> arr;
        arr.assign(n,"");
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int answ = 0;
        for(int i=1;i<n;i++)
            answ += solve(arr[i-1],arr[i]);
        cout << "Case #" << ++caso << ": "<< answ << '\n';
    }

    return 0;
}