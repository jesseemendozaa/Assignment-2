
/**
 * Description: This assignment implements a simple UNIX shell and a name-counting
 * program. The shell creates child processes using fork() and executes commands
 * using exec(). The countnames program reads a file of names and counts the
 * occurrences of each name while reporting empty lines as warnings.
 * 
 * Author names: 
 * Jada-Lien Nguyen - 
 * Jesse Mendoza - 
 * Author emails: 
 * jada-lien.nguyen@sjsu.edu 
 * jesse.mendoza@sjsu.edu 
 * Last modified date: 3/4/2026
 * Creation date: 2/27/2026
 **/

 ## Link to Output of PDF:



## Purpose 
This assignment implements a simple UNIX shell program that allows the user to execute commands and run programs as child processes. The shell reads user input, creates a child process using fork(), and executes the command using exec(). The shell also redirects standard output and error messages to .out and .err files for each process.

The program countnames.c reads a file containing names and counts the occurrences of each name in the file. The output is printed to standard output and can be captured by the shell into output files.

This assignment helps demonstrate how operating systems create and manage processes and how programs interact with the UNIX shell.

## Directory Structure 
Assignment/
│
├── shell1.c
├── countnames.c
├── README.md
│
└── test/
    ├── names1.txt
    ├── names2.txt

## How to Compile Code:

Navigate to the folder where countnames.c is located, then enter the following command in the terminal::

gcc shell1.c -o shell
gcc countnames.c -o countnames

## To run shell 
To run the shell:
./shell
Then inside the shell prompt, run:
./countnames test/names.txt

## How to run each test case:

./countnames test/names.txt
./countnames test/names1.txt
./countnames test/names2.txt
./countnames test/namesB.txt
./countnames test/names_long.txt
./countnames test/names_long_redundant.txt
./countnames test/names_long_redundant1.txt
./countnames test/names_long_redundant2.txt
./countnames test/names_long_redundant3.txt
./countnames test/testCase1.txt
./countnames test/testCase2.txt
./countnames test/testCase3.txt

## Output expected for each test case:

./countnames test/names.txt

Warning: Line 2 is empty.
Warning: Line 5 is empty.
Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1

./countnames test/names1.txt

Warning: Line 3 is empty.
Tom Wu: 3

./countnames test/names2.txt

Jenn Xu: 2
Tom Wu: 1

./countnames test/namesB.txt

Warning: Line 2 is empty.
Warning: Line 5 is empty.
Nicky: 1
Dave Joe: 2
Yuan Cheng Chang: 3
John Smith: 1


./countnames test/names_long.txt

MARY SMITH: 1
 : 99
