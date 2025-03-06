#include <iostream>

using namespace std;

int ERROR = 0;

// typedef unsigned long size_t; //
struct vector_t
{
    int* data;
    size_t size;
    size_t capacity;
} typedef Vector;

Vector* initVector();

/**
 * @brief Adds the number in the back of the vector
 *
 * @param v
 * @param number
 */
void pushBack(Vector* v, int number);

/**
 * @brief Resizes the vector
 *
 * @param v
 */
void resize(Vector* v);


/**
 * @brief Prints the vector in the specified format
 *
 */

 // Vector's size:
 // Vector's capacity:
 // Vector's data:
void print(Vector* v);

/**
 * @brief Returns the element at the provided index
 *
 * @param v
 * @param index
 * @return int
 */
int at(Vector* v, int index);

/**
 * @brief Pops the last element of the vector
 *
 * @param v
 * @return int if successful, ERROR - if not
 */
int pop(Vector* v);

/**
 * @brief Frees the memory allocated by the vector
 *
 * @param v
 */
void destroy(Vector* v);

/*int main()
{
    struct vector_t* v = initVector();
    pushBack(v, 1);
    pushBack(v, 2);
    print(v);
    delete[] v->data; // *(v).data
    delete v;

    return 0;
}*/

Vector* initVector()
{
    Vector* v = new struct vector_t;
    v->size = 0;
    v->capacity = 2;
    v->data = new int[v->capacity];
    return v;
}
void pushBack(Vector* v, int number) {
    if (v->size + 1 > v->capacity) {
        resize(v);
    }
    v->data[v->size] = number;
    v->size = v->size + 1;
}
void resize(Vector* v) {
    size_t oldCapacity = v->capacity;
    v->capacity = oldCapacity * 2;
}
void print(Vector* v) {
    cout << "Vector's size: " << v->size << "\n";
    cout << "Vector's capacity: " << v->capacity << "\n";
    cout << "Vector's data: [";
    for (int i = 0; i < v->size; i++) {
        if (i + 1 == v->size) {
            cout << v->data[i];
        }
        else {
            cout << v->data[i] << " ";
        }
    }
    cout << "]";
}
int at(Vector* v, int index) {
    if (index < 0 || v->size == 0 || index >= v->size) {
        return ERROR;
    }
    if (index >= 0) {
        return v->data[index];
    }
}
int pop(Vector* v) {
    if (v->size == 0) {
        return ERROR;
    }
    int number_of_deleted_space = v->data[v->size - 1];
    v->size = v->size - 1;
    return number_of_deleted_space;
}
void destroy(Vector* v) {
    delete[] v->data; // *(v).data
    delete v;
}