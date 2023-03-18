#include <iostream>

using namespace std;

struct StudentScore
{
    string firstName;
    string lastName;
    double averageScore;
};

void selectionSort(StudentScore &, int);
void displayData(StudentScore [], int);

int main()
{
    int totStudents;
    cout << "Enter the number of students: ";
    cin >> totStudents;

    StudentScore student[totStudents];

    for (int i = 0; i < totStudents; i++)
    {
        cout << "Enter the first name of student " << (i + 1) << ": ";
        cin >> student[i].firstName;
        cout << "Enter the last name of " << student[i].firstName << ": ";
        cin >> student[i].lastName;
        cout << "Enter the Average Score of " << student[i].firstName << ": ";
        cin >> student[i].averageScore;
        while(student[i].averageScore > 100 || student[i].averageScore < 0)
        {
            cout << "The average Score of the students must be between 0 and 100.\n";
            cout << "Enter the Average Score of " << student[i].averageScore << ": ";
            cin >> student[i].averageScore;
        }
    }

    // selectionSort(student, totStudents);

    int maxValue, maxIndex, i;
    StudentScore temp;

    for (i = 0; i < (totStudents - 1); i++)
    {
        maxValue = student[i].averageScore;
        maxIndex = i;
        temp = student[i];
        for (int index = i + 1; index < totStudents; index++)
        {
            if (student[index].averageScore > maxValue)
            {
                maxValue = student[index].averageScore;
                maxIndex = index;
                temp = student[maxIndex];
            }
        }
        student[maxIndex] = student[i];
        student[i] = temp;
    }
    displayData(student, totStudents);
}

/**
 * This function will display the information.
 * 
 * @param stu holds the StudentsScore.
*/
void displayData(StudentScore stu[], int totStu)
{
    for (int i = 0; i < totStu; i++)
    {
        cout << "Name: " << stu[i].firstName << " " << stu[i].lastName << endl;
        cout << "Score: " << stu[i].averageScore << endl;
        cout << "Rank: " << (i + 1) << endl;
    }
}

/**
 * This function will sort the students based on highest mark.
 *
 * @param students holds the students.
 * @param size holds the size of the array.
 */
// void selectionSort(StudentScore &students[], int size)
// {
    
// }

// int no;
// StudentScore student[no];
// student[2] milka
//     student[0] yohannes
//         student[1] menilik
// studenScore temp
// temp = student[2]
// student [2] = student[1]
// student[1] = temp