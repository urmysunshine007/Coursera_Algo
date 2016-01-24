#include<iostream>
#include<algorithm>

using namespace std;

int comu(int N_, int M_){
	int M = M_, N = N_;
	if (N<M){
		int temp = N;
		N = M;
		M = temp;
	}
	if (N%M == 0){
		return M;
	}
	return(comu(M, N%M));
}
int main(){
	int M, N;
	while (cin >> M >> N){
		cout << comu(M, N) << endl;
	}
	return 0;
}