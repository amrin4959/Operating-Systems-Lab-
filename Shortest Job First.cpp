#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, val, temp=0 ;
    vector<pair<int,int>> at2  ;
    double awt=0, att=0 ;

    cout << "Enter the Number of  Process : " ;
    cin >> n ;
    int wt[n], tt[n], et[n], ct[n], at1[n] ;

    vector<int> new_order;

    cout << "Enter the CPU Times : " << endl ;
    for(i=0; i<n; i++)
        cin >> ct[i] ;

    cout << "Enter the Arrival Times : " << endl ;
    for(i=0; i<n; i++)
    {
        cin >> at1[i] ;
        at2.push_back({at1[i], i});
    }

    sort(at2.begin(), at2.end());

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({ct[at2[0].second], at2[0].first, at2[0].second});
    i=1;
    int current_time=0;

    while(!pq.empty())
    {
        int burst_time = pq.top()[0];
        int index = pq.top()[2];
        pq.pop();
        new_order.push_back(index);
        current_time= current_time + burst_time;

        while(true)
        {
            if(i<n && at2[i].first<=current_time)
            {
                pq.push({ct[at2[i].second], at2[i].first, at2[i].second});
                i++;
            }
            else break;
        }
    }

    for(i=0; i<n; i++)
    {
        et[new_order[i]] = temp + ct[new_order[i]] ;
        temp = et[new_order[i]] ;
        tt[new_order[i]] = et[new_order[i]] - at1[new_order[i]] ;
        wt[new_order[i]] = tt[new_order[i]] - ct[new_order[i]] ;
    }

    for(i=0; i<n; i++)
    {
        awt = awt + wt[i] ;
        att = att + tt[i] ;
    }

    for(i=0; i<n; i++)
        cout <<  "Process : " << i+1 << "     Waiting Time : " << wt[i] << "     Turnaround Time : " << tt[i] << endl ;

    printf("\nAverage Waiting Time : %.2lf \n", awt/n );
    printf("Average Turnaround Time : %.2lf \n", att/n );
}
