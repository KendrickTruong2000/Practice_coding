#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isValid(char*);

int main() {
    char s[] = "()[]{}";

    if(isValid(s)){
        printf("Valid parentheses\n");
    }
    else{
        printf("Invalid parentheses\n");
    }

    return 0;
}

bool isValid(char* s){
    int length = 0;
    while(s[length] != '\0'){
        length++;
    }

    char stack[length];
    int top = -1;

    for(int i = 0; i < length; i++){
        char c = s[i];

        if(c == '(' || c == '[' || c == '{'){
            stack[++top] = c;
        }
        else{
            if(top == -1){
                return false;
            }

            char topChar = stack[top--];

            if((c == ')' && topChar != '(') ||
               (c == ']' && topChar != '[') ||
               (c == '}' && topChar != '{')){
                return false;
            }
        }
    }

    return top == -1;
}