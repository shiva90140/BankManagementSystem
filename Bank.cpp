#include<iostream>
#include<fstream>  // ifstream-to read from a file. //ofstream - to create/open and write to a file.
using namespace std;
int CurrentBalance=5000;

void withdrawl(int amount){
   CurrentBalance=CurrentBalance - amount;
    cout<<"Successfully Withdrawn.\nYour Current balance : "<<CurrentBalance<<"\n";
}

void deposite(int amount){
    CurrentBalance=CurrentBalance + amount;
    cout<<"Successfully Deposited.\nYour Current Balance : "<<CurrentBalance<<"\n";
}

void balanceCheck(){
    cout<<"Your Current Balance : "<<CurrentBalance<<"\n";
}

int main(){
  cout<<"\n!..Welcome to Our Bank..!\n\n";
  string name,email;
  int passcode;
  
  cout<<"Please Enter the User name: ";
  cin>>name;
  cout<<"Enter the passcode: ";
  cin>>passcode;
  cout<<"Enter your Email:";
  cin>>email;
  
  int option,amount;
  cout<<"Enter the option: 1 to Withdrawl,2 to Deposite,3 to CheckBalance : ";
  cin>>option;
  switch (option)
  {
  case 1:
      cout<<"Enter the amount: ";
      cin>>amount;
      withdrawl(amount);
    break;

  case 2:
      cout<<"Enter the amount: ";
      cin>>amount;
      deposite(amount);
      break;
   case 3:
       balanceCheck();
    break;
  }

   ifstream myFile("bank.txt");
    // check the file for errors
    if(!myFile) {
        cout << "Error: Unable to open the file." << endl;
        return 1; 
    }
    string line;
    // loop until the end of the text file
    while (!myFile.eof()) {
        // store the current line of the file // in the "line" variable
        getline(myFile, line);
        cout << line << endl;
    }
     if(line==email){
            cout<<"User already exists.\n";
        }else{
            //append data to the end of the file
            ofstream myFile("bank.txt", ios::app);
             if (myFile) {
                    myFile << name<<","<<passcode<<","<<email<<endl;
                    myFile.close();
                 }
             else {
                cout << "Unable to open file for appending." << endl;
                 return 1;
                 }
        }
    myFile.close();
  /*
    //append data to the end of the file
    ofstream myFile("bank.txt", ios::app);
    if (myFile) {
        myFile << name<<","<<passcode<< endl;
        myFile.close();
    }
    else {
        cout << "Unable to open file for appending." << endl;
        return 1;
    }
  */
    

    return 0;
}