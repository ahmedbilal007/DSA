#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums){
	int answer = 0;
	for (int val : nums)
		answer = answer ^ val;
	return answer;
}

int main(){
	vector<int> vec;
	vector<int> vect2(3,0);

	vector<int> single = {0,0,4,5,4};
//	cout << vect2[2];
//	for (int i:vect2)
//		cout << i << " ";

//	cout << vect2.size()<< endl;
//	vect2.push_back(25);
//	cout << vect2.size()<<endl;

//	vec.push_back(3);
//	vec.push_back(4);
//	vec.push_back(5);
//	cout << vec.size();
//	cout << vec.capacity();

	cout << singleNumber(single);

	return 0;
}
