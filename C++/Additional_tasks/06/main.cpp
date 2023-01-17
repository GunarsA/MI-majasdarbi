// PS > g++ main.cpp; ./a.exe

// Izveidot struktūru Students ar datu laukiem: name, surname, age, email. Izveidot izvēlni:
// 1) Pievienot studentu
// 2) Nodzēst studentu
// 3) Izdrukāt visus ievadītos studentus
// 4) Beigt programmu
// 	Datu konteineri, kurā saglabāt studenta objektus, katrs var izvēlēties pats
// Dota struktūra:
// struct Point { double x; double y; };
// Izveidot funkciju, kura aprēķina starp 2 punktiem Eiklīda attālumu
// Programmas darbības laikā lietotājs ievada šos divus punktus un uz ekrāna attēlo attālumu. Lietotājs atkārtoti var ievadīt vēl citus divus punktus un iegūt rezultātu.
// Dota struktūra:
// struct Data { int num; char chr; };
// Izveidot sekojošas funkcijas, kas attēlo uz ekrāna struktūras Data datus:
// void printByValue(Data obj);
// void printByPointer(Data *ptrObj);
// void printByReference(Data &obj);
// Dota struktūra:
// struct { int hours; int minutes; int seconds; } clock_obj;
// Izveidot sekojošas funkcijas:
// Uzstāda laiku
// Attēlo esošo laiku
// Palielina laiku pa 1 sekundi
// Norealizēt, ka lietotājs pats izvēlas ko darīt, izmantojot izvēlnes.
// Dota struktūra:
// struct node { int num; node *next; };
// Izmantojot doto struktūru, realizēt steka (LIFO) funkcijas:
// Ievietot jaunu elementu
// Izņemt elementu no steka
// Pārbaudīt vai steks ir tukšs.
// Norealizēt, ka lietotājs pats izvēlas ko darīt, izmantojot izvēlnes.

#include <iostream>
#include <limits>
#include <map>
#include <cmath>

using namespace std;

enum eNumber
{
    zero,
    one,
    two,
    three,
    four,
    five
};

double getNumber(const string msg);

void first();
void second();
void third();
void fourth();
void fifth();

int main()
{
    cout << "1. Students" << endl
         << "2. Points" << endl
         << "3. Print" << endl
         << "4. Clock" << endl
         << "5. LIFO" << endl
         << "6. End program" << endl;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)getNumber("Choice: "));
        switch (choice)
        {
        case one:
            first();
            break;
        case two:
            second();
            break;
        case three:
            third();
            break;
        case four:
            fourth();
            break;
        case five:
            fifth();
            break;
        default:
            ok = false;
            break;
        }
    } while (ok);

    return 0;
}

double getNumber(const string msg = "")
{
    double input = -1;
    bool valid = false;
    do
    {
        cout << msg << flush;
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!valid);

    return (input);
}

struct Students
{
    string name;
    string surname;
    int age;
    string email;
};

void first()
{
    cout << "1. Add new student" << endl
         << "2. Remove student" << endl
         << "3. Output all students" << endl
         << "4. End program" << endl;

    map<string, Students> map;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)getNumber("[1] Choice: "));
        switch (choice)
        {
        case one:
        {
            cout << "Enter students details: " << endl;

            Students currStudent;
            cout << "Name: ";
            cin >> currStudent.name;
            cout << "Surname: ";
            cin >> currStudent.surname;
            currStudent.age = getNumber("Age: ");
            cout << "Email: ";
            cin >> currStudent.email;

            if (map.find(currStudent.name) != map.end())
                cout << "Student by that name already exists! Wasn't added!" << endl;
            else
                map[currStudent.name] = currStudent;

            break;
        }
        case two:
        {
            cout << "Enter student name to remove: ";
            string studentToRemove;
            cin >> studentToRemove;

            if (map.find(studentToRemove) != map.end())
                map.erase(studentToRemove);
            else
                cout << "Student doesn't exist!" << endl;

            break;
        }
        case three:
            for (const auto &i : map)
                cout << "Name [" << i.first << "] Surname [" << i.second.surname << "] Age [" << i.second.age << "] Email [ " << i.second.email << "]" << endl;
            break;
        default:
            ok = false;
            break;
        }
    } while (ok);
}

