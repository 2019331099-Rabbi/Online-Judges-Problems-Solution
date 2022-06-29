#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>dq;
    int t,n,m,i,j,p,r,c;
    string s;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        c=1;
        cin>>n>>m;
        dq.clear();  //make dequeue empty
        printf("Case %d:\n",i);
        for(j=1;j<=m;j++)
        {
            cin>>s;


            if(dq.size()==n && (s=="pushLeft" || s=="pushRight"))
            {
                cout<<"The queue is full"<<endl;
                j--; //decrease value of j as dequeue is full
            }
            else if(s=="pushLeft" && !(dq.size()==n))
            {
                cin>>p;
                dq.push_front(p);
                printf("Pushed in left: %d\n",p);
            }
            else if(s=="pushRight" && !(dq.size()==n))
            {
                cin>>p;
                dq.push_back(p);
                printf("Pushed in right: %d\n",p);
            }
            else if(s=="popLeft" && !(dq.empty()))
            {

                printf("Popped from left: %d\n",dq.front());
                dq.pop_front();
            }
            else if(s=="popRight" && !dq.empty())
            {
                  printf("Popped from right: %d\n",dq.back());
                  dq.pop_back();
            }
            else if(dq.empty())
            {
                printf("The queue is empty\n");
            }
        }

    }
    return 0;
}
