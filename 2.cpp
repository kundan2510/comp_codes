#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>

bool cmp( int a, int b ) 
{
   return a > b;
}

#define MOD 1000000007
#define PI 3.141592654
#define LL long long int

using namespace std;

int main()
{
        int T=1;
        scanf("%d",&T);
        while(T--)
        {
                int l,res=0,count=0;
                stack<int> s;
                char str[1000000];
                cin>>str;
                l=strlen(str);
                int status = 0;
                for(int i=0;i<l;i++)
                {
                        if(str[i]=='<' && status==0)
                        {
                                s.push('<');
                        }
                        else if(str[i]=='<' && s.empty()==false)
                        {
                                count=0;
                                break;
                        }
                        else if(str[i]=='>' && s.empty()==false)
                        {
                                status = 1;
                                s.pop();
                                count = count + 2;
                                if(s.empty()==true)
                                {
                                        res = res + count;
                                        count=0;
                                        status = 0;
                                }
                        }
                        else if(str[i]=='>' && s.empty()==true)
                        {
                                break;
                        }
                }
                if(str[l-1]=='>' && s.empty()==false)
                        count = 0;
                cout<<(res+count)<<endl;
        }
        return 0;
}
