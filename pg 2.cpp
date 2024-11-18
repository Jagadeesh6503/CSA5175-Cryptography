#include<stdio.h>
#include <string.h>

int main(){
	
	char text[100], cipher[100];
	char key[] = "qazwsxedcrfvtgbyhnujmikolp";
	
	printf("enter a text : ");
	fgets(text , sizeof(text),stdin);
	
	

	
	
	
	for(int i =0 ; text[i] != '\0';i++ ){
		if(text[i] >= 'a' && text[i] <='z'){
			cipher[i] = key[text[i]-'a'];
		}
		else if(text[i] >= 'A' && text[i] <='Z'){
			cipher[i] = key[text[i]-'A'];
		}
		else{
			cipher[i] = text[i];
		}
		
	}
	
	printf("cipher text is %s",cipher);
	
	return 0;
}
