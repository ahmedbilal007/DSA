#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> nums, int target){
	// Time Complexity --> O(log n) --> because the search space gets half on each iteration
	// Space Complexity --> O(1)

		// Iterative approach is better than recursive approach
		// because of its better space complexity O(1)..

	int start = 0;
	int endd = nums.size() - 1;
	while (start <= endd){
		int mid = start + ((endd - start)/2);
		if (target < nums[mid]) endd = mid - 1;
		else if (target > nums[mid]) start = mid + 1;
		else return mid;
	}
	return -1; 	// target not present int the list.
}

int recursiveBS(vector<int>nums, int target, int st, int endd){
	// Time Complexity --> O(log n)
	// Space Complexity --> O(log n) --> due to recursive stack
	if (st <= endd){
		int mid = st + (endd-st)/2;
		if (target < nums[mid])
			return recursiveBS(nums,target, st, mid-1);
		else if (target > nums[mid])
			return recursiveBS(nums, target, mid+1, endd);
		else
			return mid;
	}
	return -1;
}

// Searching in a Rotated Sorted Array

int rotatedArray(vector<int> nums, int target){
	// Time Complexity --> O(log n) --> it is a kind of modified binary search
	// Space Complexity --> O(1)
	int start = 0;
	int endd = nums.size() - 1;
	while (start <= endd){
		int mid = start + (endd - start) / 2;
		if (nums[mid]==target) return mid;
		if (nums[start] <= nums[mid]){
			if (nums[start] <= target && target <= nums[mid]){
				endd = mid - 1;
			} else {
				start = mid + 1;
			}
		} else {
			if (nums[mid] <= target && target <= nums[endd]){
				start = mid + 1;
			} else {
				endd = mid - 1;
			}
		}
	}
	return -1;
}

