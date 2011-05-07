/*
 * set_get_prompt_wrapper.h
 *
 *  Created on: 07.05.2011
 *      Author: Ngoc Son
 */

#ifndef SET_GET_PROMPT_WRAPPER_H_
#define SET_GET_PROMPT_WRAPPER_H_

#include<linux/unistd.h>
#define __NR_set_get_prompt 289

_syscall3(long, set_get_prompt,char*,newPrompt, unsigned long, lengthOfPrompt, char*,oldPrompt);
#endif /* SET_GET_PROMPT_WRAPPER_H_ */
