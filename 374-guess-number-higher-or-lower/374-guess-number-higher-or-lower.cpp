/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end  = n;
        int ans;
        
        while(start<=end){
           int mid =end - ((end-start)/2);
           int pick = guess(mid);
            
            if(pick == 1){
                start = mid+1;
            }
            else if(pick == -1){
                end = mid-1;
            }
           else if(pick ==0){
               return mid;
            }   
        }
        return -1;      
    }
};

// class Solution {
// public:
//     int guessNumber(int n) {
//         int l=1;
//         int r=n;
//         while(l<=n){
//             int mid=r-((r-l)/2);
//             int num=guess(mid);
//             if(num==0) return mid;
//             else if(num==-1) r=mid-1;
//             else l=mid+1;
//         }
//         return -1;
   
//     }
// };