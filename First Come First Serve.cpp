#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, val, temp=0 ;
    vector<pair<int,int>> at2  ;
    double awt=0, att=0 ;

    cout << "Enter the Number of  Process : " ;
    cin >> n ;
    int wt[n], tt[n], et[n], ct[n] ;

    cout << "Enter the CPU Times : " << endl ;
    for(i=0; i<n; i++)
        cin >> ct[i] ;

    cout << "Enter the Arrival Times : " << endl ;
    for(i=0; i<n; i++)
    {
        cin >> val ;
        at2.push_back({val, i});
    }

    sort(at2.begin(), at2.end());

    for(i=0; i<n; i++)
    {
        while(true)
        {
            if(at2[i].first>temp)
                temp++;
            else
                break;
        }
        et[at2[i].second] = temp + ct[at2[i].second] ;
        temp = et[at2[i].second] ;
        tt[at2[i].second] = et[at2[i].second] - at2[i].first ;
        wt[at2[i].second] = tt[at2[i].second] - ct[at2[i].second] ;
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


