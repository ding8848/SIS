//
//  Maintain.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/14.
//

#include "Maintain.h"

int Maintain(void) {
    char ch;
    system("stty -icanon");
    int success, saveFlag, flag = 4;
    success = VerificationIdentity();
    if(success == 0) {
        printf("\n 您权限不够！！！");
        flag = 5;
    } else {
        do {
            printf("\n\t\t******** (Write/Maintain)维护 ********\n");
            printf("\t\t*         A(Add).增加        *\n");
            printf("\t\t*         S(Set).修改        *\n");
            printf("\t\t*         D(Del).删除        *\n");
            printf("\t\t*         Q(Quit).退出        *\n");
            printf("\t\t***************************************\n");
            printf("\n 请输入您的选择(A/S/D/Q): ");
            ch = getchar();
            switch(tolower(ch)) {
                case 'a': flag = Add(); //  增加学生信息
                          break;
                case 's': flag = Set(); //  修改学生信息
                          break;
                case 'd': flag = Del(); //  删除学生信息
                          break;
                case 'q': flag = 0; //  退出
                          break;
                default:  printf("\n 输入错误，请重新输入您的选择: ");
                          break;
            }
        } while(flag!=0);
        printf("\n 维护已完成, \n");
        printf("请您确认是否保存您所做的修改?(Y/N): ");
        ch = getchar();
        if(tolower(ch)=='y') {
            saveFlag = Save();
            if(saveFlag==0) {
                flag = 4; //  保存成功标识
                printf("\n 保存成功! \n");
            }
        }
    }
    return flag;
}
