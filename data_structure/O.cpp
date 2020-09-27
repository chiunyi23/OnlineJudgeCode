#include <cstdio>

typedef struct Node
{
    int x, y;
} node_t;

void initial(node_t &head, node_t &tail)
{
    head.x = 29;
    head.y = 24;
    tail.x = 10;
    tail.y = 24;
}

void set_next_tail(node_t* next_tail) {
    int k = 0;
    for(int i = 11; i <= 29; i++) {
        next_tail[k].x = i;
        next_tail[k].y = 24;
        k++;
    }
}

int main()
{
    int num;
    char command;
    while (~scanf("%d", &num))
    {
        if(num == 0)
            break;

        bool map[50][50] = {0};
        for (int i = 10; i < 30; i++)
            map[24][i] = 1;

        bool end = 0;
        int step = 0;
        node_t next_tail[19];
        int tail_counter = 0;
        set_next_tail(next_tail);
        // for(int  i = 0; i < 20; i++)
        //     printf("%d %d\n", next_tail[i].x, next_tail[i].y);
        node_t head, tail;
        initial(head, tail);
        // printf("%d %d %d %d \n", head.x, head.y, tail.x, tail.y);
        for (int i = 0; i < num; i++)
        {
            scanf(" %c", &command);
            if (!end)
            {
                step++;
                switch (command)
                {
                case 'N':
                    if (head.y - 1 < 0)
                    {
                        end = 1;
                        printf("The worm ran off the board on move %d.\n", step);
                        break;
                    }

                    map[tail.y][tail.x] = 0;
                    tail_counter %= 20;
                    tail.x = next_tail[tail_counter].x;
                    tail.y = next_tail[tail_counter].y;
                    next_tail[tail_counter].x = head.x;
                    next_tail[tail_counter].y = head.y - 1;

                    tail_counter++;

                    if (map[head.y - 1][head.x] == 1)
                    {
                        end = 1;
                        printf("The worm ran into itself on move %d.\n", step);
                    }
                    else
                    {
                        head.y--;
                        map[head.y][head.x] = 1;
                    }
                    break;
                case 'W':
                    if (head.x - 1 < 0)
                    {
                        end = 1;
                        printf("The worm ran off the board on move %d.\n", step);
                        break;
                    }

                    map[tail.y][tail.x] = 0;
                    tail_counter %= 20;
                    tail.x = next_tail[tail_counter].x;
                    tail.y = next_tail[tail_counter].y;
                    next_tail[tail_counter].x = head.x - 1;
                    next_tail[tail_counter].y = head.y;
                    tail_counter++;

                    if (map[head.y][head.x - 1] == 1)
                    {
                        end = 1;
                        printf("The worm ran into itself on move %d.\n", step);
                    }
                    else
                    {
                        head.x--;
                        map[head.y][head.x] = 1;
                    }
                    break;
                case 'S':
                    if (head.y + 1 > 49)
                    {
                        end = 1;
                        printf("The worm ran off the board on move %d.\n", step);
                        break;
                    }

                    map[tail.y][tail.x] = 0;
                    tail_counter %= 20;
                    tail.x = next_tail[tail_counter].x;
                    tail.y = next_tail[tail_counter].y;
                    next_tail[tail_counter].x = head.x;
                    next_tail[tail_counter].y = head.y + 1;
                    tail_counter++;

                    if (map[head.y + 1][head.x] == 1)
                    {
                        end = 1;
                        printf("The worm ran into itself on move %d.\n", step);
                    }
                    else
                    {
                        head.y++;
                        map[head.y][head.x] = 1;                        
                    }
                    break;
                case 'E':
                    if (head.x + 1 > 49)
                    {
                        end = 1;
                        printf("The worm ran off the board on move %d.\n", step);
                        break;
                    }

                    map[tail.y][tail.x] = 0;
                    tail_counter %= 20;
                    tail.x = next_tail[tail_counter].x;
                    tail.y = next_tail[tail_counter].y;
                    next_tail[tail_counter].x = head.x + 1;
                    next_tail[tail_counter].y = head.y;
                    tail_counter++;

                    if (map[head.y][head.x + 1] == 1)
                    {
                        end = 1;
                        printf("The worm ran into itself on move %d.\n", step);
                    }
                    else
                    {
                        head.x++;
                        map[head.y][head.x] = 1;
                        
                    }
                    break;
                }
            }
            
        }
        if(!end) 
            printf("The worm successfully made all %d moves.\n", step);
        /*
        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) {
                if(map[i][j] == 0)
                    printf("o");
                else
                    printf("S");
            }
            printf("\n");
        }
        */
    }
    return 0;
}