//Contains Duplicate
#include "Helper.h"

bool containsDuplicate( vector<int>& nums )
{
    //BruteForce // Time Limit exceeded
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             for(int j = i + 1; j < nums.size(); ++j)
//             {
//                 if(nums[i] == nums[j])
//                     return true;
//             }
//         }

//         return false;

    map<int, int> visited;
    for ( int i = 0; i < nums.size(); ++i )
    {
        if ( visited.find( nums[i] ) != visited.end() )
        {
            return true;
        }
        visited[nums[i]] = i;
    }

    return false;
}
