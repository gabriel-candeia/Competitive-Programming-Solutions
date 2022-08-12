#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

namespace Simplex {
	vector<vector<double>> T;
	int n, m;
	vector<int> X, Y;

	void pivot(int x, int y) {
		swap(X[y], Y[x-1]);
		for (int i = 0; i <= m; i++) if (i != y) T[x][i] /= T[x][y];
		T[x][y] = 1/T[x][y];
		for (int i = 0; i <= n; i++) if (i != x and abs(T[i][y]) > eps) {
			for (int j = 0; j <= m; j++) if (j != y) T[i][j] -= T[i][y] * T[x][j];
			T[i][y] = -T[i][y] * T[x][y];
		}
	}

	// Retorna o par (valor maximo, vetor solucao)
	pair<double, vector<double>> simplex(
			vector<vector<double>> A, vector<double> b, vector<double> c) {
		n = b.size(), m = c.size();
		T = vector<vector<double>>(n + 1, vector<double>(m + 1));
		X = vector<int>(m);
		Y = vector<int>(n);
		for (int i = 0; i < m; i++) X[i] = i;
		for (int i = 0; i < n; i++) Y[i] = i+m;
		for (int i = 0; i < m; i++) T[0][i] = -c[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) T[i+1][j] = A[i][j];
			T[i+1][m] = b[i];
		}
		while (true) {
			int x = -1, y = -1;
			double mn = -eps;
			for (int i = 1; i <= n; i++) if (T[i][m] < mn) mn = T[i][m], x = i;
			if (x < 0) break;
			for (int i = 0; i < m; i++) if (T[x][i] < -eps) { y = i; break; }

			if (y < 0) return {-1e18, {}}; // sem solucao para  Ax <= b
			pivot(x, y);
		}
		while (true) {
			int x = -1, y = -1;
			double mn = -eps;
			for (int i = 0; i < m; i++) if (T[0][i] < mn) mn = T[0][i], y = i;
			if (y < 0) break;
			mn = 1e200;
			for (int i = 1; i <= n; i++) if (T[i][y] > eps and T[i][m] / T[i][y] < mn)
				mn = T[i][m] / T[i][y], x = i;

			if (x < 0) return {1e18, {}}; // c^T x eh ilimitado
			pivot(x, y);
		}
		vector<double> r(m);
		for(int i = 0; i < n; i++) if (Y[i] < m) r[Y[i]] = T[i+1][m];
		return {T[0][m], r};
	}
}

char mat[500][500];

int n, m;
int conv(int i, int j){
    return i*m+j;
}

vector<vector<double>> adj;

int main(){
    cin >> n >> m;
    cout << n << " " << m <<"\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    adj.assign(n*m,vector<double>(n*m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='#') continue;
            if(i+1<n && mat[i+1][j]!='#'){
                int a = conv(i,j), b = conv(i+1,j);
                adj[a][b] = -1;
                adj[b][a] = -1;
            }
            if(j+1<m && mat[i][j+1]!='#'){
                int a = conv(i,j), b = conv(i,j+1);
                adj[a][b] = -1;
                adj[b][a] = -1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a = conv(i,j);
            adj[a][a] = -1;
        }
    }

    vector<double> b(n*m,-1);
    vector<double> c(n*m,-1);

    auto p = Simplex::simplex(adj,b,c);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='#') continue;
            int u = conv(i,j);
            if(p.second[u]==1){
                mat[i][j] = 'O';
            }
            cout << p.second[u] << " ";
        }
    }
    cout<<"\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << mat[i][j] << " ";
        }
        cout<<"\n";
    }


    return 0;
}