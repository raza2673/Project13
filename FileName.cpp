#include <iostream>
#include<string>
#include <limits>
using namespace std;

const int NUM_BOOKS = 6;

struct Book {
    string title;
    string author;
    int publish_year;
    bool genre;  
};

Book books[NUM_BOOKS];
Book non_fiction[NUM_BOOKS];
Book fiction[NUM_BOOKS];


void get_book_details();
void cat_books();
void old_book();

int main() {
    get_book_details();
    cat_books();
    old_book();
}

void get_book_details() {
    for (int i = 0; i < NUM_BOOKS; ++i) {
        cout << "\nEnter Book Details : ";

        cout << "\n\t\t\t>  Book Title  : ";
        getline(cin, books[i].title);

        cout << "\n\t\t\t>  Author Name : ";
        getline(cin, books[i].author);

        cout << "\n\t\t\t>  Publish Year: ";
        do {
            if (cin >> books[i].publish_year) {
                break;
            }
            else {
                cout << "Invalid input. Please enter a valid year.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (true);

        cout << "\n\t\t\t>  1-Fiction";
        cout << "\n\t\t\t>  2-Non_fiction";
        char genre;
        do {
            genre = getchar();
            if (genre == '1') {
                books[i].genre = true;
            }
            else if (genre == '2') {
                books[i].genre = false;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (genre != '1' && genre != '2');
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void cat_books() {
    int a = 0, b = 0;
    for (int i = 0; i < NUM_BOOKS; ++i) {
        if (books[i].genre == true) {
            fiction[a] = books[i];
            a++;
        }
        else {
            non_fiction[b] = books[i];
            b++;
        }
    }
}

void old_book() {
    int min_fiction_year = INT_MAX, min_non_fiction_year = INT_MAX;
    Book earliest_fiction, earliest_non_fiction;

    for (int i = 0; i < NUM_BOOKS; ++i) {
        if (fiction[i].publish_year < min_fiction_year) {
            min_fiction_year = fiction[i].publish_year;
            earliest_fiction = fiction[i];
        }

        if (non_fiction[i].publish_year < min_non_fiction_year) {
            min_non_fiction_year = non_fiction[i].publish_year;
            earliest_non_fiction = non_fiction[i];
        }
    }

    
    cout << "\n\nFiction Books:\n";
    for (int i = 0; i < NUM_BOOKS; ++i) {
        cout << "Title: " << fiction[i].title << ", \tAuthor: " << fiction[i].author << ", \tPublish Year: " << fiction[i].publish_year << endl;
    }
    cout << "Earliest Fiction Book: " << earliest_fiction.title << " by " << earliest_fiction.author << " (Publish Year: " << earliest_fiction.publish_year << ")\n";

    cout << "\nNon-Fiction Books:\n";
    for (int i = 0; i < NUM_BOOKS; ++i) {
        cout << "Title: " << non_fiction[i].title << ", \tAuthor: " << non_fiction[i].author << ", \tPublish Year: " << non_fiction[i].publish_year << endl;
    }
    cout << "Earliest Non-Fiction Book: " << earliest_non_fiction.title << " by " << earliest_non_fiction.author << " (Publish Year: " << earliest_non_fiction.publish_year << ")\n";
}          
