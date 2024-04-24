<div align="center">
<img src="https://i.imgur.com/OvnHKac.png"></img>

[![C](https://img.shields.io/badge/language-C-%23A8B9CC.svg?style=plastic)](https://en.wikipedia.org/wiki/C_(programming_language))
[![C++](https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=plastic)](https://en.wikipedia.org/wiki/C%2B%2B)

</div>

## Main
<b>1.</b> Multicolored text (two methods: first is simple output, second is output with typewriter effect)<br>
<b>2.</b> Comments are present<br>
<b>3.</b> Full string encryption with skCrypt is present.<br>
<b>4.</b> There is a convenient system of macros in the data.h file, where you can easily change output colors, output content, typewriter speed and so on.<br>
<b>5.</b> Bypass VAC

## Usage
1. Don't forget to set the C++ language standard - 17 and enable multibyte encoding in the project settings `Configuration Properties -> Advanced -> Character Set`
2. Go to https://tomeko.net/online_tools/file_to_hex.php or any other site you like, and copy your cheat there
3. Click “Copy output to clipboard”
4. Open the file `injector.c`
5. Find the array binary with type `uint8_t`, instead of `NULL` insert the bytes you copied from the site
6. Write the name of your process in the `PROCESS_NAME` macro and comment out `PROCESS_NAME2` if your game has only one process
7. Change the strings, colors, print elements, etc. in the `data.h` file using multiple macros
