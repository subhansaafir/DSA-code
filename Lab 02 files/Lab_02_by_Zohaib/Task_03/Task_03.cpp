#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
using namespace std;

struct Student
{
    int roll;
    char name[30];
    Student() : roll(0)
    {
        strcpy(name, "none");
    }
};

void addToStudentUnBuffered(int N)
{
    ofstream ofs("studentdatabase.txt", ios::binary | ios::out);
    Student s;
    for (int i = 0; i < N; i++) // Fixed: start from 0, not 1
    {
        s.roll = i;
        ofs.write((char *)(&s), sizeof(Student));
    }
    ofs.close();
}

void addToStudentBuffered(int N)
{
    const int BUFFER_SIZE = 10000;
    Student buffer[BUFFER_SIZE];
    int buffer_count = 0;

    ofstream ofs("studentdatabase_buffered.txt", ios::binary | ios::out);
    Student s;

    for (int i = 0; i < N; i++)
    {
        s.roll = i;
        buffer[buffer_count] = s;
        buffer_count++;

        if (buffer_count >= BUFFER_SIZE)
        {
            ofs.write((char *)buffer, sizeof(Student) * buffer_count);
            buffer_count = 0;
        }
    }

    if (buffer_count > 0)
    {
        ofs.write((char *)buffer, sizeof(Student) * buffer_count);
    }

    ofs.close();
}

void readAllRecordsUnBuffered()
{
    Student s;
    ifstream ifs("studentdatabase.txt", ios::binary | ios::in);
    while (!ifs.eof())
    {
        ifs.read((char *)(&s), sizeof(Student));
    }
    ifs.close();
}

void readAllRecordsBuffered()
{
    const int BUFFER_SIZE = 10000;
    Student buffer[BUFFER_SIZE];
    int buffer_count = 0;

    ifstream ifs("studentdatabase_buffered.txt", ios::binary | ios::out);
    Student s;

    while (!ifs.eof())
    {
        buffer[buffer_count] = s;
        buffer_count++;

        if (buffer_count >= BUFFER_SIZE)
        {
            ifs.read((char *)buffer, sizeof(Student) * buffer_count);
            buffer_count = 0;
        }
    }

    if (buffer_count > 0)
    {
        ifs.read((char *)buffer, sizeof(Student) * buffer_count);
    }

    ifs.close();
}

int main()
{
    SYSTEMTIME systime;

    cout << "\n1. Unbuffered Writing (one by one):";
    GetLocalTime(&systime);
    cout << "\nStart Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    addToStudentUnBuffered(1000000);

    GetLocalTime(&systime);
    cout << "\nEnd Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    cout << "\n\n2. Buffered Writing (batch processing):";
    GetLocalTime(&systime);
    cout << "\nStart Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    addToStudentBuffered(1000000);

    GetLocalTime(&systime);
    cout << "\nEnd Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    cout << "\n1. Unbuffered Reading (one by one):";
    GetLocalTime(&systime);
    cout << "\nStart Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    readAllRecordsUnBuffered();

    GetLocalTime(&systime);
    cout << "\nEnd Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    cout << "\n\n2. Buffered Reading (batch processing):";
    GetLocalTime(&systime);
    cout << "\nStart Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    readAllRecordsBuffered();

    GetLocalTime(&systime);
    cout << "\nEnd Time: " << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    return 0;
}