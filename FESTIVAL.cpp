//https://algospot.com/judge/problem/read/FESTIVAL
//
#include <iostream>

int main()
{
    int i, j, tmp;

    int C;      //number of test case
    
    int N, L;   //inputs
    int arr[1001];

    int sum, min;    //use to calc
    double ave_min, ave_tmp;

    scanf("%d", &C);
    while (C) {
        //getting input
        scanf("%d", &N);
        scanf("%d", &L);

        sum = 0;
        arr[0] = 0;
        for (i = 0; i < N; i++) {
            scanf("%d", &tmp);
            sum += tmp;
            arr[i+1] = sum;
        }

        //calc
        ave_min = 1000;
        for (i = L; i <= N; i++) {// lent for i days

            
            min = 1000 * i;
            for (j = i; j <= N;j++) {
                tmp = arr[j] - arr[j - i];
                if (min > tmp) {
                    min = tmp;
                }
            }
            ave_tmp = (double)min / (double)i;
            if (ave_min > ave_tmp) {
                ave_min = ave_tmp;
            }
        }
        printf("%.11lf\n", ave_min);

        C--;
    }

    return 0;//end
}

