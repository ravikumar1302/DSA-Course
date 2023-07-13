/*
String_Compression_Leetcode_443
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int count =1;
        for(int i=0;i<chars.size();i++)
        {
            if(i+1< chars.size() && chars[i]==chars[i+1])
            {
                count++;
            }
            else
            {
                  if(count==1)
                    s+=chars[i];
                    
                  if(count>1)
                    s+=chars[i]+to_string(count);
                     
                count=1;
            }      
        }
        chars.clear();
                for(auto i:s){chars.push_back(i);}
        return s.size();

}
};