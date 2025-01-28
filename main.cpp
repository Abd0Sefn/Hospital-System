#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void ShowMenu(std :: vector <std:: string> options){
    for(int i = 1; i <= (int)options.size(); ++i){
        std :: cout << "    " << i << ". " << options[i] << "\n";
    }
}
struct Full_name{
    std :: string f_name, middle_name, l_name;
    void display(){
        std :: cout << f_name << " " << middle_name << " " << l_name << "\n";  
    }
};
struct Date{
    int day, month, year;
    void display(){
        std :: cout << day << " / " << month << " / " << year;
    }
};
enum Week_day{
    Saturday,Sunday,Monday,Tuesday, Wednesday, Thursday, Friday 
};
enum Gender{
    Male,
    Female
};
enum Specialization{
    Neurology_clinic, Cardiology, Ear_Nose_Throat, Eyes, Orthopedic, Dental_clinic
};
struct User{
    Full_name name;
    int age;
    Gender gender; 
    int id;
    void Display(){
        std :: cout << " Name:\t";
        name.display();
        std :: cout << "ID:\t" << id << "\n";
        std :: cout << " Age:\t";
        std :: cout << age << "\n";
        std :: cout << "Gender:\t";
         if(gender)std :: cout << "Female";
         else std :: cout << "Male";
         std :: cout << "\n"; 
    }
};
struct Time{
    int hour, min;
    void display(){
        std :: cout << hour << " : " << min ;
    }
};
struct time_slot{
    std :: vector<pair<Time, Time>> slots ;
    Week_day day;
    void display(){
        std :: cout << "Day: " << day << "\n" ;
        for(auto slot : slots){
            std :: cout << " from " ;
            slot.first.display();
            std :: cout << " to ";
            slot.second.display();
            std :: cout << "\n";

        }
        
    }
};
struct Doctor : User{
    Specialization specialization;
    std :: vector <time_slot> schedules;
    void add_shedule(){} 
    void display(){
        Display();
        std :: cout << "Specialization:\t" << specialization <<"\nAvailable at schedules:\n"; 
    }
};
struct appointment{
    Patient* patient;
    Doctor* doctor;
    std :: string ailment;
    Date date;
    Time time;
    int id;
    void display(){
        cout << "\n Patient info:\n";
        patient->Display();
        cout << "\n Doctor info:\n";
        doctor->Display();
        cout << "\n ailment:\t" << ailment << "\n";
        std :: cout << "\n Date:\t";
        date.display();
        cout << "\n";
        std :: cout << "\n Time:\t";
        time.display();
        cout << "\n";
    }
};
struct Patient : User{
    std :: string patient_id;
    std :: string ailment;
    std :: vector <appointment> history;
    bool add_ailment(){}
    void display(){
        Display();
        if(!history.empty()){
            std :: cout << "\n Patient history:\n";
            for(appointment app : history){
                app.display();
                cout << "\n";
            }
        }
    }
};
struct PatientsManager{};
struct DoctorsManagers{};
struct Time_slot_Handler{
    bool comp_slots(time_slot first, time_slot second){
        return first.day < second.day;
    }
    void Handle(std :: vector <time_slot>* times){
        sort(times->begin(), times->end(), comp_slots);
    }
};
struct AppointmentSchedular{};
struct HospitalSystem{
    vector <Doctor> Doctors;
    vector <Patient> Patients;
};

int main(){
    HospitalSystem hospital;
}
