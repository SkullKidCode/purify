#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	if (argc != 4) {
	printf("Usage: %s <input_file> <output_filename> <output_folder>\n", argv[0]);
	exit(0);
	}
	
	char end_char = argv[3][strlen(argv[3]) - 1];					/* Check output file path ends in '/' */

	if (end_char == '/') {
		;
	}
	else {
		printf("Error: File path missing \"/\" at the end\n");
		printf("Usage: %s <input_file> <output_filename> <output_folder>\n", argv[0]);
		exit(0);
	}
	
	
	char * extension = ".data";
	char * file_path = strncat(argv[3], argv[2], strlen(argv[2]));
	char * full_file_path = strncat(file_path, extension, 5);			/* Creates full file path for output */
	FILE * input;
	FILE * output;
	char ch;
	long file_size;
	long n = 44;
		
	
	input = fopen(argv[1], "rb");				/* Open input file for reading */
	if (input == NULL) {
		perror("Problem opening input file");
		exit(0);
	}
	output = fopen(full_file_path, "wb");			/* Open output file for writing */
	if (output == NULL) {
		perror("Problem opening output file");
		exit(0);
	}
	
	fseek(input, 0, SEEK_END);
	file_size = ftell(input);
	rewind(input);
	fseek(input, 44, SEEK_SET);		/* Skip the wav header (first 44 bytes) */
	
	do {
		ch = fgetc(input);
		fputc(ch, output);			/* Copy over to new file */
		n++;
	} while (n < file_size);
	
	fclose(input);
	fclose(output);
}
	
	