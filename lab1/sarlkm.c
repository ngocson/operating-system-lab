/*
 * sarlkm.c
 *
 *  Created on: 04.05.2011
 *      Author: Ngoc Son
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>

static char modname[] = "sarlkm";
static char groupID[] = "osp16"; /* length 5 */

extern char* promptBuffer;
extern unsigned long currentPromptLength; /* 0 = no prompt */

static int proc_read( char *buf, char **start,off_t off, int count, int *eof, void *data ){
	if(off > 0){
		return 0;
	}
	else {
		if(currentPromptLength > 0){
			memcpy(buf,promptBuffer,currentPromptLength);
			buf += currentPromptLength;
			*buf = ' ';
			++buf;
		}

		memcpy(buf,groupID,7);
		buf += 5;

		*buf = ',';
		++buf;

		*buf = ' ';
		++buf;

		unsigned long secs = jiffies/HZ;
		int numberOfBytes = sprintf(buf,"%lu\n", secs);

		return currentPromptLength + 8 + numberOfBytes;
	}
}


int init_module( void ){
	currentPromptLength = 0;
	create_proc_read_entry( modname,0, NULL,proc_read, NULL );
	return 0;
}

void cleanup_module( void ){
	remove_proc_entry( modname, NULL );
}

MODULE_LICENSE("GPL");
