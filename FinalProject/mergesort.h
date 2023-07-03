#ifndef MERGESORT_H
#define MERGESORT_H

#include "Student.h"
#include "Vector.h"


void merge(Vector<Student> & array, int const left, int const mid,int const right);

void mergeSort(Vector<Student>& array, int const begin, int const end);

#endif // MERGESORT_H
