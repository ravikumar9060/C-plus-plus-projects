#include<iostream>
#include<vector>
#include<string>
using namespace std;
void displayToDoList(const vector<string>& todoList)
{
    int i;
    cout<<"To Do List:"<<endl;
    for( i=0 ; i < todoList.size(); i++){
     cout<<i+1 << ", " <<todoList[i] << endl;
    }
     cout<< endl ;
}
int main ()
{
    vector<string> todoList ;
    char choice ;
    do{
        cout<<"Options:" <<endl;
        cout<<"1.Add Task:" <<endl;
        cout<<"2.Remove Task:" <<endl;
        cout <<"3.View To Do List:" <<endl;
        cout <<"4.Exit:" <<endl;
        cout <<"Enter your Choice:" ;
        cin>> choice ;
         switch(choice)
         {
            case '1' :
            {
                string task ;
                cout<< "Enter the task :";
                cin.ignore();
                getline(cin,task );
                todoList.push_back(task);
                cout<< "task added sucessfully "<< endl ;
                break;
            }
            case '2':
            {
                int taskIndex ;
                displayToDoList(todoList);
                cout<< "Enter the task Number to Remove : ";
                cin>>taskIndex;
                if(taskIndex>=1 && taskIndex <= todoList.size())
                {
                    todoList.erase(todoList.begin() + taskIndex+1);
                    cout<<"Task Remove Sucessfully! :" <<endl;
                }
                else {
                    cout<<"Invalid Task Number! : "<<endl;
                }
                break ;
            }
            case '3':
            {
                displayToDoList(todoList);
                break;
            }
            case '4' :
                cout <<"Exiting Program :" << endl;
                break ;

            default :
                cout << " Invalid Choice plz try again " << endl;           
         }
    }
   while(choice != '4');
return 0 ;
}
 