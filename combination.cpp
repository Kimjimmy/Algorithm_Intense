#include<iostream>
#include<vector>

using namespace std;

vector<char> arr = { 'a','b','c','d','e' };
const int output_size = 3;
vector<char> output(output_size);
vector<bool> include(5);

//void combination(vector<char> arr,vector<char> output,int k,int r,int index) {
//	if (r==0) {
//		for (int i = 0; i < output.size(); i++) {
//			cout << output[i] << " ";
//		}
//		cout << '\n';
//	}
//	else if (k == arr.size()) {
//		return;
//	}
//	else {
//		// arr[r] 을 뽑은 경우.
//		output[index] = arr[k];
//		combination(arr,output,k + 1, r - 1,index+1);
//
//		// arr[r] 을 뽑지 않은 경우.
//		combination(arr,output,k + 1, r,index);
//	}
//}
void combination(int k, int r) {
	if (r == 0) {
		
		for (int i = 0; i < arr.size(); i++) {
			if(include[i])
				cout << arr[i] << " ";
		}
		cout << '\n';
	}
	else if (k == arr.size()) {
		return;
	}
	else {
		// arr[r] 을 뽑는 경우.
		include[k] = true;
		combination( k + 1, r - 1);

		// arr[r] 을 뽑지 않은 경우.
		include[k] = false;
		combination( k + 1, r);
	}
}
int main() {
	
	combination( 0, 3);

	return 0;
}