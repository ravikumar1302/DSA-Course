/*
Aggresive_cows_Codestudio
Aggressive Cows_GFG
Magnetic Force Between Two Balls_Leetcode_1552

Given an array of length ‘N’, where each element denotes the position of a stall.
Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive.
To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
Return the largest minimum distance.
*/

bool ispossible(vector<int> &stalls, int k, int mid)
{
    int cowcount = 1;
    int lastpos = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastpos >= mid)
        {
            cowcount++;
            if (cowcount == k)
            {
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++)
        maxi = max(maxi, stalls[i]);
    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (ispossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}