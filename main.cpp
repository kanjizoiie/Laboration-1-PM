#include <cstdlib>
#include <iostream>
#include <chrono>
#include "int_sorted.h"
#include "int_buffer.h"


void f(int_buffer buf);
int_buffer u(int_buffer in);

/*
 * 
 */
int main(int argc, char** argv) {
    int size = 400000;
    //Set arrs size.
    int arr[size];
    //Insert random numbers into the array.
    for (int i = 0; i < size; i++) {
        arr[i] =  rand() % 1000000;
    }
    
    //Time the sorting
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    //Create int_sorted object using the arr array.
    int_sorted sor(arr, size);
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    //Print all of the elements in the buffer.
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    
    std::cout << "The sort took " << time_span.count() << " seconds" << "\n";
    return 0; //Exit the application
}


int_buffer u(int_buffer in) {
    return in;
}

void f(int_buffer buf) {
    int counter = 0;
    for(int* i = buf.begin(); i != buf.end(); i++)
        *i = counter++;
        
    for(const int* i = buf.begin(); i != buf.end(); i++)
        std::cout << *i << "\n";
}