#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int length = s.length();

        if(length < 1)
            return 0;

        int num = 0;
        int CurrentDigit = 0;
        int NextDigit = 0;


        int i= length-1;

        CurrentDigit = CharToNum(s[i--]);
        num += CurrentDigit;
        for(;i>=0; i--)
        {
            NextDigit = CurrentDigit;
            CurrentDigit = CharToNum(s[i]);
            if(CurrentDigit < NextDigit)
                CurrentDigit = -CurrentDigit;
            num += CurrentDigit;
        }
        return num;
    }
private:
    int CharToNum(char ch)
    {
        int num = 0;
        switch(ch)
        {
            case 'I':       num = 1; break;
            case 'V':      num = 5;break;
            case 'X':      num = 10;break;
            case 'L':       num = 50;break;
            case 'C':       num = 100;break;
            case 'D':       num = 500;break;
            case 'M':       num = 1000;break;
            default:    break;
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout<<s.romanToInt("DCXXI")<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