PATRICIA JOHNSON: 1
LINDA WILLIAMS: 1
BARBARA JONES: 1
ELIZABETH BROWN: 1
JENNIFER DAVIS: 1
MARIA MILLER: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
HELEN HARRIS: 1
SANDRA MARTIN: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1
JESSICA HALL: 1
SHIRLEY ALLEN: 1
CYNTHIA YOUNG: 1
ANGELA HERNANDEZ: 1
MELISSA KING: 1
BRENDA WRIGHT: 1
AMY LOPEZ: 1
ANNA HILL: 1
REBECCA SCOTT: 1
VIRGINIA GREEN: 1
KATHLEEN ADAMS: 1
PAMELA BAKER: 1
MARTHA GONZALEZ: 1
DEBRA NELSON: 1
AMANDA CARTER: 1
STEPHANIE MITCHELL: 1
CAROLYN PEREZ: 1
CHRISTINE ROBERTS: 1
MARIE TURNER: 1
JANET PHILLIPS: 1
CATHERINE CAMPBELL: 1
FRANCES PARKER: 1
ANN EVANS: 1
JOYCE EDWARDS: 1
DIANE COLLINS: 1
ALICE STEWART: 1
JULIE SANCHEZ: 1
HEATHER MORRIS: 1
TERESA ROGERS: 1
DORIS REED: 1
GLORIA COOK: 1
EVELYN MORGAN: 1
JEAN BELL: 1
CHERYL MURPHY: 1
MILDRED BAILEY: 1
KATHERINE RIVERA: 1
JOAN COOPER: 1
ASHLEY RICHARDSON: 1
JUDITH COX: 1
ROSE HOWARD: 1
JANICE WARD: 1
KELLY TORRES: 1
NICOLE PETERSON: 1
JUDY GRAY: 1
CHRISTINA RAMIREZ: 1
KATHY JAMES: 1
THERESA WATSON: 1
BEVERLY BROOKS: 1
DENISE KELLY: 1
TAMMY SANDERS: 1
IRENE PRICE: 1
JANE BENNETT: 1
LORI WOOD: 1
RACHEL BARNES: 1
MARILYN ROSS: 1
ANDREA HENDERSON: 1
KATHRYN COLEMAN: 1
LOUISE B JENKINS: 1
SARA A PERRY: 1
ANNE J POWELL: 1
JACQUELINE K LONG: 1
WANDA M PATTERSON: 1
BONNIE HUGHES: 1
JULIA FLORES: 1
RUBY WASHINGTON: 1
LOIS BUTLER: 1
TINA SIMMONS: 1
PHYLLIS FOSTER: 1
NORMA GONZALES: 1
PAULA BRYANT: 1
DIANA ALEXANDER: 1
ANNIE RUSSELL: 1
LILLIAN GRIFFIN: 1
EMILY DIAZ: 1

./countnames test/names_long_redundant.txt

John Smith: 1
Emily Davis: 1
Michael Johnson: 1
Sophia Lee: 1
Daniel Rodriguez: 1
Mia Hernandez: 1
David Kim: 1
Olivia Brown: 1
Anthony Martinez: 1
Evelyn Jackson: 1
Christopher Gonzalez: 1
Avery Taylor: 2
Andrew Lee: 2
Aria Perez: 1
Matthew Davis: 1
Victoria Wilson: 1
William Anderson: 1
Madison Green: 1
Joshua Wright: 1
Isabella Clark: 1
Nathan Davis: 2
Natalie Adams: 1
Ethan Martin: 1
Chloe Baker: 1
Ryan Lee: 1
Samantha Perez: 1
Benjamin Wright: 1
Aaliyah Garcia: 1
Jacob Cooper: 1
Elizabeth Martinez: 1
Tyler Thompson: 1
Hannah Scott: 1
Alexander Rodriguez: 1
Makayla Turner: 1
Nicholas Nguyen: 1
Sofia Hernandez: 1
Brandon Smith: 1
Grace Lee: 1
Christian Martinez: 1
Ava Jones: 1
William Turner: 1
Ella Wilson: 1
Jonathan Lee: 2
Lily Johnson: 1
Samuel Davis: 1
Avery Adams: 2
Gabriella Clark: 1
Dylan Anderson: 1
Lauren Kim: 1
James Lewis: 1
Makenna Wright: 1
Luke Davis: 1
Aaliyah Brown: 1
Christopher Anderson: 1
Abigail Perez: 1
Daniel Lee: 1
Jayden Robinson: 1
Leah Lee: 1
Nicholas Jackson: 1
Avery Lee: 1
Emma Hernandez: 1
Ethan Brown: 1
Madison Martinez: 1
Lucas Davis: 1
Aria Wright: 1
Ryan Rodriguez: 1
Sophia Turner: 1
Benjamin Davis: 1
Ella Garcia: 1
Chloe Kim: 1
William Scott: 1
Ava Smith: 1
David Wright: 1
Natalie Martin: 1
Isabella Adams: 1
Brandon Davis: 1
Makayla Hernandez: 1
Alexander Clark: 1
Emily Rodriguez: 1
Christopher Lee: 1
Olivia Lee: 1
Samantha Martinez: 1
Daniel Anderson: 1
Mia Lee: 1
Jacob Wright: 1
Elizabeth Adams: 1
Tyler Martinez: 1
Hannah Garcia: 1
Nicholas Davis: 1
Sofia Thompson: 1
Brandon Brown: 1

