/*
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    
    string s = "hello";
    cout<<s.size();
    return 0;
    int p =8;
    int *ptr = &p;
    cout<<sizeof(ptr);
    

   int digit = 12%10;

   cout<<digit;

   return 0;
}


*/

// lower_bound and upper_bound in vector
 
#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector
 
using namespace std;
 
int main()
{
    int gfg[] = { 1, 1000000009 };
 
    vector<int> v(gfg, gfg + 2); // 5 6 7 7 6 5 5 6
 
    sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7
 
    vector<int>::iterator lower, upper;
    lower = lower_bound(v.begin(), v.end(), 6);
    upper = upper_bound(v.begin(), v.end(), 6);
 
    cout << "lower_bound for 6 at position "
         << (lower - v.begin() + 1) << '\n';
    cout << "upper_bound for 6 at position "
         << (upper - v.begin() + 1) << '\n';
 
    return 0;
}

