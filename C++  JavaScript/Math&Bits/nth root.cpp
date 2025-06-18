// find sqrt of a number
class Solution 
{
public:
    int mySqrt(int x) 
    {
        long num = (x /2 ) + 1;       //same as num = (x/2)+1
        while(num*num > x)
            num = (num + (x/num)) >> 1;     //same as num = (num + (x/num)) / 2
        
        return num;
    }
};