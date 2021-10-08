// 3048KB, 3764ms

#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, string> dstr;
queue<dstr> que;
bool visited[10001];

string fourdigits(int rslt) {

	if (rslt < 10)
		return "000" + to_string(rslt);
	else if (rslt < 100)
		return "00" + to_string(rslt);
	else if (rslt < 1000)
		return "0" + to_string(rslt);
	else
		return to_string(rslt);
}

string bfs(string a, string b) {

	string ans;

	while (!que.empty()) {
		que.pop();
	}

	for (int i = 0; i < 10001; i++)
	{
		visited[i] = false;
	}
	
	que.push({ stoi(a), "" });

	while (!que.empty()) {

		dstr curr = que.front();
		que.pop();

		int scurr = curr.first;
		string ccurr = curr.second;

		// D
		int drslt = scurr * 2 % 10000;
		if (!visited[drslt]) {
			if (drslt == stoi(b))
				return ccurr + "D";
			else {
				visited[drslt] = true;
				if (drslt < 1000) {
					que.push({ drslt, ccurr + "D" });
				}
				else
					que.push({ drslt, ccurr + "D" });
			}
		}

		// S
		int srslt = scurr - 1;
		if (srslt == -1)
			srslt = 9999;
		if (!visited[srslt]) {
			if (srslt == stoi(b))
				return ccurr + "S";
			else {
				visited[srslt] = true;
				if (srslt < 1000) {
					que.push({ srslt, ccurr + "S" });
				}
				else
					que.push({ srslt, ccurr + "S" });
			}
		}

		// L
		int lrslt = scurr;
		lrslt = (lrslt % 1000) * 10 + lrslt / 1000;
		if (!visited[lrslt]) {
			if (lrslt == stoi(b))
				return ccurr + "L";
			else {
				visited[lrslt] = true;
				if (lrslt < 1000) {
					que.push({ lrslt, ccurr + "L" });
				}
				else
					que.push({ lrslt, ccurr + "L" });
			}
		}

		// R
		int rrslt = scurr;
		rrslt = rrslt / 10 + (rrslt % 10) * 1000;
		if (!visited[rrslt]) {
			if (rrslt == stoi(b))
				return ccurr + "R";
			else {
				visited[rrslt] = true;
				if (rrslt < 1000) {
					que.push({ rrslt, ccurr + "R" });
				}
				else
					que.push({ rrslt, ccurr + "R" });
			}
		}
	}

	return ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> answers;

	int n;

	string a, b, ans;

	cin >> n;

	for (int k = 0; k < n; k++)
	{
		cin >> a >> b;

		ans = bfs(a, b);

		answers.push_back(ans);
	}
	
	int asize = answers.size();
	for (int i = 0; i < asize; i++)
	{
		cout << answers.at(i) << '\n';
	}

	return 0;
}
