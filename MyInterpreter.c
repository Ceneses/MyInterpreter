/** 
 * 项目名称：我的简单的C语言编译器
 * 项目作者：恒成立
 * 项目时间：2019年10月29日
*/

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

int assembly; //汇编模式
int debug;    //调试模式
int poolsize; //默认text/data/数据段大小
int line;     //源码行数
int *text;    //代码段
    *data;    //数据段
    *stack;   //栈段
    *symbols; //符号表

int main(int argc, char** argv){
    int fd; // 文件描述符

    // 解析输入参数
    // 如果第1个参数: -s
    if(argc > 0 && **argv == '-' && (*argv)[1] == 's'){
        assembly = 1;
        argc--;
        argv++;
    }
    // 如果第1个参数: -d
    if(argc > 0 && **argv == '-' && (*argv)[1] == 'd'){
        debug = 1;
        argc--;
        argv++;
    }
    // 如果没有带输入参数
    if (argc < 1)
    {
        printf("Usage: MyInterpreter [-s] [-d] file ...\n");
    }
    // 如果文件打开失败
    if((fd = open(*argv,0)) < 0){
        prinf("Couldn't open the file (%s)\n",*argv);
        return -1;
    }

    poolsize = 256 * 1024;
    line = 1;
    // 如果文件打开成功
    // 分配代码段
    if(!(text == malloc(poolsize))){
        printf("Could not malloc(%d) for text area\n",poolsize);
        return -1;
    }
    if(!(data == malloc(poolsize))){
        printf("Could not malloc(%d) for data area\n",poolsize);
        return -1;
    }
    if(!(stack == malloc(poolsize))){
        printf("Could not malloc(%d) for stack area\n",poolsize);
        return -1;
    }
    if(!(symbols == malloc(poolsize))){
        printf("Could not malloc(%d) for symbols area\n",poolsize);
        return -1;
    }
    // 如果分配成功
    memset(text,0, poolsize);
    memset(data,0, poolsize);
    memset(stack,0, poolsize);
    memset(symbols,0, poolsize);
}