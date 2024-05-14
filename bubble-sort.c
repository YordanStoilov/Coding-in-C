// This is a simple bubble-sort algorithm that takes in terminal a numeric value, representing count of random values that will be sorted and sorts the numbers by the sum of their digits

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void bubble_sort(int array[], int start, int end);

int find_sum_of_digits(int num);

int main(int argv, char* argc[])
{
    if (argv != 2)
    {
        printf("Proper usage: .bubble_sort count_of_random_numbers\n");
        return 1;
    }

    #define ARR_LEN atoi(argc[1])
    int arr[ARR_LEN];

    srand(time(NULL));
    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = rand() % INT_MAX;
    }

    for (int i = 0; i < ARR_LEN; i++)
    {
        int current_num = arr[i];
        int current_sum = current_num % 10;
    }

    bubble_sort(arr, 0, ARR_LEN);
    printf("Sorted array: [");
    for (int i = 0; i < ARR_LEN; i++)
    {
        if (i < ARR_LEN - 1)
        {
            printf("%i, ", arr[i]);
        }
        else
        {
            printf("%i]\n", arr[i]);
        }

    }
}

void bubble_sort(int array[], int start, int end)
{
    int counter;
    for (int i = 0; i < end - 1; i++)
    {
        int first_el = array[i];
        int second_el = array[i + 1];

        if (find_sum_of_digits(first_el) > find_sum_of_digits(second_el))
        {
            array[i] = second_el;
            array[i + 1] = first_el;
            counter = 1;
        }
    }
    if (!counter)
    {
        return;
    }

    bubble_sort(array, start, end - 1);
}

int find_sum_of_digits(int num)
{
    int sum = 0;

    while (num != 0) {
        int remainder = num % 10;
        sum += remainder;
        num /= 10;
    }
    return sum;

}
