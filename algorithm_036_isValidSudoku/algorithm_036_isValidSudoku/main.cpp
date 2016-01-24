//
//  main.cpp
//  algorithm_036_isValidSudoku
//
//  Created by zhounanguang on 16/1/24.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rowValid[10] = {0};
		int columnValid[10][10] = {0};
		int subBoardValid[10][10] = {0};

		for (int i = 0; i < 9; i++) {
			memset(rowValid, 0, sizeof(rowValid));
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {

					int val = board[i][j] - '0';
					if (!checkValid(rowValid, val) ||
					        !checkValid(columnValid[j], val) ||
					        !checkValid(subBoardValid[i / 3 * 3+j / 3 ], val)) {
						return false;
					}

				}
			}
		}

		return true;

	}
	bool checkValid(int vec[], int val) {
		if (vec[val] == 1)
			return false;
		vec[val] = 1;
		return true;
	}
};
int main(int argc, const char * argv[]) {
	// insert code here...
	string b0[] = {".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........"};
	vector<vector<char>> board;
	for (int i = 0; i < 9; i++) {

		vector<char> temp;
		for (int j = 0; j < 9; j++) {
			temp.push_back(b0[i][j]);
		}
		board.push_back(temp);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	Solution sol;
	bool ret = sol.isValidSudoku(board);
	cout << ret << endl;
	return 0;
}
