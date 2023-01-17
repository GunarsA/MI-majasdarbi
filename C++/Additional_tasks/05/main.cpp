// PS > g++ main.cpp; ./a.exe

// Izveidot C++ programmas:
// Lietotājs ievada divus skaitļus un uz ekrāna izvada summu. Programmā no datu tipiem var būt definēti tikai norādes (pointer’i)
// Programmā ir dots veselu skaitļu masīvs - 10 elementi. Izveidot funkciju, kurā, izmantojot norādes, lietotājam tiek  paziņots vai viņa ievadītais skaitlis atrodas masīvā vai nē
// Lietotājs ievada simbola virkni. Izveidot funkciju, kura izmantojot norādi nosaka simbola virknes garumu un izdrukā uz ekrāna
// Programmā ir dots veselu skaitļu masīvs - 10 elementi. Izveidot funkciju, kurā, izmantojot norādi tiek izdrukāti masīva elementi pretējā secībā
// Izveidot funkciju, kurai tiek padota norāde uz veselu skaitļu masīvu (10 elementi) un elementu skaits. Funkcijai ir jāatgriež norāde uz masīva mazāko elementu.
// Funkcijas definīcija: int* minElelement(int* arr, int arrSize);
// Visos uzdevumos for, while ciklos un if nosacījumos izmantot norādes.
// 1.1. Aiznest darbības uz funkciju Sum - princips tas pats - visur ir jābūt tikai izmantotām norādēm
// 1.2. Izveidot pēc līdzīga principa funkciju Swap - izmantojot norādes samaina vērtības vietām
// 1.3. Izveidot funkciju, kurai padod 3 skaitļus - tā atrod mazāko un lielāko skaitli (izmantojot tikai norādes)
// 2.1. Funkcija ne tikai izdrukā vai skaitlis atrodas masīvā, bet arī tā atrašanās indeksu
// 2.2. Funkcijai padod divus masīvus - tā izdrukā uz ekrāna no abiem masīviem unikālos skaitļus (ciklos var izmantot vai nu iteratorus vai arī norādes)
// 2.3. Funkcija padod veselu skaitļu masīvu no 1..n. Piemēram, 1, 2, 3, 4, 5
// Dotā skaitļu virkne ir korekta. Bet var tikt padota virkne, kurai kāds no skaitļiem ir izlaists. Piemēram, 1, 2, 4, 5. Funkcijai ir jāizdrukā uz ekrāna vai ir virkne ir korekta. Ja nav korekta, tad arī skaitli. Nekorekts var būt ne vairāk kā 1 skaitlis. Ciklos izmantot norādes.
// 3.1. Izveidot funkciju, kura pirmos burtus aizstāj ar lieliem burtiem (izmantojot norādes)
// 3.2. Izveidot funkciju, kura (izmantojot norādes) izdrukā simbola virkni pretājā secībā
// 3.3. Izveidot funkciju, kura pasaka vai konkrēts simbols ir virknē (izmantojot norādes)
// 4.1. Tā pati funkcija izdrukā tikai tos skaitļus, kuri ir pirmskaitļi (izmantojot norādes)
// 4.2. Tā pati funkcija izdrukā arī augošā secībā (izmantojot norādes)
// 4.3. Tā pati funkcija izdrukā, katru otro elementu no masīva (izmantojot norādes)
// 5.1. Izveidot jaunu funkciju, kura atgriež masīva pēc skaita vidējo elementu (izmantojot norādes)
// 5.2. Izveidot jaunu funkciju, kura sakārto masīva skaitļus, izmantojot norādes, un izdrukā to uz ekrāna
// 5.3. Masīva elementus aizpilda lietotājs programmas darbības laikā, vispirms pajautājot cik liels masīvs būs. Pārējās funkcijas darbojas uz jaunā masīva elementiem

#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>
#include <iterator>

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
    cout << "1. Sum" << endl
         << "2. Find number in array" << endl
         << "3. Find string length" << endl
         << "4. Reverse array" << endl
         << "5. Get smallest element" << endl
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

double sum(const double &numA, const double &numB)
{
    return numA + numB;
}

void swap(double &numA, double &numB)
{
    numA += numB;
    numB = numA - numB;
    numA -= numB;
}

void biggestAndSmallest(const double &numA, const double &numB, const double &numC)
{
    cout << "Biggest: " << (numA > numB ? (numA > numC ? numA : numC) : (numB > numC ? numB : numC)) << endl;
    cout << "Smallest: " << (numA < numB ? (numA < numC ? numA : numC) : (numB < numC ? numB : numC)) << endl;
}

void first()
{
    cout << "Enter two numbers: ";
    double *numA = new double, *numB = new double;
    cin >> *numA >> *numB;

    cout << "Sum: " << sum(*numA, *numB) << endl;

    swap(numA, numB);
    cout << "Swaped values: " << *numA << " " << *numB << endl;

    cout << "Enter third number: ";
    double *numC = new double;
    cin >> *numC;
    biggestAndSmallest(*numA, *numB, *numC);

    delete numA, numB, numC;
}

void findElement(int arr[], int arrSize, int *find)
{
    for (const int *i = arr; i != (arr + arrSize); ++i)
        if (*i == *find)
        {
            cout << "Found element at position: " << i - arr << endl;
            return;
        }

    cout << "Element not found!" << endl;
}

