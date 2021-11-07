#include<iostream>
#include<algorithm>
using namespace std;

char datad[] = { 'a','b','c','d' };
int n = 4;
void perm(int k) {
	if (k == n) {
		for (auto elem : datad) {
			cout << elem << " ";
		}
		cout << '\n';
		return; 
	}
	else {
		for (int i = k; i < n; i++) {
			std::swap(datad[k], datad[i]);
			perm(k + 1);
			swap(datad[k], datad[i]);
		}
	}
}
int main() {

	perm(0);



	return 0;
}