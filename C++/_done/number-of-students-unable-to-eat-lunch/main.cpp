#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int count = 0;
        while(students.size() > 0 && count < students.size()){
            if(students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                count = 0;
            }else{
                int first = students[0];
                students.erase(students.begin());
                students.push_back(first);
                count ++;
            }
        }
        return students.size();
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}