
#include "misc.h"

void printMe(string type){
    if (type == "banner"){
        char banner[] = \
"   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
        cout << endl << banner << endl << endl;
    }
}

// string codeName(string str1, string str2){
// string res = str1 +str2;
// transform(res.begin(), res.end(), res.begin(), ::tolower);
// res.erase(remove(res.begin(), res.end(), ' '), res.end());
// return res;
// }


