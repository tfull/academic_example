#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(int count, int* array){
    double sum = 0;

    for(int i = 0; i < count; i++){
        sum += (double)array[i];
    }

    return sum / (double)count;
}

double variance(int count, int* array){
    double x_mean = mean(count, array);
    double sum = 0;

    for(int i = 0; i < count; i++){
        double x_diff = (double)array[i] - x_mean;
        sum += x_diff * x_diff;
    }

    return sum / (double)count;
}

double standardDeviation(int count, int* array){
    return sqrt(variance(count, array));
}

int main(void){
    const int max_count = 1000;
    int count = 0;
    int* array;

    array = (int*)calloc(max_count, sizeof(int));

    while(1){
        int value;
        int result = scanf("%d", &value);
        if(result == EOF){
            break;
        }
        array[count] = value;
        count += 1;
    }

    printf("mean: %.2lf\n", mean(count, array));
    printf("variance: %.2lf\n", variance(count, array));
    printf("standard deviation: %.2lf\n", standardDeviation(count, array));

    return 0;
}
