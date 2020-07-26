#include<bits/stdc++.h>
using namespace std;

void operation(string& a, int l, int r){
    for(int i=l;i<=r;i++){
        a[i] = ((a[i]=='0') ? '1' : '0');
    }

    char temp;
    for(int i=l;i<=(r+l)/2;i++){
        temp = a[r-i];
        a[r-i] = a[i];
        a[i] = temp;
    }
}

int main(){
    int t, n;
    int start=0, curr=n-1, temp;
    
    string a, b;

    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        vector<int> answ;
        start = 0; curr = n-1;
        bool inv=false;
        for(int size=n-1;size>=0;size--){
            if((inv==false && a[curr]!=b[size]) || (inv && a[curr]==b[size])){
                if((inv==false && a[start]==b[size]) || (inv==true && a[start]!=b[size])){
                    answ.push_back(0);
                }
                answ.push_back(size);
                inv = !inv;
                if(inv){
                    temp = start;
                    start = curr;
                    curr = temp;
                }
                else{
                    temp = start;
                    start = curr;
                    curr = temp;
                }
            }
            curr += ((inv) ? 1 : -1);
        }
        cout << answ.size() << ' ';
        for(auto x:answ){
            cout << x+1 << " ";
        }cout << '\n';
    }
    return 0;
}