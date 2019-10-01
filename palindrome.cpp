#include <iostream>
#include <string>
using namespace std;

void changeExistingPalindrome(string &s)
{
    int h,l;
    int sLength = s.length();
    if( sLength == 1 && s[0]-48 >= 0 && s[0] - 48 <= 8)
    {

            s[0] = s[0] + 1;
        return;
    }


    int flag = 1;
    for(int i = 0; i < sLength; i ++)
    {
        if(s[i] != '9')
        {
            flag = 0;
        }
    }

    if(flag == 1)
    {
        char *c = new char[sLength + 2];
        for(int i = 0; i <= sLength + 1; i++)
        {
            if(i == 0 || i == sLength)
            {
                c[i] = '1';
            }
            else if(i == sLength+1)
            {
                c[i] = '\0';
            }
            else
            {
                c[i] = '0';
            }

        }
        s = c;
        return;
    }


    int mid = sLength/2;

    h = mid;
    l = mid - 1;
    if(sLength %2 == 0)
    {
        s[h] += 1;
        s[l] = s[h];
    }
    else
    {
        l = h;
        s[mid] +=  1;
    }

    while(1)
    {
        if(sLength%2 == 0 && s[h] == 58 && l>=0 )
        {
            s[h] = '0';
            s[l] = '0';
            h ++;
            l --;
            s[l] += 1;
            s[h] += 1;
        }
        else if(sLength%2 != 0 && s[h] == 58 && l>0)
        {
            s[h] = '0';
            s[l] = '0';
            h++;
            l--;
            s[l] += 1;
            s[h] += 1;
        }
        else
            break;
    }
}

void createPalindrom(string &s)
{
    int h,l;

    int sLength = s.length();


    int mid = sLength/2;
    if(sLength %2 == 0)
    {
        h = mid;
        l = mid - 1;

        int a = mid - 1;
        int b = mid ;
        for(;a>=0; a--,b++)
        {
            if(s[b]>s[a])
            {
                s[mid-1]+=1;
                //s[a]+=1;
                s[b] = s[a];
                break;
            }
            if(s[b]<s[a])
            {
                s[b] = s[a];
                break;
            }
        }

        //while(1)
        //{
          //  if(s[h] > s[l])
            //{
              //  s[l] += 1;
                //s[h] = s[l];
                //h++;
                //l--;
                //break;
            //}
           // if (s[h] < s[l])
            //{
              //  s[h] = s[l];
               // h++;
               // l--;
               // break;
            //}
            //if (s[l] == s[h] && s[l] != '9')
            //{
              //  h++;
                //l--;
//            }
 //           if (s[l] == s[h] && s[l] == '9')
   //         {
     //           s[l]+=1;
       //         s[h]+=1;
         //       break;
           // }
      //  }
    }
    else
    {
        h = mid ;
        l = mid ;

        int a = mid - 1;
        int b = mid + 1;
        for(;a>=0; a--,b++)
        {
            if(s[b]>s[a])
            {
                s[mid]+=1;
                break;
            }
            if(s[b]<s[a])
            {
                break;
            }
        }

        //if(s[mid +1] >= s[mid-1])
        //{
        //    s[mid] += 1;
        //}


    }

    while(1)
    {
        if(sLength%2 == 0 && s[l] == 58 && l>=0 )
        {
            s[h] = '0';
            s[l] = '0';
            h ++;
            l --;
            s[l] += 1;
            s[h] = s[l];
        }
        else if(sLength%2 != 0 && s[h] == 58 && l>0)
        {
            s[h] = '0';
            s[l] = '0';
            h++;
            l--;
            s[l] += 1;
            s[h] = s[l];
        }
        else {
            break;
        }
    }

    for(;l>=0;l--,h++) {
    	s[h] = s[l];
    }

}

int checkPalindrom(string &s)
{
    int i, length;
    int flag = 1;
    length = s.length();

    for(i=0;i < length ;i++)
    {
        if(s[i] != s[length-i-1])
        {
            flag = 0;
            return flag;

        }
    }
    return flag;
}


int main()
{
    int cases;
    cin >> cases;
    string s[cases];
    for(int i = 0; i < cases; i++)
        cin >> s[i];

    for(int i = 0; i < cases; i++)
    {
    	s[i].erase(0, s[i].find_first_not_of('0'));
        if(checkPalindrom(s[i]))
        {
            changeExistingPalindrome(s[i]);
            cout << s[i] << endl;
        }
        else
        {
            createPalindrom(s[i]);
            cout << s[i] << endl;
        }
    }

}


