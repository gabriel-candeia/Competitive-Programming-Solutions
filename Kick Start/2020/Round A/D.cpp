#include<bits/stdc++.h>
#define maxn 30
using namespace std;

int t, n, k, answ;

struct node{
    node* children[maxn];
    int size;

    node(){
        for(int i=0;i<maxn;i++)
            children[i] = NULL;
        size = 0;
    }
};

void insert(string s, node *root){
    for(int i=0;i<s.size();i++){
        if(!root->children[s[i]-'A'])
            root->children[s[i]-'A'] = new node();
        root->size++;
        root = root->children[s[i]-'A'];
    }
}

int solve(node *root, int ht=0){
    int qtd = 0;
    for(int i=0;i<maxn;i++)   
        if(root->children[i])
            qtd += solve(root->children[i],ht+1);
    root->size-=qtd;
    answ += ht*(root->size/k);
    return root->size - root->size%k+qtd;
}

int main(){
    cin >> t;
    int caso = 0;
    while(t--){
        cin >> n >> k;
        node *root  = new node();
        string s;

        for(int i=0;i<n;i++){
            cin >> s;
            insert(s+'[',root);
        }

        answ = 0;
        solve(root,0);
        cout << "Case #" << ++caso << ": " << answ   << '\n';
    }
    return 0;
}