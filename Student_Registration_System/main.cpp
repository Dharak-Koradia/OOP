#include "student.hpp"

// function prototypes
void mainMenu(vector<Student>&);
int findStudent(vector<Student>&, int);
void studentMenu(vector<Student>&, int);


// global variable
int ID_num = 1001;

int main()
{

    vector <Student> students;
    mainMenu(students);




    /*
    // Tested the Course class
    Course cls;
    cls.setCourseID();
    cls.setCredits();
    cls.setGrade();

    cout << "\nCourse ID: " << cls.getCourseID();
    cout << "\nCredits: " << cls.getCredits();
    cout << "\nGrade: " << cls.getGrade();
    */


   /*
   // TEST THE STUDENT CLASS (step 2)
   Student obj;
   obj.setName();
   obj.setStudID();
   obj.addCourse();

   cout << "\n\nGPA from main(): " << fixed << setprecision(2) << obj.getGPA() << "\n\n";
   obj.printTranscript();
   */

    /*
    int a  = ID_num++;

    cout << "a: " << a;
    cout << "\nID_num after: " << ID_num;

    */



    cout << "\n\n";
    return 0;
}


void mainMenu(vector <Student>& studs)
{
    int choice;
    cout << "\n\nMAIN MENU" 
        << "\n1 - Register a new student"
        << "\n2 - Returning student"
        << "\n3 - Quit"
        << "\nEnter choice: ";
    cin >> choice;
    while (choice < 1 || choice > 3)
    {
        cout << "\nInvalid choice, please re-enter: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        // Register a new student
        string name;

        cout << "\nPlease enter your name: ";
        cin.ignore();
        getline(cin, name);
        while (name.empty())
        {
            cout << "Name can't be empty, please re-enter: ";
            getline(cin, name);
        }

        Student stud;
        stud.setName(name);
        stud.setStudID(ID_num++);

        cout << name << " you are registered!  Student ID number is " << stud.getStudID() << ".\n";

        // Add a student to the vector
        studs.push_back(stud);

        // call the mainMenu again
        mainMenu(studs);
    }
    else if (choice == 2)
    {
        // Returning student
        int ID, check;
        cout << "\nPlease enter your student ID number: ";
        cin >> ID;
        check = findStudent(studs, ID);
        if (check == -1)
        {
            cout << "\nSorry, no student with ID " << ID << " is registered.\n";
            mainMenu(studs);
        }
        else
        {
            cout << "\n------------------------------------------" 
                << "\nWelcome " << studs.at(check).getName() << "!"
                << "\n------------------------------------------\n\n";
            studentMenu(studs, check);
            // once the studentMenu functions ends, it'll call mainMenu again, OR you can call the mainMenu from here
            // when user enter the choice 4, call the mainMenu() function again
        }
    }
    else
    {
        cout << "\n****************"
            << "\n****************"
            << "\nGoodbye!!!"
            << "\n****************"
            << "\n****************\n";
    }
    
    
}



void studentMenu(vector<Student>& studs, int position)
{
    
    int choice;
    cout << "\nSTUDENT MENU"
        << "\n1 - Add class"
        << "\n2 - Check GPA"
        << "\n3 - Print transcript"
        << "\n4 - Quit"
        << "\nEnter choice: ";
    cin >> choice;

    // validate the choice
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid choice, please re-enter: ";
        cin >> choice;
    }


    if (choice == 1)  // Add a Course
    {
        // addCourse function in the Student class will create a Course object and then add it
        // to the "courses" vector (private) attribute of the Student class
        studs.at(position).addCourse();
        studentMenu(studs, position);
    }
    else if (choice == 2)   // check GPA
    {
        if (studs.at(position).getCoursesSize() == 0)
        {
            cout << "\n-----------------------------" 
                << "\nYou have no courses."
                << "\n-----------------------------\n";
            studentMenu(studs, position);
        }
        else
        {
            double GPA = studs.at(position).getGPA();
            cout << "\nGPA: " << fixed << setprecision(2) << GPA << "\n";
            studentMenu(studs, position);
        }        
    }
    else if (choice == 3)  // print Transcript
    {
        if (studs.at(position).getCoursesSize() == 0)
        {

            cout << "\n-----------------------------"
                << "\nYou have no courses."
                << "\n-----------------------------\n";
            studentMenu(studs, position);
        }
        else
        {
            studs.at(position).printTranscript();
            studentMenu(studs, position);
        } 
    }
    else  // if (choice == 4), then Quit the student menu and go to the mainMenu
    {
        cout << "\nGoodbye " << studs.at(position).getName() << "!\n";
        mainMenu(studs);
    }

}



int findStudent(vector<Student>& studs, int stud_ID)
{
    for (int i = 0; i < studs.size(); i++)
    {
        if (studs.at(i).getStudID() == stud_ID)
            return i;
    }

    return -1;
}