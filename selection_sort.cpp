#include<iostream>
#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

// Initialize the size
// with the total numbers to sorted
// and the gap to be maintained in graph
vector<int> numbers;
int size = 200;
int gap = 4;

// Function for swapping the lines graphically
void swap_colors(int i, int j, int x, int y)
{
    // y is the minimum element,
    // first make this number green
    // Now, swapping it by making black again
    // and then draw the pixels
    // for white colour with x value.
    setcolor(GREEN);
    line(j, size, j, size - y);

    delay(500);

    setcolor(BLACK);
    line(j, size, j, size - y);

    setcolor(WHITE);
    line(j, size, j, size - x);

    // X is the element to be swapped,
    // first make this number black
    // Now, highlight y with green
    // representing the minimum element
    // and then draw the pixels
    // for white colour with y value.
    setcolor(BLACK);
    line(i, size, i, size - x);

    setcolor(GREEN);
    line(i, size, i, size - y);

    delay(500);

    setcolor(WHITE);
    line(i, size, i, size - y);
}

// Selection sort function
void selsort()
{
    for (int i = 0; i < size - 1; i++)
    {

        // Find the minimum element
        // in unsorted array
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element
        // with the first element
        // delay(500);
        swap(&numbers[min_idx], &numbers[i]);

        // Function to show transition in swapping
        swap_colors(gap * i + 1,
                    gap * (min_idx) + 1,
                    numbers[min_idx],
                    numbers[i]);
    }
}

// Driver program
int main()
{

    // auto detection of screen size
    int gd = DETECT, gm;
    int wid1;

    // Graph initialization
    initgraph(&gd, &gm, NULL);

    // setting up window size (gap*size) * (size)
    wid1 = initwindow(gap * size + 1, size + 1);
    setcurrentwindow(wid1);

    // Initializing the array
    for (int i = 1; i <= size; i++)
        numbers.push_back(i);

    // Find a seed and shuffle the array
    // to make it random.
    // Here  different type of array
    // can be taken to results
    // such as nearly sorted, already sorted,
    // reverse sorted to visualize the result
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(numbers.begin(), numbers.end(), default_random_engine(seed));

    // Initial plot of numbers in graph taking
    // the vector position as x-axis and its
    // corresponding value will be the height of line.
    for (int i = 1; i <= gap * size; i += gap)
    {
        line(i, size, i, (size - numbers[i / gap]));
    }

    // Delay the code
    delay(200);

    // Call sort
    selsort();

    // Wait for sometime .
    delay(5000);

    // Close the graph
    closegraph();

    return 0;
}
