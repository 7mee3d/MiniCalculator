
//  Simi simple Calculator 

#include <iostream>
#include <cmath> 
#include <vector>
#include <iomanip>
#include <string> 
#include <thread>
#include <chrono>


const float kPI = 3.14159265F;
 
enum enEvenOdd {
    EVEN = 1 , 
    ODD = 2 
};

enum enPrimeOrNot {
    PRIME = 1,
    NOT_PRIME = 2
};

using namespace std; 

enEvenOdd isEvenOrOdd(int& number) {

    return ((number & 1) == 0) ? enEvenOdd::EVEN : enEvenOdd::ODD ;

}

enPrimeOrNot CheakNumberPrime(int& number) {

    bool isPrime{ true };
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            isPrime = false; 

            break;
        }
    }
    return (isPrime) ? enPrimeOrNot::PRIME : enPrimeOrNot::NOT_PRIME; 
}

string returnWordEvenOrOdd(enEvenOdd isEven) {
    string wordEvenOrOdd[2]{ "Even" , "Odd" };
    return wordEvenOrOdd[isEven - 1];
}

string returnWordPrimeOrNot(enPrimeOrNot isPrime) {
    string wordPrimeORNot[2]{ "Prime" , "Not Prime" };
    return wordPrimeORNot[isPrime - 1];
}

string tabs(int numberTabs) {

    string tab{ "" };
    for (int counter{ 1 }; counter <= numberTabs; counter++)
        tab += '\t';

    return tab;

}

int readNumber(string const message) {

    int number{};
    cout << tabs(2) << message;
    cin >> number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << tabs(2) << "Note!! Please Sir Enter the Number Not Character . Please Enter the Number Agian : ";
        cin >> number;
    }

    return number;

}

void clearSecreen(void) {
    system("cls"); 
}

//--------------------------------------------------------
// Menu Operation 

void printHeaderHelloProject(void) {
    cout << endl << endl;
    cout << tabs(2) << "|---------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|                             ++[ Menu Calculator ]++                             |\n";
    cout << tabs(2) << "|---------------------------------------------------------------------------------|\n\n";

}

void printInformationMenu(void) {

    cout << tabs(2);cout << "["; printf("%-*i", 2, 1);   cout << "]- Addition List Numbers" << setw(57)<< "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 2);   cout << "]- Substraction List Numbers" << setw(53) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 3);   cout << "]- Multiplication List Numbers" << setw(51) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 4);   cout << "]- Divion List Numbers" << setw(59) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 5);   cout << "]- Squraing number" << setw(63) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 6);   cout << "]- Squraing root" << setw(65) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 7);   cout << "]- Even or Odd number" << setw(60) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 8);   cout << "]- Power " << setw(72) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 9);   cout << "]- Tabel of items" << setw(64) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 10);  cout << "]- Prime or Not number" << setw(59) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 11);  cout << "]- Trigonometric Function" << setw(56) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 12);  cout << "]- Find Max Number or Min" << setw(56) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 13);  cout << "]- Absolute Number" << setw(63) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 14);  cout << "]- Logarithm Number" << setw(62) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 15);  cout << "]- Factorial Number" << setw(62) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 16);  cout << "]- Matrix Operation" << setw(62) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 2, 17);  cout << "]- Exit" << setw(76) << "|\n\n\n";

}

void footerTabelMenu(void) {
    cout << tabs(2);cout << "++ Note!!!!! - Please Sir Enter Numbers Positive of Operation" <<  "\n";
    cout << tabs(2) << "[4]-Divion , [5]-Squraing number , [6]-Squraing root , [8]-Power" << setw(40) << "\n\n";
    cout << tabs(2);cout << "++ Public Note!! - Enter the Number [17] Exit The Calculator\n\n";
    cout << tabs(2) << "|_______________________________********************______________________________|\n\n";
}

void printInforamtionMenuDivionFunction(void) {

    cout << tabs(2);cout << "["; printf("%-*i", 1, 1);   cout << "]- Find Modules Two number Floating" << setw(26) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 2);   cout << "]- Find Modules Two number Integer" << setw(27) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 3);   cout << "]- Divion Two number" << setw(41) << "|\n";  
    cout << tabs(2);cout << "["; printf("%-*i", 1, 4);   cout << "]- Find Fraction componet" << setw(36) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 5);   cout << "]- Find Integer componet" << setw(37) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 6);   cout << "]- Return Menu" << setw(48) << "|\n\n";

}

void printInforamtionMenuTabelOfItemFunction(void) {

    cout << tabs(2);cout << "["; printf("%-*i", 1, 1);   cout << "]- Integer Tabel" << setw(49) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 2);   cout << "]- String (Word) Tabel" << setw(43) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 3);   cout << "]- Return to Menu" << setw(49) << "|\n\n";
    cout << tabs(2) << "|----------------------------------------------------------------|\n";
}

void printInforamtionMenuTabelOfItemFunction_Integer(void) {
    
    cout << tabs(2);cout << "["; printf("%-*i", 1, 1);   cout << "]- Add Number In Tabel" << setw(43) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 2);   cout << "]- View the Tabel " << setw(47) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 3);   cout << "]- Clear All Tabel " << setw(46) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 4);   cout << "]- Return to Menu" << setw(48) << "|\n";
    cout << tabs(2) << "|----------------------------------------------------------------|\n";


}

void printInforamtionMenuTabelOfItemFunction_String(void) {

    cout << tabs(2);cout << "["; printf("%-*i", 1, 1);   cout << "]- Add Word In Tabel" << setw(44) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 2);   cout << "]- View the Tabel " << setw(46) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 3);   cout << "]- Clear All Tabel " << setw(45) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 4);   cout << "]- Return to Menu" << setw(48) << "|\n\n";
    cout << tabs(2) << "|---------------------------------------------------------------|\n";


}

void printInforamtionMenuTrigonometricFunction(void) {

    cout << tabs(2);cout << "["; printf("%-*i", 1, 1);   cout << "]- Cos Trigonometric " << setw(39) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 2);   cout << "]- Sin Trigonometric " << setw(39) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 3);   cout << "]- Tan Trigonometric " << setw(39) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 4);   cout << "]- Return The Menu " << setw(42) << "|\n\n";
    cout << tabs(2) << "|-----------------------------------------------------------|\n";
}

