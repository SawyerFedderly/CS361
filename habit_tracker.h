#ifndef HABIT_TRACKER_H
#define HABIT_TRACKER_H

#include <iostream>
#include <string>
#include <fstream> //file stream

using namespace std;


//Structs:
struct Entry {
    int entry_num;
    string date;
    string habit;
    string good_or_bad;
};

struct Database {
    string user;
    int num_entries;
    Entry* db;
};


//Function prototypes:
Entry* create_entries(int num_entries);
void populate_database_data(Database &base, ifstream &file_in);
void populate_entries(Entry &e, ifstream &file_in);
void menu_options(Database &db, Entry &e, ofstream &file_out);
void new_entry(Database &db, Entry &e, ofstream &file_out);
void delete_entry(Database &base, ofstream &file_out);
void view_all(Database &base);
int main();


#endif