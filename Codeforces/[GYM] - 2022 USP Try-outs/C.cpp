#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long ll;
const ll K = 26;
inline ll getId(char c){
    return c - 'a';
}
struct Vertex {
    vector<ll> next;
    ll leaf;
    ll count;
    Vertex() {
        next.assign(K,-1);
        leaf = 0;
        count = 0;
    }
};

struct Trie{
    ll ans = 0, mmax = 0;
    vector<Vertex> trie;
    Trie(){
        trie.emplace_back();
    }
    void add(string const& s, ll tot) {
        ll v = 0;
        trie[v].count++;
        for(char ch: s) {
            ll c = getId(ch);
            if(trie[v].next[c] == -1){
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
            trie[v].count++;
        }
        trie[v].leaf += tot;
    } 
    void dfs(ll v){
        ans += trie[v].leaf;
        mmax = max(mmax, ans);
        for(int i=0;i<26;i++){
            char ch = i+'a';
            ll c = getId(ch);
            if(trie[v].next[c] != -1){
                dfs(trie[v].next[c]);
            }
        }
        ans -= trie[v].leaf;
    }
};

int main(){
    fastio();
    ll n; cin >> n;
    Trie t;
    for(ll i = 0; i < n; i++){
        string s; ll tot; cin >> s >> tot;
        t.add(s, tot);
    }
    t.dfs(0);
    cout << t.mmax << "\n";
    return 0;
}