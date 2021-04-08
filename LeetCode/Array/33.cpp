//Search in Rotated Array
#include "Helper.h"





int search( vector<int>& nums, int target )
{
    if ( nums.size() == 0 )
        return -1;
    else if ( nums.size() == 1 && nums[0] == target )
    {
        return 0;
    }

    int left = 0, right = nums.size() - 1;

    while ( right >= left )
    {
        //Find MidPoint
        int mid = left + (right - left) / 2;

        //Return the element
        if ( nums[mid] == target )
            return mid;

        
        else if ( nums[mid] >= nums[left] )
        {
            if ( target >= nums[left] && target < nums[mid] )
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if ( target <= nums[right] && target > nums[mid] )
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;

}

//Note: Easy way to solve this is find where the rotation lies. If mid < left --- mid element is in the right part of the array.
//If mid > right --- mid element is in the left part of the array.
//Otherwise no rotation (Normal binary search). This problem mentions that there is rotation for sure.