#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt(string s, string t){
    ll acm = 0;
    for(int i=0, j;i<s.size();i++){
        for(j=0;i+j<s.size() && j<t.size() && s[i+j]==t[j];j++);
        acm += (j==t.size());
    }
    return acm;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string haha = "haha";
        map<string,string> fst, lst;
        map<string,ll> freq;

        string id, op, a, b;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> id >> op;
            if(op[0]==':'){
                cin >> a;
                fst[id] = a.substr(0,min(4,(int)a.size()));
                lst[id] = a.substr(max(((int)a.size())-4,0));
                freq[id] = cnt(a,haha);
            }
            else{
                cin >> a >> op >> b;
                string h1, h2;
                h1 = fst[a]+fst[b];
                h2 = lst[a]+lst[b];
                if(h1.size()>4) h1 = h1.substr(0,4);
                if(h2.size()>4) h2 = h2.substr(h2.size()-4);
                freq[id] = freq[a]+freq[b]+cnt(lst[a]+fst[b],haha)-cnt(lst[a],haha)-cnt(fst[b],haha);
                fst[id] = h1, lst[id] = h2;
            }
        }
        
        cout << freq[id] << "\n";
    }

    return 0;
}