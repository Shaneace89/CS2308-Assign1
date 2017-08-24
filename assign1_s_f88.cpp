/*File Name: assign1_s_f88.cpp

Author: Shane Fleming
Date: 01/27/16
Assignment Number: 1
CS 2308.257 Spring 2016
Instructor: Jill Seaman

Grade Book*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

using namespace std;
  ifstream fin;  //opening file in "fin"
  ofstream fout; //opening file out "fout"

float examtot = 0;

//*****************************************************************
// cal:  Calculates the average for 5 exam scores, dropping lowest grade 
// returns the total points of the exams as a int
//*****************************************************************

 int cal (int &examtot)
    {
    int  low, examscore [5];
    int x = 1;
          fin >> examscore[0];
          low = examscore[0]; 
            while (x < 5)
               {
                   fin >> examscore[x];
           if (examscore[x] < low)
            low = examscore[x];
                    x++;
                }

                      examtot = (examscore[0] + examscore[1] + examscore[2] + 
                      examscore[3] + examscore[4] - low);

                          cout << examtot << " " << low << endl;
    
          return 0;

     }

int main()
{

        fin.open("class_scores.txt");
        fout.open("final_grades.txt");

string id;
fin >> id;
int test, p;

cout << id << " ";
cal(test);
cout << test << endl;

return 0;
}
