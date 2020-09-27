#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;

int main()
{
    string s;
    while( getline( cin, s ) )
    {
        string oper;
        stringstream ss;
        char operators[1000] = {0};
        int operands[1000] = {0};
        int operators_length = 0;
        int operands_length = 0;
        ss.clear();
        ss.str(s);
        
        while( ss >> oper )
        {
            if( isdigit(oper[0]) )
            {
                int number = 0;
                for( int i = 0 ; i < oper.length() ; i++ )
                {
                    number *= 10;
                    number += oper[i]-'0';
                }
                operands[operands_length++] = number;
            }
            else
            {
                switch( oper[0] )
                {
                    case '+': case '-':
                        while( operators_length > 0 )
                        {
                            if( operators[operators_length-1] == '+' )
                            {
                                operands[operands_length-2] += operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }
                            else if( operators[operators_length-1] == '-' )
                            {
                                operands[operands_length-2] -= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }   
                            else if( operators[operators_length-1] == '*' )
                            {
                                operands[operands_length-2] *= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }   
                            else if( operators[operators_length-1] == '/' )
                            {
                                operands[operands_length-2] /= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }    
                            else if( operators[operators_length-1] == '%' )
                            {
                                operands[operands_length-2] %= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            } 
                            else break; 
                        }
                        operators[operators_length++] = oper[0];
                    break;
                    case '*': case '/': case '%': 
                        while( operators_length > 0 )
                        {
                            if( operators[operators_length-1] == '*' )
                            {
                                operands[operands_length-2] *= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }
                            else if( operators[operators_length-1] == '/' )
                            {
                                operands[operands_length-2] /= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }
                            else if( operators[operators_length-1] == '%' )
                            {
                                operands[operands_length-2] %= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }
                            else break;
                        }
                        operators[operators_length++] = oper[0];
                    break;
                    case '(':
                        operators[operators_length++] = oper[0];
                    break;
                    case ')':
                        for( int i = operators_length-1; operators[i] != '(' ; i-- )
                        {
                            if( operators[i] == '+' )
                            {
                                operands[operands_length-2] += operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }
                            if( operators[i] == '-' )
                            {
                                operands[operands_length-2] -= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }   
                            if( operators[i] == '*' )
                            {
                                operands[operands_length-2] *= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }   
                            if( operators[i] == '/' )
                            {
                                operands[operands_length-2] /= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }    
                            if( operators[i] == '%' )
                            {
                                operands[operands_length-2] %= operands[operands_length-1];
                                operands_length--;
                                operators_length--;
                            }      
                        }
                        operators_length--;
                    break;
                }
            }
        }
        for( operators_length-- ; operators_length >= 0 ; operators_length-- )
        {
            if( operators[operators_length] == '+' )
            {
                operands[operands_length-2] += operands[operands_length-1];
                operands_length--;
            }
            if( operators[operators_length] == '-' )
            {
                operands[operands_length-2] -= operands[operands_length-1];
                operands_length--;
            }   
            if( operators[operators_length] == '*' )
            {
                operands[operands_length-2] *= operands[operands_length-1];
                operands_length--;
            }   
            if( operators[operators_length] == '/' )
            {
                operands[operands_length-2] /= operands[operands_length-1];
                operands_length--;
            }      
            if( operators[operators_length] == '%' )
            {
                operands[operands_length-2] %= operands[operands_length-1];
                operands_length--;
            }        
        }
        cout << operands[0] << endl;
    }
    return 0;
}