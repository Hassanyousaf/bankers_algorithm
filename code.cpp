#include <iostream>
using namespace std;
int main()
{
int n, m, i, j, k;
n = 5; 
m = 3; 
int alloc[5][3]; 
cout <<"\n===================ALLOCATION===================" << endl;
 for(int i=0;i<5;i++)
 {cout<<"Enter allocated resources for process :"<<i+1<<endl;
  for(int j=0;j<3;j++)
  {
  cin>>alloc[i][j];
  }cout<<endl;
}
cout <<"\n===================MAX TABLE===================" << endl;
int max[5][3];
 for(int i=0;i<5;i++)
 {cout<<"\nEnter MAX resources for process :"<<i+1<<endl;
  for(int j=0;j<3;j++)
  {
  cin>>max[i][j];
  }cout<<endl;
}
cout <<"\n===============AVAILABALE RESOURCES===============" << endl;
int avail[3];
cout<<"\nEnter availabale resources"<<endl;
for(int i=0;i<3;i++)
cin>>avail[i];

int need[n][m];
for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++)
	need[i][j] = max[i][j] - alloc[i][j];
}

system("cls");


int finish[n], ans[n], ind = 0;
for (k = 0; k < n; k++) {
	finish[k] = 0;
}
cout<<"Allocated Resource Table"<<endl;
cout<<"\nA	B	C"<<endl;
  for(int i=0;i<5;i++)
  {
  for(int j=0;j<3;j++){
  cout<<alloc[i][j];
  cout<<"\t";}
    cout << endl;}
    cout<<"\nMAX Resource Table"<<endl;
cout<<"\nA	B	C"<<endl;
  for(int i=0;i<5;i++)
  {
  for(int j=0;j<3;j++){
  cout<<alloc[i][j]; 
  cout<<"\t";}
    cout << endl;}
    cout<<"\nNeed Table"<<endl;
cout<<"\nA	B	C"<<endl;
for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++){
    cout<<need[i][j];
    cout<<"\t";}
    cout<<endl;
}
    cout<<"\nAvailable Resource Table"<<endl;
cout<<"\nA	B	C"<<endl;
	for(int i=0;i<3;i++){
    cout<<avail[i];
    cout<<"\t";}
    cout<<endl;
    

int y = 0;
for (k = 0; k < 5; k++) {
	for (i = 0; i < n; i++) {
	if (finish[i] == 0) {

		int flag = 0;
		for (j = 0; j < m; j++) {
		if (need[i][j] > avail[j]){
			flag = 1;
			break;
		}
		}

		if (flag == 0) {
		ans[ind++] = i;
		for (y = 0; y < m; y++)
			avail[y] += alloc[i][y];
		finish[i] = 1;
		}
	}
	}
}

int flag = 1;
for(int i = 0;i<n;i++)
{
		if(finish[i]==0)
	{
		flag = 0;
		cout << "\nThe given sequence is not safe";
		break;
	}
}

if(flag==1)
{
	cout << "\nFollowing is the SAFE Sequence" << endl;
	for (i = 0; i < n - 1; i++)
		cout << "P" << ans[i] << " ->";
	cout << " P" << ans[n - 1] <<endl;
}

	return 0;
}
