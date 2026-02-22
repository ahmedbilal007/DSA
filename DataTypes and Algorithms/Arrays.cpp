#include <iostream>
#include <vector>

using namespace std;

void passByReference(int array[], int size){
	for (int i=0; i<size; i++){
		array[i] = 2*array[i];
	}
}

int linearSearch(int array[], int target, int size) {
	for (int i=0; i<size; i++){
		if (array[i] == target) return i;
	}
	return -1;
}

void reverseArray(int arr[], int sz){
	int start = 0;
	int ending = sz - 1;
	while (start < ending){
		swap(arr[start], arr[ending]);
		start++;
		ending--;
	}
}

void printUnique(int array1[], int sz){

	for (int i=0; i<sz; i++){
		bool duplicate = false;
		for (int j=0;j<sz;j++){
			if (i==j) continue;
			if (array1[i] == array1[j]){
				duplicate = true;
				continue;
			}
		}
		if (duplicate == false)
			cout << array1[i] << " ";
	}
}

void printIntersection(int arr[], int arr2[], int sz, int sz2) {
	for (int i=0; i<sz; i++){
		for (int j=0; j<sz2; j++) {
			if (arr[i]==arr2[j])
				cout << arr[i] << " ";
		}
	}
}

vector<int> pairsum(vector<int>nums, int target){
	vector<int> ans;
	int n = nums.size();

//	for (int i=0; i<n; i++){
//		for (int j=i; j<n; j++){
//			if (nums[i] + nums[j] == target)
//			{
//				ans.push_back(i);
//				ans.push_back(j);
//				return ans;
//			}
//		}
//	}
//	return ans;

	int start = 0;
	int endd = n-1;
	while(start < endd){
		int sum = nums[start] + nums[endd];
		if (sum < target) start++;
		else if (sum > target) endd--;
		else {
			ans.push_back(start);
			ans.push_back(endd);
			return ans;
		}
	}

	return ans;

}

int majorityElement(vector<int>nums){
//// Brute Force Approach
	int n = nums.size();
//	for (int val : nums){
//		int frequency = 0;
//		for (int element : nums){
//			if (val==element){
//				frequency++;
//			}
//		}
//		if (frequency > n/2) return val;
//	}
//	return -1;

//// Optimized Approach
//	sort(nums.begin(), nums.end());
	int frequency = 1;
	int ans = nums[0];
	for (int i=1; i<n; i++){
		if (nums[i]==nums[i-1]){
			frequency++;
		} else {
			frequency = 1;
			ans = nums[i];
		}
		if (frequency > n/2){
			return ans;
		}
	}
	return ans;
}


int mooreAlgo(vector<int>& nums){
	int freq = 0, ans = 0;

	for (int i=0;i<nums.size();i++){
		if (freq==0){
			ans = nums[i];
		}
		if (freq == nums[i]){
			freq++;
		} else {
			freq--;
		}
	}
	return ans;
}


// Calculating power using binary exponentiation
double power(double x, int n){
	if (x==1 || n==0) return 1.0;
	if (x==0) return 0.0;
	if (x==-1 && n%2==0) return 1.0;
	if (x==1 && n%2!=0) return 1.0;

	long binaryForm = n;
	if (n < 0){
		x = 1/x;
		binaryForm = -binaryForm;
	}
	double ans = 1;
	while(binaryForm > 0){
		if (binaryForm % 2==1) ans *= x;
		x *= x;
		binaryForm /= 2;
	}
	return ans;
}

int buySell(int prices[], int sz){
	int maxProfit = 0;
	int bestBuy = prices[0];
	for (int i=0; i<sz; i++){
		if (prices[i] > bestBuy)
			maxProfit = max(maxProfit, prices[i] - bestBuy);
		bestBuy = min(bestBuy, prices[i]);
	}
	return maxProfit;
}

bool checkArray(int arr[], int sz){
	for (int i=0; i<sz; i++){
		if (arr[i] < arr[i-1]) return false;
	}
	return true;
}


int main(){
//	int numbers[] = {12,34,23,45,23,34,13};
//	int values[] = {1,1,2,2,3,4,5,4,3,6,7};
//	int values2[] = {8,25,4,3,6,7,33,98,21};
//	passByReference(numbers,5);
//	for (int i=0; i<5; i++){
//		cout << numbers[i] << " ";
//	}

//	cout << linearSearch(numbers, 100, 5);
//	reverseArray(numbers,5);
//	for (int i=0; i<5; i++){
//		cout << numbers[i] << " ";
//	}

//	printUnique(numbers,7);
//	printUnique(values,20);

//	printIntersection(values, values2,11,9);

	vector<int>nums = {3,2,4};
	int arr[] = {1,2,3,4,5};
//	int target = 6;
//	vector<int> answer = pairsum(nums, target);
//	cout << answer[0] << answer[1] << endl;

	cout << checkArray(arr,5);

//	vector<int>numbers = {1,2,2,1,1};
//	vector<int>numbers2 = {0,0,1,1,2,2,2,2};
////	cout << majorityElement(numbers); 	// Brute Force Approach
//
//	cout << majorityElement(numbers2);		// Optimized Approach
//
//	cout << mooreAlgo(numbers);

//	cout << power(3,5);
//	cout << power(2,-2);

//	int prices[] = {1,3,5,6,7,3,8};
//	int sz = 7;
//	cout << buySell(prices, sz) << endl;

	return 0;
}
