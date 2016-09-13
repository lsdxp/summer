//
//  main.cpp
//  cc150
//
//  Created by Shengdong  Liu on 9/13/16.
//  Copyright © 2016 Shengdong  Liu. All rights reserved.
//

#include <iostream>
#define Name_Size 50
using namespace std;

class Empty{
public:
    Empty(){}//constructor
    Empty(const Empty& rhs){}//copy
    ~Empty(){}//destructor
    virtual  //????
    Empty& operator=(const Empty& rhs);
};


class Person{
    int id;
    char name[Name_Size];
    
public:
//    Person(int a){
//        id=a;
//    }
//    Person(int a):id(a){
//        
//    }
    void print(){
        cout<<"I am a person"<<endl;
                }
    ~Person();
};

class Student: public Person{
    
public: void print(){
    cout<<"I am a student"<<endl;
                    }
};

template<class T>
class ShiftedList{
    T* array;
    int offset ,size;
public:
    ShiftedList(int sz):offset(0),size(sz){
        array=new T[size];
    }
    ~ShiftedList(){
        delete [] array;
    }
    void shiftBy(int n){
        offset=(offset+n)%size;
    }
    T getAt(int i){
        return array[convertIndex(i)];
    }
    void setAt(T item,int i){
        array[convertIndex(i)]=item;
    }
private:
    int convertIndex(int i){
        int index=(i-offset)%size;
        while (index<0) index+=size;
        return index;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Student *p=new Student();
    p->print();
    delete p;
    return 0;
}



