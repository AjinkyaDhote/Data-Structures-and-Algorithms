#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class TempTracker
{
private:

    int maxTemp_;
    int minTemp_;
    double mean_;
    int mode_;

    //utility vars
    int tempCount_;
    double totalSum_;

public:

    TempTracker() : maxTemp_(-1), minTemp_(-1), mean_(0), mode_(0), tempCount_(0), totalSum_(0) {}


    void insert( int temp )
    {
        minTemp_ = min(minTemp_, temp);
        maxTemp_ = max(maxTemp_, temp);

        tempCount_++;

        //mean
        totalSum_ += temp;
        mean_ = totalSum_ / tempCount_;




    }

    int getMax()
    {
        return maxTemp_;
    }

    int getMin()
    {
        return minTemp_;
    }

    double getMean()
    {
        return mean_;
    }

    int getMode()
    {

    }
};