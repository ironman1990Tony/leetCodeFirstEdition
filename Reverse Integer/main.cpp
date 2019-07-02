#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        unsigned int temp = 0;
        if(x < 0)
            temp = (unsigned int)(-x);
		else

			temp = (unsigned int)x;
        
		long ans = 0;
        int digit = 0;
        while(temp != 0)
        {
            ans *= 10;
            digit = temp % 10;
            ans += digit;
            temp /= 10;
        }

        if(ans > 0xFFFFFFFF/2)
            return 0;

        if(x < 0)
            return -(int)ans;
        else
            return (int)ans;
    }
};

int main()
{
    //cout << "Hello world!" << endl;
    Solution s;
    cout<<s.reverse(-2147483648)<<endl;
	cout<<sizeof(long)<<endl;
    return 0;
}
