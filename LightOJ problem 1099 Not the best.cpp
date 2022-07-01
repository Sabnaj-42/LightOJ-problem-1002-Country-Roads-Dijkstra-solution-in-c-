#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
long long dist[505];
vector<pair<int,int>>graph[505];
void dijkstra(int src)
{
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater< pair<int,int>>>pq;
   for(int i=0;i<505;i++)dist[i]=inf;
   pq.push({0,src});
   while(!pq.empty())
   {
       int curdis=pq.top().first;
       int curnod=pq.top().second;
       pq.pop();
           for(auto child:graph[curnod])
           {
               if(dist[child.first]>max(child.second,curdis))
               {
                   dist[child.first]=max(curdis,child.second);
                   pq.push({dist[child.first],child.first});
               }
           }
   }
}
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;cin>>n;
        int r;cin>>r;
        for(int i=0;i<505;i++)
        graph[i].clear();
        for(int i=0;i<r;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
        int src;cin>>src;
        dijkstra(src);
        printf("Case %d: \n",k);
        for(int i=0;i<n;i++)
           {
               if(i==src)cout<<0<<endl;
               else if(dist[i]==inf)cout<<"Impossible"<<endl;
               else cout<<dist[i]<<endl;
           }




    }
}
