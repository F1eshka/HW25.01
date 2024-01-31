#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Date {
    unsigned short day;
    unsigned short month;
    long long year;
public:
    Date() : Date(23, 12, 2023) {}

    Date(unsigned short day, unsigned short month, long long year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }
    //Делегирование
    Date(unsigned short day, unsigned short month) : Date(day, month, 2005) {}


    void PrintDate() const
    {
        cout << day << "." << month << "." << year << "\n";
    }
    //day SetGet
    void SetDay(unsigned short day)
    {
        if (day == 0 || day > 31) throw "ERROR!!! The day must be from 0 to 31 !!!";
        this->day = day;
    }
    unsigned short GetDay() const
    {
        return day;
    }
    //month SetGet
    void SetMonth(unsigned short month)
    {
        if (month == 0 || month > 12) throw "ERROR!!! The day must be from 1 to 12 !!!";
        this->month = month;
    }
    unsigned short GetMonth() const
    {
        return month;
    }
    //year SetGet
    void SetYear(long long year)
    {
        this->year = year;
    }
    long long GetYear() const
    {
        return year;
    }
};

class Student {
private:
    string surname;
    string name;
    string middlename;
    string adress;
    string phonenumber;
    unsigned int countpractic = 0;
    unsigned int counthomework = 0;
    unsigned int countexam = 0;
    int* grade_of_practic = new int[countpractic];
    int* grade_of_homework = new int[counthomework];
    int* grade_of_exam = new int[countexam];

public:
    // сигнатура конструктора копирования
    Student(const Student& original)
    {
        cout << "COPY C-TOR\n";

        this->surname = original.surname;
        this->name = original.name;
        this->middlename = original.middlename;
        this->adress = original.adress;
        this->phonenumber = original.phonenumber;
        this->countpractic = original.countpractic;
        this->counthomework = original.counthomework;
        this->countexam = original.countexam;


        this->grade_of_practic = new int[original.countpractic];
        for (int i = 0; i < countpractic; i++)
        {
            this->grade_of_practic[i] = original.grade_of_practic[i];
        }

        this->grade_of_homework = new int[original.counthomework];
        for (int i = 0; i < counthomework; i++)
        {
            this->grade_of_homework[i] = original.grade_of_homework[i];
        }

        this->grade_of_exam = new int[original.countexam];
        for (int i = 0; i < countexam; i++)
        {
            this->grade_of_exam[i] = original.grade_of_exam[i];
        }
    }

    Student() : Student("Studenchenko", "Student", "Studentovich", "Studencheskaya 38", "0630300033") {}

    Student(string surname, string name, string middlname, string adress, string phonenumber)
    {
        cout << "MAIN C-TOR\n";
        SetSurname(surname);
        SetName(name);
        SetMiddlName(middlname);
        SetAdress(adress);
        SetPhone(phonenumber);
    }
    Student(string surname, string name, string middlname, string adress) :Student(surname, name, middlename, adress, "0687680685") {}

    ~Student()
    {
        cout << "DESTRUCTOR\n";
        if (grade_of_practic != nullptr)
            delete[] grade_of_practic;
        if (grade_of_homework != nullptr)
            delete[] grade_of_homework;
        if (grade_of_exam != nullptr)
            delete[] grade_of_exam;
    }

    void PrintStudent() const
    {
        cout << "Surname: " << surname << "\n";
        cout << "Name: " << name << "\n";
        cout << "Midlname: " << middlename << "\n";
        cout << "Adress: " << adress << "\n";
        cout << "Phonnumber: " << phonenumber << "\n";
    }

    void AddPractic(int newcountry)
    {
        int* temp = new int[countpractic + 1];
        for (int i = 0; i < countpractic; i++)
        {
            temp[i] = grade_of_practic[i];
        }

        temp[countpractic] = newcountry;
        countpractic++;
        delete[]grade_of_practic;
        grade_of_practic = temp;
    }

    void PrintPractic() const
    {
        for (int i = 0; i < countpractic; i++)
        {
            cout << grade_of_practic[i] << ", ";
        }
    }

    int GePracticRatesCount(unsigned int index) const
    {
        if (index < countpractic)
        {
            return grade_of_practic[index];
        }
    }

