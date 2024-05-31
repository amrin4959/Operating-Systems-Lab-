#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m, total=0,value=0, i, j,k, cnt, best=0 ;
    cout  << " Enter the Number of Blocks : " ;
    cin >> n ;

    int block[n] ;
    vector<int> small ;

    cout << "Enter the Block Sizes : " ;
    for(i=0; i<n; i++)
        cin >> block[i] ;

    cout  << " Enter the Number of Memory Requests : " ;
    cin >> m ;

    int table[n+1][m] ;

    cout << "Enter the Requesting Memory Sizes : " ;
    for(i=0; i<m; i++)
        cin >> table[0][i] ;

    for(i=0; i<m; i++)
    {
        cnt = 0 ;
        for(j=1; j<=n; j++)
        {
            if(j==1)
            {
                for(k=1; k<=n; k++)
                {
                    if(block[k-1] - table[0][i] >=0 )
                        small.push_back(block[k-1] - table[0][i]) ;
                }
                best = *min_element(small.begin(),small.end());
                small.clear();
            }

            if(block[j-1] - table[0][i] == best && cnt==0)
            {
                table[j][i] = block[j-1] - table[0][i] ;
                block[j-1] = block[j-1] - table[0][i] ;
                cnt = 1 ;
            }
            else
                table[j][i] = block[j-1] ;
        }
        if(cnt==0)
        {
            value = table[0][i] ;
            break ;
        }
    }

    for(j=0; j<n; j++)
        total = total + block[j] ;

    for(j=0; j<=n; j++)
    {
        for(k=0; k<i; k++)
            cout << table[j][k] << "  " ;

        cout << endl ;
    }
    if(value!=0)
    {
        cout  << endl << "Can't be Allocated for " << value << endl ;
        cout << "Extended Fragmentation : " << total ;
    }
    else
        cout << " No Extended Fragmentation ! " ;
}
