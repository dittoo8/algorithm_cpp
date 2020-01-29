#include <iostream>
#include <stack>
#include <string>
 
using namespace std;
 
int pr(char c)
{
    if(c=='(') return 0;
    else if(c=='+' || c=='-') return 1;
    else if(c=='*' || c=='/') return 2;
}
 
int main()
{
    stack<char> S;
    string str;
    cin>>str;
 
    for(int i=0;i<str.size();i++)
    {
        char c=str.at(i);
        if('A'<=c && c<='Z') cout<<c;
        else if(c=='(') S.push(c);
        else if(c==')')
        {
            while(S.top()!='(')
            {
                cout<<S.top();
                S.pop();
            }
            S.pop();
        }
        else
        {
            while(!S.empty() && pr(S.top())>=pr(c))
            {
                cout<<S.top();
                S.pop();
            }
            S.push(c);
        }
    }
    while(!S.empty())
    {
        cout<<S.top();
        S.pop();
    }
    return 0;
}