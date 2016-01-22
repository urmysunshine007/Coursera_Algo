#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAXM (100000+10)

int N, C;

int a[MAXM];

int min(int a, int b){
	if (a > b) return b;
	else return a;
}
bool check(int m){
	int stall = 1;
	for (int i = 1; i<C; i++){
		int dist = 0;
		while (dist<m){
			if (stall == N) return false;
			dist += a[stall] - a[stall - 1];
			stall += 1;
		}
	}
	return true;
}


int main(){
	long l, r, mid;
	cin >> N >>C;
	l = MAXM;
	for (int i = 0; i<N; i++){
		cin >> a[i];
		if (i>0){
			l = min(l, abs(a[i] - a[i - 1]));
		}
	}
	sort(a, a + N);
	r = a[N - 1] - a[0];
	while (l <= r){
		mid = (l + r) / 2;
		if (check(mid)){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << r << endl;
	return 0;
}

