 #include <stdio.h>
#define MAXCHARS 10000
 
int main(void){
    int i = 0;
    int l;
    char c;
    char *s = (char*)malloc((MAXCHARS+1)*sizeof(char));
    while ((c=getchar())!=EOF && i<MAXCHARS){
        *(s+i) = c;
        i++;
    }
    *(s+i) = 0;
    char *reversed = (char*)malloc((i+1)*sizeof(char));
    for (l=0; l<i; l++){
        *(reversed+l) = *(s+((i-1)-l));
    }
    *(reversed+l) = 0;
    printf("%s", reversed);
    return 0;
}
