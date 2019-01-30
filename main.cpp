/*INSTRUCTIONS
DO NOT CHANGE ANY OF THE CLASSES HERE.
FREE TO INHERIT and OVERRIDE ANY CLASSES
you can make your own classes and functions
Follow the output pattern i am following
Write a function IMT2016*** which takes the file name as a parameter and
completes your task
Add that function to the taskPtrs
In case of any mistakes in my implementation, let me know
Any doubts, post in group

Tasks
1, 2 ,5 ,6 ,7 ,8


INSTRUCTIONS
- Compile using g++ *.cpp
- 2 Modes of running
    -> ./a.out lena.ppm (Runs all tasks)
    -> ./a.out lena.ppm 3 1 2 (Runs tasks 3,1,2 selectively)

*/




#include "tasks.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    cout << "Wrong command line arguements" << endl;
    return 0;
  }
  cout << "Our group task ID combination is: 1, 2 ,5 ,6 ,7 ,8" << endl << endl;

  // modify taskList to execute tasks selectively
  int taskList[8] = {1, 2, 5, 6, 7, 8};
  int taskCount;
  if (argc == 2) {
    taskCount = 6;
  } else {
    taskCount = argc - 2;
    cout << "Executing tasks: ";
    for (int i = 0; i < taskCount; i++) {
      taskList[i] = stoi(argv[i + 2]);
      if (i)
        cout << ", " << taskList[i];
      else
        cout << taskList[i];
    }
    cout << endl << endl;
  }

  // Add your task function here
  void (*taskPtrs[8])(char const *) = {IMT2016105, IMT2016064, NULL,NULL, IMT2016008, IMT2016037,IMT2016085, IMT2016124};

  for (int i = 0; i < taskCount; i++) {
    if (taskPtrs[taskList[i] - 1])
      taskPtrs[taskList[i] - 1](argv[1]);
    else {
      cout << "Task " << taskList[i] << " not found!" << endl << endl;
    }
  }

  cout << "Outputs stored in images folder\n\n";
}
