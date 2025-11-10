#include<iostream>
#include<fstream>
#include<stdio.h>
#include<windows.h>
using namespace std;

struct Student 
{ 
    int roll; 
    char name[30]; 
    Student():roll(0) 
    { 
    strcpy(name,"none"); 
    } 
};

void addToStudentUnBuffered(int N) 
{ 
    ofstream ofs("studentdatabase.txt",ios::binary|ios::out); 
    Student s;  
    for (int i=1; i<N; i++) 
    { 
    s.roll = i; 
    ofs.write((char*)(&s),sizeof(Student)); 
    } 
    ofs.close(); 
}

void addToStudentBuffered(int N,int buffersize = 2000){ 
    ofstream ofs("studentdatabase.txt",ios::binary|ios::out);
    Student s;
    if (!ofs.is_open()) {
        cout << "Error opening file.\n";
    }
    else{
        ofs.write((char*)(&s),sizeof(Student)*buffersize); 
    }
    ofs.close(); 
} 

int main(){
    SYSTEMTIME systime;  
    cout<<"\nWriting Records to File one by one";  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;  
    addToStudentBuffered(4);  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
    return 0;
}