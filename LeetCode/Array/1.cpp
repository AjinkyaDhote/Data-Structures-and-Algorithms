//Two Sum
#include "Helper.h"


vector<int> twoSum( vector<int>& nums, int target )
{
    std::unordered_map<int, int> resultmap;

    for ( int i = 0; i < nums.size(); i++ )
    {
        int diff = target - nums[i];

        if ( resultmap.count( diff ) )
            return  { resultmap[diff], i };
        resultmap[nums[i]] = i;
    }

    return {};
}