./countnames test/names_long_redundant1.txt

Warning: Line 2 is empty.
Warning: Line 4 is empty.
Warning: Line 6 is empty.
Warning: Line 8 is empty.
MARY SMITH: 1
PATRICIA JOHNSON: 1
LINDA WILLIAMS: 1
BARBARA JONES: 1
ELIZABETH BROWN: 1
JENNIFER DAVIS: 1
MARIA MILLER: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
HELEN HARRIS: 1
SANDRA MARTIN: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1
JESSICA HALL: 1
SHIRLEY ALLEN: 1
CYNTHIA YOUNG: 1
ANGELA HERNANDEZ: 1
MELISSA KING: 1
BRENDA WRIGHT: 1
AMY LOPEZ: 1
ANNA HILL: 1
REBECCA SCOTT: 1
VIRGINIA GREEN: 1
KATHLEEN ADAMS: 1
PAMELA BAKER: 1
MARTHA GONZALEZ: 1
DEBRA NELSON: 1
AMANDA CARTER: 1

./countnames test/names_long_redundant2.txt

STEPHANIE MITCHELL: 1
CAROLYN PEREZ: 1
CHRISTINE ROBERTS: 1
MARIE TURNER: 1
JANET PHILLIPS: 1
CATHERINE CAMPBELL: 1
FRANCES PARKER: 1
ANN EVANS: 1
JOYCE EDWARDS: 1
DIANE COLLINS: 1
ALICE STEWART: 1
JULIE SANCHEZ: 1
HEATHER MORRIS: 1
TERESA ROGERS: 1
DORIS REED: 1
GLORIA COOK: 1
EVELYN MORGAN: 1
JEAN BELL: 1
CHERYL MURPHY: 1
MILDRED BAILEY: 1
KATHERINE RIVERA: 1
JOAN COOPER: 1
ASHLEY RICHARDSON: 1
JUDITH COX: 1
ROSE HOWARD: 1
JANICE WARD: 1
KELLY TORRES: 1
NICOLE PETERSON: 1
JUDY GRAY: 1
CHRISTINA RAMIREZ: 1
KATHY JAMES: 1
THERESA WATSON: 1
BEVERLY BROOKS: 1
DENISE KELLY: 1
TAMMY SANDERS: 1
IRENE PRICE: 1
JANE BENNETT: 1
LORI WOOD: 1
RACHEL BARNES: 1
MARILYN ROSS: 1
ANDREA HENDERSON: 1
KATHRYN COLEMAN: 1
LOUISE B JENKINS: 1
SARA A PERRY: 1

./countnames test/names_long_redundant3.txt

ANNE J POWELL: 1
JACQUELINE K LONG: 1
WANDA M PATTERSON: 1
BONNIE HUGHES: 1
JULIA FLORES: 1
RUBY WASHINGTON: 1
LOIS BUTLER: 1
TINA SIMMONS: 1
PHYLLIS FOSTER: 1
NORMA GONZALES: 1
PAULA BRYANT: 1
DIANA ALEXANDER: 1
ANNIE RUSSELL: 1
LILLIAN GRIFFIN: 1
EMILY DIAZ: 1
ROBIN HAYES: 1
MARY SMITH: 2
PATRICIA JOHNSON: 2
LINDA WILLIAMS: 2
BARBARA JONES: 2
ELIZABETH BROWN: 2
JENNIFER DAVIS: 1
MARIA MILLER: 1
SUSAN WILSON: 1
MARGARET MOORE: 1
DOROTHY TAYLOR: 1
LISA ANDERSON: 1
NANCY THOMAS: 1
KAREN JACKSON: 1
BETTY WHITE: 1
HELEN HARRIS: 1
SANDRA MARTIN: 1
DONNA THOMPSON: 1
CAROL GARCIA: 1
RUTH MARTINEZ: 1
SHARON ROBINSON: 1
MICHELLE CLARK: 1
LAURA RODRIGUEZ: 1
SARAH LEWIS: 1
KIMBERLY LEE: 1
DEBORAH WALKER: 1

