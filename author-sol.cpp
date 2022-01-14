#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// count the numbers which contain even and odd no. set bits (separately)
		// counter[0] = numbers which have an even number of set bits (1-bits)
		// counter[1] = numbers which have an odd number of set bits (1-bits)
		vector<int> counter(2, 0);
		for (int i = 0; i < n; i++) {
			counter[__builtin_popcount(a[i]) % 2]++;
		}
		// if the set bits of a given query (number) is even, then it will not affect the set bits
		// of the numbers in the original sequence, otherwise it will flip the frequency of the numbers
		// which have an even number of set bits with the frequency of the numbers which have an odd number of set bits
		for (int i = 0; i < q; i++) {
			int p;
			cin >> p;
			int z = __builtin_popcount(p);
			if (z % 2 == 0) {
				cout << counter[0] << " " << counter[1];
			} else {
				cout << counter[1] << " " << counter[0];	
			}
			cout << '\n';
		}
  }
	return 0;
}
