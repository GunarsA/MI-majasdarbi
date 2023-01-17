// PS > g++ main.cpp; ./a.exe

// Lietotājs ievada tekstu. Doto tekstu saglabā failā.
// Dots masīvs ar 10 skaitļiem. Nepāra skaitļus saglabā file1.txt, pāra skaitļus saglabā failā file2.txt un pirmskaitļus saglabā failā file3.txt
// Ir dots file4.txt ar saturu:
// The syntax highlighting engine has been significantly improved, with new features like handling non-deterministic grammars, multi-line constructs, lazy embeds and syntax inheritance.
// Memory usage has been reduced, and load times are faster than ever.
// Eat snack.
// Write code.
// Eat snack.
// Programma nolasa failu un uz ekrāna izdrukā:
// Burtu skaitu
// Programma nolasa faila saturu no pirmā uzdevuma. lietotājs ievada vienu burtu. Programma saglabā saturu bez šī burta file5.txt failā.
// Lietotājs programmā ievada datumu un laiku. Piemēram, 13.10.2021 16:49
// Programma ievadīto laiku saglabā binārajā failā un to aizver ciet. Pēc tam nolasa no binārā faila ievadīto datumu un attēlo uz ekrāna. Visas darbības norealizēt kā funkcijas. Lietotājam pieejama izvēlne:
// 	1) Ievadit datumu un laiku
// 	2) Saglabāt binārajā failā
// 	3) Nolasīt un izdrukāt uz ekrāna
// 	4) Beigt programmu
// Izvēlnes iespējamie gadījumi ir jādefinē kā enum tips

// 1.1 -1.3. Izveidot izvēlni:
//     1) Izveidot jaunu failu
//     2) Parādīt jaunā faila nosaukumu
//     3) Apvienot jauno failu ar pirmās programmas failu
//     4) Izdzēst jauno failu
//     5) Beigt programmu
// - lietotājs ievada faila nosaukumu un pēc tam faila saturu
// - attēlo uz ekrāna jaunā faila nosaukumu. Ja nav jaunā faila, tad paziņo to lietotājam
// - jaunā faila saturu pievieno pirmās programmas failam. Ja nav jaunā faila, tad paziņo to lietotājam
// - izdzēš jauno failu. Ja nav jaunā faila, tad paziņo to lietotājam
// - pirms programmas beigšanas pārbauda vai gadījumā neeksistē kāds no jaunajiem failiem. Ja ir - tad paziņo lietotājam un piedāvā tos izdzēst. Ja lietotājs atsakās, tad programmu nevar pabeigt.
// * Jaunie faili - faili, kuri tika izveidoti programmas darbības laikā
// 2.1. Atrast summu visiem skaitļiem, kas dalās ar 3 un 5. Rezultātu ierakstīt failā file2_1.txt
// 2.2. Nolasīt visu programmu failus, iegūto saturu saglabāt string vai char[] vai char* mainīgajā (bez atstarpēm) - tādejādi izveidosies liels skaitlis
// 2.3. Izdalīt izveidoto skaitli ar 2 - rezultātu saglabāt failā file2_result.txt
// 3.1. Saskaita cik ir ciparu un atstarpju - izvada uz ekrāna rezultātus
// 3.2. Saskaita cik vārdu ir failā - izvada uz ekrāna rezultātus
// 3.3. Saskaita cik rindu ir failā - izvada uz ekrāna rezultātus
// 4.1. Lietotājs ievada divu simbolu virkni - saglabā saturu bez šiem burtiem file5.txt failā
// 4.2. Lietotājs ievada vārdu - saglabā saturu bez šī vārda file5.txt failā
// 4.3. Lietotājs ievada 2 burtus - saglabā saturu, kurā 1ais burts nomainīts pret otro burtu, file5.txt failā
// 5.1. - 5.3.
// Izveidot datu struktūru MiTalent, kurā ir sekojoši elementi: name, surname, age, hobby
// Izveidot izvēlni:
// 1) Attēlot talantus
// 2) Pievienot talantu
// 3) Izdzēst talantu
// 4) Beigt darbību
// - attēlo uz ekrāna failā visus pieejamos talantus (katru savā rindā)
// - Lietotājs pievieno jaunu, azpildot visu informāciju par talantu, dati tiek saglabāti failā
// - Izdzēš no faila lietotāja izvēlēto talantu (lietotājs ievada vārdu - ja eksistē, tad izdzēš, ja nav - tad paziņo lietotājam)
// - beidz programmas darbību

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <limits>
#include <vector>
#include <stack>

