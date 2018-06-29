#include <stdio.h>
#include <string.h>

int main ()
{
    char set[4][10] = 
        {
            "dream","dreamer","erase","eraser"
        };
    
    
    char s[100000];
    fgets(s,100000,stdin);
    
    
    int pt = 0;
    int end = strlen(s) - 1;
    while(pt < end) 
        {
            int i = 0;
            for(i = 0; i < 4; i++) 
                {
                    
                    if(strncmp(set[i],s + end - pt - strlen(set[i]),strlen(set[i])) == 0)
                        {
                            
                            pt += strlen(set[i]);
                            break;
                        }
                }
            if(i == 4)
                {
                    printf("NO");
                    return 0;
                }
            
        }
    
    printf("YES");
    return 0;
}
