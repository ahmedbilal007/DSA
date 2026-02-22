#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool isAlphaNum(char s){
	return ((tolower(s) >= 'a' && tolower(s) <= 'z') || (s >= '0' && s <= '9'));
}

bool isPalindrome(string str){
	int st = 0, endd = str.length()-1;
	while (st < endd){
		if (!isAlphaNum(str[st])){
			st++;
			continue;
		}
		if (!isAlphaNum(str[endd])){
			endd--;
			continue;
		}
		if (tolower(str[st])!=tolower(str[endd]))
			return false;
		st++;
		endd--;
	}
	return true;
}

void removeAll(string &str, string part){
	while (str.length()>0 && str.find(part)<str.length()){
		str.erase(str.find(part), part.length());
	}
}

bool isFreqSame(int freq1[], int freq2[]){
	for (int i=0; i<26; i++){
		if (freq1[i]!=freq2[i]) return false;
	}
	return true;
}

bool permutation(string str1, string str2){
	int freq[26] = {0};
	for(int i=0; i<str1.length(); i++)
		freq[str1[i]-'a']++;

	int windSize = str1.length();
	for (int i=0; i<str2.length(); i++){
		int windIdx = 0, idx = i;
		int windFreq[26] = {0};
		while(windIdx<windSize && idx<str2.length()){
			windFreq[str2[idx]-'a']++;
			windIdx++;
			idx++;
		}
		if (isFreqSame(freq, windFreq))
			return true;
	}
	return false;
}

void stringCompression(vector<char>& chars){\
	// Time Complexity --> O(n) --> as a single iterator (i) is working in both the loops,
	// that's why its time complexity is O(n) and not O(n^2)


	int idx = 0;
	for (int i=0; i<chars.size(); i++){
		char ch = chars[i];
		int countt = 0;
		while (i<chars.size() && chars[i]==ch){
			countt++;
			i++;
		}
		if (countt==1)
			chars[idx++] = ch;
		else {
			chars[idx++] = ch;
			string ct = to_string(countt);
			for (char c : ct){
				chars[idx++] = c;
			}
		}
		i--;
	}
	chars.resize(idx);
}

int main(){
	// Character Arrays
//	char arr[] = {'a', 'b', 'c', '\0'};
//	char arr2[] = "hello";
//	cout << arr << endl;
//	cout << arr2 << endl;

//	char arr[100];
//	cout << "Enter character array: ";
////	cin >> arr;
//	cin.getline(arr, 100, '$');
//	cout << arr << endl;

//	string str = "hello";
//	cout << isPalindrome(str)<<endl;
//	str = "h3a$hh?a3h";
//	cout << isPalindrome(str)<<endl;
//
//	string occur = "daabcbaabcbc";
//	removeAll(occur, "abc");
//	cout << "After removal, String is: " << occur << endl;

//	string st1 = "ab";
//	string st2 = "eidaboooo";
//	string st3 = "eidoboa";
//	cout << permutation(st1, st2) << endl;
//	cout << permutation(st1, st3) << endl;

	vector<char> chars = {'a','a','b','b','c','c','c','a'};
	stringCompression(chars);
	for (char ch : chars)
		cout << ch << " ";
	return 0;
}
