#include <iostream>
#include <string>
#include <fstream> //file stream

#include "habit_tracker.h" //header file

using namespace std;

Entry* create_entries(int num_entries){
    Entry* ptr = new Entry [num_entries];

    //initialize all entry values as 0
    for (int i = 0; i < num_entries - 1; i++){
        ptr[i].entry_num = 0;
        ptr[i].date = "";
        ptr[i].habit = "";
        ptr[i].good_or_bad = "";
    }

    return ptr;
}

void populate_database_data(Database &base, ifstream &file_in){
    base.num_entries = 0;
    file_in >> base.num_entries;
    
    //error correcting
    base.db = create_entries(base.num_entries);
    if (base.db == NULL){
        exit(0); //use return intstead
    }

    //loop populate_entries function for each Pokemon in input file
    for (int i = 0; i < base.num_entries; ++i){
        populate_entries(base.db[i], file_in);
        cout << base.db[i].entry_num << base.db[i].date << base.db[i].habit << base.db[i].good_or_bad << endl;
    }
}

void populate_entries(Entry &e, ifstream &file_in){
    //access data about each entry in input file
    file_in >> e.entry_num >> e.date >> e.habit >> e.good_or_bad;
}

void menu_options(Database &db, Entry &e, ofstream &file_out){
    //Display menu options
    cout << "How would you like to use the habit tracker?" << endl;
    cout << "[1] Add a new entry" << endl;
    cout << "[2] Delete an existing entry" << endl;
    cout << "[3] View all entries" << endl;
    cout << "[4] Quit" << endl;
    cout << "(Please enter a number between 1 and 4)" << endl;

    //trigger functions based on user input
    int answer;
    cin >> answer;
    if (answer == 1){
        new_entry(db, e, file_out); //add new entry
    }
    else if (answer == 2){
        delete_entry(db, file_out); //delete existing entry
    }
    else if (answer == 3){
        view_all(db); //view all entries
    }
    else if (answer == 4){
        exit(0); //quit
    }
    else {
        cout << "Error. Please pick a number between 1 and 4: ";
    }
}

void new_entry(Database &db, Entry &e, ofstream &file_out){
    file_out.open("database.txt", std::ios_base::app);
    //ask user to input new entry data
    e.entry_num = db.num_entries + 1;

    cout << "Enter date (this will help with the sorting functionality in a later update): ";
    cin >> e.date;
    cout << "Enter name of habit: ";
    cin >> e.habit;
    cout << "Is this habit one you want to maintain?: ";
    cin >> e.good_or_bad;

    //write new entry data into specified file
    file_out << endl;
    file_out << e.entry_num << " "; //entry number
    file_out << e.date << " "; //date
    file_out << e.habit << " "; //habit name
    file_out << e.good_or_bad << endl;
    db.num_entries = db.num_entries + 1;

    cout << "Entry recorded to file." << endl;
    file_out.close();
    
    return;
}

void delete_entry(Database &base, ofstream &file_out){
    view_all(base);

    cout << "Please select entry number to delete:";
    int answer;
    cin >> answer;

    //are you sure?
    cout << "Are you sure that you want to delete entry number " << answer << "? (y/n) ";
    string yesNo;
    cin >> yesNo;

    if (yesNo == "y" || yesNo == "Y"){
        file_out.open("database.txt", std::ofstream::out | std::ofstream::trunc);
        
        file_out << base.num_entries - 1 << endl;

        for (int i = 0; i < base.num_entries; ++i){
            if(base.db[i].entry_num != answer){
                //write new entry data into specified file
                file_out << base.db[i].entry_num << " "; //entry number
                file_out << base.db[i].date << " "; //date
                file_out << base.db[i].habit << " "; //habit name
                file_out << base.db[i].good_or_bad << endl;
            }
        }
        cout << "Entry number " << answer << " successfully deleted." << endl;
    }
    else {
        exit(0);
    }
    
    file_out.close();
}

void view_all(Database &base){
    //display entry data into console/terminal
    for (int i = 0; i < base.num_entries; ++i){
        cout << "-----------------" << endl;
        cout << "Entry number: " << base.db[i].entry_num << endl;
        cout << "Date: " << base.db[i].date << endl;
        cout << "Habit name: " << base.db[i].habit << endl;
        cout << "Maintain habit?: " << base.db[i].good_or_bad << endl;
        cout << endl;
    }
}

int main(){
    ifstream file_in;
    file_in.open("database.txt");

    //check if the file opens successfully
    if (!file_in.is_open()){
        cout << "Error opening input file!" << endl;
        exit(0); //use return instead
    }
    else {
        cout << "File opened successfully!" << endl << endl;
    }

    Database db;

    populate_database_data(db, file_in);

    file_in.close();

    ofstream file_out;
    Entry e;

    menu_options(db, e, file_out);
}