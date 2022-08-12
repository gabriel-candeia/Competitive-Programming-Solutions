#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

template<typename T>
struct splaytree{
    struct node{
        node *ch[2], *p;
        int sz;
        T val, sub, lazy;
        bool rev;

        node(T pkey){
            val = sub = pkey; 
            lazy = 0, sz = 1;
            ch[0] = ch[1] = p = NULL, rev = false;
        }
        void update(){
			sz = 1, sub = val;
			for(int i=0;i<2;i++){
                if(ch[i]){
                    sz += ch[i]->sz;
                    sub += ch[i]->sub;
			    }
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
    const T& operator[](int i){ //This allows to root->sub be wrong 
        find(i);
        return root->val;
    }
    node* findmin(bool max=false){
        if(!root) return NULL;
        node *curr = root;
        for(;curr && curr->ch[max];)
            curr = curr->ch[max];
        
        splay(curr);
        return curr;
    }
    void push_back(T x){
        node *new_ = new node(x);
        if(root) root->update(), attach(new_,root,0);
        root = new_;
    }
    splaytree<T> split(int k){ //return tree with k-1 first elements
        if(!find(k)){ 
            splaytree<T> L(root); root = NULL; return L; 
        }
        splaytree<T> L(root->ch[0]);
        root->ch[0] = NULL;
        root->update();
        return L;
    }
    pair<splaytree<T>,splaytree<T>> split_(int k){ 
        splaytree<T> L = split(k);
        return {L,splaytree<T>(root)};
    }
    void join(splaytree<T> &L){ //L is going to the left
        findmin();
        if(root) attach(root,L.root,0);
        else root = L.root;
    }
};

int main(){
    fastio();
    int n, q;

    cin >> n;
    splaytree<int> st;
    
    for(int i=1;i<=n;i++){
        st.push_back(i);
    }

    q = n;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a<b){
            int tam = min(n-b+1,b-a);
            splaytree<int> M3, M2, M1, L;
            
            tie(M3, st) = st.split_(b+tam);
            tie(M2, M3) = M3.split_(b);
            tie(M1, M2) = M2.split_(a+tam);
            tie(L, M1) = M1.split_(a);

            st.join(M1); st.join(M2), st.join(M3), st.join(L);            
        }   
    }

    for(int i=1;i<=st.size();i++){
        cout << st[i] << " ";
    }cout<<"\n";


    return 0;
}