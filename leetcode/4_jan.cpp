#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int ,int >mp;
        int temp,ans=0;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            temp=i.second;
            if(temp==1)return -1;
            if(temp%3==1){
                ans+=temp/3-1;
                ans+=2;
            }
            else
            {
                ans+=temp/3;
                ans+=(temp%3)/2;
            }
        }
        return ans;
    }
};