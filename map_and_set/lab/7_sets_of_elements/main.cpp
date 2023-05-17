#include <iostream>
#include <set>
#include <vector>

int main()
{
    using namespace std;
    set<int> nSet {}, mSet {};
    vector<int> ordered {}, repeated {};
    int n, m, number;

    cin >> n >> m;

    while(n--)
    {
        cin >> number;
        auto status { nSet.insert(number) };
        if(status.second)
            ordered.push_back(number);
    }

    while(m--)
    {
        cin >> number;
        mSet.insert(number);
    }

    if (nSet.empty() || mSet.empty())
        return 0;

    for (int num : ordered)
    {
        auto it = mSet.find(num);
        if (it != mSet.end())
        {
            repeated.push_back(num);
        }
    }

    for (int& num : repeated)
    {
        cout << num << ' ';
    }
    cout << endl;


    return 0;
}