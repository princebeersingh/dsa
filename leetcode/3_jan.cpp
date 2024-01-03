// max laser in bank
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int i=bank.size();
        int j=bank[0].size();
        int result=0,curr=0,prev=0;
        for(int x=0;x<i;x++)
        {
            for(int y=0;y<j;y++)
            {
                if(bank[x][y]=='1')
                {
                    curr++;
                }   
            }
            if(curr>0)
            {
                result+=(curr*prev);
                prev=curr;

            }
            curr=0;
        }
        return result;
    }
};