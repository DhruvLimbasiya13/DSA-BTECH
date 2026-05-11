#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void reverseSubstring(char *s, int end) {
    int start = 0;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end - 1];
        s[end - 1] = temp;
        start++;
        end--;
    }
}

void main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        char s[1005];
        
        scanf("%d", &n);
        scanf("%s", s);
        
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                reverseSubstring(s, i);
            }
        }
        
        printf("%s\n", s);
    }
    
}