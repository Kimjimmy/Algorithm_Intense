#include<iostream>
#include<algorithm>
using namespace std;

char datad[] = { 'a','b','c','d' };
const int n = 4; // datad 크기.
static int cnt = 0;

/* permutation 4P4 */
void perm_4P4(int k) {
	if (k == n) {
		for (auto elem : datad) {
			cout << elem << " ";
		}
		cout << '\n';
		return; 
	}
	else {
		for (int i = k; i < n; i++) {
			swap(datad[k], datad[i]); // 스왑
			perm_4P4(k + 1);  // 재귀
			swap(datad[k], datad[i]);  // 다시 제자리로 
		}
	}
}
void perm_4P2(int k,int r) {
	if (k==r) {
		for (int i = 0; i < r; i++) {
			cout << datad[i];
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = k; i < n; i++) {
			cnt++;
			swap(datad[i], datad[k]);
			perm_4P2(k + 1,r);
			swap(datad[i], datad[k]);
		}
		
	}
}
int main() {

	//perm_4P4(0);  // 4P4	
	perm_4P2(0,2); //4P3
	cout << cnt;


	return 0;
}