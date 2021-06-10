#include <stdio.h>
#include <stdlib.h>

int getNumOfStudents(void) {
  int numOfStudents;

  printf("Num of students: ");
  scanf("%d", &numOfStudents);
  return numOfStudents;
}

void getGrades(int* grades, int numOfStudents) {
  for (int i = 0; i < numOfStudents; i++) {
    printf("Enter grade: ");
    scanf("%d", &grades[i]);
  }
}

double averageGrade(int* grades, int numOfStudents) {
  double sum = 0;

  for (int i = 0; i < numOfStudents; i++) {
    sum += grades[i];
  }
  return sum / numOfStudents;
}

double aboveAverageGrade(int* grades, int numOfStudents) {
  double average = averageGrade(grades, numOfStudents);

  int numAboveAverage = 0;

  for (int i = 0; i < numOfStudents; i++) {
    if (grades[i] > average) {
      numAboveAverage++;
    }
  }
  return ((double)numAboveAverage / numOfStudents) * 100;
}

int main() {
  int numOfStudents = getNumOfStudents();
  int* grades = (int*)malloc(sizeof(int) * numOfStudents);

  getGrades(grades, numOfStudents);
  printf("%.2lf\n", aboveAverageGrade(grades, numOfStudents));

  free(grades);
  return 0;
}
