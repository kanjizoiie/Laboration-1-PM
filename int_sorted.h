#ifndef INT_SORTED_H
#define INT_SORTED_H
#include "int_buffer.h"
#include <cstddef>

class int_sorted {
public:
    int_sorted();
    int_sorted(const int* source, size_t size);
    size_t size() const;
    int* insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted sort(const int* begin, const int* end);
    int_sorted merge(const int_sorted& merge_with) const;
    int_sorted sel_sort(const int* begin, const int* end);
    int* find_min(int* begin, int* end);
    bool sorted();
private:
    int_buffer buffer;
};

#endif /* INT_SORTED_H */