void printInforamtionMenuMaxAndMinFunction(void) {

    cout << tabs(2);cout << "["; printf("%-*i", 1, 1);   cout << "]- Max Operation " << setw(53) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 2);   cout << "]- Min Operation " << setw(53) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 3);   cout << "]- Return The Menu " << setw(52) << "|\n\n";
    cout << tabs(2) << "|---------------------------------------------------------------------|\n";
}

void printInforamtionMenuMatrixFunction(void) {

    cout << tabs(2);cout << "["; printf("%-*i", 1, 1);   cout << "]- Find main Diagonal " << setw(51) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 2);   cout << "]- Find Secoundary Diagonal " << setw(45) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 3);   cout << "]- Replace Row to Row " << setw(51) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 4);   cout << "]- Replace Column to Column  " << setw(44) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 5);   cout << "]- Search Number in Array and Return index  " << setw(29) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 6);   cout << "]- Multiply Number Constant in Matrix  " << setw(34) << "|\n";
  //  cout << tabs(2);cout << "["; printf("%-*i", 1, 7);   cout << "]- Multiply Number Constant in Matrix  " << setw(32) << "|\n";
    cout << tabs(2);cout << "["; printf("%-*i", 1, 7);   cout << "]- Return The Menu " << setw(55) << "|\n\n";
    cout << tabs(2) << "|------------------------------------------------------------------------|\n";
}


// Operation 

int summationNumbersArray(int* array, int& sizeArray) {

    int summationNumbers{ 0 };
    for (int counter{ 0 }; counter < sizeArray; counter++)
        summationNumbers += *(array + counter);

    return summationNumbers;
}

int SubstractionNumbersArray(int* array, int& sizeArray) {

    int SubstractionNumbers{ 0 };
    SubstractionNumbers =  *(array);
    for (int counter{ 1 }; counter < sizeArray; counter++)
        SubstractionNumbers -= *(array + counter); 



    return SubstractionNumbers;
}

int multiplicationNumbersArray(int* array, int& sizeArray) {

    int multiplicationNumbers{ 1 };
    for (int counter{ 0 }; counter < sizeArray; counter++)
       multiplicationNumbers *= *(array + counter);

    return multiplicationNumbers;
}

int Squaring(int& number) {

    return number * number; 

}

int power(int& base, int &expont) {

    int pow{ 1 };
    for (int i = 1; i <= expont; i++)
        pow *= base;

    return pow;
}

float mySqrtRootFunction(float &Number)
{
    return pow(Number, 0.5F);
}

void printElementInTabel(vector<int>& vec) {

    int static numberCount = 1; 
    if (!(vec.empty()))
        for (int& number : vec) {
            cout << tabs(2);
            printf("[%-*d]- %d\n", 2, numberCount, number);
            numberCount++;
        }
    else
        cout << tabs(2) << "Note!!! The Tabel is empty Okey ? ): \n\n";
}

void printElementInTabel_String(vector<string>& vec) {

    int  numberCount = 1;
    if (!(vec.empty()))
        for (string& line : vec) {
            cout << tabs(2);
            cout << "[" << numberCount << "]- " << line << endl;
            numberCount++;
        }
    else
        cout << tabs(2) << "Note!!! The Tabel is empty Okey ? ): \n\n";
}

int MaxNumbersOInArray(int* array, int& sizeArray) {

    int maxNumber{ *array };

    for (int counter{ 0 }; counter < sizeArray; counter++)
        if (maxNumber <= *(array + counter + 1))
             maxNumber = *(array + counter + 1);

    return maxNumber;
}

int minNumbersOInArray(int* array, int& sizeArray) {
    int minNumber{ *array }; 
    for (int counter{ 1 }; counter < sizeArray; counter++) 
        if (minNumber > *(array + counter)) 
            minNumber = *(array + counter);
    return minNumber;
}

int MyAbs (int& number) {

   int flagNegative = { -1 }; 
    return (number > 0) ? number : number * flagNegative; 

}

float LogNumberByTen(float& number) {

    return static_cast <float> ( (log10(number)) ) ;
}

int FactorialNumber(int& number) {
    int fact{ 1 };

    for (int counter{ 1 }; counter <= number; counter++)
        fact *= counter; 

    return fact; 
}

//Divion Function calc 

int ModulusTwoNumbers_Float(float& number1, float& number2) {

    int quotient = static_cast<int>(number1 / number2);  // القسمة الصحيحة
    float result = number1 - (quotient * number2);       // نحسب الباقي
    return static_cast<int>(result);                     // نحوله لـ int لو تبيه كعدد صحيح
}

int ModulusTwoNumbers_Integer(int& number1, int& number2) {

    return static_cast<int>( number1 % number2 );                    
}

float divionTwoNumbers(float& number1, float& number2) {
    return (number1 / number2);

}

float findPresionNumberFloatingPoint(float& number) {

    int numberOutingFractions = number; 
    float resultNumberFraction = number - numberOutingFractions; 

    return static_cast <float> ( resultNumberFraction ) ; 
}

int findIntegerNumberFloatingPoint(float& number) {

    int numberOutingFractions = number;

    return numberOutingFractions;
}

//-----------------------------------------
// Operation tabel  

int readNumberToFillArray(string const message , int count  ) {

    int number{};
    cout << tabs(2) << message << count << " ] : ";
    cin >> number;
    
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << tabs(2) << "Note!! Please Sir Enter the Number Not Character . Please Enter the Number Agian : ";
        cin >> number;
    }

    return number;

}

void fillArrayDynamiclyWithSize_Integer(int* array, int& sizeArray) {

    cout << endl;

    for (int counter{ 0 }; counter < sizeArray; counter++) {
       ( *(array + counter)) = readNumberToFillArray("Enter the Number [ " , counter + 1 ) ;

    }

}

void readElementToTabel(vector <int>& vec) {

    char Choise{ 'Y' };
    while (Choise == 'Y' || Choise == 'y') {
        int number{};
        number = { readNumber("Enter the number to adding the tabel : ") };

        vec.push_back(number);
        cout << tabs(2) << "Are you Adding anther ! Please Sir enter the [Y/y] to be Again Enterd : ";
        cin >> Choise;
    }
    cout << "\n\n";
    cout << tabs (2) << "Note!! - The Add Elements The Tabel is Seccssfuly (:\n\n";

}