    void AddHomeWork(int newcountry)
    {
        int* temp = new int[counthomework + 1];
        for (int i = 0; i < counthomework; i++)
        {
            temp[i] = grade_of_homework[i];
        }
        temp[counthomework] = newcountry;
        counthomework++;
        delete[]grade_of_homework;
        grade_of_homework = temp;
    }

    void PrintHomeWork() const
    {
        for (int i = 0; i < counthomework; i++)
        {
            cout << grade_of_homework[i] << ", ";
        }
    }

    int GetHomeWorkRatesCount(unsigned int index) const
    {
        if (index < counthomework)
        {
            return grade_of_homework[index];
        }
    }

    void AddExam(int newcountry)
    {
        int* temp = new int[countexam + 1];
        for (int i = 0; i < countexam; i++)
        {
            temp[i] = grade_of_exam[i];
        }
        temp[countexam] = newcountry;
        countexam++;
        delete[]grade_of_exam;
        grade_of_exam = temp;
    }

    void PrintExam() const
    {
        for (int i = 0; i < countexam; i++)
        {
            cout << grade_of_exam[i] << ", ";
        }
    }

    int GetExamRatesCount(unsigned int index) const
    {
        if (index < countexam)
        {
            return grade_of_exam[index];
        }
    }

    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    string GetSurname() const
    {
        return surname;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    string GetName() const
    {
        return name;
    }

    void SetMiddlName(string middlname)
    {
        this->middlename = middlname;
    }

    string GetMiddlName() const
    {
        return middlename;
    }

    void SetAdress(string adress)
    {
        this->adress = adress;
    }

    string GetAdress() const
    {
        return adress;
    }

    void SetPhone(string phonenumber)
    {
        this->phonenumber = phonenumber;
    }

    string GetPhone() const
    {
        return phonenumber;
    }
};

void GoToPeresdacha(Student s)
{
    cout << "hey hey peresdacha...\n";
}

class Group {
private:
    Student** students;
    int size;
    string groupName;
    string specialization;
    int course;

public:
    Group() : students(nullptr), size(0), groupName("Unknown"), specialization("Unknown"), course(0) {}

    Group(const Group& other) : size(other.size), groupName(other.groupName), specialization(other.specialization), course(other.course) {
        students = new Student * [size];
        for (int i = 0; i < size; ++i) {
            students[i] = new Student(*(other.students[i]));
        }
    }

    ~Group() {
        for (int i = 0; i < size; ++i) {
            delete students[i];
        }
        delete[] students;
    }

    void SetGroupName(const string& name) {
        groupName = name;
    }

    string GetGroupName() const {
        return groupName;
    }

    void SetSpecialization(const string& spec) {
        specialization = spec;
    }

    string GetSpecialization() const {
        return specialization;
    }

    void SetCourse(int c) {
        course = c;
    }

    int GetCourse() const {
        return course;
    }

    void AddStudent(const Student& newStudent) {
        Student** temp = new Student * [size + 1];
        for (int i = 0; i < size; ++i) {
            temp[i] = students[i];
        }
        temp[size] = new Student(newStudent);
        ++size;

        delete[] students;
        students = temp;
    }

    void PrintAllStudents() const {
        for (int i = 0; i < size; ++i) {
            students[i]->PrintStudent();
        }
    }
};

int main()
{
    int x = 10; // создание оригинала примитивного типа
    int y(x); // int y = x; // создание копии на основе оригинала

    Student original;
    original.AddExam(2);
    original.AddExam(2);
    original.AddExam(2);
    original.PrintStudent();
    original.PrintExam();

    Student copy = original;

    GoToPeresdacha(original);

    Group group1;
    group1.SetGroupName("Group П26");
    group1.SetSpecialization("Computer science");
    group1.SetCourse(1);

    Student student1;
    student1.SetName("Vanya");
    student1.AddExam(3);
    student1.AddExam(4);
    student1.AddExam(5);

    Student student2;
    student2.SetName("Alexander");
    student2.AddExam(4);
    student2.AddExam(5);
    student2.AddExam(3);

    group1.AddStudent(student1);
    group1.AddStudent(student2);

    Group group2 = group1;  // создаем копию группы

    // Выводим информацию о студентах в обеих группах
    cout << "Group 1:\n";
    group1.PrintAllStudents();

    cout << "\nGroup 2 (copy of Group 1):\n";
    group2.PrintAllStudents();

    return 0;
}

