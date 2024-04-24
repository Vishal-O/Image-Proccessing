#include <iostream>
#include <fstream>
using namespace std;
//each pixel contain 3 value i.e red blue green so 
//created a class for holding these values
class Pixel{
    public:
    char red,blue,green;
};

//this function convert jpg,png etc. image into ppm format
//ppm format is uncompress format of image so we can read each pixel information
bool convert(string s1)
{
    string test,command;
    test=test+"ls "+s1;
    const char *test1 = test.c_str();
    if(system(test1)==0)
    {
    cout<<"Converting "<<s1<<" into ppm format\n";
    command="./magick convert "+s1+" ip.ppm";
    const char *test2 = command.c_str();
    system(test2);
    return true;
    }
    return false;
}

//these function compress image again into jpg format from ppm format
void com(string s1)
{
    string command;
    command=command+"./magick convert "+s1+".ppm "+s1+".jpg";
    cout<<endl;
    cout<<command;
    const char *test2 = command.c_str();
    system(test2);
}

//this function deletes temperary file which were created during execution of code
void del(string s1)
{
    string command;
    command="rm "+s1;
    const char *test2 = command.c_str();
    cout<<"\n"<<s1<<" Deleted";
    system(test2);
}

//it swap pixel data of two pixel
void swap(Pixel &A1,Pixel &A2)
    {
            Pixel temp;
            temp.red=A1.red; temp.green=A1.green;  temp.blue=A1.blue;
            A1.red=A2.red; A1.green=A2.green; A1.blue=A2.blue;
            A2.red=temp.red; A2.green=temp.green; A2.blue=temp.blue;
    }

//flipping an image
void flipImage(string input,string output)
{
    if(!convert(input))
    {
        cout<<"FILE NOT FOUND";
        return;
    }
    ifstream IP("ip.ppm");
    ofstream OP(output+".ppm");
    string type;
    int width, height, maxVal;

    IP >> type >> width >> height >> maxVal;
    IP.get();

    OP << type << endl;
    OP << width << " " << height << endl;
    OP << maxVal << endl;
    char data; 
    Pixel imageData[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            IP.get(data);
            imageData[i][j].red=data;
            IP.get(data);
            imageData[i][j].green=data;
            IP.get(data);
            imageData[i][j].blue=data;
        }
    }
    
    for(int i=0;i<height;i++)
    {
        int j=0;
        int k=width-1;
        while(j<k)
        {
            swap(imageData[i][j],imageData[i][k]);
            j++;
            k--;
        } 
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            OP<<imageData[i][j].red<<imageData[i][j].green<<imageData[i][j].blue;
        }
    }
    IP.close();
    OP.close();
    com(output);
    del("ip.ppm");
    del(output+".ppm");
    cout<<"\nIMAGE FLIPPED SUCCESSFULY";
}

//copy an image in another
void copy(string input,string output)
{
    if(!convert(input))
    {
        cout<<"FILE NOT FOUND";
        return;
    }
    ifstream IP("ip.ppm");
    ofstream OP(output+".ppm");
    string type;
    int width, height, maxVal;

    IP >> type >> width >> height >> maxVal;
    IP.get();

    OP << type << endl;
    OP << width << " " << height << endl;
    OP << maxVal << endl;
    char data; 
    Pixel imageData[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            IP.get(data);
            imageData[i][j].red=data;
            IP.get(data);
            imageData[i][j].green=data;
            IP.get(data);
            imageData[i][j].blue=data;
        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            OP<<imageData[i][j].red<<imageData[i][j].green<<imageData[i][j].blue;
        }
    }

    IP.close();
    OP.close();
    com(output);
    del("ip.ppm");
    del(output+".ppm");
    cout<<"IMAGE COPIED SUCCESSFULLY";
}

//rotate image right
void rotateRight(string input,string output)
{

    if(!convert(input))
    {
        cout<<"FILE NOT FOUND";
        return;
    }
    ifstream IP("ip.ppm");
    ofstream OP(output+".ppm");
    string type;
    int width, height, maxVal;

    IP >> type >> width >> height >> maxVal;
    IP.get();
    OP << type << endl;
    OP << height << " " << width << endl;
    OP << maxVal << endl;
    char data; 
    Pixel imageData[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            IP.get(data);
            imageData[i][j].red=data;
            IP.get(data);
            imageData[i][j].green=data;
            IP.get(data);
            imageData[i][j].blue=data;
        }
    }
      
    Pixel rotate[width][height];
    //taking transpose of matrix
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            rotate[j][i].red=imageData[i][j].red;
            rotate[j][i].green=imageData[i][j].green;
            rotate[j][i].blue=imageData[i][j].blue;
        }
    }
    //reversing each row element in matrix
    for(int i=0;i<width;i++)
        {
        int j=0;
        int k=height-1;
        while(j<k)
        {
            //swap rotate[i][j] & rotate[i][k]
            swap(rotate[i][j],rotate[i][k]);
            j++;
            k--;
        }
    }

    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            OP<<rotate[i][j].red<<rotate[i][j].green<<rotate[i][j].blue;
        }
    }

    IP.close();
    OP.close();
    com(output);
    del("ip.ppm");
    del(output+".ppm");
    cout<<"IMAGE ROTATED SUCCESSFULLY";
    }

//rotate image left
void rotateLeft(string input,string output)
{

    if(!convert(input))
    {
        cout<<"FILE NOT FOUND";
        return;
    }
    ifstream IP("ip.ppm");
    ofstream OP(output+".ppm");
    string type;
    int width, height, maxVal;

    IP >> type >> width >> height >> maxVal;
    IP.get();
    OP << type << endl;
    OP << height << " " << width << endl;
    OP << maxVal << endl;
    char data; 
    Pixel imageData[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            IP.get(data);
            imageData[i][j].red=data;
            IP.get(data);
            imageData[i][j].green=data;
            IP.get(data);
            imageData[i][j].blue=data;
        }
    }
      
    Pixel rotate[width][height];
    //taking transpose of matrix
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            rotate[j][i].red=imageData[i][j].red;
            rotate[j][i].green=imageData[i][j].green;
            rotate[j][i].blue=imageData[i][j].blue;
        }
    }
    //reversing each row element in matrix
    for(int i=0;i<height;i++)
        {
        int j=0;
        int k=width-1;
        while(j<k)
        {
            //swap rotate[i][j] & rotate[i][k]
            swap(rotate[j][i],rotate[k][i]);
            j++;
            k--;
        }
    }

    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            OP<<rotate[i][j].red<<rotate[i][j].green<<rotate[i][j].blue;
        }
    }

    IP.close();
    OP.close();
    com(output);
    del("ip.ppm");
    del(output+".ppm");
    cout<<"IMAGE ROTATED SUCCESSFULLY";
    }