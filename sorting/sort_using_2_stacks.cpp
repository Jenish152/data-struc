#include<iostream>
#include<stack>
using namespace std;



void sortt(int a[])
{
    stack<int>st;
    stack<int>p;
    for(int i=0;i<5;i++)
    {
        
       if(st.empty() || a[i]<st.top())
       {
           st.push(a[i]);
       }
       else
       {
         while(!( st.empty() || a[i]<st.top()))
         {
             p.push(st.top());
             st.pop();
             
         }
        st.push(a[i]);
        while(!p.empty())
        {
         st.push(p.top());
         p.pop();
        }
       }
    }
    
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
   
    int arr[5]={1,4,3,6,1};
    sortt(arr);
  
    return 0;
}