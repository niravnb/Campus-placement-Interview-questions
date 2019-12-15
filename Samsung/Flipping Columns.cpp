// Flipping Columns

int candidateRowCount=0;
void populateHash(int *input, int **hash, int col)
{
    bool found = false;
    for (int i=0; i<candidateRowCount; i++)
    {
        for (int j=0; j<col; j++)
        {
            if(input[j] !=hash[i][j])
                break;
            else
            {
                if (j==(col-1))
                {
                    found = true;
                    hash[i][col] +=1;
                }
            }
        }
    }

    if (!found)
    {   // save current candidate Row  in hash to be used for comparison in else block of above steps of this function 
        for (int i=0; i<col; i++)
        {
            hash[candidateRowCount][i] = input[i];
        }
        hash[candidateRowCount][col] +=1;
        candidateRowCount++;
    }
}

int getMaxCount(int** input, int N , int M, int K)
{
    int **hash= new int *[N];
    // an extra column to save frequency of row i
    for(int i=0; i<M+1; i++)
    {
        hash[i]= new int[M+1];
        hash[i][M] =0;
    }
    for(int i=0; i<N; i++)
        for(int j=0; i<M; j++)
            hash[i][j]=0;

    for(int i=0; i<N; i++)
    {
        int count = 0;
        for (int j=0; j<M; j++)
        {
            if(input[i][j]==0)
                count++;
        }
        if(count<=K)
        {
            int diff= K-count;
            if ((diff >= 0) && ((diff %2)== 0))
            {
                populateHash(input[i], hash, M);
            }
        }
    }

    int maxVal = 0;
    for (int i=0; i<candidateRowCount; i++)
    {
        if(hash[i][M]>maxVal)
            maxVal = hash[i][M];
    }
    return maxVal;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int testcase;
    cin >> testcase;
    for (int t=0; t<testcase; t++)
    {
        int N,M,K;
        cin >> N >>M;
        cin >>K;
        int **input = new int *[N];
        for (int i=0; i<N; i++)
            input[i] = new int [M];
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<M; j++)
            {
                cin >> input[i][j];
            }
        }
        int val= getMaxCount(input, N, M, K);

        cout << "Max Val" <<val << endl;
        candidateRowCount= 0;
    }
    return 0;
}
