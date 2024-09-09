#include <stdio.h>
#include <stdlib.h>


int iterative(int n) {
    if (n == 1) return 0;  
    if (n == 2) return 1;  

    int a = 0, b = 1, c;
    for (int i = 3; i <= n; i++) {  
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int recursive(int n) {
    if (n == 1) return 0;  
    if (n == 2) return 1;  
    return recursive(n - 1) + recursive(n - 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <integer> <r|i> <filename>\n", argv[0]);
        return 1;
    }

    int lineNumber = atoi(argv[1]);

    char method = argv[2][0];

    FILE *file = fopen(argv[3], "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", argv[3]);
        return 1;
    }

    int fileNumber;
    fscanf(file, "%d", &fileNumber);
    fclose(file);

    int N = lineNumber + fileNumber;

    int result = (method == 'i') ? iterative(N) : recursive(N);

    printf("%d\n", result);

    return 0;
}
