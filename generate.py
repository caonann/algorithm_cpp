#!/usr/bin/python
# coding: utf-8
import argparse
import time
import os
# 生成新文件，自动生成一些注释和必要的内容
# 生成cpp文件，生成python文件
file_type_enum={
    'py':'python',
    'cpp':'c++',
    'h':'c++_header',
    'go':'golang'
}
file_type=None

def check_invalid(args):
    file = args.filename.split('.')[-1]
    if file not in ('py','cpp','h','go'):
        raise "filename illegal"
    global file_type 
    file_type = file_type_enum[file]

def write_file(func):
    def wrapper(filename):
        content = func(filename)
        with open(filename,'a+') as f:
            f.write(content)
    return wrapper

@write_file
def generate_cpp_file(filename):
    return f'''/*
 @filename   {filename}
 @author     caonan
 @date       {time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())}
 @reference     
 @url      
 @brief  
*/
#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){{
    return 0;
}}
'''

@write_file
def generate_python_file(filename):
    return f'''#!/usr/bin/python
# coding: utf-8
#filename   {filename}
#author     caonan
#date       {time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())}
#reference 
#url
#brief

if __name__ == "__main__":
    pass
'''

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='code generater for cpp python...')
    parser.add_argument('filename', 
                        type=str,
                        help='file name eg: a.cpp,b.py,c.go')
    
    args = parser.parse_args()
    check_invalid(args)
    if file_type == 'c++':
        generate_cpp_file(args.filename)
    elif file_type == 'python':
        generate_python_file(args.filename)

    path=f'{os.getcwd()}/{args.filename}'
    print(f'generate {args.filename} success in {path}')
