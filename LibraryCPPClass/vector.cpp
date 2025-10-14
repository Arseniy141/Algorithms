#include "vector.h"

Vector::Vector()
{
    adata = nullptr;
    asize = 0;
    acapacity = 0;
}

Vector::Vector(const Vector& a)
{
    if (a.size() > 0) {
        asize = a.size();
        acapacity = a.acapacity;
        Data* new_data = new Data[acapacity];
        for (size_t i = 0; i < asize; i++) {
            new_data[i] = a.get(i);
        }
        adata = new_data;
    }
    else {
        adata = nullptr;
        asize = 0;
        acapacity = 0;
    }
}

Vector& Vector::operator=(const Vector& a)
{
    if (this != &a) {
        if (a.size() > 0) {
            delete[] adata;
            asize = a.size();
            acapacity = a.acapacity;
            Data* new_data = new Data[acapacity];
            for (size_t i = 0; i < asize; i++) {
                new_data[i] = a.get(i);
            }
            adata = new_data;
        }
        else {
            adata = nullptr;
            asize = 0;
            acapacity = 0;
        }
    }
    return *this;
}

Vector::~Vector()
{
    delete[] adata;
}

Data Vector::get(size_t index) const
{
    if (index < asize) {
        return adata[index];
    }
    else {
        return -1;
    }
}

void Vector::set(size_t index, Data value)
{
    if (index < asize) {
        adata[index] = value;
    }
}

size_t Vector::size() const
{
    return asize;
}

void Vector::resize(size_t size)
{
    if (size <= acapacity) {
        // ���� ����� ������ ������ ��� ����� ������� �����������,
        // ������ ������ ������ ��� ������������� ������
        asize = size;
    }
    else {


        // ��������� ����� ����������� � ������� ��� ���������� O(1) � �������
        size_t new_capacity = size * 2; // ����������� ����������� �����

        // ������� ����� ������ � ����� ������������
        Data* new_data = new Data[new_capacity];

        // �������� ������������ ������
        for (size_t i = 0; i < asize; ++i) {
            new_data[i] = adata[i];
        }

        // �������������� ����� �������� (���� ������ �������������)
        for (size_t i = asize; i < size; ++i) {
            new_data[i] = Data(); // �������� �� ��������� ��� ���� Data
        }

        // ����������� ������ ������ � ��������� ���������
        delete[] adata;
        adata = new_data;
        asize = size;
        acapacity = new_capacity;
    }
    return;
}