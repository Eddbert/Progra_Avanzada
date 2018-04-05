#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    FILE *fp;
    int c;
    int i = 0;
    int numeral = 0;
    int T_Flag = 0;
    int N_Flag = 0;
    int N;
    int** dice;
    int** list;
    int faces = 6;
    int x = 0;
    int y = 0;
    int k = 0;
    int l = 0;
    int caso = 0;
    char number[8];
    int previous_dice[100];
    memset(&previous_dice[0], -1, sizeof(previous_dice));
    int repeat_die;
    int start_value;
    int previous_value;
    int start = 1;
    int straight = 0;
    int highest = 0;


    fp = fopen("A-test-practice.in","r");
    if(fp == NULL)
    {
        perror("Error in opening file");
        return(-1);
    }
    do
    {
        c = fgetc(fp);
        if( feof(fp) )
        {
            break ;
        }
        //printf("%c", c);
        if(c == ' ' || c == '\n')
        {
            number[i] = 0;
            i = 0;
            numeral = atoi (number);
            if(!T_Flag)
            {
                T_Flag = 1;
                //printf ("The value of T is %d.\n",numeral);
            }
            else if(T_Flag && !N_Flag)
            {
                N_Flag = 1;
                //printf ("The value of N is %d.\n",numeral);
                N = numeral;
                dice = (int**) malloc(N*sizeof(int*));
                for (int d = 0; d < N; d++)
                    dice[d] = (int*) malloc(faces*sizeof(int));
                list = (int**) malloc(2*sizeof(int*));
                for (int d = 0; d < 2; d++)
                    list[d] = (int*) malloc(N*faces*sizeof(int));
            }
            else if(T_Flag && N_Flag)
            {
                dice[x][y] = numeral;
                //printf ("The inserting number %d.\n",numeral);
                y = y + 1;
                if(y == faces)
                {
                    y = 0;
                    x = x + 1;
                    //printf ("End die\n");
                }
                if(x == N)
                {
                    N_Flag = 0;
                    x = 0;
                    y = 0;
                    //printf ("End case\n");
                    k = 0;
                    for (int a = 0; a < N; a++) {
                        for (int b = 0; b < faces; b++) {
                            //printf("%d ", dice[a][b]);
                            list[0][k] = dice[a][b];
                            list[1][k] = a;
                            k = k + 1;
                        }
                        //printf("\n");
                    }
                    /*for (int a = 0; a < 2; a++) {
                        for (int b = 0; b < N*faces; b++) {
                            printf("%d ", list[a][b]);
                        }
                        printf("\n");
                    }*/
                    for (int a = 0; a < N*faces; a++)
                    {
                        for (int b = 0; b < N*faces; b++)
                        {
                            if (list[0][b] > list[0][a])
                            {
                                int tmp_val = list[0][a];
                                int tmp_die = list[1][a];
                                list[0][a] = list[0][b];
                                list[1][a] = list[1][b];
                                list[0][b] = tmp_val;
                                list[1][b] = tmp_die;
                            }
                        }
                    }
                    /*for (int a = 0; a < 2; a++) {
                        for (int b = 0; b < N*faces; b++) {
                            printf("%d ", list[a][b]);
                        }
                        printf("\n");
                    }*/
                    k = 0;
                    l = 0;
                    memset(&previous_dice[0], -1, sizeof(previous_dice));
                    start_value = 0;
                    straight = 0;
                    highest = 0;
                    do
                    {
                        //printf("k is %d\n", k);
                        if(start)
                        {
                            previous_value = list[0][k];
                            previous_dice[l] = list[1][k];
                            //printf("%d,%d\n", list[0][k], previous_dice[l]);
                            k = k + 1;
                            l = l + 1;
                            straight = straight + 1;
                            //printf("straight %d\n", straight);
                            start = 0;
                            if (k == N*faces)
                            {
                                break;
                            }
                        }
                        else if(!start)
                        {
                            for (int a = 0; a < l; a++) {
                                if(list[1][k] == previous_dice[a])
                                {
                                    //printf("Found repeat die\n");
                                    repeat_die = 1;
                                    break;
                                }
                            }
                            if(!repeat_die)
                            {
                                if(list[0][k] == previous_value+1)
                                {
                                    previous_value = list[0][k];
                                    previous_dice[l] = list[1][k];
                                    //printf("%d,%d\n", list[0][k], previous_dice[l]);
                                    k = k + 1;
                                    l = l + 1;
                                    straight = straight + 1;
                                    //printf("straight %d\n", straight);
                                    if (k == N*faces)
                                    {
                                        break;
                                    }
                                }
                                else if (list[0][k] == previous_value)
                                {
                                    k = k + 1;
                                    if (straight >= highest)
                                    {
                                        highest = straight;
                                    }
                                    if (k == N*faces)
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    //printf("reset\n");
                                    start = 1;
                                    if (straight >= highest)
                                    {
                                        highest = straight;
                                    }
                                    straight = 0;
                                    l = 0;
                                    start_value = start_value + 1;
                                    k = start_value;
                                    memset(&previous_dice[0], -1, sizeof(previous_dice));
                                    if (start_value == N*faces)
                                    {
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                repeat_die = 0;
                                k = k + 1;
                                if (straight >= highest)
                                {
                                    highest = straight;
                                }
                                if (k == N*faces)
                                {
                                    break;
                                }
                            }
                        }
                    }while(1);
                    caso = caso + 1;
                    printf("Case #%d: %d\n",caso,highest);
                }
            }
        }
        else
        {
            number[i] = c;
            i = i + 1;
        }
    }
    while(1);

    fclose(fp);
    return(0);
}
