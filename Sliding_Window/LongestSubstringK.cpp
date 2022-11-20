#include<bits/stdc++.h>
using namespace std;
int longestSubstringKUniqueCharacters(string &s, int k) {
	int i = 0, j = 0;
	int maxi = 0;
	map<char, int> m;
	while (j < s.size()) {
		m[s[j]]++;
		if (m.size() < k) {
			j++;
		}
		else if (m.size() == k) {
			maxi = max(maxi, j - i + 1);
			j++;
		}
		else if (m.size() > k) {
			while (m.size() > k) {
			m[s[i]]--;
			if (m[s[i]] == 0) {
				m.erase(s[i]);
			}
			i++;
		}
		j++;
	}
	}
	return maxi;
}
int longestSubstring(string &s) {
	map<char, int> m;
	int i = 0, j = 0;
	int cnt = -1;
	while (j < s.size()) {
		m[s[j]]++;
		if (m.size() == j - i + 1) {
			cnt = max(cnt, j - i + 1);
			//j++;
		}
		else if (m.size() < j - i + 1) {
			
			while (m.size() < j - i + 1) {
				m[s[i]]--;
				if (m[s[i]] == 0) {
					m.erase(s[i]);
				}
				i++;
			}

		}
		j++;
	}
	return cnt;
}

int main() {
	string s;
	cin >> s;
	cout << longestSubstring(s);
	//int k;
	//cin >> k;
	//cout << longestSubstringKUniqueCharacters(s, k);
	return 0;
}