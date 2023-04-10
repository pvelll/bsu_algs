#include "Header.h"
int getnum(int k, int n)
{
    if (k == 1) return n & 1;
    if (n & 1)
        return (1 << k) - 1 - getnum(k - 1, ((1 << k) - 1 - n) >> 1);
    else
        return getnum(k - 1, n >> 1);
}
void answer(int k)
{
    cout << "Number of cells: " << pow(2, k) << endl;
    cout << "Cell numbering after folding: " << endl;
    for (int i = 0; i < (1 << k); i++)
        cout << solution(k, i) + 1 << " ";
}
int solution(int k, int index)
{
    if (k == 0) return 0;
    if (k == 1) return index & 1;
    if (index & 1)
        return (getnum(k - 1, ((1 << k) - 1 - index) >> 1) << 1) + 1;
    else
        return getnum(k - 1, index >> 1) << 1;
}