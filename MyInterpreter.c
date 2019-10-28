/** 
 * 项目名称：我的简单的C语言编译器
 * 项目作者：恒成立
 * 项目时间：2019年10月29日
*/

int assembly; //汇编模式
int debug;    //调试模式

int main(int argc, char** argv){
    
    // 解析输入参数
    // -s
    if(argc > 0 && **argv == '-' && (*argv)[1] == 's'){
        assembly = 1;
        argc--;
        argv++;
    }
    // -d

}