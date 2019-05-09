#include "int_sorted.h"
#include <algorithm>
#include <vector>

int_sorted::int_sorted(const int* source, size_t size): buffer(source, size) {
    if(!sorted())
       *this = sort(buffer.begin(), buffer.end());
//    if(!sorted())
//        *this = sel_sort(buffer.begin(), buffer.end());
}

//Default constructor, Used in the sorting method.
int_sorted::int_sorted(): buffer(0){  
}

//Insert into the object using a linear search, with a loop to move all the trailing numbers and then insert the value on the found position.
int* int_sorted::insert(int value) {
    size_t offset = 0;
    for (int* i = buffer.begin(); i != buffer.end(); i++)
        if (value > *i)
            offset++;
    buffer = int_buffer(buffer.begin(), buffer.size() + 1);
    for (int* i = buffer.end(); i != (buffer.begin() + offset); i--)
        *i = *(i - 1);
    *(buffer.begin() + offset) = value;
    return (buffer.begin() + offset);
}

//Checks if the objects buffer is sorted
bool int_sorted::sorted() {
    const int* left = begin();
    while (left < end() - 1) {
        const int* right = left + 1;
        if (*left > *right) {
            return false;
        }
        left = right;
    }
    return true;
}
//Merges two int_sorted objects
int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    //Create a buffer to store the values in.
    int_buffer merged(merge_with.size() + size());
    //Makes the following code easier to read.
    const int* first_begin = begin();
    const int* first_end = end();
    const int* second_begin = merge_with.begin();
    const int* second_end = merge_with.end();
    //Access pointer for the algorithm to be easier to read.
    int* merge_p = merged.begin();
    //Iterate through the containers and merge them
    while (first_begin < first_end && second_begin < second_end) {
        if (*first_begin < *second_begin) {
            *merge_p++ = *first_begin++;
        }
        else {
            *merge_p++ = *second_begin++;
        }
    }
    while (first_begin < first_end) {
        *merge_p++ = *first_begin++;
    }
    while (second_begin < second_end) {
        *merge_p++ = *second_begin++;
    }
    return int_sorted(merged.begin(), merged.size());
}
//Merge sort, recursivly called, which splits the object into smaller pieces and then merges them into a sorted objects.
int_sorted int_sorted::sort(const int* begin, const int* end){
    if (begin == end) 
        return int_sorted();
    if (begin == end - 1) 
        return int_sorted(begin , 1);
    ptrdiff_t  half = (end - begin) / 2;
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

int* int_sorted::find_min(int* begin, int* end) {
    int* current_min = begin;
    while (begin != end) {
        if (*current_min > *begin)
            current_min = begin;
        ++begin;
    }
    return current_min;
}


int_sorted int_sorted::sel_sort(const int* begin, const int* end) {
    int_buffer sorted(begin, end - begin);
    for (int* i = sorted.begin(); i < sorted.end(); i++) {
        int* min = find_min(i, sorted.end());
        std::swap(*i, *min);
    }
    return int_sorted(sorted.begin(), sorted.size());
}

//Returns the buffers beginning.
const int* int_sorted::begin() const {
    return buffer.begin();
}
//Returns the buffers end.
const int* int_sorted::end() const {
    return buffer.end();
}
//Returns the buffers size.
size_t int_sorted::size() const {
    return buffer.size();
}

