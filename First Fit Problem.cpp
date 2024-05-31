#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m, total=0,value=0, i, j,k, cnt ;
    cout  << " Enter the Number of Blocks : " ;
    cin >> n ;

    int block[n] ;

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
            if(block[j-1] - table[0][i] >=0 && cnt==0)
            {
                table[j][i] = block[j-1] - table[0][i] ;
                block[j-1] = table[j][i] ;
                cnt++ ;
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
        cout << " No Extended Fragmentation : " ;
}
