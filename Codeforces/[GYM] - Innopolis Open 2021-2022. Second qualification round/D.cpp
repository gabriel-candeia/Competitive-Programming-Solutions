#include<bits/stdc++.h>
#define ll long long
#define maxn int(2005)
using namespace std;

int n;
vector<int> adj[maxn];
vector<pair<int,int>> ptsx, edges;

#define sq(x) ((x)*(ll)(x))

// 840720
struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

// 7ab617
struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// PONTO & VETOR

// 51563e
ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

// bf431d
ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

// a082d3
bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

// 42bb09
bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

// fcf924
int quad(pt p) { // quadrante de um ponto
	return (p.x<0)^3*(p.y<0);
}

// 77187b
bool compare_angle(pt p, pt q) { // retorna se ang(p) < ang(q)
	if (quad(p) != quad(q)) return quad(p) < quad(q);
	return ccw(q, pt(0, 0), p);
}

// e4ad5e
pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

// c9f07f
bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return (a ^ b) == 0 and (a * b) <= 0;
}

// 35998c
bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

bool cruza(pair<int,int> a, pair<int,int> b, pair<int,int> c, pair<int,int> d){
    return interseg(line(pt(a.first,a.second),pt(b.first,b.second)),line(pt(c.first,c.second),pt(d.first,d.second)));
}

bool isok1(vector<int> p){
    for(int i=0;i<edges.size();i++){
        for(int j=i+1;j<edges.size();j++){
            auto a = ptsx[p[edges[i].first-1]], b=ptsx[p[edges[i].second-1]], c=ptsx[p[edges[j].first-1]], d = ptsx[p[edges[j].second-1]];
            if(cruza(a,b,c,d)){
                return false;
            }
        }
    }
    return true;
}

void solve1(){
    vector<int> p(n,0);
    for(int i=0;i<n;i++) p[i] = i;

    if(!isok1(p)){
        for(;next_permutation(p.begin(),p.end());){
            if(isok1(p)){
                break;
            }
        }
    }

    for(auto x:p)
        cout << x+1 << " ";
    cout <<"\n";

    return;
}

bool ispath(){
    int cnt = 1;
    for(auto x:edges){
        if(x.first!=cnt || x.second!=cnt+1)
            return false;
        cnt++;
    }
    return true;
}

void solve2(){
    vector<array<int,3>> aux;
    for(int i=0;i<n;i++){
        aux.push_back({ptsx[i].first,ptsx[i].second,i});
    }
    sort(aux.begin(),aux.end());

    for(auto x:aux){
        cout << x[2]+1 << " ";
    }
    cout<<"\n";
}

bool isstar(){
    for(auto x:edges){
        if(x.first!=1)
            return false;
    }
    return true;
}

pair<int,int> normaliza(pair<int,int> a){
    int x = a.first, y = a.second;
    if(x==0 && y==0)
        return {x,y};
    if(x==0)
        return {0,(y>0) ? 1 : -1};
    if(y==0)
        return {(x>0) ? 1 : -1,0};
    int d = __gcd(abs(x),abs(y));
    x /= d, y /= d;
    if(y<0)
        x = -x, y = -y;
    return {x, y};

}

void solve3(){
    vector<int> answ;
    for(int i=0;i<ptsx.size();i++){
        int a = ptsx[i].first, b = ptsx[i].second;
        for(int j=0;j<ptsx.size();j++)
            ptsx[j].first-=a, ptsx[j].second-=b;

        map<pair<int,int>,int> aux;
        for(int j=0;j<ptsx.size();j++){
            if(j==i) continue;
            aux[normaliza(ptsx[j])] = j;
        }

        if(aux.size()>=n-1){
            answ.clear();
            answ.push_back(i);
            for(auto p:aux){
                answ.push_back(p.second);
            }
            break;
        }

        for(int j=0;j<ptsx.size();j++)
            ptsx[j].first+=a, ptsx[j].second+=b;
    }

    for(auto x:answ)
        cout << x+1 << " ";
    cout<<"\n";
}

vector<int> visited, resp;
int __solve(int u, int l){
    int curr = u;
    vector<int> path;
    while(!visited[u]){
        visited[curr] = 1;
        path.push_back(curr);
        for(auto v:adj[u]){
            if(!visited[v]){
                curr = v; break;
            }
        }
    }

    int l1 = l;
    for(int i=0;i<path.size();i++){
        int x = path[i];
        resp[x-1] = l1++;
    }

    for(int i=0;i<path.size();i++){
        int x = path[i];
        for(auto v:adj[x]){
            if(!visited[v]){
                l1 = __solve(v,l1);
            }
        }
    }
    return l1;
}

void solve4(){
    visited.assign(n+1,0);
    resp.assign(n,0);
    __solve(1,0);
    for(auto x:resp)
        cout << x+1 << " ";
    cout<<"\n";
}

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a,b});
    }

    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        ptsx.push_back({a,b});
    }

    if(n<=6){
        solve1();
    }
    else if(ispath()){
        solve2();
    }
    else if(isstar()){
        solve3();
    }
    else{
        solve4();
    }

    return 0;
}