// Fadi Elsadi
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float min(int total, char *data[total]);
float min2(int total, char *data[total]);
float max(int total, char *data[total]);
float max2(int total, char *data[total]);
void sum_avg(int total, char *data[total], float *a, float *b);

int main(int argc, char *argv[])
{

    int argc1 = argc - 1;
    float sum = 0, avg = 0;

    if (argc == 1)
    {
        printf("\nYou must enter at least one number after program name.\n\n");
        return 0;
    }

    printf("\nTotal numbers entered: %d", argc1);
    printf("\nmin = %.3f", min(argc, argv));
    printf("\nmin2 = %.3f", min2(argc, argv));
    printf("\nmax = %.3f", max(argc, argv));
    printf("\nmax2 = %.3f", max2(argc, argv));
    sum_avg(argc, argv, &sum, &avg);
    printf("\nsum = %.3f", sum);
    printf("\navg = %.3f", avg);
    printf("\n");

    return 0;
}

float min(int total, char *data[total])
{

    int min = atof(data[1]), current;

    for (int i = 1; i < total; i++)
    {

        current = atof(data[i]);

        if (current < min)
        {
            min = current;
        }
    }

    return min;
}

float min2(int total, char *data[total])
{

    int min = atof(data[1]), min2 = atof(data[1]), current;

    for (int i = 1; i < total; i++)
    {

        current = atof(data[i]);

        if (current < min)
        {

            min2 = min;
            min = current;
        }
        else if (current < min2)
        {

            min2 = current;
        }
        else if (min == min2)
        {

            min2 = current;
        }
    }

    return min2;
}

float max(int total, char *data[total])
{

    int max = atof(data[1]), current;

    for (int i = 1; i < total; i++)
    {

        current = atof(data[i]);

        if (current > max)
        {

            max = current;
        }
    }

    return max;
}

float max2(int total, char *data[total])
{

    int max = atof(data[1]), max2 = atof(data[1]), current;

    for (int i = 1; i < total; i++)
    {

        current = atof(data[i]);

        if (current > max)
        {

            max2 = max;
            max = current;
        }
        else if (current < max2)
        {

            max = current;
        }
        else if (max == max2)
        {

            max2 = current;
        }
    }

    return max2;
}

void sum_avg(int total, char *data[total], float *a, float *b)
{

    for (int i = 1; i < total; i++)
    {

        *a = *a + atoi(data[i]);
    }

    total = total - 1;

    *b = *a / total;
}