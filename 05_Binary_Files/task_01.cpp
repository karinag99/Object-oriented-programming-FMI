#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

const unsigned MAX_DESCR_SIZE = 129;
const unsigned MAX_EVENTS     = 50;

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

    bool setDay(unsigned short day) {
        if(!isValid(day, this->month, this->year)) 
            return 0;
        
        this->day = day;
        return 1;
    }

    bool setMonth(unsigned short month) {
        if(!isValid(this->day, month, this->year)) 
            return 0;
        
        this->month = month;
        return 1;
    }

    bool setYear(unsigned short year) {
        if(!isValid(this->day, this->month, year)) 
            return 0;
        
        this->year = year;
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
    char   description[MAX_DESCR_SIZE]; 

public:

    Event() {
        duration = 0;
        description[0] = '\0';
    }

    Event(unsigned short day, unsigned short month, unsigned short year, double duration, const char* description) {
        date.setDay(day);
        date.setMonth(month);
        date.setYear(year);

        this->duration = duration;
        strcpy(this->description, description);
    }

    void print() const{
        date.print();

        cout << "Duration: "    << duration    << endl
             << "Description: " << description << endl;

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

    bool changeDate(unsigned short day, unsigned short month, unsigned short year) {
        return (date.setDay(day) && date.setMonth(month) && date.setYear(year));
    }

    bool setDuration(double duration) {
        if (duration < 0 || duration > 3) {
            return false;
        }

        this->duration = duration;
        return true;
    }

    void setDescription(const char * description) {
        strcpy(this->description, description);
    }
};

class Calendar {
private:
    Event          events[MAX_EVENTS];
    unsigned short eventsCount;

    int getEventIndexByDescription(const char* description) {

        for (int i = 0; i < this->eventsCount; i++) {

            if (strcmp(this->events[i].getDescription(), description) == 0) {
                return i;
            }
        }
        return -1;
    }

    double getEventsDurationsByDate(const Event& newEvent) {
        double timeSpan = newEvent.getDuration();

        for(int i = 0; i < eventsCount; i++) {
            if(events[i].getDate().compareDates(newEvent.getDate()) == 0)
                timeSpan+= events[i].getDuration();
        }
        return timeSpan;
    }

public:
    Calendar() {
        eventsCount = 0;
    }

    Calendar(const char* filename) {
        ifstream inFile;
        inFile.open(filename, ios::binary | ios::in);

        if(!inFile.is_open()){
            cerr << "Could not open the file";
            return;
        }

        inFile.read((char*)this,sizeof(Calendar));
        inFile.close();
    }

    bool addEvent(const Event& newEvent) {

        if(eventsCount == 50) {
            cerr << "Too many events already" << endl;
            return 0;
        }
    
        if(getEventsDurationsByDate(newEvent) > 6) {
            cerr << "Too many events on given day" << endl;
            return 0;
        }

        events[eventsCount++] = newEvent;
        return 1;
    }

    bool changeEventDate(const char * description, unsigned short day, unsigned short month, unsigned short year) {
        int eventIndex = getEventIndexByDescription(description);

        if (eventIndex == -1) {
            cerr << "Cannot change event that isn't in the Calendar" << endl;
            return 0;
        }

        events[eventIndex].setDescription(description);
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

        for(int i = 0; i < eventsCount; i++){
            if(events[i].getDate().compareDates(date) == 0) {
                events[i].print();
            }
        }
    }

    void sortByDate() {

        for (int i = 0; i < eventsCount - 1; i++) {

            int min = i;
            for (int j = i + 1; j < eventsCount; j++) {
                if (events[min].getDate().compareDates(events[j].getDate()) == 1)
                    min = j;
            }

            if (min != i) 
                swap(events[min], events[i]);
        }
    }

    void saveToFile(const char * filename) {
        ofstream oFile;
        oFile.open(filename, ios::binary | ios::out);

        if(!oFile.is_open()) {
            cerr << "Could not open the file";
            return;
        }

        oFile.write((const char*)this, sizeof(Calendar));
        oFile.close();
    }
};

void printOddObjects(const char* filename) {
    ifstream inFile;
    inFile.open(filename,ios::binary | ios::in);
  
    if(!inFile.is_open()) {
        cerr << "Could not open file" << endl;
        return;
    }
  
    inFile.seekg(0,ios::beg);
    Event temp;
  
    while(inFile.good()) {
  
        inFile.read((char *)&temp, sizeof(Event));

        if(inFile.good()) {
            temp.print();
        }
  
        inFile.seekg(sizeof(Event), ios::cur);  
    }

  inFile.close();
}


int main() {

    return 0;
}

