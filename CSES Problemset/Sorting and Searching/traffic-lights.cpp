#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, n, p;
    multiset<int> lengths;
    set<int> lights;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> n;
    lengths.insert(x);
    lights.insert(0);
    lights.insert(x);

    for(int i=0;i<n;i++){
        cin >> p;
        auto lb = (--lights.lower_bound(p));
        auto ub = (lights.upper_bound(p));

        auto rem = lengths.find((*ub)-(*lb));
        lengths.erase(rem);
        lengths.insert((*ub)-p);
        lengths.insert(p-(*lb));

        lights.insert(p);
        cout << *(--lengths.end()) << ' ';
    }
    cout << '\n';

    return 0;
}