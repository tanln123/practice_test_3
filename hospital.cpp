#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private:
    int day, month, year;
public:
    Date(){}
    Date(int day, int month , int year)
        : day{day}, month{month}, year{year}
    {}

    void show_date()
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }

    int get_day()
    {
        return this->day;
    }
    int get_month()
    {
        return this->month;
    }
    int get_year()
    {
        return this->year;
    }

    void set_day(int day)
    {
        this->day = day;
    }
    void set_month(int month)
    {
        this->month = month;
    }
    void set_year(int year)
    {
        this->year = year;
    }
};

class Patient
{
private:
    string name;
    int id;
    int age;
    string disease;
    Date date_of_admission;
    Date date_of_discharge;
public:
    Patient(string name, int id, int age, string disease, Date date_of_admission, Date date_of_discharge)
        : name{name}, id{id}, age{age}, disease{disease}, date_of_admission{date_of_admission}, date_of_discharge{date_of_discharge}
    {}

    bool operator== (Patient other)
    {
        if(this->id == other.id) return true;
        return false;
    }
    string get_name()
    {
        return this->name;
    }
    int get_id()
    {
        return this->id;
    }
    int get_age()
    {
        return this->age;
    }
    string get_disease()
    {
        return this->disease;
    }
    Date get_admission()
    {
        return this->date_of_admission;
    }
    Date get_discharge()
    {
        return this->date_of_discharge;
    }

    void set_name(string name)
    {
        this->name = name;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_age(int age)
    {
        this->age = age;
    }
    void set_disease(string disease)
    {
        this->disease = disease;
    }
    void set_admission(Date date_of_admission)
    {
        this->date_of_admission = date_of_admission;
    }
    void set_discharge(Date date_of_discharge)
    {
        this->date_of_discharge = date_of_discharge;
    }

    void print_info()
    {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Disease: " << this->disease << endl;
        cout << "Admission date: ";
        date_of_admission.show_date();
        cout << "Discharge date: ";
        date_of_discharge.show_date();
    }
};

class Hospital
{
private:
    string name;
    vector <Patient> list_of_patient;
public:
    Hospital(){}
    Hospital(string name)
        :name{name}
    {}

    void add_patient(Patient patient)
    {
        list_of_patient.push_back(patient);
    }

    void remove_patient(Patient patient)
    {
        for (int i=0; i< list_of_patient.size(); i++)
        {
            if (list_of_patient[i] == patient)
            {
                list_of_patient.erase(list_of_patient.begin()+i);
            }
        }
    }

    int count_patient()
    {
        return list_of_patient.size();
    }

    void print_patient_list()
    {
        cout << "LIST OF ALL PATIENTS: " << endl;
        for (int i=0; i<list_of_patient.size(); i++)
        {
            list_of_patient[i].print_info();
            cout << endl;
        }
    }

    void print_patient_under_12_list()
    {
        cout << "LIST OF UNDER 12 PATIENTS: " << endl;
        for (int i=0; i<list_of_patient.size(); i++)
        {
            if (list_of_patient[i].get_age() < 12)
            {
                list_of_patient[i].print_info();
                cout << endl;
            }
        }
    }
};

int main(){
    Hospital hospital("Y Duoc");
    Date d1(19,5,2001);
    Date d2(20,6,2002);
    Date d3(29,12,1996);
    Date d4(6,8,1997);
    Date d5(23,4,1999);
    Date d6(18,8,2001);

    Patient p1("Tan", 1, 9, "Alzeihmer", d1, d2);
    Patient p2("Khoi", 2, 20, "Obesity", d3, d4);
    Patient p3("Khoa", 3, 11, "Gout", d5, d6);

    hospital.add_patient(p1);
    hospital.add_patient(p2);
    hospital.add_patient(p3);
    hospital.print_patient_list();
    cout << "-----------------" << endl;
    hospital.print_patient_under_12_list();
    cout << "Total number of patients: " << hospital.count_patient() << endl;

    hospital.remove_patient(p3);
    cout << "-----------------" << endl;
    cout << "AFTER REMOVING A PATIENT" << endl;
    hospital.print_patient_list();
    cout << "-----------------" << endl;
    hospital.print_patient_under_12_list();
    cout << "Total number of patients: " << hospital.count_patient();
	return 0;
}