int peakIndexinMountain(vector<int>nums){

	// Time Complexity --> O(log n)

	int start = 1;
	int endd = nums.size() - 2;				// Peak value can't be at first and last index
	while (start <= endd){
		int mid = start + (endd - start)/2;
		if (nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
			return mid;
		if (nums[mid] > nums[mid-1])
			start = mid + 1;
		else
			endd = mid - 1;
	}
	return -1;
}

int singleElement(vector<int>nums){

	// Time complexity --> O(log n)
	// Space Complexity --> O(1)

	int start = 0;
	int n = nums.size();
	int endd = nums.size() - 1;
	if (n==1) return nums[0];		// only single element in the array
	while(start <= endd){
		int mid = start + (endd-start)/2;
		if (mid==0 && nums[mid]!=nums[mid+1]) return nums[0];		// if answer is at the first index
		if (mid==n-1 && nums[mid]!=nums[mid-1]) return nums[mid];	// if answer is at the last index
		if (nums[mid-1]!=nums[mid]&&nums[mid]!=nums[mid+1])			// if answer exits at the mid
			return nums[mid];
		if (mid%2==0){			// even number of elements around the mid
			if (nums[mid]==nums[mid-1])		// if mid is equal to the one at the left
				endd = mid-1;			// searching in left
			else
				start = mid+1;
		} else {
			if (nums[mid-1]==nums[mid])
				start = mid+1;
			else
				endd = mid-1;
		}
	}
	return -1;
}

bool isValid(vector<int>books, int n, int m, int maxAllowedPages){
	// Time Complexity --> O(n) --> because of loop.
	int stud = 1;
	int pages = 0;
	for (int i=0; i<n; i++){
		if (books[i]>maxAllowedPages)
			return false;
		if (pages + books[i] <= maxAllowedPages)
			pages += books[i];
		else{
			stud++;
			pages = books[i];
		}
	}
	return (stud > m) ? false : true;
}

bool isPaintingPossible(vector<int> boards, int n, int m, int maxTime){
	int painter = 1;
	int time = 0;
	for (int i=0;i<n; i++){
		if (maxTime < boards[i]) return false;
		if (time + boards[i] <= maxTime)
			time += boards[i];
		else{
			painter++;
			time = boards[i];
		}
	}
	return painter > m ? false : true;
}


int boolAllocation(vector<int> pages,int books, int members){
	// Time Complexity --> O(log n * n)
	// log n --> time complexity of while loop inside this function
	// n --> time complexity of the function "isValid"
	// As the function 'isValid' is called for each iteration of while loop, That's why overall time complexity is O(log n * n)

	if (members > books) return -1;
	int sum = 0;
	int ans = -1;
	for (int i=0; i<books; i++)
		sum += pages[i];

	int st = 0, endd = sum;
	while(st <= endd){
		int mid = st + (endd-st)/2;
		if(isValid(pages, books, members, mid))
		{
			ans = mid;
			endd = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	return ans;
}

int painterPartition(vector<int>boards, int n, int m){
	// Time Complexity --> O(log(sum) * n)
	if (m > n)return -1;
	int sum = 0;
	int st = INT_MIN ;
	for (int i=0; i<n; i++){
		sum += boards[i];
		st = max(st, boards[i]);
	}
	int ans = -1;
	int endd = sum;
	while (st <= endd){
		int mid = st + (endd-st)/2;
		if (isPaintingPossible(boards, n, m, mid)){
			ans = mid;
			endd = mid - 1;
		} else {
			st = mid + 1;
		}
	}
	return ans;
}

bool possiblePlace(vector<int> positions, int n, int m, int mid){
	int cow = 1;
	int lastPlace = positions[0];
	for (int i=1; i<n; i++){
		if ((positions[i]-lastPlace) >= mid){
			cow++;
			lastPlace = positions[i];
		}
		if (cow==m)
			return true;
	}
	return false;
}

int aggressiveCow(vector<int>& positions, int n, int m){
	sort(positions.begin(), positions.end());// O(log n)
	int st = 1;
	int ans = -1;
	int endd = positions[n-1] - positions[0];
	while(st <= endd){						// O((log range) * n)
		int mid = st + (endd-st)/2;
		if (possiblePlace(positions, n, m, mid)){
			ans = mid;
			st = mid + 1;
		} else {
			endd = mid -1;
		}
	}
	return ans;
}


int main(){
	vector<int> nums = {-1,0,3,4,5,9,12};
	vector<int> nums2 = {1,2,4,7,9,11};
	vector<int> rotated = {3,4,5,6,7,0,1,2};
	vector<int> mountain = {0,3,8,9,5,2};
	vector<int> mountain2 = {1,4,5,6,10,4,3};
	vector<int> single = {1,1,2,3,3,4,4,8,8};
	vector<int> single2 = {7,7,10,10,11};
	vector<int> books = {2,1,3,4};
	vector<int> boards = {40,30,10,20};
	vector<int> boards2 = {10,50,90,30};
	vector<int> positions = {1,2,8,4,9};
//	cout << binarySearch(nums, 0) << endl;
//	cout << binarySearch(nums, 9) << endl;
//	cout << binarySearch(nums, 14) << endl;
//	cout << binarySearch(nums2, 9) << endl;
//	cout << binarySearch(nums2, 2) << endl;
//	cout << recursiveBS(nums, 0, 0, nums.size()-1) << endl;
//	cout << recursiveBS(nums, 9, 0, nums.size()-1) << endl;
//	cout << recursiveBS(nums, 14, 0, nums.size()-1)<< endl;

//	cout << rotatedArray(rotated, 0) << endl;
//	cout << rotatedArray(rotated, 5) << endl;

//	cout << peakIndexinMountain(mountain) << endl;
//	cout << peakIndexinMountain(mountain2) << endl;

//	cout << singleElement(single) << endl;
//	cout << singleElement(single2) << endl;

//	cout << boolAllocation(books,books.size(), 2) << endl;
//	cout << painterPartition(boards, boards.size(), 2) << endl;
//	cout << painterPartition(boards2, boards.size(), 2) << endl;

	cout << aggressiveCow(positions, positions.size(), 3) << endl;

	return 0;
}
