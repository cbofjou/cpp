牛客jou练习3，漂亮数



#include <iostream>
#include <vector>
#define N 100000005
using namespace std;
vector<int> ss;
char flag[N] = { 1, 1 };
int a[N] = { 0 };
void sushu()
{
    for (int i = 2; i <= N; i++)
    {
        if (flag[i] == 0)
        {
            ss.push_back(i);
        }
        for (size_t j = 0; j < ss.size(); j++)
        {
            if (i * ss[j] >= N)
            {
                break;
            }
            flag[i * ss[j]] = 1;
            if (i % ss[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    int count = 0;
    sushu();
    for (size_t i = 0; i < ss.size(); i++)
    {
        for (size_t j = 0; j < ss.size(); j++)
        {
            if (ss[i] * ss[j] >= N)
            {
                break;
            }
            a[ss[i] * ss[j]] = 1;
        }
    }
    int t = 0;
    int l = 0, r = 0;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        for (int i = l; i < min(r, N); i++)
        {
            if (a[i] == 1)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
