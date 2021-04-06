//Subrectangle Queries


#include <iostream>
#include <vector>
#include "Helper.h"

using namespace std;

class SubrectangleQueries
{
private:
    int _row;
    int _column;

    vector<vector<int>> vec;

public:
    SubrectangleQueries( vector<vector<int>>& rectangle )
    {
        vec = rectangle;
        _row = vec.size();
        //_column = vec[0].size();
    }

    void updateSubrectangle( int row1, int col1, int row2, int col2, int newValue )
    {
        for (int i = row1; i <= row2; ++i) 
        {
            for (int j = col1; j <= col2; ++j) 
            {
                vec[i][j] = newValue;
            }
        }
    }

    int getValue( int row, int col )
    {
        return vec[row][col];
    }
};