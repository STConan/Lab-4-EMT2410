////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Title                : Lab 4 "Pointer for Dynamic Array & Data Acquisition"                                 //
//Author               : Wellington Verduga Macias                                                            //
//Version and Date     : V0.1 10/31/2022                                                                      //
//Copyright disclaimer :                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
float FindAverage(float *Nums, int total);
float FindMin(float *Nums, int total);
float FindMax(float *Nums, int total);
int main ()
{
    float *UserNumbers, *StartNumber = nullptr;
    UserNumbers = new float;//Init of dynamic arrays
    StartNumber = UserNumbers;//Start both pointers
    int Counter = 0;//To keep count of total times of input

    cout<<"Please enter as many number of float numbers as you want:\n";
    cout<<"(to mark the end of your input, enter 9999999)\n";
    cin>> *UserNumbers;
    while ( *UserNumbers != 999999)//Keeps taking user input until 999999 is inputed, breaking the loop
    {
        Counter++;
        UserNumbers++;
        cin >> *UserNumbers;

    }
    cout<<"How many valid numbers being entered:"<<Counter<<endl;
    cout<<"Your entered numbers are:\n";
    for (int e=0; e<Counter; e++)//Iteration to print User's numbers and its addresses
    {
        cout<<"Number: "<<StartNumber[e]<<endl;
        cout<<"Address: "<<&StartNumber[e]<<endl;
    }
    
    float Average = FindAverage(StartNumber, Counter);
    float Maximum = FindMax(StartNumber, Counter);
    float Minimum = FindMin(StartNumber, Counter);
    
    cout<<"From the numbers provided,"<<endl;
    cout<<"The Average is: "<<Average<<endl;
    cout<<"The Maximum number is: "<<Maximum<<endl;
    cout<<"The Minimum number is: "<<Minimum<<endl;
}

float FindAverage(float *Nums, int total)//Function to sum all numbers then divide it by the total, finding the average
{
    float Sum = 0.0;
    for (int e=0; e<total; e++)
    {
        Sum = Sum + Nums[e];
    }
    float average = Sum / total;
    return average;
}

float FindMin(float *Nums, int total)//Function to find the lowest number
{
    float Min = *Nums;
    for(int e=1; e<total; e++)//Iteration to check every number in the array
    {
        if (Nums[e] < Min) //Compares the current number
        {
            Min = Nums[e];
        }
    }
    return Min;
}
