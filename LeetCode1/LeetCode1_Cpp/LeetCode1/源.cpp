#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void Stringsplit(string str, const char split, vector<int>& res) {
	istringstream iss(str);
	string token; // buffer
	while (getline(iss, token, split)) {
		res.push_back(stoi(token));
	}
}

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> answ = {};
	if (nums.size() > 1) {
		for (int i = 0; i < signed(nums.size()) - 1; i++) {
			for (int j = i + 1; j < signed(nums.size()); j++) {
				if ((nums[i] + nums[j] == target)) {
					return { i,j };
				}
			}
		}
		return {};
	}
	else {
		return vector<int>();
	}

	return nums;
}

int main() {
	cout << "Please Enter the list:" << endl;;
	string numStr;
	string targetStr;
	getline(cin, numStr);
	getline(cin, targetStr);
	int targetnum = stoi(targetStr);
	vector<int> numList;
	Stringsplit(numStr, ',', numList);
	vector<int> answList = twoSum(numList, targetnum);
	for (auto s : answList) {
		cout << s << "\n";
	}
	cout << endl;
	return 0;
}