#include<bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, int vis[], vector<pair<int>> adj[]) {
	vis[node] = 1;
	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs(it, st, vis, adj);
		}
	}
	st.push(node);
}

vector<int> shortestPath(int N, int M, vector < vector < int >> & a) {
	vector<pair <int, int>> adj[N];
	for (int i = 0; i < N; i++) {
		int u = a[i][0];
		int v = a[i][1];
		int e = a[i][2];
		adj[u].push_back({v, e});
	}
	stack<int> st;
	int vis[N] = {0};
	for (int i = 0; i < N; i ++) {
		if (!vis[i]) {
			dfs(i, st, vis);
		}
	}
	int dist[N];
	for (int i = 0; i < N ; i++) {
		dist[i] = 1e9;
	}
	dist[0] = 0;
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		for (auto it : ad[x]) {
			int v = it.first;
			int wt = it.second;
			if (wt + dist[x] < dist[v]) {
				dist[v] = wt + dist[x];
			}
		}

	}
	for (int i = 0; i < N; i++) {
		if (dist[i] == 1e9) dist[i] = -1;
	}

}
int main() {
	
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	vector<int>ans(V);
	ans = topaSort(adj, V, ans);
	for (int i = 0; i < V; i++) {
		cout << ans[i] << " "; 
	}
	
	return 0;
}


  











