#include<iostream>
#include<queue>
using namespace std;

int n, m, v;
const int MAX_VALUE = 1001;
int arr[MAX_VALUE][MAX_VALUE] = { 0, };
int visit[MAX_VALUE];

void dfs(int start) {
	cout << start << " ";
	visit[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (visit[i]==1 || arr[start][i]==0 ) {
			continue;
		}
		dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 0;
	
	while (!q.empty()) {
		start = q.front();
		cout << q.front() << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 || arr[start][i] == 0) {
				continue;
			}
			q.push(i);
			visit[i] = 0;
		}
	}
}
int main(int argc, char* argv[]) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}