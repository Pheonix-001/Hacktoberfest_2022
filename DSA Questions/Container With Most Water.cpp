/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0;
        int i=0,j=h.size()-1;
        while(i<j){
            ans=max(ans,min(h[i],h[j])*(j-i));
            if(h[i]>h[j]) j--;
            else i++;
        }
        return ans;
    }
};
