#include<bits/stdc++.h>
using namespace std;

const int N = int(2e5)+ 3;

int main(){
    vector<int> f, last;
    vector<bool> in;
    set<int> next;
    int n;

    cin >> n;
    in.assign(n+1,false);
    f.assign(n+1,0);
    last.assign(n+1,0);

    for(int i=1;i<=n;i++){
        cin >> f[i];    
        last[f[i]] = i;
        if(f[i]!=0){
            in[f[i]] = true;
        }
    }

    int curr = 1;
    for(int i=1;i<=n;i++){
        if(last[i]==0){
            next.insert(i);
            curr = i;
        }
    }

    for(int i=1;i<=n;i++){
        if(f[curr]==0){
            if(*(next.begin())==curr){
                auto it = next.begin();
                it++;
                f[curr] = *(it);
                next.erase(it);
            }
            else{
                f[curr] = *(next.begin());
                next.erase(next.begin());
            }
        }
        curr = f[curr];
    }

    for(int i=1;i<=n;i++){
        cout << f[i] << ' ';
    }
    cout << '\n';

    return 0;
}
