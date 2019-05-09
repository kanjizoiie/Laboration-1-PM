#include "int_buffer.h"
#include <algorithm>
#include <iostream>

//Parametrised size constructor.
int_buffer::int_buffer(size_t size): buffer(new int[size]()), b_size(size){
}

//Parametrised source, size constructor
int_buffer::int_buffer(const int* source, size_t size): buffer(new int[size]()), b_size(size){
    std::copy(source, source + size, buffer);
}
//Copy constructor
int_buffer::int_buffer(const int_buffer& orig): buffer(new int[orig.size()]()), b_size(orig.size()) {
    std::copy(orig.begin(), orig.end(), buffer);
}
//Swap constructor
int_buffer::int_buffer(int_buffer&& rhs): buffer(nullptr), b_size(0) {
    std::swap(this->buffer, rhs.buffer);
    std::swap(this->b_size, rhs.b_size);
}
//Assignment operator.
int_buffer& int_buffer::operator=(const int_buffer& rhs) {
    int_buffer tmp = rhs;
    std::swap(this->buffer, tmp.buffer);
    std::swap(this->b_size, tmp.b_size);
    return *this;
}
//Assignment operator.
int_buffer& int_buffer::operator=(int_buffer&& rhs) {
    std::swap(this->buffer, rhs.buffer);
    std::swap(this->b_size, rhs.b_size);
    return *this;   
}
//Return the buffers beginning, const
const int* int_buffer::begin() const {
    return buffer;
}
//Return the buffers end, const
const int* int_buffer::end() const {
    return (buffer + b_size); 
}
//Return the buffers beginning
int* int_buffer::begin() {
    return buffer;
}
//Return the buffers end
int* int_buffer::end() {
    return (buffer + b_size);
}

//Return the buffers size.
size_t int_buffer::size() const {
    return b_size;
}
//Deletes the resources in the object.
int_buffer::~int_buffer() {
    buffer = 0;
    b_size = 0;
    delete []buffer;
}

