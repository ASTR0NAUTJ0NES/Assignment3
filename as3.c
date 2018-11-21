#include <stdio.h>
/*
 * 
 * Purpose: It filters out garbage in the file passed to it.
 *
 * Assumption: That a valid file will be passed to it
 * Input: file which contains garbage
 * Output: Cleaned up file
 * Algorithm: functions which take care of each aspect of cleaning is taken care of as the input is converted
 *
 * Programmer: Andrew P. Albanese
 *
 *
 *
 *
 */

// function prototype
void skipNchar (int n);
void skipALine (void); 
int getData (char answer[100][50]);
void outputResult(char answer[100][50], int n);

int main(void) {
    int n; // number of answer
    char character;
    char answer[100][50]; // answer array stores up to 100 students and 50 answers for each person


    // read  & print character by charaeter until end of file
    n=getData (answer);
    printf("Number of Scores =%d\n",n);
    outputResult(answer,n);


    return 0;
} // main



/* Purpose: skip n characters for read
 * Input: : n(int) (#of characters skipped for read
 * Output: none
*/
void skipNchar (int n) {
    int i;
    char c;

    for (i=0;i<n;i++)
	scanf("%c",&c);

} // skipNchar



/* Purpose: skip reading a whole line
 * Input: : none
 * Output: none
*/

void skipALine (void) {
    char c;

    scanf("%c",&c);
    while (c != '\n')
       scanf("%c",&c);


} // skipALine


/* Purpose:skip the 1st line of input data, then skip 1 character before
 * get ting the rest of answer (int)  from keyboard and store them into
 * an array (int)
 *  * Input: : none
 *   * Output: a answer array and number of answer read in
 *   */

int getData (char answer[100][50]) {
    int i=0; // array row index: # of students
    int j=0; // question index


    skipALine();

    while (scanf ("%c",&answer[i][j])!= EOF) {
       // skip 28 characters
       skipNchar(28);

       // read answers
       for (j=0;j<19;j++)  {
          scanf ("%c",&answer[i][j]);
       }

       skipALine();
       i+=1; // increment counter
    } // while

    return i;
} //getData


/* Purpose:output answer array to the screen
 *  * Input: : a answer array and number of answer read in
 *   * Output: none
 *   */

void outputResult(char answer[100][50], int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < 19; j++) {
			if (answer[i][j] == ' ')
				printf("%c", '*');
			else
				printf("%c", answer[i][j]);
		}
		printf("%s", "\n");
	}
}
