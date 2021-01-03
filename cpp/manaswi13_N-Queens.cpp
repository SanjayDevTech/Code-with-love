#include<iostream>
using namespace std;

int counter = 0;

bool isQueenSafe(bool arr[][100], int size, int tq, int row, int col){
	int array[8][2] = {
		{1,0},
		{1,-1},
		{0,-1},
		{-1,-1},
		{-1,0},
		{-1,1},
		{0,1},
		{1,1}
	};
	for(int i=0;i<8;i++){
		for(int dist = 1;true;dist++){
			int rdash = row + dist*array[i][0];
			int cdash = col + dist*array[i][1];
			if(rdash < 0 || cdash < 0 || rdash >= tq || cdash >= tq){
				break;
			}
			if(arr[rdash][cdash] == 1){
				return false;
			}
		}
	}
	return true;
}

bool isBoardValid(bool arr[][100], int size, int tq){
	for(int i=0;i<size;i++){
		int row = i/tq;
		int col = i%tq;
		if(arr[row][col] == 1){
			if(isQueenSafe(arr, size, tq, row, col) == false){
				return false;
			}
		}
	}
	return true;
}


void all_combinations(bool arr[][100], int size, int qpsf, int tq, int lqp){
	
	if(qpsf == tq){
		counter++;
		if(isBoardValid(arr, size, tq)){
			for(int i=0;i<size;i++){
				int row = i/tq;
				int col=i%tq;
				if(arr[row][col] == 1){
					cout<<row<<" "<<col<<" ";
				}
			}
			cout<<counter;
			cout<<endl;
		}
		
	}

	for(int i=lqp+1;i<size;i++){
		int row = i/tq;
		int col = i%tq;
		if(arr[row][col] == 0){
			arr[row][col] = 1;
			all_combinations(arr, size, qpsf+1, tq, i);
			arr[row][col] = 0;	
		}
		
	}
}

int main()
{
	 int n=4;
	 // cin>>n;
	 bool arr[n][100];
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<100;j++){
	 		arr[i][j] = 0;
	 	}
	 }
	 all_combinations(arr, n*n, 0, n, -1); 
	 cout<<endl<<counter;
	return 0;
}
