/*
 * char.c
 *
 * Library of C functions that help with
 * character manipulation.
 *
 *    Author: Desmond Stular
 *   Created: March 25, 2024
 * Last Edit: March 25, 2024
*/

/*
 * Converts a lowercase character to uppercase.
*/
char toUppercase(char c) {
	int temp = c + 0;
	
	if (temp < 97) {
		temp += 32;
	}
	
	return (char)temp;
}

