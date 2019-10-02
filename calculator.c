void calculator(int x, int y, char op){
    switch(op)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf", x, y, x + y);
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf", x, y, x - y);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf", x, y, x * y);
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf", x, y, x / y);
            break;

        default:
            printf("Error! operator is not correct");
    }
}
