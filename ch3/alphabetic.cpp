#include "../ch2/std_lib_facilities.h"

int main()
{
    string s1, s2, s3;
    cout << "Insira três strings:\n";
    cin >> s1 >> s2 >> s3;

    if (s1 < s2)                  // comparação de s1 com s2
    {                             // (if1) se s1 menor  
        if (s1 < s3)              // compara s1 com s3
        {                         // (if2) se s1 menor
            cout << s1 + ", ";    // imprime s1
            if (s2 < s3)          // compara s2 e s3 
            {                     // (if3) se s2 menor
                cout << s2 + ", " // imprime s2 
                     << s3;       // e depois s3
            }
            else                         // (if3) se s3 menor
            {
                cout << s3 + ", " << s2; // imprime s3 e depois s2
            }
        }
        else                            // (if2) se s3 menor  
        {
            cout << s3 + ", "           // imprime s3
                 << s1 + ", " << s2;    // e depois s1 e s2
        }
    }
    else                        // (if1) se s2 menor
    {
        if (s2 < s3)            // compara s2 com s3
        {                       // (if2) se s2 menor
            cout << s2+", ";    // imprime s2
            if(s1 < s3)         // compara s1 e s3
            {                   // (if3) se s1 menor
                cout << s1+", " // imprime s1
                     << s3;     // e depois s3
            } else {            // (if3) se s3 menor
                cout << s3+", " // imprime s3
                     << s1;     // e depois s1
            }
        } else {                // (if2) se s3 menor
            cout << s3+", " << s2+", " << s1; // imprime tudo
        }
    }

    cout << endl;

    return 0;
}