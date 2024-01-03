#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int ,int >mp;
        for(auto &i:nums){mp[i]++;}
        vector<vector<int>>ans;
        while(!mp.empty()){
            vector<int> temp1,temp2;
            for(auto&[f,s]:mp){
                temp1.emplace_back(f);
                s--;
                if(s==0)temp2.emplace_back(f);
            }
             ans.emplace_back(temp1);
            for (auto &i : temp2){
                mp.erase(i);
                }

        }
        return ans;
    }
};