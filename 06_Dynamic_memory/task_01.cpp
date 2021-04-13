#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

const double DURATION_MIN_VALUE = 0;
const double DURATION_MAX_VALUE = 3;

using namespace std;

class Date {
private:
    unsigned short day;
    unsigned short month;
    unsigned short year;

    bool isLeapYear(unsigned short year) {
        return ((year % 400) || ((year % 4 == 0) && (year % 100 != 0)));
    }

    bool isValid(unsigned short day, unsigned short month, unsigned short year) {

        if(month > 12 || day > 31)
            return 0;

        unsigned short validDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if(isLeapYear(year)) {
            validDays[1]++;
        }

        if(day > validDays[month - 1])
            return 0;

        return 1;
    }

    void setDefaultValues() {
        day   = 1;
        month = 1;
        year  = 2021;
    }

public:
    Date() {
        setDefaultValues();
    }

    Date(unsigned short day, unsigned short month, unsigned short year) {

        if(!isValid(day, month, year)) {
            setDefaultValues();
        };

        this->day   = day;
        this->month = month;
        this->year  = year;
    }

    void print() const{
        cout << "Date: ";
        cout << day   << '.' 
             << month << '.'
             << year  << endl;
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    bool setDate(unsigned short day, unsigned short month, unsigned short year) {
        if(!isValid(day, month, year)) 
            return 0;
        
        this->day   = day;
        this->month = month;
        this->year  = year;
        return 1;
    }

    //*this > date  => 1
    //*this == date => 0
    //*this < date  => -1
    short compareDates(const Date& date) {

        if(year > date.year)
            return 1;
        else if(year == date.year) {
            
            if(month > date.month)
                return 1;
            else if(month == date.month) {

                if(day > date.day)
                    return 1;
                else if(day == date.day)
                    return 0;
            } 
        }

        return -1;

    }
};

class Event {
private:   
    Date   date;
    double duration;
    char*  description; 
    int    descrLen;
                                 
    void copy(const Event& other) {
        this->date = other.getDate();
        
        this->duration = other.duration;

        this->descrLen = other.descrLen;
        this->description = new char[this->descrLen + 1];
        strcpy(this->description, other.description);
    }

    void erase() {
        delete[] this->description;
    }
    
public:

    Event() {
        duration       = DURATION_MIN_VALUE;
        description    = new char[1];
        description[0] = '\0';
        descrLen       = 0;
    }
    
    Event(unsigned short day, unsigned short month, unsigned short year, double duration, const char* description) {
      
        date.setDate(day, month, year);

        if(!setDuration(duration)) {
            this->duration = DURATION_MIN_VALUE;
        }

        this->descrLen = strlen(description);
        this->description = new char[this->descrLen + 1];
        strcpy(this->description, description);
    }

    Event(const Event& other) {
        copy(other);
    }
   
    Event& operator=(const Event& other){
        if(this != &other) {
            erase();
            copy(other);
        }
        return *this;
    }

    ~Event() {
        erase();
    }
    
    Date getDate() const{
        return date;
    }

    double getDuration() const{
        return duration;
    }
    
    const char* getDescription() const{
        return this->description;
    }

    int getDescrLen() const {
        return this->descrLen;
    }

    bool setDate(unsigned short day, unsigned short month, unsigned short year) {
        return date.setDate(day, month, year);
    }

    bool setDuration(double duration) {
        if (duration < DURATION_MIN_VALUE || duration > DURATION_MAX_VALUE) {
            return false;
        }

        this->duration = duration;
        return true;
    }

    void setDescription(const char * description) {
        
        int newLength = strlen(description);

        if (newLength > this->descrLen) {
            delete[] this->description;
            this->description = new char[newLength + 1];
        }
        this->descrLen = newLength;
        strcpy(this->description, description);
    }

    void print() const{
        date.print();

        cout << "Duration: "    << duration    << endl
             << "Description: " << description << endl;

    }

    void saveEventToFile(ofstream& oFile) {
        oFile.write((const char*)&date, sizeof(Date));
        oFile.write((const char*)&duration, sizeof(double));

        oFile.write((const char*)&descrLen, sizeof(int));
        oFile.write(description, (descrLen + 1)*sizeof(char));
    }

