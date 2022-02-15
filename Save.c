//
//  Save.c
//  Standard Student Information System (SIS)
//
//  Created by 丁嘉诚 on 2022/2/15.
//

#include "Save.h"
int Save(void) {
    FILE *fp;
    stu *p;
    p = head;
    if((fp=fopen("DATASHEET.DAT", "w"))==NULL) {
        printf("\n 保存文件不正常, 请检查! \n");
        fclose(fp);
        return 1;
    } else {
        rewind(fp); //  使文件位置指针重回文件开始的位置
        while(p!=NULL) {
            fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n"                                             , p->No
                                                  , p->name
                                                  , p->age
                                                  , p->sex
                                                  , p->className
                                                  , p->address
                                                  , p->email
                                                  , p->QQ
                                                  , p->tel);
            p = p -> next;
        }
        fclose(fp);
        return 0;
    }
} //  保存数据到 DATASHEET.DAT 文件
