#include "gdbinhex.h"
#include <iostream>
#include <sstream>
#include <iomanip>

//using namespace std;
using namespace godot;

void GDBinHex::_register_methods() {
	register_method("bin2hex", &GDBinHex::bin2hex);
	register_method("hex2bin", &GDBinHex::hex2bin);
	register_method("hex2float", &GDBinHex::hex2float);
	register_method("float2hex", &GDBinHex::float2hex);

}

void GDBinHex::_init(){

}

PoolByteArray GDBinHex::bin2hex(String bin){ 
	PoolByteArray hexarray;
    unsigned int res=0;
    for (size_t i=0; i<bin.length(); i++) {
         res = (res<<1)|(bin[i] -'0');
    } 
    hexarray.append(res);
	return hexarray;
}

String GDBinHex::hex2bin(PoolByteArray hexval){
    std::stringstream list;
    for (int i=0; i<hexval.size(); ++i){
        list << std::setfill('0') << std::setw(2) << std::right << std::hex << (int)hexval[i];
    }
    std::string s = list.str();
    std::string out;

     for(auto i: s){
        uint8_t n;
        if(i <= '9' and i >= '0')
            n = i - '0';
        else
            n = 10 + i - 'A';
        for(int8_t j = 3; j >= 0; --j)
            out.push_back((n & (1<<j))? '1':'0');
    }
    return String(out.c_str());
}

float GDBinHex::hex2float(PoolByteArray hexval){
	float f = 0.0;
	if(hexval.size()==4){
		f = *((float*)hexval.read().ptr());
	}
	return f;
}

PoolByteArray GDBinHex::float2hex(float val){
	PoolByteArray hexval;
	 union FloatToChar {
        float f;
        char  c[sizeof(float)];
    };
    FloatToChar x;
    x.f = val;
    for (size_t i=0; i<sizeof(float); i++) { 
        hexval.append(x.c[i]); 
    }
    return hexval;
}


