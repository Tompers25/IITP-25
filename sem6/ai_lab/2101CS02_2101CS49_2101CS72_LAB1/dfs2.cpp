#include <bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y)
{
    if (x < 0 || y < 0 || x >= 3 || y >= 3)
    {
        return false;
    }
    return true;
}

vector<pair<int, int>> vp = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool func(set<vector<vector<char>>> &s, vector<vector<char>> &v, vector<vector<char>> &target, int i, int j, int &co)
{

    if (v == target)
    {
        return true;
    }

    if (co == 10000)
    {
        return false;
    }

    bool ans = false;

    for (auto it : vp)
    {
        int dx = it.first + i;
        int dy = it.second + j;

        // vector<vector<char>> tem=v;

        if (isvalid(dx, dy))
        {

            char te = v[i][j], temp = v[dx][dy];

            v[i][j] = temp;
            v[dx][dy] = te;

            if (s.find(v) == s.end())
            {
                co++;

                s.insert(v);
                if (func(s, v, target, dx, dy, co))
                {
                    return true;
                }
            }

            v[i][j] = te;
            v[dx][dy] = temp;
        }
    }

    return false;
}

int main()
{

    set<vector<vector<char>>> s;

    vector<vector<char>> v, target;

    v = {{'3', '2', '1'}, {'4', '5', '6'}, {'8', '7', 'B'}};

    target={{'B','2','1'},{'3','5','6'},{'4','8','7'}};
    
    int i = 2, j = 2;

    s.insert(v);
    int co = 0;

    if (func(s, v, target, i, j, co))
    {
        cout << "The target state can be achived" << endl;
    }
    else
    {
        cout << "The target state cannot be achieved" << endl;
    }

    return 0;
}