#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(1e6+5)
using namespace std;

const ll mod = 1e9+7, base = 31;
ll pot[maxn];

void precomp(){
    pot[0] = 1;
    for(int i=1;i<maxn;i++)
        pot[i] = (base*pot[i-1])%mod;
}

struct splaytree{
    struct node{
        node *ch[2], *p;
        int sz;
        ll val, sub, subr;

        node(ll pkey){
            val = sub = subr = pkey; 
            sz = 1, ch[0] = ch[1] = p = NULL;
        }
        void update(){
			sz = 1, sub = subr = val;
            if(ch[0]){
                sub = ((ch[0]->sub*base)%mod+sub)%mod;
                subr = ((subr*pot[ch[0]->sz])%mod+ch[0]->subr)%mod;
                sz += ch[0]->sz;
            }
            if(ch[1]){
                sub = ((sub*pot[ch[1]->sz])%mod+ch[1]->sub)%mod;
                subr = ((ch[1]->subr*pot[sz])%mod+subr)%mod;
                sz += ch[1]->sz;
            }
        }
    };

    node* root;

    splaytree(){
        root = NULL;
    }
    splaytree(node *proot){
        root = proot;
        if(root) root->p = NULL;
    }
    bool side(node *x){
        return (x->p && x==x->p->ch[1]);
    }
    int size(node *x){
        return ((x) ? x->sz : 0);
    }
    int size(){
        return size(root);
    }
    void attach(node *p, node *x, bool side){
        if(x) x->p = p;
        if(p) p->ch[side] = x, p->update();
    }
    void rotate(node *x){
        if(!x) return;
        node *p = x->p, *pp = x->p->p;
        bool dir = side(x), pdir = side(p);

        attach(p,x->ch[1-dir],dir);
        attach(x,p,1-dir);
        attach(pp,x,pdir);
    }
    void splay(node *x){
        if(!x) return;
        for(;x->p;){
            if(x->p->p==NULL) rotate(x); //ZIG
            else if(side(x)==side(x->p)) rotate(x), rotate(x); //ZIG ZIG
            else rotate(x->p), rotate(x); //ZIG ZAG
        }
        root = x;
    }
    node* find(int k){ //finds kth, if k>sz returns last element
        if(!root || k>root->sz) return NULL;
        node *curr = root;
        for(;curr && k!=size(curr->ch[0])+1;){
            bool dir = k>size(curr->ch[0])+1;
            k -= dir*(size(curr->ch[0])+1);
            curr = curr->ch[dir];
        }
        
        splay(curr);
        return curr;
    }
    node* findmin(bool max=false){
        if(!root) return NULL;
        node *curr = root;
        
        for(;curr && curr->ch[max];)
            curr = curr->ch[max];
        
        splay(curr);
        return curr;
    }
    void push_back(ll x){
        node *new_ = new node(x);
        if(root) root->update(), attach(new_,root,0);
        root = new_;
    }
    splaytree split(int k){ //return tree with k-1 first elements
        if(!find(k)) {
            splaytree L(root); root = NULL; return L;
        }
        splaytree L(root->ch[0]);
        root->ch[0] = NULL;
        root->update();
        return L;
    }
    pair<splaytree,splaytree> split_(int k){ 
        splaytree L = split(k);
        return {L,splaytree(root)};
    }
    void join(splaytree &L){ //L is going to be to the left o this
        findmin();
        if(root) attach(root,L.root,0);
        else root = L.root;
    }
    void insert(int c, int pos){
        splaytree L = split(pos);
        L.push_back(c);
        join(L);
    }
    void erase(int l, int r){
        splaytree M = split(r+1);
        splaytree L = M.split(l);
        join(L);
    }

    bool isPalidrome(int l, int r){
        splaytree M = split(r+1);
        splaytree L = M.split(l);
        bool answ = (M.root->sub==M.root->subr);
        M.join(L), join(M);
        return answ;
    }
    
};

int main(){
    fastio();
    precomp();
    int n, q;
    splaytree st;
    
    cin >> n >> q;
    
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        st.push_back(c-'a'+1);
    }
    
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int l, r;
            cin >> l >> r;
            st.erase(l,r);
        }
        else if(op==2){
            char c; int pos;
            cin >> c >> pos;
            st.insert(c-'a'+1,pos);
        }   
        else{
            int l, r;
            cin >> l >> r;
            cout << (st.isPalidrome(l,r) ? "yes" : "no") <<"\n";
        }
    }

    cout << "\n";

    return 0;
}