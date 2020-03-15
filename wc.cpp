#include<stdio.h>
#include<assert.h>
#include<string.h>

int CCount(char *filename);
int WCount(char *filename);
int LCount(char *filename);
void LineCount(char *filename);

int main(int argc,char *argv[]){
      switch(argv[1][1]){
      case 'c':{
          printf("Number of characters:%d\n",CCount(argv[2]));   //功能-c
          break;
      }
      case 'w':{
         printf("Number of words:%d\n",WCount(argv[2]));    //功能-w
          break;
      } 
      case 'l':{
         printf("Number of lines:%d\n",LCount(argv[2]));    //功能-l
          break; 
      }                
      default:{
          printf("ERROR\n");
          break;
      }    
    }
    return 0;
}


//返回文件file.c的字符数
int CCount(char *filename){
  FILE *fp=fopen(filename,"r");
  int count=0;
  char c;    //接收返回的字符
  if(fp==NULL){
      exit(-1);
  }
  c=fgetc(fp);
  while(c!=EOF){
         count++;
       c=fgetc(fp); 
  }
  fclose(fp);
  return count;
}


//计算纯英文单词个数
int WCount(char *filename){
    FILE *fp=fopen(filename,"r");
     if(fp==NULL)
       exit(-1);
    char c;
    int count=0;
    int InWord=1;
    c=fgetc(fp);
    while (c!=EOF){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) //字符是字母
        {
            count+=InWord;
            InWord=0;   //表示当前字母在词中
        }
        else
        {
            InWord=1;  //表示当前字符不在词中
        }     
        c=fgetc(fp);
    }
    fclose(fp);
    return count;
}
 

//计算行数
int LCount(char *filename){
    FILE *fp;
    char str[200];
    int count=0,n;
    fp=fopen(filename,"r");
    if(fp==NULL)
       exit(-1); 
    for(;fgets(str,200,fp)!=NULL;count++);   //读取一行字符串
    fclose(fp);
    return count;
}