#define LEN 20

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

double get_number(const string msg);

void first();
void second();
void third();
void fourth();
void fifth();

int main()
{
    cout << "1: Save text to file" << endl
         << "2: Save numbers to files" << endl
         << "3. Read digit count from file" << endl
         << "4. Remove char " << endl
         << "5. Date" << endl
         << "6. End program" << endl;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)get_number("Choice: "));
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

double get_number(const string msg = "")
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

void first()
{
    cout << "Enter text to save to a file: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string str;
    getline(cin, str);

    ofstream fileOut("first.txt", ios::out);
    fileOut << str;
    fileOut.close();

    cout << "Text saved to [first.txt]!" << endl;

    cout << "1: Make a new file" << endl
         << "2: Show name of new file" << endl
         << "3. Add new file to original file" << endl
         << "4. Remove new file" << endl
         << "5. End program" << endl;

    stack<string> fileNames;

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)get_number("[1] Choice: "));
        switch (choice)
        {
        case one:
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter file name: ";
            string fileName;
            getline(cin, fileName);
            fileNames.push(fileName);

            cout << "Enter file content: ";
            string temp;
            getline(cin, temp);

            ofstream fileOut(fileName, ios::out);
            fileOut << temp;

            fileOut.close();

            break;
        }
        case two:
            if (fileNames.size())
                cout << "New file name: " << fileNames.top() << endl;
            else
                cout << "No new file created!" << endl;

            break;
        case three:
        {
            if (fileNames.size())
            {
                ofstream fileOut("first.txt", ios::out | ios::app);
                ifstream fileIn(fileNames.top(), ios::in);

                while (true)
                {
                    string temp;
                    getline(fileIn, temp);
                    fileOut << '\n'
                            << temp;

                    if (fileIn.eof())
                        break;
                }

                fileOut.close();
                fileIn.close();

                cout << "Content appended!" << endl;
            }
            else
            {
                cout << "No new file created!" << endl;
            }
            break;
        }
        case four:
        {
            if (fileNames.size())
            {
                remove(fileNames.top().c_str());
                fileNames.pop();

                cout << "File deleted!" << endl;
            }
            else
            {
                cout << "No new file created!" << endl;
            }

            break;
        }
        default:
            if (!fileNames.empty())
            {
                cout << "Can't end program without deleting files!" << endl
                     << "Do you wish to delete all created files now? (y|n)" << endl;
                char temp;
                cin >> temp;
                if (temp == 'y')
                {
                    while (!fileNames.empty())
                    {
                        remove(fileNames.top().c_str());
                        fileNames.pop();
                    }
                    ok = false;
                }
            }
            else
            {
                ok = false;
            }

            break;
        }
    } while (ok);
}

bool isPrime(const int &x)
{
    if (x <= 1)
        return false;

    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;

    return true;
}

string divideLargeNumber(const string &number, const int divisor)
{
    string result;

    int index = 0;
    int dividend = number[index] - '0';
    while (dividend < divisor)
    {
        dividend = dividend * 10 + (number[++index] - '0');
    }

    while (number.size() > index)
    {
        result += (dividend / divisor) + '0';
        dividend = (dividend % divisor) * 10 + number[++index] - '0';
    }

    if (result.length() == 0)
    {
        return "0";
    }

    return result;
}

