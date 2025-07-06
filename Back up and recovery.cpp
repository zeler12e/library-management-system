#include <iostream>
using namespace std;

// ------------------ Global Arrays ------------------

const int MAX_BOOKS = 100;
int bookIDs[MAX_BOOKS];
char bookTitles[MAX_BOOKS][50];
char bookAuthors[MAX_BOOKS][50];
bool bookIssued[MAX_BOOKS];
int bookCount = 0;

// ------------------ Backup Arrays ------------------

int backupBookIDs[MAX_BOOKS];
char backupBookTitles[MAX_BOOKS][50];
char backupBookAuthors[MAX_BOOKS][50];
bool backupBookIssued[MAX_BOOKS];
int backupBookCount = 0;

// ------------------ Helper: Manual Copy ------------------

void copyText(char dest[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

// ------------------ Book Management ------------------

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    }

    cout << "Enter Book ID: ";
    cin >> bookIDs[bookCount];
    cin.ignore();

    cout << "Enter Book Title: ";
    cin.getline(bookTitles[bookCount], 50);

    cout << "Enter Author Name: ";
    cin.getline(bookAuthors[bookCount], 50);

    bookIssued[bookCount] = false;
    bookCount++;

    cout << "✅ Book added successfully!\n";
}

void viewBooks() {
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }

    cout << "\n--- Book List ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << bookIDs[i] << " | " << bookTitles[i] << " | " << bookAuthors[i]
             << " | " << (bookIssued[i] ? "Issued" : "Available") << "\n";
    }
}

// ------------------ Backup & Recovery ------------------

void createBackup() {
    backupBookCount = bookCount;
    for (int i = 0; i < bookCount; i++) {
        backupBookIDs[i] = bookIDs[i];
        copyText(backupBookTitles[i], bookTitles[i]);
        copyText(backupBookAuthors[i], bookAuthors[i]);
        backupBookIssued[i] = bookIssued[i];
    }
    cout << "📦 Backup created successfully.\n";
}

void recoverFromBackup() {
    bookCount = backupBookCount;
    for (int i = 0; i < bookCount; i++) {
        bookIDs[i] = backupBookIDs[i];
        copyText(bookTitles[i], backupBookTitles[i]);
        copyText(bookAuthors[i], backupBookAuthors[i]);
        bookIssued[i] = backupBookIssued[i];
    }
    cout << "🔁 Recovery from backup completed.\n";
}

// ------------------ Menu ------------------

void bookMenu() {
    int choice;
    do {
        cout << "\n=== Book Management Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Create Backup\n";
        cout << "4. Recover From Backup\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: createBackup(); break;
            case 4: recoverFromBackup(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "❗ Invalid choice.\n";
        }
    } while (choice != 0);
}

// ------------------ Main ------------------

int main() {
    bookMenu();
    return 0;
}
