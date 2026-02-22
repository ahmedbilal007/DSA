#include <iostream>
using namespace std;

int maxSubArraySum(int arr[], int sz){
	int maxSum = INT_MIN;
	for (int st=0; st<sz; st++){
		int curSum = 0;
		for (int endd=st; endd<sz; endd++){
			curSum += arr[endd];
			maxSum = max(curSum, maxSum);
		}
	}
	return maxSum;
}

int KanadesAlgo(int arr[], int sz){
	int curSum = 0, maxSum = INT_MIN;
	for (int i=0; i<sz; i++){
		curSum += arr[i];
		maxSum = max(curSum, maxSum);
		if (curSum < 0) curSum = 0;
	}
	return maxSum;
}



int main(){

	int n=5;
	int arr[] = {1,2,3,4,5};
//	for (int st=0; st<n; st++){
//		for (int end=st; end<n; end++){
//		for (int i=st; i<=end; i++){
//			cout << arr[i];
//		}
//		cout << " ";
//		}
//		cout << endl;
//	}


	int sumArray[] = {1,4,2,-5,-6,3,2,15};
	cout << maxSubArraySum(sumArray, 8);
	cout << KanadesAlgo(sumArray, 8);

	return 0;
}
