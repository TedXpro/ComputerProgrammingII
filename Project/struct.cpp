#include <iostream>

using namespace std;

struct StudentScore
{
    string firstName;
    string lastName;
    double averageScore;
};

void accept(StudentScore[], int);
void sort(StudentScore [], int);
void displayData(StudentScore [], int);

int main()
{
    int totStudents;
    cout << "Enter the number of students: ";
    cin >> totStudents;

    StudentScore student[totStudents];

    accept(student, totStudents);
    sort(student, totStudents);
    displayData(student, totStudents);
    return 0;
}

/**
 * This function will accept students information.
 * 
 * @param stu holds the students information.
 * @param size holds the number of students.
 */
void accept(StudentScore stu[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the first name of student " << (i + 1) << ": ";
        cin >> stu[i].firstName;
        cout << "Enter the last name of " << stu[i].firstName << ": ";
        cin >> stu[i].lastName;
        cout << "Enter the Average Score of " << stu[i].firstName << ": ";
        cin >> stu[i].averageScore;
        while (stu[i].averageScore > 100 || stu[i].averageScore < 0)
        {
            cout << "The average Score of the students must be between 0 and 100.\n";
            cout << "Enter the Average Score of " << stu[i].averageScore << ": ";
            cin >> stu[i].averageScore;
        }
    }
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
        cout << "\nName: " << stu[i].firstName << " " << stu[i].lastName << endl;
        cout << "Score: " << stu[i].averageScore << endl;
        cout << "Rank: " << (i + 1) << endl;
    }
}

/**
 * This function will sort the students based on highest mark
 * using seletion sort.
 *
 * @param students holds the students.
 * @param size holds the size of the array.
 */
void sort(StudentScore students[], int size)
{
    int maxValue, maxIndex, i;
    StudentScore temp;
    for (i = 0; i < (size - 1); i++)
    {
        maxValue = students[i].averageScore;
        maxIndex = i;
        temp = students[i];
        for (int index = i + 1; index < size; index++)
        {
            if (students[index].averageScore > maxValue)
            {
                maxValue = students[index].averageScore;
                maxIndex = index;
                temp = students[maxIndex];
            }
        }
        students[maxIndex] = students[i];
        students[i] = temp;
    }
}