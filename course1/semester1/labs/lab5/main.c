#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 1000

#define STACK struct node

STACK {
    int data;
    STACK *next;
};

void stackInit(STACK **top) { // Stack initialization.
    *top = NULL;
}

bool isEmpty(STACK *top) { // Checking if stack is empty.
    return (top == NULL) ? true : false;
}

void push(STACK **top, int e) {

    STACK *p = (STACK *)malloc(sizeof(STACK));
    p -> data = e;
    p -> next = *top;
    *top = p;
}

int getTop(STACK *top) {

    return top -> data;
}

int pop(STACK **top) {

    STACK *p = *top;
    int e = p -> data;
    *top = p -> next;
    free(p);

    return e;
}

int priority(char ch) { // Operators priority.

    switch(ch) {

        case '(':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

int isOperator (char сh) { //Checking if symbol is operator.

    switch (сh) {

        case '+':
        case '-':
        case '*':
        case '/':
            return 1;

        default:
            return 0;
    }
}

int check(char *str) { // Checking if input string contains syntax errors.

    int lBracketCnt = 0, rBracketCnt = 0;

    if (strchr(str, ')') < strchr(str, '('))
        return 0;

    if (strrchr(str, ')') < strrchr(str, '('))
        return 0;

    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '(')
            lBracketCnt++;

    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ')')
            rBracketCnt++;

    if (lBracketCnt != rBracketCnt)
        return 0;

    if (strlen(str) == 0)
        return 0;

    if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
        return 0;

    if (isOperator(str[strlen(str) - 1]) == 1)
        return 0;

    for (int i = 0; i < strlen(str); i++) {

        if (!((str[i] >= '0' && str[i] <= '9') ||
              (str[i] >= '(' && str[i] <= '+') ||
              (str[i] == '-') || (str[i] == '/')))
            return 0;

        if (str[i] == '(' && str[i + 1] == ')')
            return 0;

        if (str[i] == ')' && str[i + 1] == '(' )
            return 0;

        if (str[i] == '(' && str[i + 2] == ')' && isOperator(str[i + 1]) == 1)
            return 0;

        if ((str[i] == '+' || str[i] == '-' ||
             str[i] == '*' || str[i] == '/') &&
            (str[i + 1] == '+' || str[i + 1] == '-' ||
             str[i + 1] == '*' || str[i + 1] == '/'))
            return 0;
    }
}

int main() {

    STACK *s_opt, *s_num;
    char opt[MAX_LENGTH] = {};
    int i = 0, tmp = 0, num1 = 0, num2 = 0;

    stackInit(&s_opt);
    stackInit(&s_num);

    gets(opt);

    if (!(check(opt))) {
        printf("syntax error");
        return 0;
    }

    while (opt[i] != '\0' || isEmpty(s_opt) != true) {

        if (opt[i] >= '0' && opt[i] <= '9') {
            tmp = tmp * 10 + opt[i] - '0';
            i++;

            if (opt[i] > '9' || opt[i] < '0') {
                push(&s_num, tmp);
                tmp = 0;
            }
        }
        else {

            if ((isEmpty(s_opt) == true) ||
                (priority(opt[i]) > priority(getTop(s_opt))) ||
                ((getTop(s_opt) == '(') && (opt[i] != ')'))) {

                push(&s_opt, opt[i]);
                i++;
                continue;
            }

            if (((opt[i] == '\0') && (isEmpty(s_opt) != true)) ||
                ((opt[i] == ')') && (getTop(s_opt) != '(')) ||
                (priority(opt[i]) <= priority(getTop(s_opt)))) {

                switch(pop(&s_opt)) {

                    case'+':
                        num1 = pop(&s_num);
                        num2 = pop(&s_num);
                        push(&s_num, (num2 + num1));
                        break;

                    case'-':
                        num1 = pop(&s_num);
                        num2 = pop(&s_num);
                        push(&s_num, (num2 - num1));
                        break;

                    case'*':
                        num1 = pop(&s_num);
                        num2 = pop(&s_num);
                        push(&s_num, (num2 * num1));
                        break;

                    case'/':
                        num1 = pop(&s_num);
                        num2 = pop(&s_num);

                        if (num1 == 0) {
                            printf("division by zero");
                            return 0;
                        }

                        push(&s_num, (num2 / num1));
                        break;
                }
            }
        }
    }

    printf("%d", getTop(s_num));
    return 0;
}