void readElementToTabelString(vector <string>& vec) {
    char Choise{ 'Y' };
    cin.ignore(); 
    while (Choise == 'Y' || Choise == 'y') {
        string Line{};
        cout << tabs(2) << "Enter the word to adding the tabel : ";
        getline(cin, Line); 

        vec.emplace_back(Line);

        cout << tabs(2) << "Are you Adding anther ! Please Sir enter the [Y/y] to be Again Enterd : ";
        cin >> Choise;
        cin.ignore(); 
    }

    cout << "\n\n";
    cout << tabs(2) << "Note!! - The Add Elements The Tabel is Seccssfuly (:\n";
    cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
}

void clearAllElementInTabel(vector <int>& vec) {

    cout << endl << endl;

    if (vec.empty()) 
        cout << tabs(2) << "Note!!!!!!!!!! The Tabel Algready Empty ): \n";
    
    else {
        vec.clear();
        cout << tabs(2) << "The Clear The Tabel is Seccssfuly (:\n\n";
    }

    cout << endl << endl;

}

void clearAllElementInTabel_String(vector <string>& vec) {

    cout << endl << endl;

    if (vec.empty())
        cout << tabs(2) << "Note!!!!!!!!!! The Tabel Algready Empty ): \n";

    else {
        vec.clear();
        cout << tabs(2) << "The Clear The Tabel is Seccssfuly (:\n\n";
    }

    cout << endl << endl;

}

//---------------------------- 
//Header Operation 

void printHeaderSummationOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|----------------------------------------------------|\n";
    cout << tabs(2) << "|--------+[ Welcome The Addition Operation ]+--------|\n";
    cout << tabs(2) << "|----------------------------------------------------|\n\n";

}

void printHeaderSubstractionOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|---------------------------------------------------------|\n";
    cout << tabs(2) << "|---------+[ Welcome The Substraction Operation ]+--------|\n";
    cout << tabs(2) << "|---------------------------------------------------------|\n\n";

}

void printHeaderMultiplicationOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|---------------------------------------------------------------------|\n";
    cout << tabs(2) << "|-------------+[ Welcome The Multiplication Operation ]+--------------|\n";
    cout << tabs(2) << "|---------------------------------------------------------------------|\n\n";

}

void printHeaderDivionOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|-------------------------------------------------------------|\n";
    cout << tabs(2) << "|-------------+[ Welcome The Divion Operation ]+--------------|\n";
    cout << tabs(2) << "|-------------------------------------------------------------|\n\n";

}

void printHeaderSqauringOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|---------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Squaring Operation ]+-------------|\n";
    cout << tabs(2) << "|---------------------------------------------------------------|\n\n";

}

void printHeaderSqauringRootOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|--------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Squaring Root Operation ]+-------------|\n";
    cout << tabs(2) << "|--------------------------------------------------------------------|\n\n";

}

void printHeaderCheakEvenOrOddOperation(void) {

    clearSecreen();
    cout << tabs(2) << "|-------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Cheak Even or Odd Number Operation ]+-------------|\n";
    cout << tabs(2) << "|-------------------------------------------------------------------------------|\n\n";

}

void printHeaderCheakPrimeOrNotOperation(void) {
    clearSecreen();

    cout << tabs(2) << "|-------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Cheak Prime or Not Number Operation ]+------------|\n";
    cout << tabs(2) << "|-------------------------------------------------------------------------------|\n\n";

}

void printHeaderPowerOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Power Operation ]+-------------|\n";
    cout << tabs(2) << "|------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemOperation(void) {

    cout << tabs(2) << "|----------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome Tabel of Item Operation ]+-------------|\n";
    cout << tabs(2) << "|----------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemIntegerOperation(void) {

    clearSecreen();
    cout << tabs(2) << "|----------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome Integer Tabel of Item Operation ]+---------|\n";
    cout << tabs(2) << "|----------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemStringOperation(void) {


    cout << tabs(2) << "|---------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome String Tabel of Item Operation ]+---------|\n";
    cout << tabs(2) << "|---------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemIntegerOperationSectionAddNumbers(void) {


    cout << tabs(2) << "|---------------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome Integer Tabel of Item Deparament Add Numbers Operation ]+---------|\n";
    cout << tabs(2) << "|---------------------------------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemStringOperationSectionAddNumbers(void) {


    cout << tabs(2) << "|-----------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome String Tabel of Item Deparament Add Word Operation ]+---------|\n";
    cout << tabs(2) << "|-----------------------------------------------------------------------------------|\n\n\n";
    cout << tabs(2) << "Please Sir , Enter the word Not included the Spaces Becouse Not Fail Operation and View Logical Error (: \n\n";


}

void printHeaderTabelItemIntegerOperationSectionViewNumbers(void) {


    cout << tabs(2) << "|----------------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome Integer Tabel of Item Deparament View Numbers Operation ]+---------|\n";
    cout << tabs(2) << "|----------------------------------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemStringOperationSectionViewNumbers(void) {


    cout << tabs(2) << "|-------------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome String Tabel of Item Deparament View Words Operation ]+---------|\n";
    cout << tabs(2) << "|-------------------------------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemIntegerOperationSectionClearNumbers(void) {


    cout << tabs(2) << "|---------------------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome Integer Tabel of Item Deparament Clear All Numbers Operation ]+---------|\n";
    cout << tabs(2) << "|---------------------------------------------------------------------------------------------|\n\n";

}

void printHeaderTabelItemStringOperationSectionClearNumbersWords(void) {

    cout << tabs(2) << "|------------------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome String Tabel of Item Deparament Clear All Words Operation ]+---------|\n";
    cout << tabs(2) << "|------------------------------------------------------------------------------------------|\n\n";

}

void printHeaderTregomitricFunctionOperation(void) {

    cout << tabs(2) << "|-----------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome to trigonometric Operation ]+---------|\n";
    cout << tabs(2) << "|-----------------------------------------------------------|\n\n";

}

void printHeaderMaxAndMinFunctionOperation(void) {

    cout << tabs(2) << "|---------------------------------------------------------------------|\n";
    cout << tabs(2) << "|----------+[ Welcome to Find Max and Min Number Operation ]+---------|\n";
    cout << tabs(2) << "|---------------------------------------------------------------------|\n\n";

}

void printHeaderMaxOperation(void) {

    cout << tabs(2) << "|------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome Find Max Number Operation ]+-------------|\n";
    cout << tabs(2) << "|------------------------------------------------------------------|\n\n";

}

