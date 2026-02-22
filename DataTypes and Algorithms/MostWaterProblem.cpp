#include <iostream>
using namespace std;

int bruteApproach(int arr[], int sz){
	int maxWater = INT_MIN;
	for (int i=0; i<sz; i++){
		for (int j=i+1; j<sz; j++){
			int width = j-i;
			int height = min(arr[i], arr [j]);
			int area = width * height;
			maxWater = max(maxWater, area);
		}
	}
	return maxWater;
}

int optimalApproach(int heights[], int sz){
	int lp = 0;
	int rp = sz - 1;
	int answer = 0;
	while (lp < rp){
		int width = rp - lp;
		int height = min(heights[rp], heights[lp]);
		int curWater = width * height;
		answer = max(answer, curWater);
		(heights[lp] < heights[rp]) ? lp++ : rp--;
	}
	return answer;
}

int main(){
	int heights[] = {1,8,6,2,5,4,8,3,7};;
	int sz = 9;
	cout << "Max Water: " << bruteApproach(heights, sz) << endl ;
	cout << "Max Water: " << optimalApproach(heights, sz);
	return 0;
}
