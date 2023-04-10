//#include <iostream>
//#include <stack>
//
//
//void Found(int* nums, int amount);
//
//
//using namespace std;
//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//    int amount{};
//    cout << "Ведите количество символов " << endl;
//    cin >> amount;
//
//    int* nums = new int[amount];
//
//    for (int i = 0; i < amount; i++)
//    {
//        cin >> nums[i];
//    }
//
//    Found(nums, amount);
//    delete[]nums;
//    return 0;
//}
//
//void Found(int* nums, int amount)
//{
//    int len = amount;
//    int mid = len / 2 + 1;
//    cout << mid << endl;
//
//    stack<int>st; // stek для левой части
//    stack<int>st2; // stek для правой части
//
//    // по левой части
//    for (int i = 0; i < mid; i++)
//    {
//        if (st.empty())
//        {
//            st.push(nums[i]); // проверка на первый элемент
//            continue;
//        }
//
//        if (nums[i] < st.top())
//        {
//            st.pop(); // удаляем первый элемент (верх)
//            st.push(nums[i]);
//        }
//    }
//
//    int min_left = st.top();
//    cout << min_left << endl;
//
//    // По правой части
//    for (int i = mid; i < len; i++)
//    {
//        if (st2.empty())
//        {
//            st2.push(nums[i]);
//            continue;
//        }
//
//        if (nums[i] < st2.top())
//        {
//            st2.pop();
//            st2.push(nums[i]);
//        }
//    }
//
//    int min_right = st2.top();
//    cout << min_right << endl;
//}
#include<iostream>
#include<stack>
#include<string> 

using namespace std;

int main()
{
    string s;
    stack<char> b;
    cin >> s;

    for (auto c = s.begin(); c != s.end(); c++)
    {
        if (!b.empty() && ((*c == ')' && b.top() == '(') || (*c == ']' && b.top() == '[') || (*c == '}' && b.top() == '{')))
        {
            b.pop();
        }

        else if (*c == ')'|| *c == ']' || *c == '}')
        {
            cout << "NO";
            return 0;
        }

        else
        {
            b.push(*c);
        }
    }

    b.empty() ? cout << "YES" : cout << "NO";
    return 0;
}