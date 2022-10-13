// In Josephus Surviver problem 'n' no. of people(1,2,3,...,n) sit around in a circle and every 'kth' person is eliminated from the circle and the program finds the last surviver.

#include <iostream>
#include <list>
using namespace std;

int func(list<int> l, int k)
{
    auto it = l.begin();
    while (l.size() > 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            it++;
            if (it == l.end())
            {
                it = l.begin();
            }
        }
        it = l.erase(it);
        if (it == l.end()) // to make sure that the pointer does not point to the end
        {
            it = l.begin();
        }
    }
    return *l.begin();
}

int main()
{
    int n, k;
    cout << "Enter the no. of people and k value: ";
    cin >> n >> k;
    list<int> l;
    for (int i = 0; i < n; i++)
    {
        l.push_back(i);
    }
    int res = func(l, k);
    cout << "The last surviver is: " << res << endl;
    return 0;
}