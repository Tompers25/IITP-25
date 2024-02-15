#include <bits/stdc++.h>
using namespace std;
pair<int, int> find_pair(vector<vector<int>> v)
{

    pair<int, int> ans;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == -1)
            {
                ans.first = i;
                ans.second = j;
            }
        }
    }
    // cout<<ans.first<<" "<<ans.second<<endl;
    return ans;
}

// Define the type of your pair
using Element = pair<int, pair<vector<vector<int>>, int>>;

// Define the comparator function
struct Comparator
{
    bool operator()(const Element &a, const Element &b) const
    {

        return a.first > b.first;
    }
};

int main()
{
    vector<vector<int>> grid = {{3, 2, 1}, {4, 5, 6}, {8, 7, -1}};
    vector<vector<int>> target = {{1, 2, 3}, {4, 5, 6}, {7, 8, -1}};
    // vector<vector<int>> target = {{-1, 2, 1}, {3, 5, 6}, {4, 8, 7}};
    map<vector<vector<int>>, int> visited;
    int r = 3, c = 3;
    // bfs algorithm
    cout << " ---------------->UCS ALGO<------------------------- " << endl;
    // priority_queue<pair<int, pair<vector<vector<int>>, int>>> q;
    priority_queue<Element, vector<Element>, Comparator> q;

    q.push({0, {grid, 1}});
    visited[grid] = 1;
    int steps = -1;

    while (q.size() != 0)
    {

        int level = q.top().first;
        vector<vector<int>> v = q.top().second.first;
        int ans_step = q.top().second.second;
        pair<int, int> p = find_pair(v);
        // cout << p.first << " ==> " << p.second << endl;

        q.pop();

        if (v == target)
        {
            steps = ans_step;
            break;
        }

        // up
        if (p.first - 1 >= 0)
        {

            vector<vector<int>> temp = v;
            swap(temp[p.first][p.second], temp[p.first - 1][p.second]);
            if (visited[temp] == 0)
            {

                visited[temp] = 1;
                q.push({level + 1, {temp, ans_step + 1}});
                grid = temp;
            }
        }

        // down
        if (p.first + 1 <= 2)
        {
            vector<vector<int>> temp = v;
            swap(temp[p.first][p.second], temp[p.first + 1][p.second]);
            if (visited[temp] == 0)
            {
                visited[temp] = 1;
                q.push({level + 1, {temp, ans_step + 1}});
            }
        }

        // if (steps > 0)
        // break;

        // right
        if (p.second + 1 <= 2)
        {
            vector<vector<int>> temp = v;
            swap(temp[p.first][p.second], temp[p.first][p.second + 1]);
            if (visited[temp] == 0)
            {
                visited[temp] = 1;
                q.push({level + 1, {temp, ans_step + 1}});
            }
        }
        // left
        if (p.second - 1 >= 0)
        {

            vector<vector<int>> temp = v;
            swap(temp[p.first][p.second], temp[p.first][p.second - 1]);
            if (visited[temp] == 0)
            {
                // cout<<p.first+1<<" ==> "<<p.second+1<<endl;
                visited[temp] = 1;
                q.push({level + 1, {temp, ans_step + 1}});
            }
        }
    }
    cout << "Found in No of Steps " << steps << endl;
}