void printHeaderMinOperation(void) {

    cout << tabs(2) << "|------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome Find Min Number Operation ]+-------------|\n";
    cout << tabs(2) << "|------------------------------------------------------------------|\n\n";

}

void printHeaderAbsoluteValueOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|----------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Absolute Number Operation ]+-------------|\n";
    cout << tabs(2) << "|----------------------------------------------------------------------|\n\n";

}

void printHeaderLogNumberOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|-----------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Logarithm Number Operation ]+-------------|\n";
    cout << tabs(2) << "|-----------------------------------------------------------------------|\n\n";

}

void printHeaderFactorialNumberOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|-----------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Factorial Number Operation ]+-------------|\n";
    cout << tabs(2) << "|-----------------------------------------------------------------------|\n\n";

}

void printHeaderMatrixNumberOperation(void) {
    clearSecreen();
    cout << tabs(2) << "|------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Department Matrix Operation ]+-------------|\n";
    cout << tabs(2) << "|------------------------------------------------------------------------|\n\n";
}

void printHeaderMatrixNumberOperationFillMatrixHello(void) {
    clearSecreen();
    cout << tabs(2) << "|---------------------------------------------------------------------------------------|\n";
    cout << tabs(2) << "|--------------+[ Welcome The Department Matrix To Fill Matrix Operation ]+-------------|\n";
    cout << tabs(2) << "|---------------------------------------------------------------------------------------|\n\n";
}

//----------------------------------------------- 
// Result operation 

void printResultOperationSummation( int result) {

    cout << tabs(2) << "|----------------------------------------------------|\n";
    cout << tabs(2) << "Summation the all number to enterd is = " << result << '\n';
    cout << tabs(2) << "|----------------------------------------------------|\n";


}

void printResultOperationMultiplication(int result) {

    cout << tabs(2) << "|---------------------------------------------------------------------|\n";
    cout << tabs(2) << "Result finial multiplication the all number to enterd is = " << result << '\n';
    cout << tabs(2) << "|---------------------------------------------------------------------|\n";


}

void printResultOperationSubstraction(int result) {

    cout << tabs(2) << "|---------------------------------------------------------|\n";
    cout << tabs(2) << "Result finial Substraction all numbers to enterd = " ; printf("%+d", result);    cout << '\n';
    cout << tabs(2) << "|---------------------------------------------------------|\n";


}

void printResultOperationDivionInt(int &result) {

    cout << tabs(2) << "|-------------------------------------------------------------|\n";
    cout << tabs(2) << "Result finial Divion all numbers to enterd = "; printf("%+d", result);    cout << '\n';
    cout << tabs(2) << "|-------------------------------------------------------------|\n";


}

void printResultOperationDivionFloat(float& result) {

    cout << tabs(2) << "|-------------------------------------------------------------|\n";
    cout << tabs(2) << "Result finial Divion all numbers to enterd = "; printf("%+f", result);    cout << '\n';
    cout << tabs(2) << "|-------------------------------------------------------------|\n";


}

void printResultOperationSquaring(int &result) {

    cout << tabs(2) << "|---------------------------------------------------------------|\n";
    cout << tabs(2) << "Square the number to enterd is = "; printf("%+d", result);    cout << '\n';
    cout << tabs(2) << "|---------------------------------------------------------------|\n";


}

void printResultOperationSquaringRoot(float& result) {

    cout << tabs(2) << "|--------------------------------------------------------------------|\n";
    cout << tabs(2) << "Square root the number to enterd is = "; printf("%+.3f", result);    cout << '\n';
    cout << tabs(2) << "|--------------------------------------------------------------------|\n";

}

void printResultOperationTregomitric (float& result  ) {

    cout << tabs(2) << "|-----------------------------------------------------------|\n";
    cout << tabs(2) << "Result the angle to enterd is = "; printf("%+.6f", result);    cout << '\n';
    cout << tabs(2) << "|-----------------------------------------------------------|\n";


}

void printResultString(string& result , int& number  ) {

    cout << tabs(2) << "|--------------------------------------------------------------------|\n";
    cout << tabs(2) << "The Number to enterd [" << number <<"] is : " << result ,  cout << '\n';
    cout << tabs(2) << "|--------------------------------------------------------------------|\n";


}

void printResultOperationPower(int& result) {

    cout << tabs(2) << "|------------------------------------------------------------|\n";
    cout << tabs(2) << "Power the number to enterd is = "; printf("%+d", result);    cout << '\n';
    cout << tabs(2) << "|------------------------------------------------------------|\n";


}

void printResultOperationMax(int &result) {

    cout << tabs(2) << "|-------------------------------------------------------------------|\n";   
    cout << tabs(2) << "Max Number of the all number to enterd is = " << result << '\n';
    cout << tabs(2) << "|-------------------------------------------------------------------|\n";

}

void printResultOperationMin(int& result) {

    cout << tabs(2) << "|-------------------------------------------------------------------|\n";
    cout << tabs(2) << "Min Number of the all number to enterd is = " << result << '\n';
    cout << tabs(2) << "|-------------------------------------------------------------------|\n";
}

float readNumberFloating(string const message) {

    float number{};
    cout << tabs(2) << message;
    cin >> number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << tabs(2) << "Not Correct Value , Please Sir Try Agian enterd : ";
        cin >> number;
    }

    return static_cast <float> (number);

}

void printResultOperationAbsolute(int& result) {

    cout << tabs(2) << "|----------------------------------------------------------------------|\n";
    cout << tabs(2) << "Absolute the number to enterd is = "; printf("%+d", result);    cout << '\n';
    cout << tabs(2) << "|----------------------------------------------------------------------|\n";


}

void printResultOperationLog(float& result) {

    cout << tabs(2) << "|----------------------------------------------------------------------|\n";
    cout << tabs(2) << "Logarithm the number to enterd is = "; printf("%+.4f", result);    cout << '\n';
    cout << tabs(2) << "|----------------------------------------------------------------------|\n";


}

void printResultOperationFactorial(int& result) {

    cout << endl;
    cout << tabs(2) << "|-----------------------------------------------------------------------|\n";
    cout << tabs(2) << "Factorial the number to enterd is = "; printf("%+d", result);    cout << '\n';
    cout << tabs(2) << "|-----------------------------------------------------------------------|\n";

}

