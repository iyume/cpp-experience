这个库保存了我大学里 C++ 面向对象、数据结构的作业和实验代码。

文件夹名称带 object 的为对象编程的实验课，大多数为简单的代码。

# Questions

- Empty function declaration occur to object constructor call

As a subsolution, write "void" into parameter in function declaration is thinked as redundant.

In my opinion, separating the obj declaration and callable function is a good way.

> Reference: [https://stackoverflow.com/questions/180172/default-constructor-with-empty-brackets](https://stackoverflow.com/questions/180172/default-constructor-with-empty-brackets)

- Usage of Double Ampersand (T&&)

Stay for update...

# Note

**compile flags (duplicated)**

`-c`                      Only run preprocess, compile, and assemble steps

`-S`                      Only run preprocess and compilation steps

`-g`                      Generate source-level debug information

`-o <file>`               Write output to `<file>`

`-pthread`                Support POSIX threads in generated code

`-v`                      Show commands to run and use verbose output

# Workspace Setting

`launch.json`

```
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Simple: build and debug active file",
            "type": "lldb",
            "request": "launch",
            "program": "${fileDirname}/a.out",
            "preLaunchTask": "Simple: clang++ build active file"
        },
        {
            "name": "Makefile: build and debug active file",
            "type": "lldb",
            "request": "launch",
            "program": "${fileDirname}/a.out",
            "preLaunchTask": "Makefile: clang++ build active file"
        }
    ]
}
```

`tasks.json`

```
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "Simple: clang++ build active file",
            "command": "clang++",
            "args": [
                "-I/absolute/path/to/library",
                "-std=c++17",
                "-stdlib=libc++",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/a.out",
                "-v"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "type": "shell",
            "label": "Makefile: clang++ build active file",
            "command": "make",
            "args": [],
            "options": {
                "cwd": "${fileDirname}"
            },
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

# Log

- 2021-04-05

Just currently what I think that cpp is a good language for its interesting and not bad-looking syntax.

- 2021-04-06

Begin to produce beautiful and readable cpp code, not as a developer but as a neko.
