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


// find nth root of a number input n and m 

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int low =1 , high = m;
        
        while(low<=high){
            int mid = (low+high)/2;
            long mp = pow(mid,n);
            if(mp==m) return mid;
            else if(mp > m ) high = mid-1;
            else low = mid+1;
        }
        return -1;
        
    }
};