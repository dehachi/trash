/*
木の最小共通祖先

初期化(自動): init(隣接リスト, 根(任意))
頂点uと頂点vの最小共通祖先: ancestor(頂点u, 頂点v)
頂点uと頂点vの最短距離: distance(頂点u, 頂点v) 

verified: https://judge.yosupo.jp/submission/55950
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct LowestCommonAncester {
    vector<int> dep;
    vector<vector<int>> par;
    int parlen;
    int deplen;
    LowestCommonAncester(vector<vector<int>> g) {init(g);}
    void dfs(vector<vector<int>> &g, int pos, int d) {
        dep[pos] = d;
        for (int to: g[pos]) {
            if (dep[to] != -1) continue;
            par[0][to] = pos;
            dfs(g, to, d+1);
        }
    }
    void init(vector<vector<int>> &g, int s=0) {
        deplen = g.size();
        parlen = 0;
        while (deplen > (1<<parlen)) parlen++;
        dep.assign(deplen, -1);
        par.assign(parlen, vector<int>(deplen));
        dfs(g, s, 0);
        for (int i=0; i<parlen-1; i++) {
            for (int j=0; j<deplen; j++) {
                par[i+1][j] = par[i][par[i][j]];
            }
        }
    }
    int ancestor(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int h = dep[u]-dep[v];
        for (int i=parlen-1; i>=0; i--) {
            if (h < 1<<i) continue;
            u = par[i][u];
            h -= 1<<i;
        }
        if (u == v) return u;
        for (int i=parlen-1; i>=0; i--) {
            if (par[i][u] == par[i][v]) continue;
            u = par[i][u];
            v = par[i][v];
        }
        return par[0][u];
    }
    int distance(int u, int v) {
        return dep[u]+dep[v]-2*dep[ancestor(u, v)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    LowestCommonAncester lca(g);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.ancestor(u, v) << "\n";
    }
    return 0;
}
