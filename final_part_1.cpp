#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

struct garbage{
	int x, y, i;
	garbage(){}
	garbage(int x_, int y_, int i_) :x(x_), y(y_), i(i_){}
	bool indist(int x1, int y1, int d){
		if (abs(x1 - x) <= d && abs(y1 - y) <= d) return true;
		else return false;
	}
};
// struct bomb{
// 	int x, y, i;
// 	bomb(int x_, int y_ ,int i_):x(x_), y(y_)， i(i_){}
// };
int main(){
	int T;
	cin >> T;
	for (int i = 0; i<T; i++){
		int d, n;
		cin >> d>>n;
		garbage gbg[20];
		int minx = 1025, miny = 1025, maxx = 0, maxy = 0;
		for (int j = 0; j<n; j++){
			int x, y, i;
			cin >> x >> y >> i;
			gbg[j] = garbage(x, y, i);
			if (x<minx) minx = x;
			if (x>maxx) maxx = x;
			if (y<miny) miny = y;
			if (y>maxy) maxy = y;
		}
		//input all garbage points
		int dminx, dminy, dmaxx, dmaxy;
		dminx = max(0, minx - d);
		dminy = max(0, miny - d);
		dmaxx = min(1024, maxx + d);
		dmaxy = min(1024, maxy + d);
		int ngbg = 0;
		int maxngbg = 0;
		int nbomb = 0;
		for (int i = dminx; i<dmaxx + 1; i++){
			for (int j = dminy; j<dmaxy + 1; j++){
				ngbg = 0;
				for (int k = 0; k<n; k++){
					if (gbg[k].indist(i, j, d)){
						ngbg += gbg[k].i;
					}
				}
				if (ngbg>maxngbg){
					maxngbg = ngbg;
					nbomb = 1;
				}
				else if (ngbg == maxngbg){
					nbomb += 1;
				}
			}
		}
		cout << nbomb << ' ' << maxngbg << endl;
	}
	return 0;
}