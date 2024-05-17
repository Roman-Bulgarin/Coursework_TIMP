#include "md5.h"

using namespace CryptoPP;

string MD5_hash(string hash)
{

    
    string massange; 
    
    Weak1::MD5 hashmd4;  
    
    StringSource(hash, true, 
                    new HashFilter(hashmd4, 
                                    new HexEncoder( 
                                        new StringSink(massange)))); 
                                        
    
    return massange;
}
