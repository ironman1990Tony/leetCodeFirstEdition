#include <iostream>

using namespace std;
class Solution{
public:
    string conversion(string s,int nRows)
    {
        if(nRows <= 1 )
            return s;
        int i = 0;  //行标
        int j = 0;  //字符串s的下标
        string result = "";

        int step = 2 * (nRows -1);

        for(i=0; i<nRows; i++)
        {
            for(j=i; j<s.length(); j+=step)
            {
                result += s[j];
                if( i == 0 || i == nRows - 1)   //如果是第0行和最后一行，就完全符合规律
                    continue;

                //如果不是第0行和最后一行，则还有一个斜线上的数
                int slash = j + step - 2*i;
                if(slash < s.length())
                    result +=s[slash];
            }
        }
        return result;
    }

};

int main()
{
    Solution s;
    cout<<s.conversion("PAYPALISHIRING",3)<<endl;
    //cout<<"hello"<<endl;
    return 0;
}
