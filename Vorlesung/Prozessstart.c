/*
 * main.c
 * 
 * Copyright 2023 user <user@user-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int status;
	pid_t pid = fork();
	
	if(pid == 0) {
		printf("Child: Das ist der Child an sich \n");
	} else if(pid > 0) {
		printf("Parent: Das ist der Parent an sich \n");
		printf("Parent: Parent wartet bis Child fertig ist \n");
		waitpid(pid, &status, 0);
		printf("Parent: Child ist fertig \n");
	} else {
		fprintf(stderr, "Error: %s \n ", strerror(errno));
	}
	
	return 0;
}

