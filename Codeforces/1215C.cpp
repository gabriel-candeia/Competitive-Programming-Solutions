#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s, t;
    vector<int> p1, p2;

    cin >> n >> s >> t;
    int cmp = 0;
    for(int i=0;i<n;i++){
        cmp = s[i]-t[i]+1;
        if(cmp==0){
            p1.push_back(i+1);
        }
        else if(cmp==2){
            p2.push_back(i+1);
        }
    }

    if(p1.size()%2!=p2.size()%2){
        cout << -1 << '\n';
    }
    else{
        cout << p1.size()/2 + p2.size()/2 + 2*(p1.size()%2) << '\n';
        while(p1.size()>=2){
            cout << p1.back() << " ";
            p1.pop_back();
            cout << p1.back() << " " << "\n";
            p1.pop_back();
        }
        while(p2.size()>=2){
            cout << p2.back() << " ";
            p2.pop_back();
            cout << p2.back() << " " << "\n";
            p2.pop_back();
        }
        if(p1.size()==1){
            cout << p1.back() << " " << p1.back() << '\n';
            cout << p1.back() << " " << p2.back() << '\n';
        }
    }   

    return 0;
}