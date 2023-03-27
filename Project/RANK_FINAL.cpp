/*      Name                ID
1. Newal Yeman          UGR/9108/14
2. Yigerem Bisrat       UGR/5026/14
3. Yodahe Gossa         UGR/9595/14
4. Yoak Moges           UGR/3567/14
5. Yohannes Belay       UGR/4223/14
*/
#include <iostream>
#include <iomanip>
#include <cstdlib> 
using namespace std;

struct StudentScore
{
    string firstName;
    string lastName;
    double averageScore;
};
void swap(StudentScore stu[], int a, int b);
void sorter(StudentScore [], int);
void displayData(StudentScore [], int);
int rank(StudentScore[], int);

int main()
{
    int totStudents;
    cout << "Enter the number of students: ";
    cin >> totStudents;
    StudentScore student[totStudents];

    for (int i = 0; i < totStudents; i++)
    {
    	system("cls");
        cout << "Enter the first name of student " << (i + 1) << ": ";
        cin >> student[i].firstName;
        cout << "Enter the last name of " << student[i].firstName << ": ";
        cin >> student[i].lastName;
        cout << "Enter the Average Score of " << student[i].firstName<< ": ";
        cin >> student[i].averageScore;
        while(student[i].averageScore > 100 || student[i].averageScore < 0)
        {
        	system("cls");
            cout << "The average Score of the students must be between 0 and 100.\n";
            cout << "Enter the Average Score of " << student[i].firstName<<" "<<student[i].lastName<< ": ";
            cin >> student[i].averageScore;
        }
    }
    
     
    sorter(student, totStudents);
    displayData(student, totStudents);
    return 0;
}


void displayData(StudentScore stu[], int totStu)
	{
	    system("cls");
	         cout<<left<<setw(10)<<"Rank"<<left<<setw(26)<<"Name "<<left<<setw(10)<<"Average Score"<<endl;
	
		for(int i = 0; i<totStu; i++)
		{
		     cout<<left<<setw(10)<<rank(stu,i)<<left<<setw(26)<<stu[i].firstName<<left<<setw(10)<<stu[i].averageScore<<endl;     
		
	    }
		  	
	}
void swap(StudentScore stu[], int a,int b)
{
	StudentScore temp; //or only temp
	temp = stu[a];
	stu[a] = stu[b];
	stu[b] = temp;
}
void sorter(StudentScore student[], int size)
{
	for (int i = 0; i<size-1; i++)
	{
		int max = i;
		for(int j = i+1; j<size; j++)
		{
			if(student[j].averageScore > student[max].averageScore)
			max = j;
		}
		if(i!=max)
		{
			swap(student,i,max);
		}
	}
}
int rank(StudentScore stu[], int position)
{
	    if (position==0)
	    return 1;
		else if(stu[position].averageScore==stu[position-1].averageScore)
		return rank(stu,position-1);
		else
		return position+1;
}


