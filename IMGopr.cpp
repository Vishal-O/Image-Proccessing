#include <iostream>
#include "image.h"
using namespace std;

  
int main() 
{
    int choice;
    string ip,op;
    while(1)
    {
    cout<<"\n-----------------------------------------------\n";
    cout<<"\n1: Copy Image \n2: Rotate Left\n3: Rotate Right\n4: FLIP A IMAGE\n5: exit";
    cout<<"\nCHOICE =>";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter Input Image Name with Extension(eg.Test.jpg) : ";
        cin>>ip;
        cout<<"Enter Output Image Name without Extension : ";
        cin>>op;
        copy(ip,op);
        break;
    case 2:
        cout<<"Enter Input Image Name with Extension(eg.Test.jpg) : ";
        cin>>ip;
        cout<<"Enter Output Image Name without Extension : ";
        cin>>op;
        rotateLeft(ip,op);
        break;
    case 3:
        cout<<"Enter Input Image Name with Extension(eg.Test.jpg) : ";
        cin>>ip;
        cout<<"Enter Output Image Name without Extension : ";
        cin>>op;
        rotateRight(ip,op);
        break;
    case 4:
        cout<<"Enter Input Image Name with Extension(eg.Test.jpg) : ";
        cin>>ip;
        cout<<"Enter Output Image Name without Extension : ";
        cin>>op;
        flipImage(ip,op);
        break;
    case 5:
        exit(0);
    default :
        cout<<"\nEnter valid choice";
        break;
    }
    }
    return 0;
}
