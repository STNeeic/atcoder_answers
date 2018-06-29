#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list
{
    int n[2];
    char k;
    struct list* next;
} LIST;

    

LIST *head;
LIST *rt;



void list_init()
{
    head = rt = malloc(sizeof(LIST));
    rt->next = NULL;
    
}


void  list_set(int i, int j, char k)
{
    rt->next = malloc(sizeof(LIST));
    rt->next->n[0] = i;
    rt->next->n[0] = j;
    rt->next->k = k;
    rt = rt->next;
    rt->next = NULL;
    
}

int search_list(int i , int j, char k)
{
    LIST* p = head;
    while(p != NULL)
        {
            if(p->n[0] == i || p->n[1] == i)
                            if(p->n[0] == j || p->n[1] == j)
                                if(p->k == k || p->k == k) 
                                    {
                                        return 1;
                                    }
            p = p->next;
            
        }
    return 0;
}



int check_tree(LIST * rt, int nc, int i, char* memo, char k)
{
    int out = 0;
    for(int j = 0; j < nc; j++)
        {
            if( (memo[j] & k )== 0 && search_list(i, j, k))
                {
                    memo[j] |= k;
                    out += check_tree(rt,nc,j,memo,k) + 1;
                }
        }
    return out;
}

int main ()
{
    list_init();
    for(int i = 0; i < 100000; i++)
        {
            list_set(i,i,3);
        }
    
    
    char inp[10000];
    fgets(inp,10000,stdin);
    
    int nc = atoi(strtok(inp," "));
    int nr = atoi(strtok(NULL," "));
    int nt = atoi(strtok(NULL," "));
    for(int i = 0; i < nr + nt; i++)
        {
            memset(inp,0,10000);
            fgets(inp,10000,stdin);
            int a = atoi(strtok(inp," "));
            int b = atoi(strtok(NULL," "));
            if(i < nr) list_set(a,b,1);
            else list_set(a,b,2);
            
        }

    for(int i = 0; i < nc; i++)
        {
            int out = 0;
            char memo[100000] = 
                {
                };
            check_tree(rt, nc, i, memo,1);
            check_tree(rt, nc, i, memo,2);
            for(int j = 0; j < 100000; j++)
                {
                    if(memo[j] == 3) out++;
                }
            
            printf("%d",out);
            
            if(i + 1 != nc) printf(" ");
            
        }
    

    return 0;
}

