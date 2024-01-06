#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}
void inputMatrix(double x[N][N]){
	double y=1;
	for(int i=0;i<N;i++){
		cout<<"Row "<<i+1<<": ";
		for(int j=0;j<N;j++){
			cin>>x[i][j];
			y*=x[i][j];
		}
	}
}
void findLocalMax(const double x[N][N],bool z[N][N]){
	int sum=N-1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==0||i==sum||j==0||j==sum){
				z[i][j]=0;
			}else if(x[i][j]>=x[i-1][j]&&x[i][j]>=x[i+1][j]&&x[i][j]>=x[i][j-1]&&x[i][j]>=x[i][j+1]){
				z[i][j]=1;
			}else{
				z[i][j]=0;
			}
		}
	}
}
void showMatrix(const bool z[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<z[i][j]<<" ";
		}
		cout<<"\n";
	}
}