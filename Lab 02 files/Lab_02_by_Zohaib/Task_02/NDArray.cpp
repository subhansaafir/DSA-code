#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class NDArray
{
private:
    T *data;
    int *dimensions;
    int ndim;
    int total_size;

    void calculate_total_size()
    {
        total_size = 1;
        for (int i = 0; i < ndim; i++)
        {
            total_size *= dimensions[i];
        }
    }

    // int calculate_index()
    // {
    //     int actual_index = 0;
    //     int index = 1;
    //     for (int i = 1; i <= ndim; i++)
    //     {
    //         int index *= i;
    //         // cout << 'I' << i;
    //         for (int j = i + 1; j <= ndim; j++)
    //         {
    //             index *= j;
    //         }
    //         if (i != n)
    //             actual_index += index;
    //     }
    // }

public:
    NDArray(int ndim, T *dims) : ndim(ndim)
    {
        if (ndim < 0)
        {
            throw invalid_argument("Number of dimensions must be positive:(");
        }
        dimensions = new int[ndim];
        for (int i = 0; i < ndim; i++)
        {
            if (dims[i] < 0)
            {
                throw invalid_argument("All dimensions must be positive:(");
            }
            dimensions[i] = dims[i];
        }
        this->calculate_total_size();
        data = new T[total_size]();
    }

    int calculateIndex(int *indexset)
    {
        int actual_index = 0;
        for (int i = 0; i < ndim; i++)
        {
            if (indexset[i] < 0 || indexset[i] >= dimensions[i])
            {
                throw out_of_range("Index out of range");
            }

            int multiplier = 1;
            for (int j = i + 1; j < ndim; j++)
            {
                multiplier *= dimensions[j];
            }
            actual_index += indexset[i] * multiplier;
        }
        return actual_index;
    }

    void setValue(int *indexset, T val)
    {
        int idx = calculateIndex(indexset);
        data[idx] = val;
    }

    T getValue(int *indexset)
    {
        int idx = calculateIndex(indexset);
        return data[idx];
    }

    int size()
    {
        return total_size;
    }

    ~NDArray()
    {
        delete[] data;
        delete[] dimensions;
    }
};

int main()
{
    int dim_size[3] = {5, 3, 10};

    NDArray<int> arr(3, dim_size);

    int index_set[3] = {4, 2, 8};
    cout << arr.calculateIndex(index_set) << endl;

    int val = 123;
    arr.setValue(index_set, val);
    cout << arr.getValue(index_set) << endl;

    return 0;
}