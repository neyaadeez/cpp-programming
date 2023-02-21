#include<iostream>
#include<string>

using namespace std;
 
class Person {
    string name;
    int age;
    string nty;
    double addhr;
    double panno;
    double income;
    
    public:
    void input(string n,int a,string nat,double add,double pan,double inc){
        name=n;
        age=a;
        nty=nat;
        addhr=add;
        panno=pan;
        income=inc;
    }
    
    void info(){
        cout<<"Enter the following details: "<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Nationality"<<nty<<endl;
        cout<<"Aadhar No: "<<addhr<<endl;
        cout<<"Pan No: "<<panno<<endl;
        cout<<"Income: "<<income<<endl;
        
    }
};

int main(){
    string nm;
    int ag;
    string nati;
    double adno ;
    double pno;
    double in;
    
    cout<<"Enter the name: ";
    cin>>nm;
    
    try{
        cout<<"Enter the age: ";
        cin>>ag;
        if(ag<18)
        throw ag;
        
        cout<<"Enter the income per year: ";
        cin>>in;
        if(in<5000000)
        throw in;
        
        cout<<"Enter your nationality: ";
        cin>>nati;
        if(nati!="India")
        throw nati;
        
        cout<<"Enter the pan no: ";
        cin>>pno;
        if(sizeof(pno)<8)
        throw pno;
        
        p1.input(nm,ag,nati,adno,pno,in);
        p1.info();
    }
}

catch(int p){
    cout<<"Sorry age is invalid for job"<<ag;
}
catch(double q){
    cout<<"Sorry income is not sufficient"<<in;
}
catch(string r){
    cout<<"Sorry only for Indian Nationality"<<nati;
}
catch(double s){
    cout<<"Sorry PAN No is invalid"<<pno;
}
return 0;
}