    void readEventFromFile(ifstream& inFile) {
        inFile.read((char*)&date, sizeof(Date));
        inFile.read((char*)&duration, sizeof(double));

        inFile.read((char*)&descrLen, sizeof(int));

        erase();
        description = new char[descrLen + 1];
        inFile.read(description, (descrLen + 1)*sizeof(char));
    }
};


class Calendar {
private:
    Event* events;
    unsigned count;
    unsigned capacity;

    int getEventIndexByDescription(const char* description) {

        for (int i = 0; i < this->count; i++) {

            if (strcmp(this->events[i].getDescription(), description) == 0) {
                return i;
            }
        }
        return -1;
    }

    double getEventsDurationsByDate(const Event& newEvent) {
        double timeSpan = newEvent.getDuration();

        for(int i = 0; i < count; i++) {
            if(events[i].getDate().compareDates(newEvent.getDate()) == 0)
                timeSpan+= events[i].getDuration();
        }
        return timeSpan;
    }
      
    void resize() {

        Event* tmp = new Event[capacity*2];

        for(int i = 0; i < count; i++)
            tmp[i] = events[i];

        delete[] events;

        events = tmp;
        capacity *=2;

    }

    void copy(const Calendar& other) {
        count = other.count;
        capacity = other.capacity;
        events = new Event[capacity];
        
        for(int i = 0; i < count; i++){
            events[i] = other.events[i];
        }
    }

    void erase() {
       delete []events;
    }
public:
    
    Calendar() {
        count = 0;
        events = new Event[2];
        capacity = 2;     
    }

    Calendar(const char* filename) {
        ifstream inFile;
        inFile.open(filename, ios::binary | ios::in);

        if(!inFile.is_open()){
            cerr << "Could not open the file";
            return;
        }

        inFile.read((char*)&capacity, sizeof(unsigned));
        inFile.read((char*)&count, sizeof(unsigned));

        events = new Event[capacity];

        for(int i = 0; i < count; i++) {
            events[i].readEventFromFile(inFile);
        }

        inFile.close();
    }
    
    Calendar(const Calendar& other) {
        copy(other);
    }

    Calendar& operator=(const Calendar& other) {
        if (this != &other) {
            erase();
            copy(other);
        }
        return *this;
    }

    ~Calendar() {
        erase();
    }

    bool addEvent(const Event& newEvent) {

        if (count >= capacity) {
           resize();
        }
       
        if(getEventsDurationsByDate(newEvent) > 6) {
            cerr << "Too many events on given day" << endl;
            return 0;
        }

        events[count++] = newEvent;
        return 1;
    }

    bool changeEventDate(const char * description, unsigned short day, unsigned short month, unsigned short year) {
        int eventIndex = getEventIndexByDescription(description);

        if (eventIndex == -1) {
            cerr << "Cannot change event that isn't in the Calendar" << endl;
            return 0;
        }

        events[eventIndex].setDate(day, month, year);
    }

    bool changeEventDuration(const char * description, double duration) {
        int eventIndex = getEventIndexByDescription(description);

        if (eventIndex == -1) {
            cerr << "Cannot change event that isn't in the Calendar" << endl;
            return 0;
        }
        
        events[eventIndex].setDuration(duration);
    }

    void printEventsForDate(unsigned short day, unsigned short month, unsigned short year) {
        Date date(day, month, year);

        for(int i = 0; i < count; i++){
            if(events[i].getDate().compareDates(date) == 0) {
                events[i].print();
            }
        }
    }

    void sortByDate() {

        for (int i = 0; i < count - 1; i++) {

            int min = i;
            for (int j = i + 1; j < count; j++) {
                if (events[min].getDate().compareDates(events[j].getDate()) == 1)
                    min = j;
            }

            if (min != i) 
                swap(events[min], events[i]);
        }
    }

    void saveCalendarToFile(const char * filename) {
        ofstream oFile;
        oFile.open(filename, ios::binary | ios::out);

        if(!oFile.is_open()) {
            cerr << "Could not open the file";
            return;
        }

        oFile.write((const char*)&capacity, sizeof(unsigned));
        oFile.write((const char*)&count, sizeof(unsigned));

        for(int i = 0; i < count; i++)
            events[i].saveEventToFile(oFile);

        oFile.close();
    }
};


int main() {


    return 0;
}
