/*
Valid Perfect Square
Description: Given a positive integer num, return true if num is a perfect square or false otherwise.
             A perfect square is an integer that is the square of an integer.
*/

#include <iostream>

class Solution
{
public:
/*
The first solution has time limit problem
mid should be long type
*/
    bool isPerfectSquare(int num) {
        if(num == 1)    return true;
        int l = 1, r = num, mid = 0; // hier the boundary is important
        while(l < r)
        {
            mid = l + (r - l)/2;
            if (mid > 46340) mid = 46340; 
            if((mid*mid) == num)  return true;
            else if(mid*mid > num)  r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }

    bool isPerfectSquare1(int num) {
    if(num == 1) return true;
    int l = 1, r = num;
    while(l <= r) {
        long mid = l + (r - l) / 2; // using long to avoid overflow
        long squared = mid * mid;
        if(squared == num) return true;
        else if(squared > num) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
};