//------------------------------------------

void FunctionAddition(void) {

    clearSecreen();

    int sizeArray;


    printHeaderSummationOperation();
   //Create Array Dynamic 
    sizeArray = { readNumber("Enter the count number to be Addition all : ") };
    int* array = new int[sizeArray];

    fillArrayDynamiclyWithSize_Integer(array, sizeArray);

    int resultSummationOperation = summationNumbersArray(array, sizeArray);

    cout << endl;
    printResultOperationSummation (resultSummationOperation);

    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
   delete[]array;



}

void FunctionSubstraction(void) {

   

    int sizeArray;

    printHeaderSubstractionOperation();
    //Create Array Dynamic 
    sizeArray = { readNumber("Enter the count number to be Substraction all : ") };
    int* array = new int[sizeArray];

    fillArrayDynamiclyWithSize_Integer(array, sizeArray);

    int resultSubstractionOperation = SubstractionNumbersArray(array, sizeArray);

    cout << endl;
    printResultOperationSubstraction(resultSubstractionOperation);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();
    delete[]array;



}

void FunctionMultiplication(void) {

   

    int sizeArray;

    printHeaderMultiplicationOperation();
    //Create Array Dynamic 
    sizeArray = { readNumber("Enter the count number to be Multiplication all : ") };
    int* array = new int[sizeArray];

    fillArrayDynamiclyWithSize_Integer(array, sizeArray);

    int resultMultiplicationOperation = multiplicationNumbersArray(array, sizeArray);

    cout << endl;
    printResultOperationMultiplication( resultMultiplicationOperation);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();
    delete[]array;



}

void FunctionDivion(void);

void FunctionSqauring(void) {

 
    printHeaderSqauringOperation();

    int number{};
    number = { readNumber("Enter the Number : ") };
    cout << endl;
    int result = Squaring(number);
    printResultOperationSquaring(result); 
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();
}

void FunctionSqauringRoot(void) {


    printHeaderSqauringRootOperation();

    float number{};
    number = { readNumberFloating("Enter the Number : ") };
    cout << endl;

    if (number < 0) {
        cout << tabs(2) << "Note !!!! Enter Anther Time the Positive Number to be performing find Square root .\n\n";
        cout << tabs(2) << "Please Sir wait [3]seconds to return of menu and Thank You (:\n\n";
        this_thread::sleep_for(chrono::seconds(3));
    }
    else {
        float result = mySqrtRootFunction(number);
        printResultOperationSquaringRoot(result);
        cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
        this_thread::sleep_for(chrono::seconds(5));
        clearSecreen();
    }
}

void FunctionEvenOrOdd(void) {

    printHeaderCheakEvenOrOddOperation();

    int number{};
    number = { readNumber("Enter the Number : ") };
    cout << endl;
    string result = returnWordEvenOrOdd(isEvenOrOdd (number));
    printResultString(result , number );
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();

}

void FunctionPower(void) {

    
    printHeaderPowerOperation();

    int number{}, expont{} ;
    number = { readNumber("Enter the Number : ") };
    expont = { readNumber("Enter the expont : ") };
    cout << endl;
    if (number > 0 && expont) {
        int result = power(number, expont);
        printResultOperationPower(result);
        cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
        this_thread::sleep_for(chrono::seconds(5));
        clearSecreen();
    }
    else {
        cout << tabs(2) << "Note !!!! Enter Anther Time the Positive Number to be performing find Power Number .\n\n";
        cout << tabs(2) << "Please Sir wait [3]seconds to return of menu and Thank You (:\n\n";
        this_thread::sleep_for(chrono::seconds(3));
    }
}

void FunctionPrimeOrNot(void) {

    printHeaderCheakPrimeOrNotOperation();

    int number{};
    number = { readNumber("Enter the Number : ") };
    cout << endl;
    string result = returnWordPrimeOrNot(CheakNumberPrime(number));
    printResultString(result, number);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();

}

void FunctionTabel(void);

void Function_String_AddElement(vector <string>& vec) {

    clearSecreen();
    printHeaderTabelItemStringOperationSectionAddNumbers();
    readElementToTabelString(vec);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    clearSecreen();
}

void Function_String_ViewElement(vector <string>& vec) {
    static int numberCount = 1; 

    cout << endl << endl;
    clearSecreen();
    printHeaderTabelItemStringOperationSectionViewNumbers();
    printElementInTabel_String(vec);
    cout << endl << endl << endl;
    cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(7));


    numberCount = 1;
    clearSecreen();
}

void Function_String_ClearElement(vector <string>& vec) {

    cout << endl << endl;
    clearSecreen();
    printHeaderTabelItemStringOperationSectionClearNumbersWords();
    clearAllElementInTabel_String(vec);
    cout << endl << endl << endl;
    cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearSecreen();

}

void Function_Integer_AddElement(vector <int>& vec) {

    clearSecreen();
    printHeaderTabelItemIntegerOperationSectionAddNumbers();
    readElementToTabel(vec);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    clearSecreen();
}

void Function_Integer_ViewElement(vector <int>& vec) {

    cout << endl << endl;
    clearSecreen();
    printHeaderTabelItemIntegerOperationSectionViewNumbers();
    printElementInTabel(vec);
    cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";

    std::this_thread::sleep_for(std::chrono::seconds(7));
    clearSecreen();

}

void Function_Integer_ClearElement(vector <int>& vec) {

    cout << endl << endl;
    clearSecreen();
    printHeaderTabelItemIntegerOperationSectionClearNumbers();
    clearAllElementInTabel(vec);
    cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearSecreen();

}

void FunctionCos(void) {

    float result{};
    float angle{};
    float angleTr{};

    angle = { readNumberFloating("Enter the Angle : ") };
    angleTr = (::kPI / 180) * angle;
    result = cos(angleTr);
    printResultOperationTregomitric(result);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    
}

void FunctionSin(void) {

    float result{};
    float angle{};
    float angleTr{};

    angle = { readNumberFloating("Enter the Angle : ") };
    angleTr = (::kPI / 180) * angle;
    result = sin(angleTr);
    printResultOperationTregomitric(result);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));

}

void FunctionTan(void) {

    float result{};
    float angle{};
    float angleTr{};

    angle = { readNumberFloating("Enter the Angle : ") };
    angleTr = (::kPI / 180) * angle;
    result = tan(angleTr);
    printResultOperationTregomitric(result);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));

}

