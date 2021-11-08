#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> vec{ 'a','b'};
const int r = 3;  // 3�� ���
vector<char> buffer(r);  // ���� ����� ���� ��� ����

void repeatPermutation(int k,int r) {
	if (k == r) {
		for (int i = 0; i < r; i++) {
			cout << buffer[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < vec.size();i++ ) {
		buffer[k] = vec[i];
		repeatPermutation(k + 1, r);
	}
}

//vector<char> vec{ 'a','b','c','d' };
//vector<char> buffer(2);  // ���� ����� ���� ��� ����

void permutation(vector<pair<char,bool>> check ,int k,int r) {  // 2Pr ����
	if (k == r) {
		for(int i=0; i<r; i++){
			cout << buffer[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < vec.size(); i++) { //i �� k ���� ���� ��ü ���̱���
			
			if (check[i].second == true)
				continue;
			else {
				buffer[k] = check[i].first;  // ������ �ʾҴٸ� buffer�� ����.
				check[i].second = true;  // ���� ���Ҷ�� ǥ��
				permutation(check, k + 1, r); // K+1 ���� ���� �ٽ� ���Ϸ�
				check[i].second = false; // ���ϰ� �ٽ� ���ƿ����� üũ ����
			}
		}
	}
}
int main() {

	repeatPermutation(0, 3);

	//vector<pair<char, bool>> check;
	//for (int i = 0; i < vec.size(); i++) {
	//	check.push_back(make_pair(vec[i], false));
	//}
	//permutation(check,0,2); //4P2 ����
	return 0;
}