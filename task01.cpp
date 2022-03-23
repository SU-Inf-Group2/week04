#include <iostream>
#include <fstream>

using namespace std;

const size_t NAME_SIZE = 32;
const size_t EMAIL_SIZE = 128;

struct Student
{
    char name[NAME_SIZE];
    long fac_number;
    char email[EMAIL_SIZE];
};

void write_to_file(Student* students, ofstream& out)
{
    for(size_t i = 0; i < 3; i++)
    {
        out.write((char*)&students[i], sizeof(Student));
    }
}

void read_from_file(Student* students, ifstream& in)
{
    for(size_t i = 0; i < 3; i++)
    {
        in.read((char*)&students[i], sizeof(Student));
    }
}

int main()
{
    Student students[3] =
    {
        {"Ivan", 11234, "ivan@abv.bg"},
        {"Petar", 47342, "pesho@gmail.bg"},
        {"Georgi", 00002, "gosho@fmi-uni.bg"}
    };

    ofstream table_out("students_table.bin", ios::binary);
    if(!table_out.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }

    write_to_file(students, table_out);
    table_out.close();

    ifstream table_in("students_table.bin", ios::binary);
    if(!table_in.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }

    read_from_file(students, table_in);
    table_in.close();

    for(int i = 0; i < 3; i++)
    {
        cout << "Student "<< i+1 << " name: ";
        cout << students[i].name << endl;
        cout << "Student "<< i+1 << " faculty number: ";
        cout << students[i].fac_number << endl;
        cout << "Student "<< i+1 << " email: ";
        cout << students[i].email << endl;
        cout << endl;
    }
}