void FunctionTabel(void);

void TabelInteger(void) {
    vector <int> v;
    while (true) {
        clearSecreen();
        printHeaderTabelItemIntegerOperation();
        printInforamtionMenuTabelOfItemFunction_Integer();
        int choise;
        cout << endl << endl;
        cout << tabs(2) << "Enter the Choise : ";
        cin >> choise;

        switch (choise) {
        case 1:
            Function_Integer_AddElement(v);
            break;
        case 2:
            Function_Integer_ViewElement(v);
            break;
        case 3:
            Function_Integer_ClearElement(v);
            break;
        case 4:
            return; 
        }
    }
}

void TabelString(void) {

    vector <string> vec {""};

    while (true) {
        clearSecreen();
        printHeaderTabelItemStringOperation();
        printInforamtionMenuTabelOfItemFunction_String();
        int choise = { 0 };
        cout << endl << endl;
        cout << tabs(2) << "Enter the Choise : ";
        cin >> choise;

        switch (choise) {
        case 1:
            Function_String_AddElement(vec);
            break;
        case 2:
            Function_String_ViewElement(vec);
            break;
        case 3:
            Function_String_ClearElement(vec);
            break;
        case 4:
            return; 
        }
    }
}

void FunctionMax(void) {

    clearSecreen();

    int sizeArray;
    printHeaderMaxOperation();
    //Create Array Dynamic 
    sizeArray = { readNumber("Enter the count number to be Find Max Number : ") };
    int* array = new int[sizeArray];
    cout << tabs(2) << "!!Note , Please Sir enterd the Integer Numbers - Okey ? \n\n";

    fillArrayDynamiclyWithSize_Integer(array, sizeArray);

    int resultMaxNumberOperation = MaxNumbersOInArray(array, sizeArray);

    cout << endl;
    printResultOperationMax(resultMaxNumberOperation);

    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    delete[]array;
}

void FunctionMin(void) {

    clearSecreen();

    int sizeArray;
    printHeaderMinOperation();
    //Create Array Dynamic
    // 
    sizeArray = { readNumber("Enter the count number to be Find Min Number : ") };
    int* array = new int[sizeArray];
    cout << tabs(2) << "!!Note , Please Sir enterd the Integer Numbers - Okey ? \n\n";

    fillArrayDynamiclyWithSize_Integer(array, sizeArray);

    int resultMinNumberOperation = minNumbersOInArray(array, sizeArray);

    cout << endl;
    printResultOperationMin(resultMinNumberOperation);

    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    delete[]array;
}

void FunctionTreo(void) {
    while (true) {

        clearSecreen();
        printHeaderTregomitricFunctionOperation();

        printInforamtionMenuTrigonometricFunction();
        cout << endl;
        cout << tabs(2);
        int choise;
        cout << endl;
        choise = readNumber("Enter the Choise :");

        switch (choise) {

        case 1:
            FunctionCos();
            break;
        case 2:
            FunctionSin();
            break;
        case 3:
            FunctionTan();
            break;

        case 4: return;
        }
    }
}

void FunctionNumberMaxAndMin(void) {

    while (true) {

        clearSecreen();
        printHeaderMaxAndMinFunctionOperation();
        printInforamtionMenuMaxAndMinFunction();
        cout << endl;
        cout << tabs(2);
        int choise;

        cout << endl;
        choise = readNumber("Enter the Choise :");

        switch (choise) {

        case 1:
            FunctionMax();
            break;
        case 2:
            FunctionMin();
            break;
        case 3: return;
        }
    }
}

void FunctionAbsolute(void) {

    printHeaderAbsoluteValueOperation();

    int number{};
    number = { readNumber("Enter the Number : ") };
    cout << endl;
    int result = MyAbs(number);
    printResultOperationAbsolute(result);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();
}

void FunctionLog(void) {

    printHeaderLogNumberOperation();

    float number{};
    cout << endl << endl;
    cout << tabs(2) << "!!!! Note this operation to find Logarithm number by (Ten) Log10 . \n\n";
    number = { readNumberFloating("Enter the Number : ") };

    float result = LogNumberByTen(number);

    printResultOperationLog(result);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();
}

void FunctionFactorial(void) {

    printHeaderFactorialNumberOperation();

    int number{};
    cout << endl << endl;
    cout << tabs(2) << "!!!! Note this operation to find Factorial Integer type number \n\n";
    number = { readNumber("Enter the Number : ") };

    int result = FactorialNumber(number);

    printResultOperationFactorial(result);
    cout << tabs(2) << "Please Sir wait [5]seconds to return of menu and Thank You (:\n\n";
    this_thread::sleep_for(chrono::seconds(5));
    clearSecreen();
}
 
void MenuCalculator(void) {
    printHeaderHelloProject();
    printInformationMenu();
    footerTabelMenu();
}

void StartCalculator(void);

void fillArray2D(int* array[], int& row, int& column) {

    for (int counterI{ 0 }; counterI < row; counterI++) {
        for (int counterJ{ 0 }; counterJ < column; counterJ++) {
            cout << tabs(2) << "Enter the Element [" << counterI + 1 << "][" << counterJ + 1 << "]:";
            cin >> array[counterI][counterJ];
        }
        cout << endl;

    }
}

void findMainDiagonal(int* array[], int& row, int& column, int* arrayRows , int& size ) {

    size = { 0 };
    for (int counterI{ 0 }; counterI < row; counterI++) {

        for (int counterJ{ 0 }; counterJ < column; counterJ++) {
            if (counterI == counterJ)
                arrayRows[size++] = array[counterI][counterJ];
        }
    }
}

void findSecoundaryDiagonal(int* array[], int& row, int& column, int* arrayRows, int& size) {

    size = { 0 };
    for (int counterI{ 0 }; counterI < row; counterI++) {

        for (int counterJ{ 0 }; counterJ < column; counterJ++) {
            if (((row - ( counterI + counterJ ) ) == 1 ))
                arrayRows[size++] = array[counterI][counterJ];
        }
    }
}

void printArray2D(int* array[], int& row, int& column) {

    cout << endl; 
    cout << tabs(2) << "The Matrix to your enterd : \n\n";

    for (int i = 0; i < row; i++) {
        cout << tabs(3) <<"[ ";
        for (int j = 0; j < column; j++)
            cout << array[i][j] << " ";
        cout << "] \n";
    }
    cout << endl;

    cout << tabs(2) << "|------------------------------------------------------------------------|\n";

}

