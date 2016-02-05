//
//  main.cpp
//  algorithm_039_combinationSum
//
//  Created by zhounanguang on 16/2/5.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<int> temp;
public:
	bool findCombination(vector<int> &candidates, int start, int cur_target, vector<vector<int>> &ret){
		int length = candidates.size();
		for(int i = start;i<length;i++){
			if(cur_target==0){
				temp.push_back(candidates[i]);
				ret.push_back(temp);
                temp.erase(temp.end()-1);
				return true;
			}
			else if(cur_target>0){
				for(int j=i;j<length;j++){
					temp.push_back(candidates[i]);
                    findCombination(candidates,j,cur_target- candidates[j],ret);
                    temp.erase(temp.end()-1);
				}
				return false;
			}
			else if(cur_target<0){
				return false;
			}
		}
		return false;
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
        	temp.clear();
        	findCombination(candidates,i,target - candidates[i],ret);
        }
        return ret;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[]={1,2,3,4,6,7};
    int length = sizeof(a)/sizeof(a[0]);

	vector<int> candidates(a,a+length);
	int target = 7;
	Solution sol;
	vector<vector<int>> ret = sol.combinationSum(candidates,target);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}
