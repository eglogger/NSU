#include <stdio.h>
#include <malloc.h>

void swap(int *a, int *b) {

  int t = *a;

  *a = *b;
  *b = t;
}

void quickSort(int array[], int low, int high) {

    if (low > high)
        return;

    int pivot = array[(low + high) / 2];
    int i = low;
    int j = high;

    while (i <= j) {

        while(array[i] < pivot)
            i++;
        
        while(array[j] > pivot) 
            j--;

        if (i <= j) {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }

    quickSort(array, low, j);
    quickSort(array, i, high);
}

int main() {

    int len;
    int *data = malloc(len * sizeof(int));

    scanf_s("%d", &len);

    for (int i = 0; i < len; i++)
        scanf_s("%d", &data[i]);

    quickSort(data, 0, len - 1);

    for (int i = 0; i < len; i++)
        printf("%d  ", data[i]);

    return 0;
}
