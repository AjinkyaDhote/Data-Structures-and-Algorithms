//Running Sum of 1d Array

#include "helper.h"

using namespace std; //Using only for solutions

vector<int> runningSum( vector<int>& nums ) 
{
#if define OLD_IMPLEMENTATION //Runtime 4 ms
    
        vector<int> newVec;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            newVec.push_back(sum + nums[i]);
            sum = nums[i] + sum;
        }
    
#elif NEW_IMPLEMENTATION //Runtime 0 ms

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = nums[i] + sum;
        nums[i] = sum;
    }

    return nums;

#endif
}
