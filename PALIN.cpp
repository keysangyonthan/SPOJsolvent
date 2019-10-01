#include <bits/stdc++.h>

using namespace std;

void reverse_replace(string &k, int i, int j) {
	while (i >= 0) k[j++] = k[i--];
}

void increment(string &k, int j) {
	while (j >= 0 && k[j] == '9') k[j--] = '0';

	if (j < 0)
		k = '1' + k;
	else
		++k[j];
}

void smallest_greater_palin(string &k) {
	int i, j;

	i = (k.length() - 1)/2, j = k.length()/2;
	while (i >= 0 && j < k.length()) {
		if (k[i] > k[j]) {
			reverse_replace(k, i, j);
			return;
		} else if (k[i] < k[j]) {
			break;
		}
		--i, ++j;
	}

	increment(k, (k.length() - 1)/2);
	i = (k.length() - 1)/2, j = k.length()/2;
	if (k.length() & 1) --i, ++j;
	reverse_replace(k, i, j);
}

main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string K;
		cin >> K;
		smallest_greater_palin(K);
		cout << K << '\n';
	}
}