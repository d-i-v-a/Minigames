#include <iostream>
using namespace std;
void default1(int a[5][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            a[i][j]=0;
        }
    }
}
void place(int a[5][5])
{
    int i,j,k;
    for(k=0;k<12;k++)
    {
        cout<<"enter the coordinates: ";
        cin>>i;
        cin>>j;
        a[i][j]=1;
        cout<<"\nShip added\n";
    }
 }
void check(int a[5][5])
{
    int c=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]==2 || a[i][j]==0)
            {
                c=1;
            }
        }
    }
    for(int j=0;j<5;j++)
    {
        for(int i=0;i<5;i++)
        {
            if(a[i][j]==2 || a[i][j]==0)
            {
                c=1;
            }
        }
    }
    if(c==0)
    {
        cout<<"\nyou lose\n";
    }
    else
    {
        cout<<"\nyou win\n";
    }
}
void display(int a[5][5])
{
    cout<<"\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<a[i][j]<<"\t";
            
        }
        cout<<"\n";
    }
}
void shoot(int a[5][5])
{
	int i,j,k;
	for(k=0;k<5;k++)
	{
		cout<<"target your coordinates... the value of i,j"<<endl;
    	cin>>i;
    	cin>>j;
    	if(a[i][j]==1)
    	{
    		cout<< "\nshooting successfully\n";
    		a[i][j]=2;
    	}
    	else if(a[i][j]==2)
    	{
    	    cout<<"\nalready shot there\n";
    	}
    	else
    	{
    		cout<<"\nshoot unsuccessfully\n";
        }
    	   
    }
}

int main()
{
    int a[5][5];
    default1(a);
    place(a);
    display(a);
    shoot(a);
    display(a);
    check(a);
    return 0;
}