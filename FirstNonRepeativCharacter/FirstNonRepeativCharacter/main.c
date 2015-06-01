//
//  main.c
//  FirstNonRepeativCharacter
//
//  Created by allamaprabhu on 5/26/15.
//  Copyright (c) 2015 GeeksForGeek. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char *str = "geeksforgeeks";
    int count[256]={0};
    int i=0;
    while (str[i] !='\0')
    {
        char c = str[i];
        count[c]=count[c]+1;
        i++;
    }
    
    for (int j=0; str[j]!= '\0'; j++) {
        char c = str[j];
        if (count[c]==1) {
            printf("Char is : %c",c);
            break;
        }
    }
    return 0;
}
