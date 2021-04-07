//Minimum in a Rotated Sorted Array
#include"Helper.h"

int findMin( vector<int>& nums )
{
#if define OLD_IMPLEMENTATION //Accepted but Time Complexity is O(n) which can be improved. Space Complexity O(1)
    int GLOBAL_MIN = INT_MAX;

    if ( nums.size() == 1 )
        return nums[0];
    else if ( nums.size() == 0 )
        return 0;

    for ( int i = 0; i < nums.size() - 1; ++i )
    {
        if ( nums[i + 1] < nums[i] )
        {
            GLOBAL_MIN = nums[i + 1];
            break;
        }
    }

    if ( GLOBAL_MIN == INT_MAX )
        return nums[0];
    else
        return GLOBAL_MIN;

#elif NEW_IMPLEMENTATION //This can be solved using Binary search as the array is sorted.
    
    if ( nums.size() == 1 )
        return nums[0];

    //Left and Right pointers.
    int left = 0, right = nums.size() - 1;

    //Handling no Rotation
    if ( nums[right] > nums[0] )
        return nums[0];

    //Binary Search
    while ( right >= left )
    {
        int midPoint = left + (right - left) / 2;

        if ( nums[midPoint] > nums[midPoint + 1] )
            return nums[midPoint + 1];
        else if ( nums[midPoint - 1] > nums[midPoint] )
            return nums[midPoint];

        //we go right
        if ( nums[midPoint] > nums[0] )
        {
            left = midPoint + 1;
        }
        //we go left
        else
        {
            right = midPoint - 1;
        }
    }
  
    return -1;

#endif // OLD_IMPLEMENTATION
}