#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
    using namespace std;
    using namespace chrono;
    
string tolowercase(const string &input){
    string str=input;
    transform(str.begin(),str.end(),str.begin(),::tolower);
    return str;
}

string getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t cTime = system_clock::to_time_t(now);
    tm *lTime = localtime(&cTime);

    ostringstream timeStream;
    timeStream << put_time(lTime, "%Y-%m-%d %H:%M:%S");
    return timeStream.str();
}

int main(){
    string input;
    string name;
    cout << "************************************************ALICE(A CHATBOT)************************************************" << endl;

    cout << "Alice: Hii I am Alice, a chatbot who works on some predefined rules. I welcome you here (type 'bye' to exit)." << endl;
   
    while(true){
        cout << "Alice: How may I help you?" << endl;
        cout << "User: ";
        getline(cin, input);

        string input1=tolowercase(input);
        if(input1=="hi" || input1=="hey" || input1=="hello"){
            cout << "Alice: Hello " + name + "!" <<endl;
        }
        else if(input1.find("how are you")!=string::npos){
            cout << "Alice: I am alright!" << endl;
        }
        else if(input1.find("time")!=string::npos){
            cout << "Alice: Current time: " + getCurrentTime() + "!!" << endl;
        }
        else if(input1=="what's my name?" || input1=="what is my name?"){
            if(name.empty()){
                cout << "Alice: Sorry You didn't tell your name!" <<endl;
                 cout << "Alice: May I know your name?" << endl;
                cout << "User: ";
                 getline(cin, name);
                 cout << "Alice: Nice to meet you " + name + "!!!" << endl;
            }
            else   
                cout << "Alice: Your name is " + name + "." << endl;
        }
        else if (input.find("weather")!=string::npos) {
            cout << "Alice: The weather is sunny with a chance of rain later today." << endl;
        }
       
        else{
        if(input1=="bye"){
            cout << "Alice: Bye Bye! It's nice talking to you" << endl;
            break;
        }
         else{
            cout << "Alice: I am Sorry, I do not Understand this." <<endl;
        }
        }
    }
    return 0;

}