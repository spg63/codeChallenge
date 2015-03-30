//
//  main.cpp
//  numDigitToText
//
//  Created by Sean Grimes on 12/24/14.
//  Copyright (c) 2014 Grimes. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string numStr;// for user entered number
    
    // names for use in output
    string onesName[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string teensName[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    string tensName[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    string illion_preName[] = { "m", "b", "tr", "quadr", "quint", "sext", "sept", "oct", "non", "dec" };
    string decillion_preName[]={ "un", "duo", "tre", "quattuor", "quin", "sex", "septen", "octo", "novem" };
    
    char repeat = 'y';
    
    do// as long as user wishes to enter number for naming
    {
        cout << "Number = "; cin >> numStr;
        
        cout << "power = " << numStr.size() - 1 << endl;
        if( numStr.size() > 66 )
        {
            cout << "The number's too damn big! Try again." << endl;
            continue;
        }
        
        while( numStr.size()%3 != 0 )
            numStr = '0' + numStr;// pad the string with leading '0' until size = multiple of 3
        
        // for each group of 3 digits from most to least significant
        for( unsigned int i = 0; i < numStr.size(); i += 3 )
        {
            if( numStr[i + 0] > '0' )// treat the hundreds place
                cout << onesName[ numStr[i + 0] - '0' - 1 ] << " hundred ";
            
            if( numStr[i + 1] == '0' || numStr[i + 1] > '1' )// treat tens and ones digits for non-teens case
            {
                if( numStr[i + 1] > '1' ) cout << tensName[ numStr[i + 1] - '0' - 2 ] << " ";
                if( numStr[i + 2] > '0' ) cout << onesName[ numStr[i + 2] - '0' - 1 ] << " ";
            }
            else// special teens case
                cout << teensName[ numStr[i + 2] - '0' ] << " ";
            
            // naming each factor of 1,000
            unsigned int j = ( numStr.size() - i )/3;
            if( j == 2 ) cout << "thousand ";
            else if( j > 2 )
            {
                
                if( j <= 12 ) cout << illion_preName[ j - 3 ];// 'xx' before "illion" cases
                else if( j <= 21 ) cout << decillion_preName[ j - 13 ] << "dec";// 'xx' before "dec" + "illion" cases
                else if( j == 22 ) cout << "vigint";// special 'xx' before "vigint" + "illion" case
                
                cout << "illion ";// the "illion" suffix
            }
        }
        
        cout << endl << "Repeat? (y/n): ";
        cin >> repeat;
    }while( repeat == 'y' );
    
    
    cout << endl;
    return 0;
}