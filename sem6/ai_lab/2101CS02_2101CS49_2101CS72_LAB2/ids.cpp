#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int inf = LLONG_MAX;

// vector<vector<int>> start = {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};
// vector<vector<int>> target = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

vector<vector<int>> start = {{3, 2, 1}, {4, 5, 6}, {8, 7, 0}};
vector<vector<int>> target = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

set<vector<vector<int>>> st;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inside(int a, int b)
{
    if (a < 0 || b < 0 || a >= 3 || b >= 3)
    {
        return false;
    }
    return true;
}

int upto;
int ans = -1;

void funct(int level, vector<vector<int>> &top, int r, int c)
{
    if (level == upto)
    {
        if (top == target)
        {
            ans = level;
        }

        return;
    }


    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> toch = top;
        int ii = r + dx[i], jj = c + dy[i];
        if (inside(ii, jj))
        {

            swap(toch[ii][jj], toch[r][c]);
        
            if (st.find(toch) == st.end())
            {
                st.insert(toch);
                funct(level + 1, toch, ii, jj);

                st.erase(st.find(toch));
            }
        }
    }
}

int32_t main()
{
    std::ios_base ::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cout << std::fixed << std::setprecision(25);
    ans = -1;
    if (start == target)
    {
        cout << "Reached the destination in 1 steps \n";
    }
    for (int i = 0; i <=27; i++)
    {
        // cout << "for depth " << i << '\n';
        if (ans != -1)
        {
            break;
        }
        upto = i;
        st.clear();
        st.insert(start);
        funct(0, start, 2, 2);
    }
    if (ans == -1)
    {
        cout << "NOT found upto depth of 10000 \n";
    }
    else
    {
        cout << "Target is reached at the " << ans + 1 << " level \n";
    }
    return 0;
}