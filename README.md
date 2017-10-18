# purify
A program that removes WAV file headers, to be used with corruption.

purify removes the first 44 bytes of a file, which constitutes the file header in WAV files.
It is meant for use with my other program corruption, to revert a databent file back from a WAV file to whatever it was before.

Usage: ./purify <input_file> <output_filename> <output_folder>

purify attaches a '.data' extension to the output file, you will have to manually change it back to whatever the file used to be before putting it through corruption.
