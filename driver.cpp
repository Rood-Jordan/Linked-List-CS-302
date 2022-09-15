
//Jordan Rood
//Homework 1 - Linked list
//09-13-2021

#include <iostream>
#include <string>
#include <exception>
#include "linkedList.h"

using namespace std;

int getMenuChoice();
void addStringToDo(linkedList<string>& );
void completeTask(linkedList<string>& );
void displayList(linkedList<string>& );
void completeList(linkedList<string>& );

int main(){
    int userChoice;
    linkedList<string> aToDoList;

    do{
        try{
        userChoice = getMenuChoice();

            switch(userChoice){
                case 1:
                    addStringToDo(aToDoList);
                    break;
                case 2:
                    completeTask(aToDoList);
                    break;
                case 3:
                    displayList(aToDoList);
                    break;
                case 4:
                    completeList(aToDoList);
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!!" << endl;
                    break;
            }
        }
        catch(const char* e){
            cout << e << endl;
        }

    }while(userChoice != 0);

    return 0;
}

int getMenuChoice(){
    int choice;
    cout << "TODO List" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Complete Task" << endl;
    cout << "3. Display List" << endl;
    cout << "4. Complete List" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;
    return choice;
}

void addStringToDo(linkedList<string>& aToDoList){
    int position;
    string task;

    if(aToDoList.isEmpty()){
        cout << "No tasks currently!" << endl;
    }
    else{
        displayList(aToDoList);
    }

    cout << "What is the priority of this task?" << endl;
    cin >> position;
    
    cout << "What is the new task?" << endl;
    if(cin.peek() == '\n'){
        cin.ignore();
    }
    getline(cin, task);
    
    aToDoList.insert(position, task);
}

void completeTask(linkedList<string>& aToDoList){
    int taskCompleted;

    if(aToDoList.isEmpty()){
        cout << "No tasks currently!" << endl;
    }
    else{
        displayList(aToDoList);

        cout << "Please select which task you've completed: " << endl;
        cin >> taskCompleted;

        cout << "Completed: " << aToDoList.getEntry(taskCompleted) << endl << endl;

        aToDoList.remove(taskCompleted); 
    }   
}

void displayList(linkedList<string>& aToDoList){

    if(aToDoList.isEmpty()){
        cout << "List is Empty!" << endl << endl;
        return;
    }

    for(int position = 1; position <= aToDoList.getLength(); position++){
        cout << position << ": " << aToDoList.getEntry(position) << endl;
    }
    cout << endl;
}

void completeList(linkedList<string>& aToDoList){
    aToDoList.clear();
    displayList(aToDoList);
}
