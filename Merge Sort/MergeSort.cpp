#include <iostream>
using namespace std;
 
#define MAX_LEN_ARRAY 100

void printArray(int A[], int first, int second)
{
    for (auto i = first; i <= second; i++)
        cout << A[i] << " ";
}


void merge(int numbers[], int first_cursor,int separator, int second_cursor)
{
    int len_left, len_right, cursor_left = 0, cursor_right = 0, cursor_merged_array = first_cursor;
    len_right = second_cursor - separator;
    len_left = separator - first_cursor + 1;
 
    int *part_right = new int[len_right];
    int *part_left = new int[len_left];

    for (int cursor = 0; cursor < len_right; cursor++)
    {
        part_right[cursor] = numbers[separator + 1 + cursor];
    }
    for (int cursor = 0; cursor < len_left; cursor++)
    {
        part_left[cursor] = numbers[first_cursor + cursor];
    }

    while (cursor_right < len_right && cursor_left < len_left)
    {
        if (part_right[cursor_right] > part_left[cursor_left])
        {
            numbers[cursor_merged_array] = part_right[cursor_right];
            cursor_right++;
        }
        else
        {
            numbers[cursor_merged_array] = part_left[cursor_left];
            cursor_left++;
        }
        cursor_merged_array++;
    }

    while (cursor_right < len_right)
    {
        numbers[cursor_merged_array] = part_right[cursor_right];
        cursor_merged_array++;
        cursor_right++;
    }

    while (cursor_left < len_left)
    {
        numbers[cursor_merged_array] = part_left[cursor_left];
        cursor_merged_array++;
        cursor_left++;
    }
}

void sort(int numbers[], int first_cursor, int second_cursor)
{
    if (second_cursor > first_cursor)
    {
        int separator = (second_cursor - first_cursor) / 2;
        separator += first_cursor;
        sort(numbers, first_cursor, separator);
        sort(numbers, separator + 1, second_cursor);
        merge(numbers, first_cursor, separator, second_cursor);
    }
}
 

 
int main()
{
    // With default values

    int numbers[] = { 12, 11, 13, 5, 6, 7 };
    int number_of_numbers = sizeof(numbers) / sizeof(numbers[0]);
    cout << "This is our numbers \n";

    // User input
    // int numbers[MAX_LEN_ARRAY];
    // int number_of_numbers = 0;
    // cout << "Tell me, number of your numbers:  ";
    // cin >> number_of_numbers;
    // for (int i = 0; i < number_of_numbers; i++)
    // {
    //     cin >> numbers[i];
    // }
    
    // cout << "This is your numbers:  \n";

    for (auto i = 0; i < number_of_numbers; i++)
        cout << numbers[i] << " ";
    cout << endl;

    sort(numbers, 0, number_of_numbers - 1);
 
    cout << "This is sorted numbers: \n";
    for (auto i = 0; i < number_of_numbers; i++)
        cout << numbers[i] << " ";
    cout << endl;
    return 0;
}