//
//  main.cpp
//  algorithm_037_solveSudoku
//
//  Created by zhounanguang on 16/1/25.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

    	solve(board,0);
    }
    bool solve(vector<vector<char>> &board,int position){
    	if(position==81)
    		return true;
    	int row = position/9;
    	int column = position%9;
    	if(board[row][column]=='.'){
    		for(int i=1;i<=9;i++){
    			board[row][column]='0'+i;
    			if(isValidSudoku(board))
    				if(solve(board,position+1))
    					return true;
    			board[row][column]='.';
    		}
    	}
    	else{
    		if(solve(board,position+1)){
    			return true;
    		}
    	}
    	return false;
    }
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
    bool checkValid(int vec[], int val){
    	if(vec[val]==1)
    		return false;
    	vec[val]=1;
    	return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string b0[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
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
	sol.solveSudoku(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}
