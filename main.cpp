#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{

    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    const int max = 1000;

    string name[max];
    int age[max];
    double salary[max];
    char gender[max];

    int added= -1;
    int choice;
    bool loop = true;
    while(loop)
    {
        cout << "1) Add New Employee" << endl <<
             "2) Print All Employee" << endl <<
             "3) Delete By Age" << endl <<
             "4) Update Salary By Name" << endl;

        cin >> choice;
        if (!(choice >= 1 && choice <= 4)) {
            cout << "Invalid Choice" << endl;
        }

        if (choice == 1)
        {

            cout << "Enter Name: ";
            cin >> name[added + 1];
            cout << "Enter Age: ";
            cin >> age[added + 1];
            cout << "Enter Salary: ";
            cin >> salary[added + 1];
            cout << "Enter Gender(F/M): ";
            cin >> gender[added + 1];
            added++;
        }

        else if (choice == 2) {
            if (!name[0].empty()) {


                for (int i = 0; i <= added; i++) {
                    cout << name[i] << " " << age[i] << ' ' << salary[i] << ' ' << gender[i] << ' ' << endl;
                }
            } else {
                cout << "No Employees" << endl;
            }
        }
        else if (choice == 3)
        {
            cout<<" Enter ages"<<endl;
            int age1,age2;
            cin>>age1>>age2;
            int counter = 0;
            if (age2==age[added])
            {
                    name[added]="";
                    age[added]=0;
                    salary[added]=0;
                    gender[added]=0;
                added--;
            }
            for (int i = added ; i >=0 ; i-- ) {
                if (age[i] >= age1 && age[i] < age2) {
                    name[i] = name[i + 1];
                    age[i] = age[i + 1];
                    salary[i] = salary[i + 1];
                    gender[i] = gender[i + 1];
                    name[i + 1] = "";
                    age[i + 1] = 0;
                    salary[i + 1] = 0;
                    gender[i + 1] = 0;
                    counter++;
                }
            }
            added = added - counter;
        }

        else if (choice==4)
        {
            string employeeName; double Salary;
            cout<<"Enter the name with Salary ";
            cin>>employeeName>>Salary;
            bool check = true;
            for(int i = 0 ; i <= added ; i++)
            {
                if (name[i] == employeeName)
                {
                    salary[i] = Salary;
                    check = false;
                }
            }
            if ( check )
            {
                cout<<"Invalid Name"<<endl;
            }
        }
        cout<<"If you contunie press 1, if not press 0"<<endl;
        cin>>loop;
        cout << "==============================="<< endl;
    }


    return 0;
}