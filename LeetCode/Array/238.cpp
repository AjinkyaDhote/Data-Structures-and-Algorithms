// Product of Array Except Self
#include "Helper.h"

vector<int> productExceptSelf( vector<int>& nums )
{
    int result = nums[0];
    vector<int> numbers;
    bool hasZero = false;
#if define OLD_IMPLEMENTATION // This was using the Division method.
    for ( int i = 1; i < nums.size(); ++i )
    {
        if ( nums[i] == 0 )
        {
            if ( hasZero )
            {
                result = 0;
                break;
            }
            hasZero = true;
            continue;
        }

        result *= nums[i];
    }

   for ( int i = 0; i < nums.size(); ++i )
   {
       if ( result == 0 )
       {
           numbers.push_back( 0 );
           continue;
       }
       if ( hasZero )
       {
           if ( nums[i] == 0 )
               numbers.push_back( result );
           else
               numbers.push_back( 0 );
           continue;
       }

       numbers.push_back( result / nums[i] );
   }
#elif NEW_IMPLEMENTATION //Without division and in O(n)

    int size = nums.size();
    vector<int> left(size), right(size);

    left[0] = 1;

    for ( int i = 1; i < nums.size(); ++i )
    {
        left[i] = nums[i - 1] * left[i - 1];
    }

    right[nums.size() - 1] = 1;
    for ( int i = nums.size() - 2; i >= 0; i-- )
    {
        right[i] = nums[i + 1] * right[i + 1];
    }

    //Fill the Return array
    for ( int i = 0; i < nums.size(); ++i )
    {
        numbers.push_back( left[i] * right[i] );
    }

#endif
    return numbers;
}

int main()
{
    vector <int> nums = { 1,0 };
    productExceptSelf( nums );

    return 0;
}