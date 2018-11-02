#include <iostream>
#include "char_stack.h"
#include <string>
#include <stdio.h>


using namespace std;

bool pair_check(char open, char close)
{
    if(open == '(' && close == ')') 
    {
        return true;
    }

    else if(open == '[' && close == ']')
    {
        return true;
    }
    else if(open == '{' && close == '}') 
    {
        return true;
    }
	return false;
}

char correct (char open)
{
	if (open == '(')
	{
		return ')';
	}
	else if (open == '[')
	{
		return ']';
	}
	return '}';
}

bool tabcheck(char e)
{
	return e == '\t';
}




int main()
{
    char_stack s;	//create stack
    int line = 0;	//line counter
    char c[250];	//chracter array	
    char l;			//pop to this varaible
    while(cin.peek() != EOF)	//while not EOF
    {
    	line++;				//increment line
		cin.getline(c, 250);	//get line and store in char array
		int len = cin.gcount();	//get length of line
		int i = 0;
		for(i; i< len; i++ )	//traverse through array
		{
	    	if(c[i] == '(' || c[i] == '[' || c[i] == '{')
	    	{
                s.push(c[i]);	//push if opening bracket
            }
	    
	    	else if( c[i] == ')' || c[i] == ']' || c[i] == '}')

	    	{
                if (s.empty())
                {
                    cout << "Error on line " << line << ": Too many " << c[i] << endl; //routine 
                    for(int j = 0; j<=i; j++)
                    {
                    	cout << c[j];
                    }
                    cout << endl;
                    for (int k =0; k<= i; k++)
                    {
                    	if(tabcheck(c[k]))
                    	{
                    		cout << '\t'; /* if tab character, print tab instead of white space*/
                    	}
                    	else
                    	{
                    		cout << " ";
                    	}
                    }
                    for (int z = i+1; z<len; z++)
                    {
                    	cout << c[z];
                    }
                    cout << endl;                    

                    return 0;
            	}
               	
               	l = s.pop();
                if (!pair_check(l,c[i]))	// function call to check if pair
                {
                    cout << "Error on line " << line << " Read " << c[i] << ", expected " << correct(l) << endl; //function call to correct
                    for(int j = 0; j<=i; j++)
                    {
                    	cout << c[j];
                    }
                    cout << endl;
                    for (int k =0; k<= i; k++)
                    {
                    	if(tabcheck(c[k]))
                    	{
                    		cout << '\t';
                    	}
                    	else
                    	{
                    		cout << " ";
                    	}
                    }
                    for (int z = i+1; z<len; z++)
                    {
                    	cout << c[z];
                    }
                    cout << endl; 
                    return 0;
                }
            }
        }
	}

    if (!s.empty())
    {
		char d = s.pop();
		cout << "Error at end of file: Too many " << d << endl;
		return 0;
    }
    cout << "No Errors Found" << endl;
    return 0;
} 
