#include<iostream>

using namespace std;
int N,M,K, hashRow, ans;


int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    std::ios::sync_with_stdio(false);

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> K;
        hashRow = 0;
        ans = 0;
        int data[N][M];
        for(int i =0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> data[i][j];
            }
        }
        int hash[N][M+1];
        for(int i =0; i<N; i++){
            for(int j=0; j<=M; j++){
                hash[i][j] = 0;
            }
        }
        for(int i=0; i<N; i++){
            int zerosCount = 0;
            for(int j=0;j<M;j++){
                if(data[i][j]==0) zerosCount++;   
            }
            if(zerosCount<=K){
                int diff = K - zerosCount;
                if(diff>=0 && (diff)%2==0){
                    bool found = false;
                    for(int i1 =0; i1<hashRow; i1++){
                        for(int j=0; j<M; j++){
                            if(hash[i1][j]!=data[i][j]) break;
                            if(j==M-1){
                                hash[i1][M] +=1;
                                found = true;
                            }
                        }
                    }
                    
                    
                    if(!found){
                        for(int i1 =0; i1<M; i1++){
                         hash[hashRow][i1] = data[i][i1];   
                        }
                        hash[hashRow][M] += 1; 
                        hashRow++;
                    }
                }
            }
        }
        
        
        
        for(int i =0; i<N; i++){
                if(hash[i][M] > ans) ans = hash[i][M];
        }
        
        // Print the answer to standard output(screen).
        cout << "#" << test_case << " " << ans << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}