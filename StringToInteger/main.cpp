#include <iostream>

using namespace std;

class Solution{
public:
    int myAtoi(string str)
    {
        int ans = 0;
        if(0 == str.length())
            return 0;

        int i = 0;

        for(; i<str.length(),str[i] == ' '; i ++);
        bool negative = false;
        if(str[i] == '+' )
        {
            negative = false;
            i ++;
        }else if(str[i] == '-')
        {
            negative = true;
            i ++;
        }
        for( ; i<str.length(); i++)
        {
            if(str[i] < '0' || str[i] > '9')
                break;
            ans *= 10;
            int digit = str[i] - '0';
            ans += digit;
        }
        if(negative)
            ans = -ans;
       return ans;
    }
};
int main()
{
    //cout << "Hello world!" << endl;
    Solution s;
    cout<<s.myAtoi("-2147483649")<<endl;
    return 0;
}
