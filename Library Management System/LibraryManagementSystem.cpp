#include<iostream>
#include<string>
using namespace std;

//================ LIBRARY ITEM CLASS ================

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:

    // Default Constructor
    LibraryItem()
    {
        title = "";
        author = "";
        dueDate = "";
    }

    // Parameterized Constructor
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    virtual ~LibraryItem(){}

    // Getters
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    // Setters
    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
};

//================ BOOK CLASS ================

class Book : public LibraryItem
{
private:
    string isbn;

public:

    Book(string t,string a,string d,string i)
        : LibraryItem(t,a,d)
    {
        isbn = i;
    }

    void checkOut()
    {
        cout<<"\nBook Checked Out Successfully.\n";
    }

    void returnItem()
    {
        cout<<"Book Returned Successfully.\n";
    }

    void displayDetails()
    {
        cout<<"\n----- Book Details -----\n";
        cout<<"Title : "<<getTitle()<<endl;
        cout<<"Author : "<<getAuthor()<<endl;
        cout<<"Due Date : "<<getDueDate()<<endl;
        cout<<"ISBN : "<<isbn<<endl;
    }
};

//================ DVD CLASS ================

class DVD : public LibraryItem
{
private:
    int duration;

public:

    DVD(string t,string a,string d,int dur)
        : LibraryItem(t,a,d)
    {
        duration = dur;
    }

    void checkOut()
    {
        cout<<"\nDVD Checked Out Successfully.\n";
    }

    void returnItem()
    {
        cout<<"DVD Returned Successfully.\n";
    }

    void displayDetails()
    {
        cout<<"\n----- DVD Details -----\n";
        cout<<"Title : "<<getTitle()<<endl;
        cout<<"Author : "<<getAuthor()<<endl;
        cout<<"Due Date : "<<getDueDate()<<endl;
        cout<<"Duration : "<<duration<<" Minutes"<<endl;
    }
};

//================ MAGAZINE CLASS ================

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:

    Magazine(string t,string a,string d,int issue)
        : LibraryItem(t,a,d)
    {
        issueNumber = issue;
    }

    void checkOut()
    {
        cout<<"\nMagazine Checked Out Successfully.\n";
    }

    void returnItem()
    {
        cout<<"Magazine Returned Successfully.\n";
    }

    void displayDetails()
    {
        cout<<"\n----- Magazine Details -----\n";
        cout<<"Title : "<<getTitle()<<endl;
        cout<<"Author : "<<getAuthor()<<endl;
        cout<<"Due Date : "<<getDueDate()<<endl;
        cout<<"Issue Number : "<<issueNumber<<endl;
    }
};


class LibraryManagementSystem
{
private:
    LibraryItem* libraryItems[100];
    int totalItems;

public:

    LibraryManagementSystem()
    {
        totalItems = 0;
    }

    // Destructor
    ~LibraryManagementSystem()
    {
        for(int i = 0; i < totalItems; i++)
        {
            delete libraryItems[i];
        }
    }

    // Add Item
    void addItem()
    {
        int choice;

        cout << "\n1. Book";
        cout << "\n2. DVD";
        cout << "\n3. Magazine";

        cout << "\nEnter Choice : ";
        cin >> choice;

        string title, author, dueDate;

        cin.ignore();

        cout << "Enter Title : ";
        getline(cin, title);

        cout << "Enter Author : ";
        getline(cin, author);

        cout << "Enter Due Date : ";
        getline(cin, dueDate);

        try
        {
            if(choice == 1)
            {
                string isbn;

                cout << "Enter ISBN : ";
                getline(cin, isbn);

                if(isbn.length() < 5)
                    throw "Invalid ISBN!";

                libraryItems[totalItems++] = new Book(title,author,dueDate,isbn);
            }

            else if(choice == 2)
            {
                int duration;

                cout << "Enter Duration (Minutes) : ";
                cin >> duration;

                if(duration <= 0)
                    throw "Duration Invalid!";

                libraryItems[totalItems++] = new DVD(title,author,dueDate,duration);
            }

            else if(choice == 3)
            {
                int issue;

                cout << "Enter Issue Number : ";
                cin >> issue;

                if(issue <= 0)
                    throw "Invalid Issue Number!";

                libraryItems[totalItems++] = new Magazine(title,author,dueDate,issue);
            }

            else
            {
                cout << "Invalid Choice!\n";
            }

            cout << "\nItem Added Successfully.\n";
        }

        catch(const char* msg)
        {
            cout << "\nException : " << msg << endl;
        }

        catch(...)
        {
            cout << " Exception Unknown!\n";
        }
    }

    // Display All Items
    void displayItems()
    {
        if(totalItems == 0)
        {
            cout << "\nLibrary Empty.\n";
            return;
        }

        cout << "\n====== Library Items ======\n";

        for(int i=0;i<totalItems;i++)
        {
            libraryItems[i]->displayDetails();
        }
    }

    // Search Item
    void searchItem()
    {
        if(totalItems==0)
        {
            cout<<"\nLibrary Empty.\n";
            return;
        }

        string searchTitle;

        cin.ignore();

        cout<<"Enter Title : ";
        getline(cin,searchTitle);

        for(int i=0;i<totalItems;i++)
        {
            if(libraryItems[i]->getTitle()==searchTitle)
            {
                cout<<"\nItem Found!\n";
                libraryItems[i]->displayDetails();
                return;
            }
        }

        cout<<"\nItem Not Found.\n";
    }

    // Check Out
    void checkOutItem()
    {
        string searchTitle;

        cin.ignore();

        cout<<"Enter Title : ";
        getline(cin,searchTitle);

        for(int i=0;i<totalItems;i++)
        {
            if(libraryItems[i]->getTitle()==searchTitle)
            {
                libraryItems[i]->checkOut();
                return;
            }
        }

        cout<<"\nItem Not Found.\n";
    }

    // Return Item
    void returnLibraryItem()
    {
        string searchTitle;

        cin.ignore();

        cout<<"Enter Title : ";
        getline(cin,searchTitle);

        for(int i=0;i<totalItems;i++)
        {
            if(libraryItems[i]->getTitle()==searchTitle)
            {
                libraryItems[i]->returnItem();
                return;
            }
        }

        cout<<"\nItem Not Found.\n";
    }
};


int main()
{
    LibraryManagementSystem library;

    int choice;

    do
    {
        cout << "\n========= Library Management System =========\n";
        cout << "1. Add Item\n";
        cout << "2. Display All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Check Out Item\n";
        cout << "5. Return Item\n";
        cout << "6. Exit\n";

        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                library.addItem();
                break;

            case 2:
                library.displayItems();
                break;

            case 3:
                library.searchItem();
                break;

            case 4:
                library.checkOutItem();
                break;

            case 5:
                library.returnLibraryItem();
                break;

            case 6:
                cout << "\nThank You! Exiting Library Management System...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    }while(choice != 6);

    return 0;
}