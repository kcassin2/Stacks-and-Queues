#include <cctype>      // for the tolower function
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void Menu(void);
char GetChoice(void);
bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol);

int main(void)
{
    char symbol;
    bool balanced = true;
    char openSymbol;
    stack <char> stack;
    
    cout << "Enter an expression and press return." << endl;
   
    
    while (symbol != '\n' && balanced)
    {
        
       
       
        
 if(IsOpen(symbol)==true){
     stack.push(symbol);
 }
 
 else if(IsClosed(symbol)== true){
     
     if(stack.empty()==true){
            balanced=false;
     }
 
        
        else{
             openSymbol=stack.top();
    stack.pop();
        
     if(Matches( symbol,  openSymbol)==true){
         
         balanced=true;
     }
     else{
    
        balanced=false;
     }
 
        }
        
 }
        // if( openSymbol==Peek(stack)){
        //  
        // } 
        // }
  cin.get(symbol);
 
    }
    
    
    if ((balanced) && (stack.empty()))
        cout << "Expression is well formed." << endl;
    else
        cout << "Expression is not well formed."  << endl;
       
    
    
    queue<float> Queue;
    float Num;
    char Choice;
    
    Menu();
    cout << "Enter the letter for your choice: "<<endl;
    Choice = GetChoice();
    
    while (Choice != 'Q')
    {
        if (Choice == 'I')
        {
          //int item; 
        cout<<"Enter the float to insert into the queue: ";
        cin>>Num;
        
        Queue.push(Num);
        

        }
        else if (Choice == 'B')
        {
            if(Queue.empty()==true){
                 cout<<"Queue is Empty"<<endl;
            }
            else{
            int x = Queue.back();
            //cout<<x<<endl;
             cout<<"The last item added to the Queue: "<<x<<endl;
            }
            
            //cout<<"The last item added to the Queue: "<<Num<<endl;
        }
        else if (Choice == 'S')
        {
        int y =    Queue.size();
          cout<<"The size of the Queue: "<<y<<endl;
        }
        else if (Choice == 'R')
        {
            if(Queue.empty()==true){
              cout<<"Queue is Empty"<<endl;
          }
          else{
            int i;
             i= Queue.front();
          Queue.pop();
         
          cout<<"The number removed was: "<<i<<endl;
          }
          
            }
    
        else if (Choice == 'E')
        {
            if(Queue.empty()==true){
                cout<<"The queue is empty"<<endl;
            }
  else{
      cout<<"The queue is not empty"<<endl;
  }
        }
        else if (Choice != 'Q')
            cout << "Invalid Choice." << endl;
        
        Menu();
        cout << "Enter the letter for your choice: "<<endl;
        
        Choice = GetChoice();
       
    }
    
    return 0;
}

bool IsOpen(char symbol)
{
    if (symbol == '(' || symbol == '{' || symbol == '[')
        return true;
    else
        return false;
}

bool IsClosed(char symbol)
{
    if (symbol == ')' || symbol == '}' || symbol == ']')
        return true;
    else
        return false;
}

bool Matches(char symbol, char openSymbol)
{
    return  ((openSymbol == '(' && symbol == ')')
             || (openSymbol == '{' && symbol == '}')
             || (openSymbol == '[' && symbol == ']'));
}
/* Given:  Nothing.
 Task:   To present a menu of available options on screen.
 Return: Nothing.
 */
void Menu(void)
{
    cout << endl << "Menu of available Queue options:" << endl;
    cout << "   I   Insert an item" << endl;
    cout << "   R   Remove an item" << endl;
    cout << "   E   Check if queue is empty" << endl;
    cout << "   S   Returns the Size of the Queue" << endl;
    cout << "   B   Returns the Last Item in the Queue" << endl;
    cout << "   Q   Quit" << endl << endl;
}
/* Given:  Nothing.
 Task:   To read a letter from the keyboard indicating the
 user's choice.
 Return: This letter (in upper case) in the function name.
 */
char GetChoice(void)
{
    char Temp;
    
    cin >> Temp;
    Temp = toupper(Temp);
    return Temp;
}
