#include <iostream>
#include <string>
#include "structs.h"

//ES- Note: Don't use `using namespace` in a header
using namespace std;

//ES- Note: You can inline default values on structs and classes:
struct Student { //ES- Note: Camel is fine here, but most everything else has been very snakey.
                 // with a mixed case environment, POD or simple objects will often match primitive styles.
    int age           = -1;
    string first_name = "INVALID";
    string last_name  = "INVALID";
    int standard      = -1;
};
// But doing so will will automatically generate a default constructor
// invalidating the POD/PDS status of the type!


int hackerrank::structs()
{
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard << endl;

    return 0;
}
