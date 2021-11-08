#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> vec{ 'a','b'};
const int r = 3;  // 3개 출력
vector<char> buffer(r);  // 원소 출력을 위한 출력 버퍼

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
//vector<char> buffer(2);  // 원소 출력을 위한 출력 버퍼

void permutation(vector<pair<char,bool>> check ,int k,int r) {  // 2Pr 순열
	if (k == r) {
		for(int i=0; i<r; i++){
			cout << buffer[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < vec.size(); i++) { //i 는 k 부터 문자 전체 길이까지
			
			if (check[i].second == true)
				continue;
			else {
				buffer[k] = check[i].first;  // 사용되지 않았다면 buffer에 저장.
				check[i].second = true;  // 사용된 원소라고 표시
				permutation(check, k + 1, r); // K+1 원소 부터 다시 구하러
				check[i].second = false; // 구하고 다시 돌아왔으면 체크 해제
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
	//permutation(check,0,2); //4P2 순열
	return 0;
}