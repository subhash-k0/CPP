#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int age;
    bool gender;

    //Default construuctor
    student(){
        cout<<"Default contruuctor"<<endl;
    }

    //making Construuctor (parametriz contruuctor)
    student(string s, int a, bool g){
        cout<<"parametriz contruuctor"<<endl;
        name = s;
        age =a;
        gender=g;

    }

    student(student &a){
        cout<<"copy constructor"<<endl;
        name=a.name;
        age=a.age;
        gender=a.gender;

    }

//to acess private
// void setname(string s){
//     name=s;
// }

void getName(){
    cout<<name<<endl;
}

    void printInfo(){
       cout<<"name= "<<name<<endl;
       cout<<"age= "<<age<<endl;
       cout<<"gender= "<<gender<<endl;

    }

    //Constructor overloading
    bool operator == (student &a){
        if(name==a.name && age == a.age && gender == a.gender){
            return true;
        }
        return false;
    }

    //distructor
    ~student(){
        cout<<"Destructor"<<endl;
    }
};

int main(){

    // student a;
    // a.name = "uname";
    // a.age = 13;
    // a.gender = 1;

    // student arr[3];
    // for(int i=0;i<3;i++){
    //     cout<<"name- ";
    //     cin>>arr[i].name;
    //     cout<<"age- ";
    //     cin>>arr[i].age;
    //     cout<<"gender- ";
    //     cin>>arr[i].gender;
    // }

    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }

    student a("rahul",20,1);
    // a.getName();
    // a.printInfo();

    student b;   //not work withouut default constructor
    // b.printInfo();

    //copy constructor
    student c(a);
    // c.printInfo();
    student d=a;
    // d.printInfo();

    if(c==a){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }


return 0;
}