void second()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    string fileNames[4] = {"file1.txt", "file2.txt", "file3.txt", "file2_1.txt"};
    fstream fileIO[4];
    for (int i = 0; i < 4; ++i)
        fileIO[i].open(fileNames[i], ios::out);

    int sum = 0;
    for (const &i : arr)
    {
        if (i & 1)
            fileIO[0] << i << ", ";
        else
            fileIO[1] << i << ", ";
        if (isPrime(i))
            fileIO[2] << i << ", ";
        if (!(i % 15))
            sum += i;
    }

    fileIO[3] << sum;

    for (int i = 0; i < 4; ++i)
        fileIO[i].close();

    for (int i = 0; i < 4; ++i)
        fileIO[i].open(fileNames[i], ios::in);

    string concat = "";

    for (auto &i : fileIO)
    {
        while (true)
        {
            char temp;
            i.get(temp);

            if (i.eof())
                break;

            if (temp >= '0' && temp <= '9')
                concat.push_back(temp);
        }
    }

    for (int i = 0; i < 4; ++i)
        fileIO[i].close();

    ofstream fileOut("file2_result.txt", ios::out);

    fileOut << divideLargeNumber(concat, 2);

    fileOut.close();
}

void third()
{
    ifstream fileIn("file4.txt", ios::in);

    int charCount = 0;
    while (true)
    {
        char temp;
        fileIn >> temp;

        if (fileIn.eof())
            break;

        if (temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')
            ++charCount;
    }

    cout << "Character count: " << charCount << endl;

    fileIn.clear();
    fileIn.seekg(ios::beg);

    int digitCount = 0, spaceCount = 0;
    while (true)
    {
        char temp;
        fileIn.get(temp);

        if (fileIn.eof())
            break;

        if (temp >= '0' && temp <= '9')
            ++digitCount;
        else if (temp == ' ')
            ++spaceCount;
    }

    cout << "Digit count: " << digitCount << endl
         << "Space cound: " << spaceCount << endl;

    fileIn.clear();
    fileIn.seekg(ios::beg);

    int wordCount = 0;
    while (true)
    {
        string temp;
        fileIn >> temp;

        if (fileIn.eof())
            break;

        ++wordCount;
    }

    cout << "Word count: " << wordCount << endl;

    fileIn.clear();
    fileIn.seekg(ios::beg);

    int lineCount = 0;
    while (!fileIn.eof())
    {
        string temp;
        getline(fileIn, temp);
        ++lineCount;
    }

    cout << "Line count: " << lineCount << endl;

    fileIn.close();
}

void fourth()
{
    ifstream fileIn("file4.txt", ios::in);
    ofstream fileOut("file5.txt", ios::out);

    cout << "Enter character to remove: ";
    char charToRemove;
    cin >> charToRemove;

    while (true)
    {
        char temp;
        fileIn.get(temp);

        if (fileIn.eof())
            break;

        if (temp != charToRemove)
            fileOut << temp;
    }

    fileIn.clear();
    fileIn.seekg(ios::beg);
    fileOut << "\n\n";

    cout << "Enter two character string of characters to remove: ";
    char str[2];
    cin >> str;

    while (true)
    {
        char temp;
        fileIn.get(temp);

        if (fileIn.eof())
            break;

        if (temp != str[0] && temp != str[1])
            fileOut << temp;
    }

    fileIn.clear();
    fileIn.seekg(ios::beg);
    fileOut << "\n\n";

    cout << "Enter word to remove: ";
    string word;
    cin >> word;

    while (!fileIn.eof())
    {
        string temp;
        getline(fileIn, temp);

        istringstream stringIn(temp);

        while (stringIn >> temp)
            if (temp != word)
                fileOut << temp << " ";

        if (!fileOut.eof())
            fileOut << "\n";
    }

    fileIn.clear();
    fileIn.seekg(ios::beg);
    fileOut << "\n\n";

    cout << "Enter two characters (1st to be replaced by 2nd): ";
    char find, replace;
    cin >> find >> replace;

    while (true)
    {
        char temp;
        fileIn.get(temp);

        if (fileIn.eof())
            break;

        if (temp == find)
            fileOut << replace;
        else
            fileOut << temp;
    }

    fileIn.close();
    fileOut.close();
}

struct MiTalent
{
    char name[LEN];
    char surname[LEN];
    int age;
    char hobby[LEN];
};

void fifth()
{
    cout << "1: Enter date" << endl
         << "2: Save date to file" << endl
         << "3. Read date from file" << endl
         << "4. End program" << endl;

    string date;
    date.resize(50);

    bool ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)get_number("[5] Choice: "));
        switch (choice)
        {
        case one:
            cout << "Enter date: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, date);
            break;
        case two:
        {
            ofstream fileOut("fifth.bin", ios::out | ios::binary);
            fileOut.write(date.data(), date.size());
            fileOut.close();
            break;
        }
        case three:
        {
            ifstream fileIn("fifth.bin", ios::in | ios::binary);
            if (fileIn.is_open())
            {
                fileIn.read(&date[0], date.size());
            }
            fileIn.close();
            cout << "Date: " << date << endl;
            break;
        }
        default:
            ok = false;
            break;
        }
    } while (ok);

    cout << "1. Show talents" << endl
         << "2. Add talent" << endl
         << "3. Remove talent" << endl
         << "4. End program" << endl;

    ok = true;
    do
    {
        const eNumber choice = static_cast<eNumber>((int)get_number("[5] Choice: "));
        switch (choice)
        {
        case one:
        {
            ifstream fileIn;
            fileIn.open("fifth_2.bin", ios::in | ios::binary);

            if (fileIn.is_open())
            {
                while (true)
                {
                    MiTalent currTalent;
                    fileIn.read((char *)&currTalent, sizeof(MiTalent));

                    if (fileIn.eof())
                        break;
                    else
                        cout << "-------------" << endl;

                    cout << "Name: " << currTalent.name << endl
                         << "Surname: " << currTalent.surname << endl
                         << "Age: " << currTalent.age << endl
                         << "Hobby: " << currTalent.hobby << endl;
                }
            }
            else
            {
                cout << "File doesn't exist!" << endl;
            }

            fileIn.close();

            break;
        }

        case two:
        {
            ofstream fileOut("fifth_2.bin", ios::out | ios::app | ios::binary);

            MiTalent talent;

            string temp;

            cout << "Name: ";
            cin >> temp;
            strcpy(talent.name, temp.c_str());

            cout << "Surname:";
            cin >> temp;
            strcpy(talent.surname, temp.c_str());

            talent.age = (int)get_number("Age: ");

            cout << "Hobby: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, temp);
            strcpy(talent.hobby, temp.c_str());

            fileOut.write((char *)&talent, sizeof(MiTalent));

            break;
        }
        case three:
        {
            cout << "Enter talent name to delete: ";
            string talent_name;
            cin >> talent_name;

            ifstream fileIn("fifth_2.bin", ios::in | ios::binary);

            vector<MiTalent> vector;

            if (fileIn.is_open())
            {
                bool found = false;
                while (true)
                {
                    MiTalent currTalent;
                    fileIn.read((char *)&currTalent, sizeof(MiTalent));

                    if (fileIn.eof())
                        break;

                    if (currTalent.name != talent_name)
                        vector.push_back(currTalent);
                    else
                        found = true;
                }
                if (found)
                {
                    ofstream fileOut("fifth_2.bin", ios::out | ios::binary);
                    for (const auto &i : vector)
                        fileOut.write((char *)&i, sizeof(MiTalent));

                    fileOut.close();

                    cout << "Deleted talent with name: " << talent_name << endl;
                }
                else
                {
                    cout << "Talent not found!" << endl;
                }
            }
            else
            {
                cout << "No talents saved!" << endl;
            }

            fileIn.close();

            break;
        }
        default:
            ok = false;
            break;
        }
    } while (ok);
}
