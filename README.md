# Instructions
* Take your primary exe and open it in HxD or 010 - cntrl+a copy as C
* Paste into encrypt.cpp
* Compile and run encrypt.cpp - shellcode.txt should be created
* Copy the char array from shellcode.txt and replace it wit rawData[] in runPE.cpp
* compile to produce your final stub (runPE.exe)
* Execution will load into memory, un encrypt using XOR key and execute
