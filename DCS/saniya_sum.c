// saniyas code
#include <stdio.h>
#include <omp.h>
int main() {
    int N, i, total = 0;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int a[N];
    printf("Enter %d elements:\n", N);
    for(i=0;i<N;i++) scanf("%d",&a[i]);

    int t;
    printf("Enter number of threads: ");
    scanf("%d",&t);
     #pragma omp parallel num_threads(t)
    {
        int id = omp_get_thread_num();
        int nT = omp_get_num_threads();
        int start = id*(N/nT);
        int end = (id==nT-1)? N : start + (N/nT);
        int sum = 0;

        for(i=start;i<end;i++) sum += a[i];
        printf("Thread %d -> sum=%d\n",id,sum);

        #pragma omp atomic
        total += sum;
    }

    printf("Total = %d\n", total);
    return 0;
}

//installation

// https://github.com/niXman/mingw-builds-binaries/releases
// posix-seh-urct 

// C:\mingw64\bin --> add this path in environment variables

// Inside VS Code terminal (press Ctrl + ~), type:
// gcc -fopenmp ass3.c -o sum.exe
// ✅ This compiles the program with OpenMP support.
// Then run it:
// .\sum.exe




// chatgpt modified code

// #include <stdio.h>
// #include <omp.h>

// int main() {
//     int n;
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int arr[n];
//     printf("Enter %d elements:\n", n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);

//     int num_threads;
//     printf("Enter number of threads: ");
//     scanf("%d", &num_threads);

//     omp_set_num_threads(num_threads);
//     int total = 0;

//     #pragma omp parallel reduction(+:total)
//     {
//         int id = omp_get_thread_num();
//         int local_sum = 0;

//         int start = id * (n / num_threads);
//         int end;

//         // Simple if-else instead of ternary operator
//         if (id == num_threads - 1)
//             end = n;     // last thread goes till the end
//         else
//             end = start + (n / num_threads);

//         for (int i = start; i < end; i++) {
//             local_sum += arr[i];
//         }

//         if (end - start == 1)
//             printf("Thread %d -> adding arr[%d] = %d\n", id, start, local_sum);
//         else
//             printf("Thread %d -> adding arr[%d] and arr[%d] = %d\n", id, start, end - 1, local_sum);

//         total += local_sum;
//     }

//     printf("Total = %d\n", total);
//     return 0;
// }



// Inside VS Code terminal (press Ctrl + ~), type:
// gcc -fopenmp ass3.c -o sum.exe
// ✅ This compiles the program with OpenMP support.
// Then run it:
// .\sum.exe