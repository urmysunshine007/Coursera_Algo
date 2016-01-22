#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int N, S;
	cin >> N >> S;
	long cost = 0;
	int c[10000], y[10000];
	cin >> c[0]>>y[0];
	cost += c[0] * y[0];
	for (int i = 1; i<N; i++){
		cin >> c[i] >> y[i];
		if (c[i] - c[i - 1]>S){
			c[i] = c[i - 1] + S;
		}
		cost += c[i] * y[i];
	}
	cout << cost;
}