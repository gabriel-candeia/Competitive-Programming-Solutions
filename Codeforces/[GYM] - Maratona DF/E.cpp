#include <bits/stdc++.h>

using namespace std; 

vector<string> sss = { "Algebra", "Aritmetica", "Backtracking", 
                         "Bigint", "Combinatoria", 
                         "Estruturas de Dados", "Geometria", 
                         "Ordenacao", "Programacao Dinamica", 
                         "SegTrees", "Teoria dos Numeros", 
                         "Travessia em Grafos"  };

vector<string> reader(string& s) {
    s.append(1,',');
    vector<string> ans;
    auto it = s.begin();
    string temp;
    while(it != s.end()) {
        if(*it != ',')
            temp.append(1, *it);
        else {
            ans.push_back(temp);
            temp.clear();
        }
        it++;
    }
    return ans;
}

vector<set<string>> arr;

map<string, int> bst;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    for(auto a : sss)
        bst[a];
    int n; cin >> n;
    cin.ignore();
    vector<string> tmp;
    set<string> t;
    for(int i = n; i--;) { 
        string s; getline(cin, s);
        tmp = reader(s);
        for(auto a : tmp) {
            bst[a]++;
        }
    }
   
    int mmaax = 0;
    int mmin = n;
    for(auto [a, b]:bst) {
        mmaax = max(mmaax, b);
        mmin = min(mmin, b);
        //cout << a << " " << b<<'\n';
    }
    
    vector<pair<int, string>> answ;

    for(auto [a, b] : bst) {
        if(b==0 || 4*b < 3*mmaax)
            answ.push_back({b, a});
    }
    
    sort(answ.begin(), answ.end());

    if(answ.empty()) {
        cout << "Tudo em Ribas!" << endl;
    } else {
        for(auto [a, b]:answ) {
            cout << "Falta " << b << "!" << endl;
        }
    }
        
    return 0;
}