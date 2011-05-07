/*
 * set_get_prompt.c
 *
 *  Created on: 07.05.2011
 *      Author: Ngoc Son
 */

#include <linux/kernel.h>
#include<linux/linkage.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/module.h>

unsigned long currentPromptLength;
char* promptBuffer;

asmlinkage long sys_set_get_prompt(char* newPrompt, unsigned long  lengthOfPrompt, char* oldPrompt){
	if(currentPromptLength > 0 && currentPromptLength >= lengthOfPrompt){
		/* nothing to do because the old memory space is enough for the new prompt */

	}else{
		if(currentPromptLength > 0 && currentPromptLength <  lengthOfPrompt){
			/* old memory space is not enough for new prompt */
			/* free the old memory space */
			kfree(promptBuffer);
		}
		/* allocate memory space for new prompt*/
		promptBuffer = (char*) kmalloc(lengthOfPrompt,GFP_KERNEL);
	}
	copy_to_user(oldPrompt,promptBuffer,currentPromptLength);

	copy_from_user(promptBuffer,newPrompt,lengthOfPrompt);
	currentPromptLength = lengthOfPrompt;

	return 0;

}

EXPORT_SYMBOL(currentPromptLength);
EXPORT_SYMBOL(promptBuffer);
