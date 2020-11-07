extends Node

onready var CONV = preload("res://bin/gdbinhex.gdns").new()


func _on_bt_convert_pressed():
	var val : float = float($in.text)
	$Label_float2Hex.text = CONV.float2hex(val).hex_encode()
	
	$Label_hex2bin.text = CONV.hex2bin(CONV.float2hex(val))
	
	var hex1 = "0x"+CONV.bin2hex($Label_hex2bin.text.substr(0,8)).hex_encode()+" "
	var hex2 = "0x"+CONV.bin2hex($Label_hex2bin.text.substr(8,8)).hex_encode()+" "
	var hex3 = "0x"+CONV.bin2hex($Label_hex2bin.text.substr(16,8)).hex_encode()+" "
	var hex4 = "0x"+CONV.bin2hex($Label_hex2bin.text.substr(24,8)).hex_encode()+" "
	$Label_bin2hex.text = hex1+hex2+hex3+hex4
	
	$Label_hex2float.text = str(CONV.hex2float(CONV.float2hex(val)))

