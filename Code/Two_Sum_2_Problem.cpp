class Solution {

public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, h = n-1;                      //Standard binary search low high variables
        int curr;                                //For storing sum of values at low and high indices
        while(l<h){
            curr = numbers[l]+numbers[h];
            if(curr==target) return {l+1,h+1};    //Adding 1 for 1-based indexing
            else if(curr<target) l++;
            else h--;
        }
        return {};                                 //For returning  a vector in all case although this will never be returned                    
    }

};
