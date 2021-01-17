/** 
fanavard.ir
question: Optimal packaging 
team id: Cactus developers
Behnam Khalili
Faraz Golshahi
Mohammadreza Afshar
*/

#include <iostream>

#include <vector>

using namespace std;

/**
GussJ helps us to find a possiable 'j' that we can be sure the final answer isn't between 1 and this guess. 
@param arr Takes the size of every single object in vector.
@param numberOfObjects Takes the number of objects.
@param numberOfBoxes Takes the number of boxes.
@param sizeOfBoxes Takes the maximom size of boxes. 
@return Return a guess about the starting point of our objects to put in boxes. 
*/
int GuessJ(vector < int > arr, int numberOfObjects, int numberOfBoxes, int sizeOfBoxes);

/**
Check checks if our guess is true or not. if it isn't, we check the next objects in vector to find the answer.
@param guess Is the our guess about the starting point of our objects to put in boxes. 
@param arr Takes the size of every single object in vector.
@param numberOfObjects Takes the number of objects.
@param numberOfBoxes Takes the number of boxes.
@param sizeOfBoxes Takes the maximom size of boxes. 
@return Return true if the last object is put in the boxes when we start from the guess objct, or false if there is no box for last object.
*/
bool Check(int guess, vector < int > arr, int numberOfObjects, int numberOfBoxes, int sizeOfBoxes);

int main() {
   int numberOfObjects, numberOfBoxes, sizeOfBoxes, helpForInput;
   vector < int > objectSizes;

   // getting inputs:
   cin >> numberOfObjects >> numberOfBoxes >> sizeOfBoxes;
   for (int i = 0; i < numberOfObjects; i++) {
      cin >> helpForInput;
      objectSizes.push_back(helpForInput);
   }

   // main program:
   int guessAboutJ = GuessJ(objectSizes, numberOfObjects, numberOfBoxes, sizeOfBoxes);
   while (!Check(guessAboutJ, objectSizes, numberOfObjects, numberOfBoxes, sizeOfBoxes))
      guessAboutJ++;

   // showing the result:
   int numberOfObjectsThatArePutInBoxes = numberOfObjects - guessAboutJ;
   cout << numberOfObjectsThatArePutInBoxes;

   return 0;
}

// function definitions:

int GuessJ(vector < int > arr, int numberOfObjects, int numberOfBoxes, int sizeOfBoxes) {
   int sum = 0;
   for (int i = numberOfObjects - 1; i >= 0; i--) {
      sum += arr[i];
      if (sum >= sizeOfBoxes * numberOfBoxes)
         return i;
   }
   return 0;
}

bool Check(int guess, vector < int > arr, int numberOfObjects, int numberOfBoxes, int sizeOfBoxes) {
   vector < int > emptySpaceOfBoxes(numberOfBoxes, sizeOfBoxes);
   int idOfInProgressObject = guess;
   for (int i = 0; i < numberOfBoxes; i++) { // this for loop will work with boxes one-by-one
      bool temp = true;
      while (temp) { // this while loop will work with objects one-by-one
         emptySpaceOfBoxes[i] -= arr[idOfInProgressObject];
         if (emptySpaceOfBoxes[i] < 0) {
            emptySpaceOfBoxes[i] += arr[idOfInProgressObject];
            temp = false;
            idOfInProgressObject--;
            if (idOfInProgressObject == numberOfObjects)
               return true;
         }
         if (emptySpaceOfBoxes[i] == 0)
            temp = false;
         idOfInProgressObject++;
         if (idOfInProgressObject == numberOfObjects)
            return true;
      }
   }
   return false;
}