void printUnique(int arr[], int arrSize, int arr2[], int arr2Size)
{
    cout << "Unique elements: ";

    for (const int *i = arr; i != (arr + arrSize); ++i)
    {
        bool found = false;
        for (const int *j = arr2; j != (arr2 + arr2Size); ++j)
        {
            if (*i == *j)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << *i << " ";
        }
    }

    for (const int *i = arr2; i != (arr2 + arr2Size); ++i)
    {
        bool found = false;
        for (const int *j = arr; j != (arr + arrSize); ++j)
        {
            if (*i == *j)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << *i << " ";
        }
    }

    cout << endl;
}

void findMistake(int arr[], int arrSize)
{
    if (arr[0] != 1)
    {
        cout << "Array is incorrect!" << endl;
        return;
    }

    for (const int *i = arr + 1; i != (arr + arrSize); ++i)
    {
        if (*i - 1 != *(i - 1))
        {
            cout << "Array is incorrect at postion " << i - arr << " with number " << *i << endl;
            return;
        }
    }

    cout << "Array is correct!" << endl;
}

void second()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Enter number to find: ";
    int *find = new int;
    cin >> *find;
    findElement(arr, 10, find);
    delete find;

    int arr2[10] = {5, 4, 3, 23, 3, 5, 5, 5, 5, 5};
    printUnique(arr, 10, arr2, 10);

    int *arr3Size = new int;
    cout << "Enter array size: ";
    cin >> *arr3Size;
    cout << "Enter " << *arr3Size << " digits: ";
    int *arr3 = new int[*arr3Size];
    for (int *i = arr3; i != arr3 + *arr3Size; ++i)
        cin >> *i;
    findMistake(arr3, *arr3Size);
}

void capitalize(string &str)
{
    istringstream *stringIn = new istringstream(str);
    str = "";
    string *temp = new string;

    while (*stringIn >> *temp)
    {
        if ((*temp)[0] >= 'a' && (*temp)[0] <= 'z')
            (*temp)[0] -= 32;

        str.append(*temp + " ");
    }

    str.pop_back();

    delete stringIn, temp;
}

void printReverse(const string &str)
{
    for (const char *i = str.c_str() + (str.length() - 1);; --i)
    {
        cout << *i;

        if (i == str.c_str())
            break;
    }
    cout << endl;
}

bool findChar(const string &str, const char &find)
{
    for (const char *i = str.c_str(); i != str.c_str() + str.length(); ++i)
        if (*i == find)
            return true;

    return false;
}

void third()
{
    string *str = new string;

    cout << "Enter string: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, *str);

    int *length = new int(0);
    for (const char *i = (*str).c_str(); *i; ++i)
    {
        ++(*length);
    }
    cout << "String length: " << *length << endl;

    capitalize(*str);
    cout << "Capitalized string: " << *str << endl;

    printReverse(*str);

    cout << "Enter character to find: ";
    char *character = new char;
    cin >> character;
    if (findChar(*str, *character))
        cout << "Character found!" << endl;
    else
        cout << "Character not found!" << endl;

    delete str, length, character;
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

void print(int arr[], int arrSize)
{
    cout << "Number in reverse: ";
    for (const int *i = &arr[arrSize - 1];; --i)
    {
        cout << *i << " ";

        if (i == arr)
            break;
    }
    cout << endl;

    cout << "Prime numbers: ";
    for (const int *i = arr; i != arr + arrSize; ++i)
        if (isPrime(*i))
            cout << *i << " ";
    cout << endl;

    cout << "Numbers in nondecreasing order: ";
    int *sorted = new int[arrSize];
    copy(arr, arr + arrSize, sorted);
    sort(sorted, sorted + arrSize);
    for (const int *i = sorted; i != sorted + arrSize; ++i)
        cout << *i << " ";
    cout << endl;
    delete[] sorted;

    cout << "Every 2nd number: ";
    for (const int *i = arr; i != arr + arrSize; i += 2)
        cout << *i << " ";
    cout << endl;
}

void fourth()
{
    int arr[10] = {0, 1, 2, 2, 4, 3, 6, 7, 3, 9};

    print(arr, 10);
}

int *minElelement(int *arr, int arrSize)
{
    int *ans = &arr[0];

    for (int *i = arr; i != (arr + arrSize); ++i)
    {
        if (*i < *ans)
        {
            ans = i;
        }
    }

    return ans;
}

const int *middleElement(const int *arr, const int &arrSize)
{
    return &arr[(arrSize - 1) / 2];
}

int *partition(int arr[], const int &low, const int &high)
{
    int *pivot = new int(arr[low]);
    int *i = new int(low - 1), *j = new int(high + 1);

    while (true)
    {
        do
        {
            (*i)++;
        } while (arr[*i] < *pivot);

        do
        {
            (*j)--;
        } while (arr[*j] > *pivot);

        if (*i >= *j)
        {
            delete pivot, i;
            return j;
        }

        swap(arr[*i], arr[*j]);
    }
}

void quickSort(int arr[], int low, const int &high)
{
    if (low < high)
    {
        int *pivot = partition(arr, low, high);

        quickSort(arr, low, *pivot);
        quickSort(arr, *pivot + 1, high);

        delete pivot;
    }
}

void fifth()
{

    cout << "Enter array size: ";
    int *size = new int;
    cin >> *size;

    cout << "Enter " << *size << " integers: ";
    int *arr = new int[*size];
    for (int *i = arr; i != arr + *size; ++i)
        cin >> *i;

    cout << "Smallest element: " << *minElelement(arr, *size) << endl;

    cout << "Middle element: " << *middleElement(arr, *size) << endl;

    quickSort(arr, 0, *size - 1);

    cout << "Sorted array: ";
    for (const int *i = arr; i != arr + *size; ++i)
        cout << *i << " ";
    cout << endl;
}
