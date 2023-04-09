#include <iostream>
#include <string>
#include <vector>
#include "main.hpp"


//using user defined-> book class 
class Book {
public:
    // book has title and author
    Book(std::string title, std::string author)
        : a_title(std::move(title)), a_author(std::move(author)) {}

    bool operator==(const Book& other) const {
        return a_title == other.a_title && a_author == other.a_author;
    }

    bool operator!=(const Book& other) const {
        return !(*this == other);
    }

    // friend function for output of title and author
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.a_title << " by " << book.a_author;
        return os;
    }

private:
    std::string a_title;
    std::string a_author;
};

//using user defined course struct
struct Course {
    std::string name;
    int id;

    bool operator==(const Course& other) const {
        return name == other.name && id == other.id;
    }

    bool operator!=(const Course& other) const {
        return !(*this == other);
    }
};

int main() {
    // Example usage with Book class
    std::cout << std::endl;
    std::cout << "Test book class" << std::endl; 

    Repository<Book> bookRepo;
    bookRepo.add(Book("The Great Gatsby", "F. Scott Fitzgerald"), "Classic American literature");
    bookRepo.add(Book("Fairy Tale", "Stephen King"), "Fiction");
    bookRepo.add(Book("Stay Close", "Harlan Coben"), "Thriller");
    bookRepo.add(Book("C++", "Bjarne Stroustrup"), "Reference work");

    std::cout << "Book repository size: " << bookRepo.size() << std::endl;
    std::cout << "Order of C++: " << bookRepo.order(Book("C++", "Bjarne Stroustrup")) << std::endl;
    bookRepo.remove(Book("Stay Close", "Harlan Coben"));
    std::cout << "Book repository size after removing Stay Close: " << bookRepo.size() << std::endl;

    std::cout << std::endl;
    std::cout << "Test course struct" << std::endl; 

    // Example usage with Course struct
    Repository<Course> courseRepo;
    courseRepo.add({ "C++", 3520 }, "Computer Science");
    courseRepo.add({ "Advanced Programming", 3500 }, "Data Science");
    courseRepo.add({ "Tech and Values", 1145 }, "Philosophy");

    std::cout << "Course repository size: " << courseRepo.size() << std::endl;
    std::cout << "Order of Data Science: " << courseRepo.order({ "Math", 3500 }) << std::endl;
    courseRepo.remove({ "Tech and Values", 1145 });
    courseRepo.remove({ "French", 2000 });
    std::cout << "Course repository size: " << courseRepo.size() << std::endl;


    std::cout << std::endl;
    std::cout << "Test double datatype" << std::endl; 

    // using generic type double
     Repository<double> d;

    // add items to the repository
    d.add(5.2, "Double 5.2.");
    d.add(4.0, "Double 4.0.");
    d.add(58.6, "Double 58.6.");

    // print the size of the repository
    std::cout << "Size of repository: " << d.size() << std::endl;
  
    // print the order of an item in the repository
    double num = 5.2;
    std::cout << "Order of " << num << " in repository: " << d.order(num) << std::endl;

    // remove an item from the repository
    d.remove(5.2);
    d.remove(58.6); 
    d.add(21.4, "Double 21.4.");

    // print the size of the repository after removing an item
    std::cout << "Size of repository after removing: " << d.size() << std::endl;


    // using generic type string
    Repository<std::string> repo;

    std::cout << std::endl;
    std::cout << "Test string datatype" << std::endl; 

    // add items to the repository
    repo.add("hello", "String is hello.");
    repo.add("world", "String is world.");
    repo.add("Saturday", "String is Saturday.");

    // print the size of the repository
    std::cout << "Size of repository: " << repo.size() << std::endl;

    // print the order of an item in the repository
    std::string item = "Saturday";
    std::cout << "Order of \"" << item << "\" in repository: " << repo.order(item) << std::endl;

    // remove an item from the repository
    repo.remove("Saturday");

    // print the size of the repository after removing an item
    std::cout << "Size of repository after removing: " << repo.size() << std::endl;

    return 0;
}





