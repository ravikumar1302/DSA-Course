/*
Unique_no_of_occurences_Leetcode_1207

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m1; //map for occurences of elements
        map<int,int> m2; //map for uniqueness
        vector<int> ::iterator itr;
        for(itr=arr.begin();itr!=arr.end();itr++)
        {
            auto map_itr=m1.find(*itr);
            if(map_itr==m1.end())
                m1.insert(pair<int,int>(*itr,1));  //add pair if not present
            else
                map_itr->second=map_itr->second+1; // increminting value as key already there
        }
        for(auto map_it=m1.begin();map_it!=m1.end();map_it++)
        {
            auto it=m2.find(map_it->second);
            if(it==m2.end())                    //finding that all values are unique or not
                m2.insert(pair<int,int>(map_it->second,1)); 
            else
                return false;                      // returns false if m2 have duplicate value of any key
        }
        return true;
            
    }
};