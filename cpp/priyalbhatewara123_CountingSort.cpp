//COUNTING SORT

#include<bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int a[n];
	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > maxNum) {
			maxNum = a[i];
		}
	}

	int freq[maxNum + 1] = {0};
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}

	for (int i = 0; i <= maxNum; i++) {
		if (freq[i] != 0) {
			while (freq[i]--) {
				cout << i << " ";
			}
		}
	}

	return 0;
}