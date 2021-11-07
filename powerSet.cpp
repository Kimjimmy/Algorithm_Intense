#include<iostream>
#include<vector>
#include<string>

using namespace std;


string arr[] = { "a","b","c","d" };
const int n = sizeof(arr) / sizeof(arr[0]);

bool include[4];

void powerSet(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			if (include[i])cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	else {
		include[k] = false;
		powerSet(k + 1);
		include[k] = true;
		powerSet(k + 1);
	}

}

int main() {


	powerSet(0);

	return 0;
}