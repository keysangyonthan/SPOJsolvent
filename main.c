#include <stdio.h>

int main() {
    int x, y;
    char op;
    printf("Enter the 1st number");
    scanf("&d", x);
    printf("Enter the 2st number");
    scanf("&d", y);
    printf("Enter the operator")
    scanf("%c", op);
    calculator(x,y,op);

    return 0;
}
