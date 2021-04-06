#include <iostream>
#include<algorithm>

using namespace std;

class Rectangle
{
private:

    //Coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    //dimensions
    int width_;
    int height_;

public:
    Rectangle() : leftX_(0), bottomY_(0), width_(0), height_(0) {}

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX), bottomY_(bottomY), width_(width), height_(height_) {}

    int getLeftX() const
    {
        return leftX_;
    }

    int getBottomY() const
    {
        return bottomY_;
    }

    int getWidth() const
    {
        return width_;
    }

    int getHeight() const
    {
        return height_;
    }


    bool operator==(const Rectangle& other) const
    {
        return leftX_ == other.leftX_ && bottomY_ == other.bottomY_ &&
            width_ == other.width_ && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};


class XOverlap
{
private:
    int startPoint_;
    int width_;

public:
    XOverlap() : startPoint_(0), width_(0) {}

    XOverlap( int startPoint, int width ) : startPoint_( startPoint ), width_( width ) {}

    int getstartPoint() const
    {
        return startPoint_;
    }

    int getWidth() const
    {
        return width_;
    }

    bool OverlapExists() const
    {
        return width_ > 0;
    }

    bool operator==( const XOverlap& other ) const
    {
        return startPoint_ == other.startPoint_ && width_ == other.width_ ;
    }

    bool operator!=(const XOverlap& other) const
    {
        return !( *this  == other );
    }

    XOverlap findXOverlap( int x1, int width1, int x2, int  width2 )
    {
        int highestStartPoint = max( x1, x2 );
        int lowestEndPoint = min( (x1 + width1), (x2 + width2) );

        if (highestStartPoint >= lowestEndPoint)
            return XOverlap();

        int overlapWidth = lowestEndPoint - highestStartPoint;

        return XOverlap( highestStartPoint, overlapWidth );
    }
};


class YOverlap
{
private:
    int startPoint_;
    int height_;

public:
    YOverlap() : startPoint_(0), height_(0) {}

    YOverlap(int startPoint, int height) : startPoint_(startPoint), height_(height) { }

    bool OverlapExists() const
    {
        return height_ > 0;
    }

    bool operator==(const YOverlap& other) const
    {
        return startPoint_ == other.startPoint_ &&
            height_ == other.height_;
    }

    bool operator!=(const YOverlap& other) const
    {
        return !(*this == other);
    }

    YOverlap findYOverlap(int y1, int height1, int y2, int height2)
    {
        int highestStartPoint = max(y1, y2);
        int lowestEndPoint = min((y1 + height1), (y2 + height2));

        if (highestStartPoint > lowestEndPoint)
            return YOverlap();

        int overlapWidth = lowestEndPoint - highestStartPoint;

        return YOverlap(highestStartPoint, overlapWidth);

    }
};

    //We can combine both of the above classes into one RangeOverlap Function
    //and calculate XOverlap and YOverlap

class RangeOverlap
{
private:
    int startPoint_;
    int length_;

public:
    RangeOverlap() : startPoint_(0), length_(0) {}

    RangeOverlap(int startPoint, int length) : startPoint_(startPoint), length_(length) {}

    int getstartPoint() const
    {
        return startPoint_;
    }

    int getLength() const
    {
        return length_;
    }

    bool OverlapExists()
    {
        return length_ > 0;
    }

    bool operator==(const RangeOverlap& other) const
    {
        return startPoint_ == other.startPoint_ && length_ == other.length_;
    }

    bool operator!=(const RangeOverlap& other) const
    {
        return !(*this == other);
    }

    RangeOverlap findRangeOverlap(int point1, int length1, int point2, int length2)
    {
        int highestStartPoint = max(point1, point2);
        int lowestEndPoint = min((point1 + length1), (point2 + length2));

        if (highestStartPoint > lowestEndPoint)
            return RangeOverlap();

        int overlapWidth = lowestEndPoint - highestStartPoint;
        return RangeOverlap(highestStartPoint, overlapWidth);
    }

    Rectangle findRectangularOverlap(const Rectangle& rect1, const Rectangle& rect2)
    {
        RangeOverlap XOverlap = findRangeOverlap(rect1.getLeftX(), rect1.getWidth(),
            rect2.getLeftX(), rect2.getWidth());

        RangeOverlap YOverlap = findRangeOverlap(rect1.getBottomY(), rect1.getHeight(),
            rect2.getBottomY(), rect2.getWidth());

        if (!XOverlap.OverlapExists() && !YOverlap.OverlapExists())
            return Rectangle();

        return Rectangle(
            XOverlap.getstartPoint(),
            YOverlap.getstartPoint(),
            XOverlap.getLength(),
            YOverlap.getLength()
        );

    }
};

