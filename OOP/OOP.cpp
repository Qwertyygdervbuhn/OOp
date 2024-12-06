#include <iostream>
using namespace std;

class Book {
    char* Author;
    char* Text;
    int pages;
    int year;

public:
    Book() = default;

    Book(const Book&) = delete;
    Book& operator=(const Book&) = delete;

    Book(Book&& obj) noexcept
        : Author(obj.Author), Text(obj.Text), pages(obj.pages), year(obj.year) {
        obj.Author = nullptr;
        obj.Text = nullptr;
    }

    Book& operator=(Book&& obj) noexcept {
        if (this != &obj) {
            delete[] Author;
            delete[] Text;

            Author = obj.Author;
            Text = obj.Text;
            pages = obj.pages;
            year = obj.year;

            obj.Author = nullptr;
            obj.Text = nullptr;
        }
        return *this;
    }

    ~Book() {
        delete[] Author;
        delete[] Text;
    }
};

int main()
{




};