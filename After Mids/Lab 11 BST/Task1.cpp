#include<iostream>
#include<string>
using namespace std;

struct StudentNode{  
    int rollNo;     
    string name;    
    double cgpa;    
    StudentNode* left;  
    StudentNode* right;  
};   

class StudentBST {  
private:  
    StudentNode* root;  

    void inOrderHelper(StudentNode *p) {
        if (p != NULL) {
            inOrderHelper(p->left);
            cout<<"Roll No: "<<p->rollNo <<", Name: "<< p->name<<", CGPA: "<<p->cgpa<<endl;
            inOrderHelper(p->right);
        }
    }

public:  
    StudentBST(){
        root = NULL;
    }
    ~StudentBST (){
        delete root;
    }
    void inOrder(){
        inOrderHelper(root);
    cout <<endl;
    }

    bool insert(int rollNo, string name, double cgpa){
        StudentNode* curr = root;
        while(curr != NULL){
            if(curr->rollNo == rollNo){
                cout<< "Student already Exist"<<endl;
                return false;
            }else if (rollNo < curr->rollNo){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        StudentNode* newNode = new StudentNode();
        
        return false;
    }

    bool search(int roll){
        StudentNode* curr = root;

        while (curr != NULL){
            if (curr->rollNo == roll){
                cout<<"Founded: Roll No: " <<curr->rollNo<<", Name: "<<curr->name <<", CGPA: "<<curr->cgpa<<endl;
                return true;
            }
            else if(roll < curr->rollNo){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        cout<<"Roll No: "<<roll<<" not found"<<endl;
        return false;
    } 


    bool remove(int rollNo){
        StudentNode* curr = root;

        while (curr != NULL){
            if (curr->rollNo == rollNo){
                cout<<"Roll NO deleted: "<<curr->rollNo<<endl;
                delete curr;
                return true;
            }
            else if(rollNo < curr->rollNo){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        cout<<"Roll No: "<<rollNo<<" not found, Cant able to remove"<<endl;
        return false;
    }

};  


int main(){
    StudentBST tree;
    int choice;
    do{
        cout<< "1. insert new student\n2. Search for Student\n 3. see the list of students\n4. Quit"<<endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                int rollNo;
                string name;
                double cgpa;
                
                cout<<"Enter RollNo: ";
                cin>> rollNo;
                cout<<"Enter Name: ";
                cin>> name;
                cout<<"Enter CGPA: ";
                cin>> cgpa;

                tree.insert(rollNo, name, cgpa);
            }
                break;
            case 2:
            {
                int rollNo;
                cout<< "Enter Rollno you want to search: ";
                cin >>rollNo;
                bool a = tree.search(rollNo);
            }
                break;
            case 3:
                tree.inOrder();
                break;
            case 4:
                cout<<"Existing Program.."<<endl;
                break;
            default:
                cout << "Invalid!"<<endl;
                break;
        }
        
    }while(choice!=4);
    return 0;
}