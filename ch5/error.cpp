#include "../ch2/std_lib_facilities.h"

int main()
    try
    {
        error("teste");
        return 0;
    }
    catch(runtime_error& e)
    {
        cerr << "error: " << e.what() << endl;
        return 1;
    }
