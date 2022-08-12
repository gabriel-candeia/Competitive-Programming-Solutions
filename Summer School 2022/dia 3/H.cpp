#include <bits/stdc++.h>

using namespace std;

int n;

bool ok(vector<int> &perm, vector<tuple<int, int>> &dom, int bitmask){
    bool ok2 = true;
    //1 vira, 0 fica
    for(int i = 1, a, b, c, d, x, y; i < n; i++){
       tie(a, b) = dom[perm[i-1]];
       tie(c, d) = dom[perm[i]];
       x = (bitmask&(1<<(i-1))) ? a : b;
       y = (bitmask&(1<<(i))) ? d : c;
       ok2 &= (x == y);
    }
    return ok2;
}

void show(vector<int> &perm, vector<tuple<int, int>> &dom, int bitmask){
    vector<tuple<int, char>> v(n);
    int j; char ch;
    for(int i = 0; i < n; i++){
        // i -> perm[i]
        // v[perm[i]] = i
        ch = ((bitmask&(1<<i)) ? 'b' : 'a');
        v[i] = {perm[i], ch};
        //cout << perm[i] << " " << ch << "\n";
    }
    for(auto sla:v){
        tie(j, ch) = sla;
        cout << j+1 << " " << ch << "\n";
    }
}

int main(){
    cin >> n;
    vector<int> perm;
    vector<tuple<int, int>> dom;
    for(int i = 0, a, b; i < n; i++){
        perm.emplace_back(i);
        cin >> a >> b;
        dom.emplace_back(tuple<int,int>{a, b});
    }
    do{
        for(int i = (1<<n)-1; i >= 0; i--){
            if(ok(perm, dom, i)){
                show(perm, dom, i);
                return 0;
            }
        }
    }while(next_permutation(perm.begin(), perm.end()));
    cout << "Wrong Answer\n";
    return 0;
}