#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// zero in subtraction 4-4
string addition(string s1, string s2)
{
    string num1,num2;
    int carry = 0;

    if(s1.length() > s2.length())
    {
        num1 = s1;
        num2 = s2;
    }
    else
    {
        num1 = s2;
        num2 = s1;
    }

    int i,j;

    for(i = num1.length() - 1, j = num2.length() - 1; j >= 0; i--,j--)
    {
        num1[i] += num2[j] + carry - 48 -48;
        carry = num1[i]/10;
        num1[i] = (num1[i]%10) + 48;
    }
    while(carry == 1)
    {
        if(i >= 0)
        {
            num1[i] += 1 - 48;
            carry = num1[i] / 10;
            num1[i] = (num1[i] % 10) + 48;
            i--;
        }
        else if(i == -1)
        {
            char *c = new char[num1.length() + 2];
            for(int j = 0; j < num1.length() + 2; j++)
            {
                if(j == 0)
                {
                    c[j] = '1';
                }
                else if(j == num1.length() + 1)
                {
                    c[j] = '\0';
                }
                else
                {
                    c[j] = num1[j - 1]; 
                }
                
            }
            num1 = c;
            carry = 0;
        }

        
    }

    return num1;
    
}



string multiply(string s1, string s2, int n)
{
    if(s2 == "0" || s1 == "0")
    {
        return "0";
    }        
    
    char c[2];
    c[1] = '\0';
    int i,j;
    string sum = "0";
    string r2;
    int x = n;
    j = n;
    while(n >= 0)
    {   r2.clear();
        int carry = 0;
        for(i = s1.length() - 1 ; i>=0; i--)
        {

            c[0] = ((s1[i] - 48)*(s2[j] - 48) + carry)%10 + 48;
            r2.insert(0, c);
            carry = ((s1[i] - 48)*(s2[j] - 48) + carry)/10;        
        }
        if(carry)
        {
            c[0] = carry + 48;
            r2.insert(0,c);
        }
        for(int k = x; k > n; k--)
        {
            r2.push_back('0');
        }

        sum = addition(r2,sum);
        //cout << sum << endl;
        n--;
        j--;
    }

    return sum;
    
}



string subraction(string s1, string s2)
{

    int borrow = 0;



    int i,j;

    for(i = s1.length() - 1, j = s2.length() - 1; j >= 0; i--,j--)
    {
        if(s1[i] < s2[j])
        {
            s1[i] = s1[i] + 10;
            s1[i] = s1[i] - s2[j] - borrow + 48;
            borrow = 1;
        }
        else
        {
            s1[i] = s1[i] - s2[j] - borrow + 48;
            borrow = 0;
        }
    }
    while(borrow == 1)
    {
        if(s1[i] > 48)
        {
            s1[i] = s1[i] - 1;
            break;
        }
        else
        {
            s1[i] = '9';
            i--;
        }
        
    }

    s1.erase(0, s1.find_first_not_of('0'));

    return s1;
    
}



int main()
{
    int width;
    char op;
    int cases;
    cin >> cases;

    string s[cases];

    for(int i = 0; i < cases; i++)
    {
        cin >> s[i];
    }

    for(int i = 0; i < cases; i++)
    {
        int num1, num2;
        string t(s[i]);
        string result;

        int sLength = t.length();
        int j = 0;
        while(t[j] != '+' && t[j] != '-' && t[j] != '*')
        {
            j++;
        }

        string s1(t, 0, j);
        string s2(t, j+1, sLength - j);
        string s3(t, j,sLength -j);

        stringstream toInterger1(s1);
        toInterger1 >> num1;

        stringstream toInterger2(s2);
        toInterger2 >> num2;

        op = t[j];

        switch (op)
        {
            case '+':
                if(s1.length() > s3.length())
                {
                    width = s1.length();
                }
                else 
                {
                    width = s3.length();
                }

                result = addition(s1,s2);
            
                if(result.length() > width)
                {
                    width = result.length();

                }   

                cout.setf(ios::right, ios::adjustfield);

                cout.fill(' ');
                cout.width(width);
                cout << s1 << endl;
                cout.fill(' ');
                cout.width(width);
                cout << s3 << endl;

                for(int i =0; i < width; i++)
                {
                cout << "-";
                }

                cout.fill(' ');
                cout.width(width);
                cout << endl << result;
                break;

            case '-':
                if(s1.length() > s3.length())
                {
                    width = s1.length();
                }
                else 
                {
                    width = s3.length();
                }

                cout.setf(ios::right, ios::adjustfield);

                cout.fill(' ');
                cout.width(width);
                cout << s1 << endl;
                cout.fill(' ');
                cout.width(width);
                cout << s3 << endl;

                for(int i =0; i < width; i++)
                {
                    cout << "-";
                }

                cout.fill(' ');
                cout.width(width);
                cout << endl << subraction(s1,s2);
                break;
            
            case '*':
                int width1;
                if(s1.length() > s3.length())
                {
                    width = width1 = s1.length();
                }
                else 
                {
                    width = width1 = s3.length();
                }

                string resultF = multiply(s1,s2,s2.length()-1);
            
                if(resultF.length() > width)
                {
                    width = resultF.length();

                }   

                cout.setf(ios::right, ios::adjustfield);

                cout.fill(' ');
                cout.width(width);
                cout << s1 << endl;
                cout.fill(' ');
                cout.width(width);
                cout << s3 << endl;
                
                if(s2.length() != 1)
                {
                char *c =new char[width1 + 1];
                for(int i =0; i <= width1; i++)
                {
                    c[i] = '-';
                    if(i == width1)
                    {
                        c[i] = '\0';
                    }
                }
                cout.width(width);
                cout << c;
                cout << endl;

                int n = 0;
                for(int i = s2.length() - 1; i >= 0; i--,n++)
                {
                    delete c;
                    char temp[2];
                    temp[1] = '\0';
                    temp[0] = s2[i];
                    result = multiply(s1,temp,0);
                    int sizec = result.length()+n+1;
                    c = new char[sizec];
                    int j;


                    j = 0;
                    for(int k = 0; k < result.length();j++, k++)
                    {
                        
                        c[j] = result[k];
                    }
                    while(j < sizec)
                    {
                        if(j == sizec -1)
                        {
                            c[j] = '\0';
                        }
                        else
                        {
                           c[j] = ' ';
                        }
                        j++;
                        
                    }
                    
                    cout.width(width);
                    cout << c;
                    cout << endl;
                }
                }



                for(int i =0; i < width; i++)
                {
                cout << "-";
                }

                cout.fill(' ');
                cout.width(width);
                cout << endl << resultF;
                break;


        }
        cout << endl << endl;



    }







}
