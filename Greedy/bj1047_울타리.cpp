#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int space[1000001][1000001] = {0,};

void setAxis(int x, int y, int &xMax, int &yMax, int &xMin, int &yMin)
{
    xMax = max(x,xMax);
    yMax = max(y,yMax);
    xMin = min(x, xMin);
    yMin = min(y, yMin);
}

int main() {
    int n;  // number of tree;
    int x, y, p;
    int xMax = 0;
    int yMax = 0;
    int xMin = 1000001;
    int yMin = 1000001;

    cin >> n;

    while (n--)
    {
        cin >> x >> y >> p;
        // 1. 최대 좌표와 최소 좌표를 구하기.
        setAxis(x, y, xMax, yMax, xMin, yMin);

        // 2. 경우의 수 나누기
        //  a. 직사각형 경계선의 나무를 벌목하는 경우
        //  b. 직사각형 내부의 나무를 벌목하는 경우
        //  c. 직사각형 경계선과 내부의 나무를 둘다 벌목하는 경우
            
        // 만들 수 있는 나무의 개수가 큰 나무를 집중하는게 먼저인가?
        // 아니면  최대 or 최소 좌표를 없애는게 먼저인가? 
    }
    cout << xMax << yMax << xMin << yMin << endl ;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(){
// 	int n;
// 	cin >> n;

// 	int res = n;

// 	vector<int> x(n), y(n), nfence(n), xsort(x), ysort(x);

// 	for(int i=0; i<n; i++){
// 		cin >> x[i] >> y[i] >> nfence[i];
// 		xsort[i] = x[i];
// 		ysort[i] = y[i];
// 	}

// 	sort(xsort.begin(), xsort.end());
// 	sort(ysort.begin(), ysort.end());

// 	vector<int> in;

// 	for(int a=0; a<n; a++){ for(int b=a; b<n; b++){
// 		for(int c=0; c<n; c++){ for(int d=c; d<n; d++){
// 			int ntree = 0, out_sum =0, in_sum =0;
// 			int need = 2*(xsort[b] - xsort[a] + ysort[d] - ysort[c]);

// 			for(int i=0; i<n; i++){
// 				if(x[i] >= xsort[a] && x[i] <= xsort[b]
// 						&& y[i] >= ysort[c] && y[i] <= ysort[d]){
// 					 ntree ++;
// 					 in.push_back(nfence[i]);
// 					 in_sum += nfence[i];
// 				}
// 				else{
// 					out_sum += nfence[i];
// 				}	
// 			}//i

// 			if(out_sum >= need){
// 				res = min(res, n- ntree);
// 			}
// 			else{
// 				if(out_sum + in_sum >= need){
// 					sort(in.begin(), in.end(), greater<int>());
// 					for(int i=0; i<in.size(); i++){
// 						ntree--;
// 						out_sum += in[i];
// 						if(out_sum >= need){
// 							res = min(res, n- ntree);
// 							break;
// 						}
// 					}
// 				}
// 			}
// 			in.clear();
// 		}}
// 	}}

// 	cout << res << endl;

// 	return 0;
// }