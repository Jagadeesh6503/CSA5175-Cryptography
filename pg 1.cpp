#include<stdio.h>
#include <string.h>

int main(){
	
	char text[100], cipher[100];
	char key=[njkhbjaddak];
	
	printf("enter a text : ");
	fgets(text , sizeof(text),stdin);
	printf("enter key value");
	scanf("%d",&k);
	
	
	
	for(int i =0 ; text[i] != '\0';i++ ){
		if(text[i] >= 'a' && text[i] <='z'){
			cipher = key[text[i]-'a'];
		}
		if(text[i] >= 'A' && text[i] <='Z'){
			cipher = key[text[i]-'A'];
		}
	}
	printf("cipher text is %s",cipher);
	
	return 0;
}