struct Point
{
    double x;
    double y;
};

double getEuclideanDistance(Point a, Point b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) * 1.0);
}

void second()
{
    cout << "1. Get distance between points" << endl
         << "2. End program" << endl;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)getNumber("[2] Choice: "));
        switch (choice)
        {
        case one:
        {
            Point firstPoint, secondPoint;

            cout << "Enter first point (x,y): ";
            firstPoint.x = getNumber();
            firstPoint.y = getNumber();

            cout << "Enter second point (x,y): ";
            secondPoint.x = getNumber();
            secondPoint.y = getNumber();

            cout << "Distance between points: " << getEuclideanDistance(firstPoint, secondPoint) << endl;

            break;
        }
        default:
            ok = false;
            break;
        }
    } while (ok);
}

struct Data
{
    int num;
    char chr;
};

void printByValue(Data obj)
{
    cout << obj.num << " " << obj.chr << endl;
}
void printByPointer(Data *ptrObj)
{
    cout << (*ptrObj).num << " " << (*ptrObj).chr << endl;
}
void printByReference(Data &obj)
{
    cout << obj.num << " " << obj.chr << endl;
}

void third()
{
    Data *object = new Data{23, 'B'};

    cout << "Print by value: " << endl;
    printByValue(*object);

    cout << "Print by pointer: " << endl;
    printByPointer(object);

    cout << "Print by reference: " << endl;
    printByReference(*object);
}

void fourth()
{
    cout << "1. Set time" << endl
         << "2. Show time" << endl
         << "3. Increment time by one" << endl
         << "4. End program" << endl;

    struct
    {
        int hours;
        int minutes;
        int seconds;
    } clock_obj;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)getNumber("[4] Choice: "));
        switch (choice)
        {
        case one:
        {
            clock_obj.hours = getNumber("Enter hours: ");
            clock_obj.minutes = getNumber("Enter minutes: ");
            clock_obj.seconds = getNumber("Enter seconds: ");

            break;
        }
        case two:
            cout << "Hours: " << clock_obj.hours << endl
                 << "Minutes: " << clock_obj.minutes << endl
                 << "Seconds: " << clock_obj.seconds << endl;

            break;
        case three:
            if (clock_obj.seconds < 59)
            {
                ++clock_obj.seconds;
            }
            else
            {
                if (clock_obj.minutes < 59)
                {
                    ++clock_obj.minutes;
                }
                else
                {
                    if (clock_obj.hours < 23)
                        ++clock_obj.hours;
                    else
                        clock_obj.hours = 0;

                    clock_obj.minutes = 0;
                }
                clock_obj.seconds = 0;
            }

            break;
        default:
            ok = false;
            break;
        }
    } while (ok);
}

struct node
{
    int num;
    node *next;
};

class stack
{
private:
    node *_top;
    int _size;

public:
    stack()
    {
        this->_top = new node{0, nullptr};
        this->_size = 0;
    }
    ~stack()
    {
        while (this->_size)
            (void)this->pop();

        delete this->_top;
    }
    void push(int element)
    {
        if (!(this->_size)++)
            this->_top->num = element;
        else
            this->_top = new node{element, this->_top};
    }
    int pop()
    {
        if (!this->_size)
            return 0;

        --(this->_size);

        if (!this->_size)
            return this->_top->num;

        node *nextNode = this->_top->next;
        int currValue = this->_top->num;

        delete this->_top;
        this->_top = nextNode;

        return currValue;
    }
    int size()
    {
        return this->_size;
    }
};

void fifth()
{
    cout << "1. Add new element" << endl
         << "2. Remove element" << endl
         << "3. Output size" << endl
         << "4. End program" << endl;

    stack stack;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)getNumber("[5] Choice: "));
        switch (choice)
        {
        case one:
        {
            int temp = getNumber("Enter number to add: ");

            stack.push(temp);

            break;
        }
        case two:
            if (stack.size())
                cout << "Removed [" << stack.pop() << "] from stack" << endl;
            else
                cout << "Stack is empty" << endl;
            break;
        case three:
            cout << "Size of stack: " << stack.size() << endl;
            break;
        default:
            ok = false;
            break;
        }
    } while (ok);
}
