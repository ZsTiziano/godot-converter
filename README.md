## Godot engine converter - GDNative modules

    
![image](https://user-images.githubusercontent.com/21335398/98444682-550de000-2113-11eb-9366-ee8f60e7fa06.png)

### Info
This is a small godot engine library written in C ++ and integrated with GDNative.

### contained functions:

```bash
bin2hex(String) -> PoolByteArray
hex2bin(PoolByteArray) -> String 
hex2float(PoolByteArray) -> float 
float2hex(float) -> PoolByteArray 
```

### Usage

Clone the project

```bash
git clone https://github.com/ZsTiziano/godot-converter.git
```

### Add godot-cpp

We recommend using Git for managing your project. The instructions below assume
you're using Git. Alternatively, you can download the source code directly from
GitHub. In this case, you need to download both
[godot-cpp](https://github.com/GodotNativeTools/godot-cpp) and
[godot_headers](https://github.com/GodotNativeTools/godot_headers).

```bash
git submodule add https://github.com/GodotNativeTools/godot-cpp
git submodule update --init --recursive
```

Right now, our directory structure should look like this:

```text
godot-converter/
├─godot-cpp/
| └─godot_headers/
├─sample/
└─src/
```

### Compiling the C++ bindings library

The final step is to compile our C++ bindings library:

```bash
cd godot-cpp
scons platform=<your platform> generate_bindings=yes
cd ..
```

Replace `<your platform>` with either `windows`, `linux`, `osx` or `android`. If
you leave out `platform`, the target platform will automatically be detected
from the host platform.

The resulting library will be created in `godot-cpp/bin/`, take note of its name
as it'll differ depending on the target platform.

and in the project main folder:

```bash
scons platform=<your platform>
```

### For more information on GDNative consult the repository:

https://github.com/GodotNativeTools/godot-cpp


### License:

- **Code**: GPLv3

