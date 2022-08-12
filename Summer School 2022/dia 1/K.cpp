#include<bits/stdc++.h>
using namespace std;

struct noh{
    int v;
    vector<int> children;

    noh(){
        v = 0;
        children.assign(31,-1);
    }
};

vector<noh*> trie;
map<int,string> mp;
map<pair<int,int>,int> freq;

void insere(const string& s){
    if(trie.size()==0) trie.push_back(new noh());
    int u = 0;
    for(int i=0;i<s.size();i++){
        //if(freq[{trie[u]->v,i}]) freq[{trie[u]->v,i}]--;
        trie[u]->v++;
        freq[{trie[u]->v,i}]++;
        if(trie[u]->children[s[i]-'a']==-1){
            trie[u]->children[s[i]-'a'] = trie.size();
            trie.push_back(new noh());
        }
        u = trie[u]->children[s[i]-'a'];
    }
}

void remove(const string& s){
    //if(trie.size()==0) trie.push_back(noh());
    int u = 0;
    for(int i=0;i<s.size();i++){
        if(freq[{trie[u]->v,i}]) freq[{trie[u]->v,i}]--;
        trie[u]->v--;
        //freq[{trie[u]->v,i}]++;
        //f(trie[u]->v) st[i].insert(trie[u]->v);
        u = trie[u]->children[s[i]-'a'];
    }
}

int main(){
    int q, iter = 0;
    string s;

    cin >> q;
    for(int j=0;j<q;j++){
        int op;
        iter++;
        cin >> op;
        
        if(op==1){
            cin >> s;
            reverse(s.begin(),s.end());
            s.push_back('z'+1);
            mp[iter] = s;
            insere(s);
        }
        else if(op==2){
            int k, l;
            cin >> k >> l;
            cout << ((freq[{k,l}]) ? "YES" : "NO") <<"\n";
        }
        else{
            int i;
            cin >> i;
            if(mp.find(i)==mp.end()) continue;
            remove(mp[i]);
            mp.erase(i);
        }
    }

    return 0;
}