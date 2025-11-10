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

void allStudentUnBuffered(int N) 
{ 
    ifstream file("studentdatabase.txt",ios::binary|ios::in); 
    Student s;  
    for(int i=1; i<N; i++) 
    { 
    s.roll = i; 
    file.read((char*)(&s),sizeof(Student)); 
    } 
    file.close(); 
}

void allStudentBuffered(int N,int buffersize = 1000){ 
    ofstream file("studentdatabase.txt",ios::binary|ios::in);
    Student s;
    if (!file.is_open()) {
        cout << "Error opening file.\n";
    }
    else{
        // file.read((char*)(&s),sizeof(Student)*buffersize); 
    }
    file.close(); 
} 

int main(){
    SYSTEMTIME systime;  
    cout<<"\nWriting Records to File one by one";  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;  
    // addToStudentUnBuffered();  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
    return 0;
}