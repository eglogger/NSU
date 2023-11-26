#include <stdio.h>

void fillSpiral(int n, int arr[n][n]) {
    int num = 1;

    for (int layer = 0; layer < n; layer++) {
        for (int i = 0 + layer; i < n - layer; i++) {
            arr[0 + layer][i] = num;
            num++;
        }
        num--;
        for (int i = 0 + layer; i < n - layer; i++) {
            arr[i][n - 1 - layer] = num;
            num++;
        }
        num--;
        for (int i = n - 1 - layer; i >= 0 + layer; i--) {
            arr[n - 1 - layer][i] = num;
            num++;
        }
        num--;
        for (int i = n - 1 - layer; i >= 1 + layer; i--) {
            arr[i][0 + layer] = num;
            num++;
        }
    }

}

int main() {

    int n;

    scanf("%d", &n);

    int arr[n][n];

    fillSpiral(n, arr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
    }

    return 0;
}