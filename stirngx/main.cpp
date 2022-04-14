#include <iostream>
#include <cstring>

class MyString{
    char* content;
    int capacity;
    int length;

public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    MyString& Assign(const MyString& str);
    MyString& Assign(const char* str);
    MyString& Insert(int loc, const MyString& str);
    MyString& Insert(int loc, const char* str);
    MyString& Insert(int loc, char c);

    int Capacity() const;
    int Length() const ;
    char At(int i) const;
    void Print()  const ;
    void Println()  const ;
    void Reserve(int size) ;


};

MyString::MyString(char c) {
    capacity = length = 1;
    content = new char[1];
    content[0] = c;
}
MyString::MyString(const char *str) {
    capacity = length = strlen(str);
    content = new char[length];
    for (int i = 0; i < length; ++i) {
        content[i] = str[i];
    }
}
MyString::MyString(const MyString &str) {
    capacity = length = str.length;
    content = new char[length];
    for (int i = 0; i < length; ++i) {
        content[i] = str.content[i];
    }
}
MyString::~MyString() {
    delete[] content;
}

MyString& MyString::Assign(const MyString &str) {
    if(str.length > capacity){
        delete[] content;
        capacity = str.length;
        content = new char[capacity];
    }

    length = str.length;
    for (int i = 0; i < length; ++i) {
        content[i] = str.content[i];
    }
    return *this;
}
MyString& MyString::Assign(const char *str) {
    int strLength = strlen(str);
    if(strLength > capacity){
        delete[] content;
        capacity =  strLength;
        content = new char[length];
    }

    length = strLength;
    for (int i = 0; i < length; ++i) {
        content[i] = str[i];
    }

    return *this;
}
MyString& MyString::Insert(int loc, const MyString& str){

}
MyString& MyString::Insert(int loc, const char* str){

}
MyString& MyString::Insert(int loc, char c){

}

int  MyString::Capacity() const { return  capacity;}
int  MyString::Length() const { return length;}
char MyString::At(int i) const {
    if (i >= length || i < 0){
        return NULL;
    }
    else{
        return content[i];
    }
}
void MyString::Print()  const {
    for (int i = 0; i < length; ++i) {
        std::cout << content[i] ;
    }
}
void MyString::Println()  const {
    for (int i = 0; i < length; ++i) {
        std::cout << content[i] ;
    }
    std::cout << std::endl;
}
void MyString::Reserve(int size) {
    if( size > capacity)
    {
        char* prevContent = content;
        content = new char[size];
        capacity = size;

        for (int i = 0; i < size; ++i) {
            content[i] = prevContent[i];
        }
        delete[] prevContent;
    }

}

int main() {
    MyString str1("very very very long string");
    str1.Reserve(30);

    std::cout << "Capacity : "<< str1.Capacity() << std::endl;
    std::cout << "String Length : "<< str1.Length() << std::endl;
    str1.Println();
    return 0;
}
