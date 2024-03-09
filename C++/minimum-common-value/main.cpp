#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    if(nums1.size() == 0 || nums2.size() == 0)
        return -1;
    int p1 = 0, p2 = 0;
    while(p1 < nums1.size() || p2 < nums2.size()){
        if(nums1[p1] == nums2[p2]){
            return nums1[p1];
        }
        (nums1[p1] < nums2[p2]) ? (p1++) : (p2++);
    }
    return -1;
}

int main()
{
    cout << "Hello world";
}