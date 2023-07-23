#include <iostream>

using namespace std;

int main(){
    int n, square, k, i, j;
    cout<<"ENTER NO. OF ROWS/ COLUMNS: ";
    cin>>n;
    square=n*n;
    int row,column;
    i=0;
    j=n/2;
    int A[5][5];
    A[i][j]=1;
    
    
    for(k=2; k<=square; k++)
    {
        if ((k-1)%n==0){
            i = i + 1;
            A[i][j] = k;
            // cout<<i<<"\t"<<j<<"\t"<<k<<endl;
           continue;
        }
        
        if(i-1<0)
        {
            i=n-1; 
            j=j+1;
            
        }
        else if(j+1>=n)
        {
            j=0;
            i=i-1;
            
        }
        else
        {
            j=j+1;
            i=i-1;
        }
        // cout<<i<<"\t"<<j<<"\t"<<k<<endl;
        A[i][j]=k;
    }


    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
