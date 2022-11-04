#include <iostream>
#include <queue>  // подключили библиотеку queue

using namespace std;

void main()
{
    queue<int> Q1;
    srand(time(NULL));
    int time_av, time_av_copy, time_av_const, dellete_element;
    int r_time_to_add,r_time_to_add_copy;
    int r_time_to_dell, r_time_to_dell_copy;
    int count_for_dell = 0;
    int count=1;


    cout << "Ведіть кількість одиниць часу які пройшли:";
    cin >> time_av;
    time_av_copy = time_av;
    time_av_const = time_av;
    cout << endl << " edding logs " << endl;
    do {
        r_time_to_add = rand() % 10 + 3;
        if (time_av >= r_time_to_add) {
            time_av -= r_time_to_add;
            cout << ":: LOG :: " << "Element " << count << "  added by " << time_av << " sec : time to adding " << r_time_to_add << endl;

            Q1.push(count);
            count++;
        }
        else {
            break;
        }
    } while (true);
    
    cout << endl << " delling logs " << endl;

    do {
        r_time_to_dell = rand() % 12 + 5;
        if (time_av_copy >= r_time_to_dell) {
            time_av_copy -= r_time_to_dell;
            dellete_element = Q1.front();
            Q1.pop();
            cout << ":: LOG :: " << "Element " <<  dellete_element << " by " << time_av_copy << " sec : time to managed " << r_time_to_dell << endl;
            count_for_dell++;
        }
        else {
            break;
        }

    } while (true);
    cout << "Now queue is ::     ";
    while (!Q1.empty()) {
        cout << " " << Q1.front() << " ";
        Q1.pop();
    }
}