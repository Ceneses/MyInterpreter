/** 
 * 项目名称：我的简单的C语言编译器
 * 项目作者：恒成立
 * 项目时间：2019年10月29日
*/

int assembly; //汇编模式
int debug;    //调试模式

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
    // 如果文件打开成功
    
}