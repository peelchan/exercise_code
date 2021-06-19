#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[10000002];
int data[10000002]; 
queue<long long> q1;
queue<long long> q2;

void generateArray(int n, int m, int seed) {
    unsigned x = seed;
    for(int i = 1; i <= n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        arr[i] = x % m + 1;
    }
}

int main()
{

    int n, m, seed;
    cin >> n >> m >> seed;
    //n=10000000, m=10000000, seed=88;
    generateArray(n, m, seed); 
    for(int i = 1; i <= n; i++){
    	data[arr[i]]++;
	}
	int index = 0;
	for(int i = 1; i <= m; i++){
		int k = 0;
		while(k < data[i]){
			//data_sort[index++] = i;
			q1.push(i);
			k++;
		}
	}
	long long x, y; 
	long long ans = q1.front();
	while(q1.size() + q2.size() >= 2){
		if(q2.size() > 0 && q1.size() > 0){
			if(q1.front() < q2.front()){
				x = q1.front();
				q1.pop();
			}
			else{
				x = q2.front();
				q2.pop(); 
			}
		} 
		else{
			if(q2.size() > 0 ){
				x = q2.front();
				q2.pop(); 
			}
			else{
				x = q1.front();
				q1.pop();
			}
		}
		if(q2.size() > 0 && q1.size() > 0){
			if(q1.front() < q2.front()){
				y = q1.front();
				q1.pop();
			}
			else{
				y = q2.front();
				q2.pop(); 
			}
		} 
		else{
			if(q2.size() > 0 ){
				y = q2.front();
				q2.pop(); 
			}
			else{
				y = q1.front();
				q1.pop();
			}
		}
		if(x*2 >= y) {
            ans = max(ans, x*2);
            q2.push(x*2);
        } else {
            ans = max(ans, y);
            q2.push(y);
        }
	}

    cout << ans << endl;

    return 0;
}

