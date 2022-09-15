#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;


void eval( string expression, int type );

string a,b, x;



int main( int argc, char *argv[] )
{
    string expression = "";
    cout << "Input command  withount spase like(2 + 3 mast be 2+3) : ";
    cin >> expression;
    int type;
    cout << "Input x: ";
    cin >> x;
    cout << "Input a,b type" << endl;
    cout << "Input 0 if has a" << endl;
    cout << "Input 1 if has a but hasnt b" << endl;
    cout << "Input 2 if has b but hasnt a" << endl;
    cout << "Input 3 if has b alse has a" << endl;
    cout << "Input type: ";
    cin >> type;
    if (type == 1){
        cout << "Input a: ";
        cin >> a;
    } else if (type == 2){
        cout << "Input b: ";
        cin >> b;
    } else if (type == 3){
        cout << "Input a: ";
        cin >> a;
        cout << "Input b: ";
        cin >> b;
    }
    for ( int i = 1; i < argc; i++ )
    {
       expression = expression + argv[i];
    }
    cout << "Expression [ " << expression << " ] = " << endl;
    eval( expression, type );
}


void eval( string expression, int type )
{
    string program = "";
    program = program + "#include <cmath>\n";
    program = program + "#include <iostream>\n";
    program = program + "using namespace std;\n";
    program = program + "int main()\n";
    program = program + "{\n";
    if (type == 0){
        program = program + "float x = " + x + ";";
        program = program + "   cout << \"Result: \" <<";
        program = program + "" + expression;
        program = program + " << endl;\n";
    } else if (type == 1) {
        program = program + "float x = " + x + ";";
        program = program + "float a = " + a + ";";
        program = program + "   cout << \"Result: \" <<";
        program = program + "" + expression;
        program = program + " << endl;\n";
    } else if (type == 2){
        program = program + "float x = " + x + ";";
        program = program + "float b = " + b + ";";
        program = program + "   cout << \"Result: \" <<";
        program = program + "" + expression;
        program = program + " << endl;\n";
    } else if (type == 3){
        program = program + "float x = " + x + ";";
        program = program + "float a = " + a + ";";
        program = program + "float b = " + b + ";";
        program = program + "   cout << \"Result: \" <<";
        program = program + "" + expression;
        program = program + " << endl;\n";
    }
    program = program + "}";
    ofstream out( "abc.cpp" );
    out << program;
    out.close();
    system( "g++ -static-libstdc++ -o abc.exe abc.cpp" );
    system( "abc" );
    system("pause");
}