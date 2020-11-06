#ifndef GDBINHEX_H
#define GDBINHEX_H

#include <Godot.hpp>
#include <Node.hpp>

namespace godot {

class GDBinHex : public Node {
	GODOT_CLASS(GDBinHex, Node)

public:
	static void _register_methods();
	void _init();

	PoolByteArray bin2hex(String bin);
    String hex2bin(PoolByteArray hex);
	float hex2float(PoolByteArray hex);
	PoolByteArray float2hex(float val);
};

}

#endif
