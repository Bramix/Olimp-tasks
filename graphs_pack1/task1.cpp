#include <vector>
#include <iostream>
using namespace std;

int n, start;
void dfs(int pos, vector <vector<int> > list, vector <bool> &  used) {
	used[pos] = true;
	for (int i = 0; i < list[pos].size(); i++) {
		int to = list[pos][i];
		if (!used[to])
			dfs(to, list, used);
	}
}
int main(void)
{
	int start, buf, res = 0;
	cin >> n >> start;
	vector <vector<int> > list(n);
	vector <bool> used(n, false);
	start--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> buf;
			if (buf) {
				list[i].push_back(j);
				list[j].push_back(i);
			}
		}
	dfs(start, list, used);
	for (int i = 0; i < used.size(); i++)
		if (used[i]) res ++;
	cout << res;
}