./countnames test/testCase1.txt

Warning: Line 4 is empty.
Warning: Line 6 is empty.
Mike Lam: 1
Jimmy Le: 1
J i m m y L e: 1
M ike Lam: 1
JeSsE: 1
JESSE: 1

./countnames test/testCase2.txt

Warning: Line 2 is empty.
Warning: Line 6 is empty.
Warning: Line 10 is empty.
Warning: Line 14 is empty.
Jose Mendez: 1
Ana Nguyen: 2
Charlie Kirk: 1
Barrack Obama: 1
Tommy Obama: 1
 : 1
 Tim Tran: 1
Andrew White: 2
ANDREW WHITE: 1
Nguyen Ana: 1

./countnames test/testCase3.txt

Warning: Line 6 is empty.
Warning: Line 10 is empty.
Warning: Line 13 is empty.
Warning: Line 16 is empty.
ABRAHAM LINCOLN: 1
ABRAHAM RAMIREZ: 1
 ABRAHAM LINCOLN: 1
ADRIAN ADRIAN: 1
ADRIAN: 1
JADA NGUYEn: 1
GEORGE WASHINGTON: 2
JADA NGUYEN: 1
JORGE PEREZ: 1
JESSE MENDOZA: 1
MENDOZA JESSE: 1

## Situations / Edge Cases:

- names.txt - Tests empty lines + duplicates + names with space
- names1.txt - Tests empty line + 1 repeated name
- names2.txt - Tests duplicates
- namesB.txt - Tests empty lines + duplicates
- names_long.txt - Tests many unique names + lines with one space
- names_long_redundant.txt - Tests many unique names with some duplicates
- names_long_redundant1.txt - Tests many unique names with a few empty lines 
- names_long_redundant2.txt - Tests many unique names
- names_long_redundant3.txt - Tests many unique names with some duplicates
- testCase1.txt - Tests spaces in between letters
- testCase2.txt - Tests empty lines + leading space + empty line with a space + case sensitivity
- testCase3.txt - Tests empty lines + same first name + leading space + duplicate

## Lessons Learned

Jada Lien Nguyen-
Through this project, I learned how a simple UNIX shell operates and how the operating system creates and manages processes. I gained experience using system calls such as fork(), exec(), and wait() to execute commands entered by a user. This project helped me better understand how shells launch programs and how each command runs as a separate process. I also learned how output and error messages can be redirected into .out and .err files. Overall, this project strengthened my C programming skills and helped me practice debugging and testing programs in a UNIX environment.

Jesse Mendoza - 
During this project, I learned more about how command execution works in a UNIX environment. I worked with system calls like fork() to create child processes and exec() to run programs from the shell. This helped me understand how the shell interacts with other programs and how the operating system manages multiple running processes. I also learned how to capture program output and error messages into separate files. This assignment improved my understanding of process control and reinforced important C programming concepts.

## References

- [Stack Overflow](https://stackoverflow.com): 
- Used to better understand string handling in C and file input functions like fgets() and fopen().
- Course materials: Lecture slides and notes from the SP26 course.
- [GNU Make Documentation](https://www.gnu.org/software/make/manual/make.html): For understanding Makefile syntax and usage.
- AI assistant (ChatGPT) — Used to clarify concepts related to string manipulation, input handling, and improving documentation wording.

## Acknowledgements

Thank you to the course instructor for the clear assignment guidelines. The class Discord was helpful for discussing edge cases. ZyBooks and reviewing the C textbook reinforced key concepts, and online resources and AI tools helped clarify specific implementation details.
