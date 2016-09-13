/*File Name: assign1_s_f88.cpp

Author: Shane Fleming
Date: 01/27/16
Assignment Number: 1
CS 2308.257 Spring 2016
Instructor: Jill Seaman

Grade Book Calculator*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

   ifstream fin;  //**opening file in "fin"**
   ofstream fout; //**opening file out "fout"**

/********************************************************************
 examgradeF:  adds together the 5 exam scores, dropping lowest grade
 examTotal:  holds completed exam score 
 returns:  the total points of the exams as a int
*********************************************************************/ 
              //**"F" at end of examgradeF is for Function**
 int examgradeF(int &examTotal)
    {
	int  low, examScore [5], x = 1;  
              //**low = lowest exam, examScore[ ] = array for exam scores**

            fin >> examScore[0];
               low = examScore[0]; 
               
          while (x < 5)
               {
                   fin >> examScore[x];
		      if (examScore[x] < low)
		         low = examScore[x];
                           x++;
                }

                      examTotal = (examScore[0] + examScore[1] + examScore[2] + 
                      examScore[3] + examScore[4] - low);

          return 0;

     }

/*****************************************************************
 assgradeF:  adds the four assignments grades together
 assTotal:  holds completed exam score
 returns:  the total points of the assignments as a int
******************************************************************/

 int assgradeF(int &assTotal)
    {
        int ass[4], x = 0;
             //**ass[ ] = array for assignments scores, x = counter**

            while (x < 4)
               {
                   fin >> ass[x];
                      assTotal += ass[x];
                        x++;
                }

          return 0;

     }

/****************************************************************
 headerF:  produces a header for the "fout" file
 void: returns nothing
*****************************************************************/

 void headerF()
    {
        fout
           << "StudentID     Points     Percent     Grade" << endl
           << "__________________________________________" << endl
           << endl;
    }

/*****************************************************************
 lettergradeF: outputs the correct letter grade earned
 tempTotal: holds total earned score from course
 returns: nothing, outputs earned letter grade
******************************************************************/

 char lettergradeF(float &tempTotal)
    {
         char finalGrade;
           //**variable for letter grade**

                if (tempTotal >= 448)
                        finalGrade = 'A';
                else if (tempTotal <= 447 && tempTotal >= 398)
                        finalGrade = 'B';
                else if (tempTotal <= 397 && tempTotal >= 348)
                        finalGrade = 'C';
                else if (tempTotal <= 347 && tempTotal >= 298)
                        finalGrade = 'D';
                else
                        finalGrade = 'F';
          fout << finalGrade << endl;
        
       return 0;
    }

/*****************************************************************
 loopF: loops and pulls information from class_scores.txt
 returns:  nothing, outputs to final_grades.txt 
******************************************************************/

 void loopF()
    {
        string id;

            while (fin >> id)
              {
                 int examTotal = 0, assTotal = 0, part = 0;
                 float tempTotal = 0;
                   //**examTotal = total of top 4 exams,** 
                   //**assTotal = total of all assignments,** 
                   //**part = participation grade**

                    fout << id << "        ";
   
                examgradeF(examTotal);

                    fin >> part;
                      if (part > 60)
                        part = 60;

                assgradeF(assTotal);

                    tempTotal = examTotal + part + assTotal;
                      fout << fixed << setprecision(0) << tempTotal
                         << "        ";
                      fout << fixed << setprecision(1) << (tempTotal / 500) * 100 
                         << "         ";

                lettergradeF(tempTotal);
         
               }
    }   

/*****************************************************************
 main: creates final_grades.txt, and runs Functions headerF, loopF
 retruns: nothing
******************************************************************/

int main()
   {
          fin.open("class_scores.txt");
          fout.open("final_grades.txt");

       headerF();
       loopF();

    return 0;
   }
