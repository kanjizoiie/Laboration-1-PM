#ifndef INT_BUFFER_H
#define INT_BUFFER_H
#include <cstddef>

class int_buffer {
public:
    int_buffer() = delete;
    explicit int_buffer(size_t size);
    int_buffer(const int* source, size_t size);
    int_buffer(const int_buffer& orig);
    int_buffer(int_buffer&& rhs);
    int_buffer& operator=(const int_buffer& rhs);
    int_buffer& operator=(int_buffer&& rhs);
    size_t size() const;
    int* begin();
    int* end();
    const int* begin() const;
    const int* end() const;
    
    ~int_buffer();
private:
    int* buffer = nullptr;
    size_t b_size = 0;
};

#endif /* INT_BUFFER_H */

