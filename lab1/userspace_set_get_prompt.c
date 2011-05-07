/*
 * userspace_set_get_prompt.c
 *
 *  Created on: 07.05.2011
 *      Author: Ngoc Son
 */
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "set_get_prompt_wrapper.h"

int main(int argc, char *argv[]){
	char* newPrompt = argv[1];
	char oldPrompt[200];
	if(set_get_prompt(newPrompt,strlen(newPrompt),oldPrompt) == 0){
		printf("Setting new Prompt is successful!\n");
		printf("old Prompt = %s\n",oldPrompt);
	}
	else{
		printf("Setting new Prompt is failed!\n");
	}

	return 0;
}