string returnSeparator(int& number, int& size) {
    return (size - 1 > number) ? ", " : " "; 
}

void printArrayMainDiagmoal(int* array, int& size) {

    cout << tabs(2) << "|------------------------------------------------------------------------|\n";
    cout << tabs(2) << "The Main Diagonal is array 2D : [ ";
    for (int counter{ 0 }; counter < size; counter++)
        cout << array[counter] << returnSeparator(counter, size);
    cout << " ] \n";
    cout << tabs(2) << "|------------------------------------------------------------------------|\n";

}

void printArraySecandaryDiagmoal(int* array, int& size) {

    cout << tabs(2) << "|------------------------------------------------------------------------|\n";
    cout << tabs(2) << "The Secandary Diagonal is array 2D : [ ";
    for (int counter{ 0 }; counter < size; counter++)
        cout << array[counter] << returnSeparator(counter, size);
    cout << " ] \n";
    cout << tabs(2) << "|------------------------------------------------------------------------|\n";

}

void replaceRowToRow(int* array[], int row, int column, int RowMain, int RowToReplace) {
    int* tempRow = new int[column];

    for (int j = 0; j < column; j++) {
        tempRow[j] = array[RowMain][j];
    }

    for (int j = 0; j < column; j++) {
        array[RowMain][j] = array[RowToReplace][j];
    }

    for (int j = 0; j < column; j++) {
        array[RowToReplace][j] = tempRow[j];
    }

    delete[] tempRow;
}

void replaceColumnToColumn(int* array[], int row, int column, int ColumnMain, int ColumnToReplace) {
    int* tempColumn = new int[row];

    for (int i = 0; i < row; i++) {
        tempColumn[i] = array[i][ColumnMain];
    }

    for (int i = 0; i < row; i++) {
        array[i][ColumnMain] = array[i][ColumnToReplace];
    }

    for (int i = 0; i < row; i++) {
        array[i][ColumnToReplace] = tempColumn[i];
    }

    delete[] tempColumn;
}

void FunctionMainDiagonal(int &row , int &column , int *Array2D[]) {

    cout << endl;
    printArray2D(Array2D, row, column);
    cout << endl << endl;
    int row1{ 0 }, row2{};
    int sizeR = min(row, column);
    int* arrayR = new int[sizeR];
    if (row % 2 == 0 && column % 2 == 0) {
        findMainDiagonal(Array2D, row, column, arrayR, sizeR);
        printArrayMainDiagmoal(arrayR, sizeR);
    }
    else {
        cout << endl;
        cout << tabs(2) << "!Note : Please the Row and Column is Square to start perform operation \n";
        cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
    }
}

void FunctionSecoundaryDiagonal(int& row, int& column, int* Array2D[]) {

    cout << endl;
    printArray2D(Array2D, row, column);
    cout << endl << endl;
    int sizeR = min(row, column);
    int* arrayR = new int[sizeR];

    if (row % 2 == 0 && column % 2 == 0) {
        cout << endl;
        findSecoundaryDiagonal(Array2D, row, column, arrayR, sizeR);
        printArraySecandaryDiagmoal( arrayR, sizeR);
        cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
    }
    else {
        cout << endl;
        cout << tabs(2) << "!Note : Please the Row and Column is Square to start perform operation \n";
        cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
    }
}

void FunctionReplaseRowToRow(int& row, int& column, int* Array2D[]) {
    int row1{ 0 }, row2{};
    cout << endl;
    printArray2D(Array2D, row, column);
    cout << endl << endl;


    row1 = { readNumber("Enter the Row Main , Please Sir Enter Index to Row not Poisitons ") };
    row2 = { readNumber("Enter the Row To Replase , Please Sir Enter Index to Row not Poisitons") };

    if (row % 2 == 0 && column % 2 == 0) {

        while (row < row1 || row < row1) {

            cout << tabs(2) << "Please Sir Enter Again row and Column is Square to be Perform operation you : ";
            cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(7));
            clearSecreen();
            row1 = { readNumber("Enter the Row Main , Please Sir Enter Index to Row not Poisitons ") };
            row2 = { readNumber("Enter the Row To Replase , Please Sir Enter Index to Row not Poisitons") };


        }
        replaceRowToRow(Array2D, row, column, row1, row2);
        printArray2D(Array2D, row, column);
        cout << endl;
        cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(7)); 


    }

    
    cout << endl;
    cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(7));
}

void FunctionReplaseColumnToColumn(int& row, int& column, int* Array2D[]) {
    int row1{ 0 }, row2{};

    printArray2D(Array2D, row, column);
    cout << endl << endl;

    int column3 = { readNumber("Enter the column Main , Please Sir Enter Index to column not Poisitons ") };
    int column4 = { readNumber("Enter the column To Replase , Please Sir Enter Index to column not Poisitons") };

    if (row % 2 == 0 && column % 2 == 0) {
        replaceColumnToColumn(Array2D, row, column, column3, column4);
        printArray2D(Array2D, row, column);
        cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
    }
    else {
            cout << tabs(2) << "Please Sir Enter Again row and Column is Square to be Perform operation you : ";
            cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(7));
    }
   

}      

void searchNumberInMatrix(int* array[], int row, int column, int numberToSearch) {

    bool Flagfound = false;

    cout << tabs(2) << "Positions where " << numberToSearch << " is found: ";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (array[i][j] == numberToSearch) {
                cout <<  "At [" << i << "][" << j << "]\n";
                Flagfound = true;
            }
        }
    }

    if (!Flagfound)
        cout << tabs(2) << "Number " << numberToSearch << " not found in the matrix.\n";
    
}

void FunctionSearchNumberInMatrix(int& row, int& column, int* Array2D[]) {

    cout << endl;
    printArray2D(Array2D, row, column);
    cout << endl << endl;
    cout << tabs(2) << "Enter the Number to search in matrix : ";
    int numberToSearch;
    cin >> numberToSearch;
    searchNumberInMatrix(Array2D, row, column, numberToSearch);
    cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(7));
}

void multiplyMatrixByConstant(int* array[], int row, int column, int &constant) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            array[i][j] *= constant;
        }
    }

}

