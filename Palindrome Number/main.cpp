#include <iostream>


/*
    判断是否回文数
*/

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        bool ans = false;
        int temp = x;
        int sum = 0;

        while(0 != temp)
        {
            sum *= 10;
            sum += (temp%10);
            temp /= 10;
        }
        if(sum == x)
            ans = true;

        return ans;
    }
};

int main()
{
    //cout << "Hello world!" << endl;
    Solution s;
    cout<<s.isPalindrome(123)<<endl;
    return 0;
}
