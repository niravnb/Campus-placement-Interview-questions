#include <iostream>
#include <cstdlib>
using namespace std;

int toss(){
	int flip = rand()%2;
	return flip;
}

int random(int n){
    int ret = 0;
    for(int i =0; i<n; i++){
        ret += toss();
    }
	return ret;
}

int main(){
    srand(time(0)); 
    int n;
    cin >> n;
    cout << random(n) << endl;

    return 0;

}
