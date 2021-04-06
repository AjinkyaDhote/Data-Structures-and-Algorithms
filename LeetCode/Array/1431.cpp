//Kids With the Greatest Number of Candies

#include "helper.h"
#include <algorithm>

using namespace std; //Using only for solutions

vector<bool> kidsWithCandies( vector<int>& candies, int extraCandies )
{

#if define OLD_IMPLEMENTATION //Runtime 4MS
    vector <bool> result;
    int greatest = INT_MIN;
    for (int i = 0; i < candies.size(); ++i)
    {
        if (candies[i] > greatest)
            greatest = candies[i];
    }

    for (int i = 0; i < candies.size(); ++i)
    {
        if ((candies[i] + extraCandies) >= greatest)
            result.push_back( true );
        else
            result.push_back( false );
    }
    return result;
#elif NEW_IMPLEMENTATION //Runtime 0MS
    
    vector <bool> result;
    //Using max_element
    int greatest = *max_element( candies.begin(), candies.end() );

    for (int i = 0; i < candies.size(); ++i)
    {
        result.push_back( (candies[i] + extraCandies) >= greatest );
    }
    return result;

#endif
}