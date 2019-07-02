#include <iostream>

using namespace std;
class Solution{
public:
    string conversion(string s,int nRows)
    {
        if(nRows <= 1 )
            return s;
        int i = 0;  //�б�
        int j = 0;  //�ַ���s���±�
        string result = "";

        int step = 2 * (nRows -1);

        for(i=0; i<nRows; i++)
        {
            for(j=i; j<s.length(); j+=step)
            {
                result += s[j];
                if( i == 0 || i == nRows - 1)   //����ǵ�0�к����һ�У�����ȫ���Ϲ���
                    continue;

                //������ǵ�0�к����һ�У�����һ��б���ϵ���
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
