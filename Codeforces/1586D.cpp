#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> a(n,1);

    int last = -1;
    for(int i=n, curr=2;i>=0 && curr<=n;i--,curr++){
        int resp;
        a[n-1] = curr;

        cout << "?";
        for(auto x:a)
            cout <<" "<< x;
        cout << endl;

        cin >> resp;
        if(resp==0){
            last = i;
            break;
        }
    }

    if(last==-1)
        last = 1;

    vector<int> p(n,0);
    p[n-1] = last;

    for(int i=0;i<last-1;i++){
        int resp;
        a.assign(n,last-i);
        a[n-1] = 1;

        cout << "?";
        for(auto x:a)
            cout <<" "<< x;
        cout << endl;

        cin >> resp;
        resp--;
        p[resp] = i+1;
    }

    for(int i=last+1;i<=n;i++){
        int resp;
        a.assign(n,1);
        a[n-1] = 2+(i-(last+1));

        cout << "?";
        for(auto x:a)
            cout <<" "<< x;
        cout << endl;

        cin >> resp;
        resp--;
        p[resp] = i;
    }

    
    cout << "!";
    for(auto x:p)
        cout <<" "<< x;
    cout << endl;

    return 0;
}