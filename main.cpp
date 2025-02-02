#include <iostream>
#include <vector>
#include<queue>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const string SPLITTER = ",";
void ShowMenu(std :: vector <std:: string> &options){
    for(int i = 1; i <= (int)options.size(); ++i){
        std :: cout << "    " << i << ". " << options[i] << "\n";
    }
}
int menu(std :: vector <std :: string> options){
    int choice = -1;
    ShowMenu(options);
    std :: cout << "\nEnter your choice from " << 1 << " to "<< options.size() << " : \n";
    while(choice == -1){
        std :: cout << "Invalid Choice!";
        std :: cout << "\nEnter your choice from " << 1 << " to "<< options.size() << " : \n";
    }
    return choice;
}
vector<string> SplitString(string line, string splitter = ","){
    string datum = "";
    vector <string> result;
    for(auto c : line){
        if(c == splitter[0]){
            result.push_back(datum);
            datum = "";
        }
        else
        datum += string(1, c);
    }
    return result;
}
int ToInt(string num){
    int n = 0;
    for(auto c : num){
        n = 10 * n + (c - '0');
    }
    return n;
}
struct Full_name{
    std :: string f_name, middle_name, l_name;
    void display(){
        std :: cout << f_name << " " << middle_name << " " << l_name << "\n";  
    }
    Full_name(){
        f_name = middle_name = l_name = "";
    }
    Full_name(vector<string> v){
        f_name = v[0]; middle_name = v[1]; l_name = v[2];
    }
    void read_name(){
        std :: cout << "Enter your first name: ";
        cin >> f_name;
        std :: cout << "Enter your second name: ";
        cin >> middle_name;
        std :: cout << "Enter your last name: ";
        cin >> l_name;
    }
    string ToString(){
        return f_name + SPLITTER + middle_name + SPLITTER + l_name;
    }
};
struct Date{
    int day, month, year;
    void display(){
        std :: cout << day << " / " << month << " / " << year;
    }
    string ToString(){
        return to_string(day) + SPLITTER + to_string(month) + SPLITTER + to_string(year);
    }
    Date(){
        day = month = year = 0;
    }
    Date(vector<string> v){
        day = ToInt(v[0]);
        month = ToInt(v[1]);
        year = ToInt(v[2]);
    }
};
enum Week_day{
    Saturday,Sunday,Monday,Tuesday, Wednesday, Thursday, Friday
};
struct Week{
    Week_day day;
    Week(int d){
        day = Week_day(d);
    }
    string ToString(){
    switch (day)
    {
    case 0 : return "Saturday";
    case 1 : return "Sunday";
    case 2 : return "Monday";
    case 3 : return "Tuesday";
    case 4 : return "Wednesday";
    case 5 : return "Thursday";
    case 6 : return "Friday";
    default:
        break;
    }
}
};
enum gender_type{
    Male,
    Female
};
struct Gender{
    gender_type type;
    string ToString(){
        if(type == Male)
        return "Male";
        else 
        return "Female";
    }

};
enum specialization_enum{
    Neurology_clinic, Cardiology, Ear_Nose_Throat, Eyes, Orthopedic, Dental_clinic
};
struct Specialization{
    specialization_enum type;
    string ToString(){
        switch (type)
        {
            case 0 : return "Neurology_clinic";
            case 1 : return "Cardiology";
            case 2 : return "Ear_Nose_Throat";
            case 3 : return "Eyes";
            case 4 : return "Orthopedic";
            case 5 : return "Dental_clinic";
            default: break;
        }
    }
};
struct User{
    Full_name name;
    int age;
    Gender gender; 
    int id;
    void read_person(){
        name.read_name();
        cout << "Enter your age: ";
        cin >> age;
        gender.type = gender_type(menu({"Male", "Female"}) - 1);
    };
    void Display(){
        std :: cout << " Name:\t";
        name.display();
        std :: cout << "ID:\t" << id << "\n";
        std :: cout << " Age:\t";
        std :: cout << age << "\n";
        std :: cout << "Gender:\t";
        std :: cout << gender.ToString();
        std :: cout << "\n"; 
    }
    string ToStringUser(){
        return name.ToString() + SPLITTER + to_string(age) + SPLITTER + gender.ToString() + SPLITTER + to_string(id);
    }
};
struct Time{
    int hour, min;
    void display(){
        std :: cout << hour << " : " << min ;
    }
    string ToString(){
        return to_string(hour) + SPLITTER + to_string(min); 
    }
};
// in the future
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
    std :: vector <time_slot> schedules; // in the future
    void add_shedule(){} 
    void display(){
        Display();
        std :: cout << "Specialization:\t" << specialization.ToString() <<"\nAvailable at schedules:\n"; 
    }
    string ToString(){
        return ToStringUser() + SPLITTER + specialization.ToString() ; 
    }
};
struct appointment{
    Patient* patient;
    Doctor* doctor;
    std :: string ailment;
    Date date;
    Time time;
    int id;
    bool cancelled = 0;
    appointment(){
        date = Date();
        time = Time();
    }
    appointment(Patient &_patient, Doctor& _doctor, string _ailment, Date _date, Time _time){
        patient = &_patient;
        doctor = &_doctor;
        ailment = _ailment;
        date = _date;
        time = _time;
    }
    void display(){
        if(cancelled){
            std :: cout << "Cancelled\n";
            return;
        }
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
    string ToString(){
        return patient->phone_number + SPLITTER + doctor->name.ToString() + SPLITTER + ailment + SPLITTER + date.ToString() + SPLITTER + time.ToString(); 
    }
};
struct Patient : User{
    std :: string  phone_number;
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
    string ToString(){
        ostringstream oss(ToStringUser() + SPLITTER + phone_number+ SPLITTER);
        for(auto app : history){
            oss << app.ToString() + SPLITTER ;
        }
        return oss.str();
    }
};
struct PatientsManager{
    map <string, Patient> Patients_by_phone_number_map;
    int last_id = 0;
    string read(){
        std :: cout << "Enter the patient's phone number: \t";
        string phone;
        cin >> phone;
        if(Patients_by_phone_number_map.count(phone)){
            cout << "Welcome, ";
            Patients_by_phone_number_map[phone].name.display();
        }
        else{
            Patient temp;
            temp.phone_number = phone;
            temp.id = ++last_id;
            temp.read_person();
            Patients_by_phone_number_map[phone] = temp;
        }
        return phone;
    }
    void search_app_by_history(){
        cout << "Enter the phone number you booked with:\n";
        string phone_number;
        cin >> phone_number;
        if(Patients_by_phone_number_map.count(phone_number)){
            auto &h = Patients_by_phone_number_map[phone_number].history;
            for(auto app = h.crbegin(); app <h.crend(); ++app){
                appointment a = *app;
                a.display();
            }
        }
    }
    void LoadDataBase(){}
    void WriteDataBase(){}
};
struct DoctorsManagers{
    std :: map <std ::string, Doctor> NameDoctorsMap;
    std :: map <int, vector<string>> spec_doctors_map;
    Specialization read_specialization(){
        
    }
    void LoadDataBase(){}
    void WriteDataBase(){}
    string help_find_doctor(){
        cout << "Enter Specialization: \n";
        Specialization spec;
        spec.type = specialization_enum(menu({"Neurology_clinic", "Cardiology", "Ear_Nose_Throat", "Eyes", "Orthopedic", "Dental_clinic"}) - 1);
        if(int sz = spec_doctors_map[spec.type].size()){
            cout << "There is " << sz << "in this Specialization:\n";
            int idx = menu(spec_doctors_map[spec.type]);
            return spec_doctors_map[spec.type][idx - 1];
        }
        else{
            cout << "Sorry, there is no available doctors in this specialization until now\n";
            return ""; 
        }
    }
    string book(){
        string name;
        cin >> name;
        bool help;
        if(!NameDoctorsMap.count(name)){
            cout << "This name is not existed!\nCan I help you (0, 1)?\n";
            cin >> help;
            if(!help){
                return "";
            }
            else{
                return help_find_doctor() ;
            }
        }
    }
};
struct Time_slot_Handler{
    