void FunctionMultiplyingInMatrix(int& row, int& column, int* Array2D[]) {

    cout << endl;
    printArray2D(Array2D, row, column);
    cout << endl << endl;
    cout << tabs(2) << "Enter the Number to Multiply of matrix All Element  : ";
    int numberConstant;
    cin >> numberConstant;
    multiplyMatrixByConstant(Array2D, row, column, numberConstant);
     cout << tabs(2) << "Matrix after multiplication by " << numberConstant << ":\n";

         printArray2D(Array2D, row, column);
         cout << tabs(2) << "Please Sir wait [7]seconds to return of menu and Thank You (:\n\n";
         std::this_thread::sleep_for(std::chrono::seconds(7));
}

void FunctionMatrix(void) {


    printHeaderMatrixNumberOperationFillMatrixHello();

    cout << endl;
    int row = { readNumber("Enter the Row ") };
    cout << endl;

    int column = { readNumber("Enter the Row ") };

    int** array2D = new int* [row];

    for (int i = 0; i < row; i++)
        array2D[i] = new int[column];

    fillArray2D(array2D, row, column);


    while (true) {

        printHeaderMatrixNumberOperation();
        printInforamtionMenuMatrixFunction();
       
       int choise = { readNumber("Enter the Operation : ") };

        switch (choise) {

        case 1:
            FunctionMainDiagonal(row, column, array2D);
            break;
        case 2:
            FunctionSecoundaryDiagonal(row, column, array2D);
            break;
        case 3:
            FunctionReplaseRowToRow(row, column, array2D);
            break;
        case 4:
            FunctionReplaseColumnToColumn(row, column, array2D);
            break;
        case 5:
            FunctionSearchNumberInMatrix(row, column, array2D);
            break;
        case 6:
            FunctionMultiplyingInMatrix(row, column, array2D);
        case 7:
            return;

        }
    }
}

void ExitCalculator(void) {
    clearSecreen();
    cout << endl << endl;
    cout << tabs(2) << "Thank you sir to used My Calculator (:";
    cout << tabs(2) << "Programmed By Ahmed Jehad Ahmed \n";

    return;
}
int main()
{

    StartCalculator();
    //Ahmed Jehad Ahmed 
 }


void FunctionDivion(void) {

    clearSecreen();

    int choise{ 1 };
    float numberOne{}, numberTwo{};


    while (choise != 6) {

        cout << endl << endl << endl << endl;

        printHeaderDivionOperation();
        printInforamtionMenuDivionFunction();
        cout << tabs(2) << "|-------------------------------------------------------------|\n";


        cout << endl;
        choise = { readNumber("Enter the Operation : ") };
        cout << endl;

        switch (choise)
        {
           
        case 1:

            numberOne = readNumberFloating("Enter the Number One: ");
            numberTwo = readNumberFloating("Enter the Number Two: ");

            {
                float result = ModulusTwoNumbers_Float(numberOne, numberTwo);
                cout << endl;
                printResultOperationDivionFloat(result);
                
            }
            cout << endl;
            cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case 2:
            numberOne = readNumberFloating("Enter the Number One: ");
            numberTwo = readNumberFloating("Enter the Number Two: ");

            {
                int numberInteger1 = static_cast<int>(numberOne);
                int numberInteger2 = static_cast<int>(numberTwo);
                int result = ModulusTwoNumbers_Integer(numberInteger1, numberInteger2);
                cout << endl;

                printResultOperationDivionInt(result);
               
            }
            cout << endl;
            cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case 3:

            numberOne = readNumberFloating("Enter the Number One: ");
         
            numberTwo = readNumberFloating("Enter the Number Two: ");

            {
                float result = divionTwoNumbers(numberOne, numberTwo);
                cout << endl;

                printResultOperationDivionFloat(result);
               
            }
            cout << endl;
            cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case 4:
            numberOne = readNumberFloating("Enter the Number: ");
            {
                float result = findPresionNumberFloatingPoint(numberOne); 
                cout << endl;

                printResultOperationDivionFloat(result);
            
            }
            cout << endl;
            cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case 5:
            numberOne = readNumberFloating("Enter the Number: ");
            {
                int result = findIntegerNumberFloatingPoint(numberOne); 
                cout << endl;

                printResultOperationDivionInt(result);
            }
            cout << endl;
            cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;

        case 6:
            clearSecreen(); 
            StartCalculator();
            break;

        default:
            cout << endl;
            cout << tabs(2) << "Invalid Choice!\n";
            cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
            this_thread::sleep_for(chrono::seconds(2));
        }
      
        std::this_thread::sleep_for(std::chrono::seconds(4));
        clearSecreen();
    }
}

void FunctionTabel(void) {
    while (true) {

        clearSecreen();
        printHeaderTabelItemOperation();
        printInforamtionMenuTabelOfItemFunction();
        int choise = { 0 };
        choise = { readNumber("Enter the Operation : ") };

        switch (choise) {
        case 1:
            TabelInteger();
            break;
        case 2:
            TabelString();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}

void StartCalculator(void) {

    while (true) {

        clearSecreen();
        MenuCalculator();
        int choise = { 0 };
        choise = { readNumber("Enter the Operation : ") };

        switch (choise) {
        case 1:
            FunctionAddition();
            break;
        case 2:
            FunctionSubstraction();
            break;
        case 3:
            FunctionMultiplication();
            break;
        case 4:
            FunctionDivion();
            break;
        case 5:
            FunctionSqauring();
            break;
        case 6:
            FunctionSqauringRoot();
            break;
        case 7:
            FunctionEvenOrOdd();
            break;
        case 8:
            FunctionPower();
            break;
        case 9:
            FunctionTabel();
            break;
        case 10:
            FunctionPrimeOrNot();
            break;
        case 11:
            FunctionTreo();
            break; 
        case 12 : 
            FunctionNumberMaxAndMin();
            break;
        case 13 : 
            FunctionAbsolute(); 
            break; 
        case 14 :
            FunctionLog(); 
            break;
        case 15:
            FunctionFactorial();
            break;
        case 16 :
            FunctionMatrix();
            break;
        case 17:
            ExitCalculator();
            break;

        default:
            cout << endl;
            cout << tabs(2) << "Invalid Choice!\n";
            cout << tabs(2) << "Please Sir wait [2]seconds to return of menu and Thank You (:\n\n";
            this_thread::sleep_for(chrono::seconds(2));
        }
    }
}
