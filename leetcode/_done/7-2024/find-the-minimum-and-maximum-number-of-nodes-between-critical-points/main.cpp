#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// daily-question 2024-07-05
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    vector<pair<int, int>> calc;
    vector<int> build;

    int idx = 0;
    while (head != nullptr) {
      if (calc.size() < 3) {
        calc.push_back({head->val, idx});
      }
      if (calc.size() == 3) {
        if ((calc[0].first < calc[1].first && calc[2].first < calc[1].first) ||
            (calc[0].first > calc[1].first && calc[2].first > calc[1].first)) {
          build.push_back(calc[1].second);
        }
        calc.erase(calc.begin());
      }
      head = head->next;
      idx++;
    }
    vector<int> res;
    if (build.size() <= 1) {
      res.push_back(-1);
      res.push_back(-1);
    } else {
      int size = build.size();
      int minimun = INT32_MAX;
      for (int i = 1; i < size; i++) {
        minimun = min(minimun, build[i] - build[i - 1]);
      }
      res.push_back(minimun);
      res.push_back(build[size - 1] - build[0]);
    }
    return res;
  }
};

ListNode *createListFromVector(const std::vector<int> &vec) {
  if (vec.empty())
    return nullptr;

  ListNode *head = new ListNode(vec[0]);
  ListNode *current = head;

  for (size_t i = 1; i < vec.size(); ++i) {
    current->next = new ListNode(vec[i]);
    current = current->next;
  }

  return head;
}

int main() {
  vector<int> inp = {6, 8, 4, 1, 9, 6, 6, 10, 6};
  Solution *solution = new Solution();
  ListNode *cvInp = createListFromVector(inp);
  solution->nodesBetweenCriticalPoints(cvInp);
  cout << "Hello world";
}