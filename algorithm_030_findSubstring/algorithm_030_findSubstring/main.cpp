//
//  main.cpp
//  algorithm_030_findSubstring
//
//  Created by zhounanguang on 16/1/17.
//  Copyright © 2016年 zhounanguang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int length = words.size();
        if(length<=0)
        	return ret;
        int word_size = words[0].length();
        map<string,int> word_counting;
        map<string,int> counting;
        for(int i=0;i<length;i++){
        	word_counting[words[i]]++;
        }
        int i,j;
        if(s.length()<length*word_size)
        	return ret;
        for(i=0;i<=s.length()-length*word_size;i++){
        	counting.clear();
        	for(j=0;j<length;j++){
        		string word = s.substr(i+j*word_size,word_size);
        		if(word_counting.find(word)!=word_counting.end()){
        			counting[word]++;
        			if(counting[word]>word_counting[word])
        				break;
        		}
        		else{
        			break;
        		}
        	}
        	if(j==length)
        		ret.push_back(i);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "a";
    string s1[] = {"a","a"};
    int length = sizeof(s1)/sizeof(s1[0]);
    vector<string> words(s1,s1+length);
    Solution sol;
    vector<int> ret = sol.findSubstring(s,words);
    for(int i=0;i<ret.size();i++)
    	cout<<ret[i]<<endl;
    return 0;
}
