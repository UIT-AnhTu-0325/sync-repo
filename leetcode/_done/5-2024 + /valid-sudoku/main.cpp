#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

bool isValidUnit(vector<char> &unit)
{
    if (unit.size() != 9)
        return false;
    bool arr[9] = {false, false, false, false, false, false, false, false, false};
    for (int i = 0; i < unit.size(); i++)
    {
        if (unit[i] != '.')
        {
            int idx = int(unit[i] - '1');
            if (arr[idx] == true)
                return false;
            arr[idx] = true;
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    bool result = true;
    for (int i = 0; i < 9; i++)
    {
        result &= isValidUnit(board[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        vector<char> tmp = vector<char>();
        for (int j = 0; j < 9; j++)
        {
            tmp.push_back(board[j][i]);
        }
        result &= isValidUnit(tmp);
    }
    int flgRow = 3, flgCol = 3, size = 3;

    while (flgRow <= 9)
    {
        vector<char> tmp = vector<char>();
        for (int i = flgRow - size; i < flgRow; i++)
        {
            for (int j = flgCol - size; j < flgCol; j++)
            {
                tmp.push_back(board[i][j]);
            }
        }
        result &= isValidUnit(tmp);
        flgCol += size;
        if(flgCol > 9)
        {
            flgRow += size;
            flgCol = 3;
        }
    }
    return result;
}

// Function to convert a string to a vector of characters
std::vector<char> stringToVector(const std::string& str) {
    std::vector<char> result;
    for (char c : str) {
        if (c != '"' && c != ',' && c != '[' && c != ']') {
            result.push_back(c);
        }
    }
    return result;
}

// Function to convert a string representation to a 2D vector of characters
std::vector<std::vector<char>> stringToVectorVector(const std::string& str) {
    std::vector<std::vector<char>> result;

    // Use stringstream to split the input string into individual vectors
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, ']')) {
        std::vector<char> row = stringToVector(token);
        if (!row.empty()) {
            result.push_back(row);
        }
    }

    return result;
}

int main()
{
    std::string input = "[[\".\",\"2\",\".\",\".\",\".\",\".\",\".\",\".\",\".\"],[\".\",\".\",\".\",\".\",\".\",\".\",\"5\",\".\",\"1\"],[\".\",\".\",\".\",\".\",\".\",\".\",\"8\",\"1\",\"3\"],[\"4\",\".\",\"9\",\".\",\".\",\".\",\".\",\".\",\".\"],[\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\"],[\".\",\".\",\"2\",\".\",\".\",\".\",\".\",\".\",\".\"],[\"7\",\".\",\"6\",\".\",\".\",\".\",\".\",\".\",\".\"],[\"9\",\".\",\".\",\".\",\".\",\"4\",\".\",\".\",\".\"],[\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\",\".\"]]";

    // Convert the string to a 2D vector of characters
    std::vector<std::vector<char>> result = stringToVectorVector(input);
    bool ok = isValidSudoku(result);
    cout << ok;
}