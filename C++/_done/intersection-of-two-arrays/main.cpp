#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
    int MAXX = 10005;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int a[MAXX];
        for(int i = 0 ; i < MAXX; i ++){
            a[i] = 0;
        }
        for(int i = 0 ; i < nums1.size(); i ++){
            a[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++){
            if(a[nums2[i]] == 1){
                a[nums2[i]] = 2;
            }
        }
        vector<int> res;
        for(int i = 0 ; i< MAXX; i ++){
            if(a[i] == 2)
            res.push_back(i);
        }
        return res;
    }
};

int main()
{
    cout << "Hello world";
}