    bool comp_slots(time_slot first, time_slot second){
        return first.day < second.day;
    }
    void Handle(std :: vector <time_slot>* times){
        sort(times->begin(), times->end(), comp_slots);
        
    }
};
struct AppointmentSchedular{
    map<const Doctor*, queue<appointment*>> appointments_queues;
    map<string, appointment> IdAppointmentMap;
    int last_id = 0;
    void LoadDataBase(){}
    void WriteDataBase(){}
    void MakeAppointment(Doctor &doctor, Patient &patient, Date date, Time time){
        string ailment;
        cout << "Enter Patient's element: ";
        cin >> ailment;
        appointment app = appointment( patient, doctor, ailment, date, time);
        app.id = ++last_id;
        appointments_queues[&doctor].push(&app);
        patient.history.push_back(app);
    }
    void Display_Patients_turn(Doctor &doc){
        queue <appointment*> &q =  (appointments_queues[&doc]);
                            while(true){
                                if(q.empty()){
                                    cout << "\t\tNo appointments to view\n";
                                    break;
                                }
                                else{
                                    if(q.front()->cancelled == 1){
                                        q.front() = nullptr;
                                        q.pop();
                                        continue;
                                    }
                                    cout << "\t\tAppointment ID: " << q.front()->id << "\n\t\tPatient Name: ";
                                    q.front()->patient->name.display();
                                    break;
                                }

                            }
    } 
    
};
struct HospitalSystem{
    PatientsManager patient_manager;
    DoctorsManagers doctors_manager;
    AppointmentSchedular schedular;
    Time_slot_Handler handler;
    Date date;
    Time time;
    void run(){
        while(true){
            int choice = menu({"Add Appointment", "View Appointment", "Cancel Appointment", "Exit"});
            if(choice == 1)
            {
            
            string name = doctors_manager.book();
                if(name != ""){
                    Doctor &doctor = doctors_manager.NameDoctorsMap[name];
                    Patient &patient = patient_manager.Patients_by_phone_number_map[patient_manager.read()];
                    schedular.MakeAppointment(doctor, patient, date, time);
                }
                else
                continue;
            }
            else if(choice == 2){
                for(auto spec : {0, 1, 2, 3, 4, 5}){
                    vector<string> v = doctors_manager.spec_doctors_map[specialization_enum(spec)];
                    if(!v.empty()){
                        cout << "Specialization " << spec + 1 << " :\n";
                        for(int i = 0; i < (int)v.size(); ++i){
                            cout << "\t" << i + 1<< ". " << v[i] << "\n";
                            schedular.Display_Patients_turn(doctors_manager.NameDoctorsMap[v[i]]);
                        }
                    }
                }
                bool search_app = false;
                cout << "\nWant to search appointment:(0, 1)?\n";
                cin >> search_app;
                if(search_app){
                   patient_manager.search_app_by_history(); 
                }
            }
            else if(choice == 3){
                cout << "Enter appointment id: \n";
                string id;
                cin >> id;
                if (schedular.IdAppointmentMap.count(id)){
                    cout << "Are you sure?(0 for sure, 1 for not)\n";
                    bool NotSure = 1;
                    cin >> NotSure;
                    if(!NotSure){
                        schedular.IdAppointmentMap[id].cancelled = true;
                    }
                    else
                    continue;
                }
                else{
                    cout << "This ID is not existed in the system.\nCan I help you?\n";
                    bool want_help = 1;
                    cin >> want_help;
                    if(want_help){
                        patient_manager.search_app_by_history(); 
                    }
                }
            }
        }
    }
};

int main(){
    HospitalSystem hospital;
    hospital.run();
    return 0;
}
