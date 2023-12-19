////////////////////////////////STUDENT RESULT MANAGEMENT///////////////////
#include <iostream>
#include <conio.h>//CONSOLE
#include <stdlib.h>
#include <fstream>//FILE HANDLING
#include <windows.h>//WINDOW FUNCTIONALITY

using namespace std;

///////////////////////////////MAIN CLASS////////////////////
class student{
private:
    string sName, mName, fName, cName, crName, roll_no, rgln, dd, mm, yy, grade, result;
    float per;
    int oop, OOSDM, DBMS, CYBER, skills, sum;
public:
    void menu();
    void append();
    void display();
    void deleted();
};

///////////////////////MENU FUNCTION/////////////////////////
void student::menu(){
    start:
        system("cls");
        system("Color 3F");
        int choice;
        char x;

        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t |   \t\tSTUDENT MANAGEMENT SYSTEM          |    "<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t |\t\t[1] \t - Enter New Record        |"<<endl;
        cout<<"\t\t\t\t |\t\t[2] \t - Display Record          |"<<endl;
        cout<<"\t\t\t\t |\t\t[3] \t - Delete Record           |"<<endl;
        cout<<"\t\t\t\t |\t\t[4] \t - Exit                    |"<<endl;

        cout<<"\n************************************************************************************************************************"<<endl;
        cout<<"\t\t\t\t |    Choose Option : { 1 / 2 / 3 / 4 }            | "<<endl;
        cout<<"\n************************************************************************************************************************"<<endl;
        cout<<" --> Enter choice:: ";
        cin>>choice;

        switch(choice){
        case 1:
            do{

                append();
                cout<<"\n --> Add New Record (y/n)";
                cin>>x;
            } while(x=='Y' || x=='y');
            break;
        case 2:
            display();
            break;
        case 3:
            deleted();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"\n --> Invalid choice!! Please Try Again "<<endl;
        }
        getch();
        goto start;
}

///////////////////////ADDING///////////////
void student::append(){
    fstream file;
    system("cls");
    system("Color 20");
    cout<<"\n************************************************************************************************************************"<<endl;
    cout<<"\t\t\t\t\t\t | Add Student Details | "<<endl;
    cout<<"\n************************************************************************************************************************"<<endl;

    cout<<"\t\t\t --> Enter Name:: ";
    cin>>sName;
    cout<<"\n\t\t\t --> Enter Mother Name:: ";
    cin>>mName;
    cout<<"\n\t\t\t --> Enter Father Name:: ";
    cin>>fName;
    cout<<"\n\t\t\t --> Enter Department:: ";
    cin>>cName;
    cout<<"\n\t\t\t --> Enter Course:: ";
    cin>>crName;
    cout<<"\n\t\t\t --> Enter Roll Number:: ";
    cin>>roll_no;
    cout<<"\n\t\t\t --> Enter CGPA:: ";
    cin>>rgln;
    cout<<"\n\t\t\t --> Enter Birth Date (DD/MM/YY):: ";
    cin>>dd>>mm>>yy;

    cout<<"\t\t\t--------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t -> -> -> Enter Your Marks Per Subject <- <- <-"<<endl;
    cout<<"\t\t\t--------------------------------------------------------------"<<endl;
    cout<<"\t\t\t --> OOP:: ";
    cin>>oop;
    cout<<"\t\t\t --> CYBER SECURITY:: ";
    cin>>CYBER;
    cout<<"\t\t\t --> OOSDM:: ";
    cin>>OOSDM;
    cout<<"\t\t\t --> DBMS:: ";
    cin>>DBMS;
    cout<<"\t\t\t --> LIFE SKILLS:: ";
    cin>>skills;

    /////////////TOTAL MARKS, PERCENTAGE AND GRADE///////////////////////
    sum = oop + CYBER + OOSDM + DBMS + skills;
    per = sum/5;
    if( per >= 80){
        grade = 'A';
        result = "Excellent!";
    } else if( per >= 60){
        grade = 'B';
        result = "Good Job!";
    } else if( per >= 35){
        grade = 'C';
        result = "Work Hard!";
    } else {
        grade = 'D';
        result = "FAIL!!";
    }

    /////////////////FILE TO STORE THE DATA////////////////////
    file.open("studentResult.txt", ios::out | ios::app);///ios::out write to the stream/ for output
    file<<" "<<sName<<" "<<fName<<" "<<mName<<" "<<cName<<" "<<crName<<" "<<roll_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<oop<<" "<<CYBER<<" "<<OOSDM<<" "<<DBMS<<" "<<skills<<endl;
    file.close();
}

