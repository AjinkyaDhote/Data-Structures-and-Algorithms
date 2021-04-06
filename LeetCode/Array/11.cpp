//Container with most water

#include "Helper.h"


int maxArea( vector<int>& height )
{
    int maxArea = INT_MIN;
#if define OLD_IMPLEMENTATION //BruteForce //Times out //Time:O(n^2) //Space:O(1)
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                maxArea = max( maxArea, min( height[i], height[j] ) * (j - i));
                
            }
        }
        return maxArea;

#elif NEW_IMPLEMENTATION //Time:O(n), Runtime : 40ms, Space:17.8MB
        
    int i = 0;
    int j = height.size() - 1;

    while ( i != j )
    {
        maxArea = max( maxArea, min( height[i], height[j] ) * (j - i) );
        height[i] >= height[j] ? j-- : i++;
    }

    return maxArea;
#endif

}