//////////////////////DISPLAY///////////////////////////
void student::display(){
    system("cls");
    system("Color 0F");

    fstream file;

    cout<<"\n************************************************************************************************************************"<<endl;
    cout<<"\t\t\t\t\t\t\t | Student Result Table |"<<endl;
    cout<<"\n************************************************************************************************************************"<<endl;

    file.open("studentResult.txt", ios::in);//Read from the stream/ open for input
    if(file){
        cout<<"\n\t\t\t No Data is Found........";
        file.close();
    } else {
        file>>sName>>fName>>mName>>cName>>crName>>roll_no>>rgln>>dd>>mm>>yy>>oop>>CYBER>>OOSDM>>DBMS>>skills>>sum>>per>>grade>>result;
        while(!file.eof()){
            cout<<"\n\n\t Department : "<<cName<<endl;
            cout<<"\t Course: "<<crName<<endl;

            cout<<"\n\n\t Student's Name : "<<sName;
            cout<<"\t\t\t\t\t Roll No : "<<roll_no<<endl;
            cout<<"\n\t Mother's Name : "<<mName;
            cout<<"\t\t\t\t\t Date Of Birth : "<<dd<<" / "<<mm<<" / "<<yy<<endl;
            cout<<"\n\t Father's Name : "<<fName;
            cout<<"\t\t\t\t\t CGPA : "<<rgln<<endl;

            cout<<"\n\t*----------------------------------------------------------------------------------------------*";
            cout<<"\n\t|   Subject Name    |\t  Marks Obtained  |\tOut-OF   |  Percentage   |\tGrade    |";
            cout<<"\n\t*----------------------------------------------------------------------------------------------*";
            cout<<"\n\t|\t OOP         |\t      "<<oop<<"      |\t"<<100 <<"\t |"<<"\t\t |"<<"\t\t |"<<endl;
            cout<<"\t| \t CYBER SECURITY   |\t     "<<CYBER<<"    |\t"<<100 <<"\t  |"<<"\t\t |"<<"\t\t  |"<<endl;
            cout<<"\t| \t OOSDM        |\t        "<<OOSDM<<"      |\t"<<100 <<"\t  |"<<"\t\t  |"<<"\t\t  |"<<endl;
            cout<<"\t| \t DBMS         |\t         "<<DBMS<<"       |\t"<<1000 <<"\t  |"<<"\t\t  |"<<"\t\t  |"<<endl;
            cout<<"\t| \t LIFE SKILLS     |\t      "<<skills<<"     |\t"<<100 <<"\t  |"<<"\t\t  |"<<"\t\t  |"<<endl;
            cout<<"\t*-------------------------------------------------------------------------------------------------*";
            cout<<"\n\t\t\t\t Total Marks -> "<<sum<<"\t\t\t Result -> "<<result<<endl;

            cout<<"\n\n\t Dated : ";
            cout<<"\t\t\t\t\t\t Principle Signature : "<<endl;

            cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
            file>>sName>>fName>>mName>>cName>>crName>>roll_no>>rgln>>dd>>mm>>yy>>oop>>CYBER>>OOSDM>>DBMS>>skills>>sum>>per>>grade>>result;
        }
    }
    file.close();
}

/////////////////////////////DELETE RECORDS///////////////////////////
void student::deleted(){
    system("cls");
    system("Color 0F");

    string rollno;
    int found = 0;
    fstream file, file1;

    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t | DELETE STUDENT/'S RECORDS |"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

    file.open("studentResult.txt", ios::in);
    if(!file){
        cout<<"\n\t\t\t No Data Found!...";
        file.close();
    } else {
        cout<<"\n\t\t\t--> Enter Roll No. of Student You Want To Delete The Data : ";
        cin>>rollno;
        file1.open("temp.txt", ios::out | ios::app);

        file>>sName>>fName>>mName>>cName>>crName>>roll_no>>rgln>>dd>>mm>>yy>>oop>>CYBER>>OOSDM>>DBMS>>skills>>sum>>per>>grade>>result;
        while(!file.eof()){
            if(rollno!=roll_no){
                file<<" "<<sName<<" "<<fName<<" "<<mName<<" "<<cName<<" "<<crName<<" "<<roll_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<oop<<" "<<CYBER<<" "<<OOSDM<<" "<<DBMS<<" "<<skills<<endl;
            } else {
                found++;
                cout<<"\n\t\t\t Record Deleted Successfully...";
            }

            file>>sName>>fName>>mName>>cName>>crName>>roll_no>>rgln>>dd>>mm>>yy>>oop>>CYBER>>OOSDM>>DBMS>>skills>>sum>>per>>grade>>result;
        }
        if(found==0){
            cout<<"\n\t\t\t Student Roll Number is Not Found!...";
        }
        file.close();
        file1.close();

        remove("studentResult.txt");
        rename("temp.txt", "studentResult.txt");
    }
}

////////////////////////////////MAIN FUNCTION//////////////////////////

int main(){

    student s;
    s.menu();

    getch();
 return 0;
 //smart Technology
}
