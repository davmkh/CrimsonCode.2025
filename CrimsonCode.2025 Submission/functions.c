#include "Header.h"

void menu(void)
{
	Profile p1 = { 0, 0, 0, "___" };

	FILE* outfile;
	outfile = fopen("stats.txt", "rb");
	if (outfile != NULL)
	{
		load_stats(&p1, outfile);
		fclose(outfile);
	}

	int menu_choice = 0;
	int exit = 0;
	do
	{
		printf("\t\t\t               Enter a valid number for what you'd like to do\n\n");
		printf("\t\t\t-----------------------------------------------------------------------------");
		printf("\n\t\t                                    > 1. Info");
		printf("\n\t\t                                    > 2. Play");
		printf("\n\t\t                                    > 3. Set Name");
		printf("\n\t\t                                    > 4. Stats");
		printf("\n\t\t                                    > 5. Tutorials");
		printf("\n\t\t                                    > 6. Save");
		printf("\n\t\t                                    > 7. Achievements");
		printf("\n\t\t                                    > 8. Exit");
		printf("\n\t\t\t-----------------------------------------------------------------------------\n");
		scanf("%d", &menu_choice);

		system("cls\n");
		switch (menu_choice)
		{
		case 1:
			how_to_play();
			break;
		case 2:
			printf("You have decided to play the game, enjoy!\n");
			system("pause");
			system("cls");
			run_intro(&p1);
			break;
		case 3:
			setname(&p1);
			system("cls");
			break;
		case 4:
			stats(&p1);
			system("cls");
			break;
		case 5:
			help_examples();
			break;
		case 6:
			outfile = fopen("stats.txt", "wb");
			save_stats(&p1, outfile);
			printf("Saved your stats!");
			fclose(outfile);
			break;
		case 7:
			printf("\n\t\t\t\tYou have decided to view your achievements.\n");
			printf("\t\t\t\t---------------------------------------------- \n\n");
			system("pause");
			system("cls");
			achievements(&p1);
		case 8:
			printf("\nGoodbye!\n\n");
			exit = 1;
			break;
		default:
			printf("You have entered an invalid character, try again. \n");
			system("pause");
			system("cls");
		}
	} while (exit != 1 && menu_choice >= 1 && menu_choice <= 7);
}

void how_to_play(void)
{
	// Note: We looked up how to change the colors. The chunk of lines from 42-46 are copy paste. 
	const char* WHITE = "\033[0m";
	const char* GREEN = "\033[0;32m";
	const char* BLUE = "\033[0;34m";
	const char* RED = "\033[0;31m";
	const char* PURPLE = "\033[0;35m";

	printf("You have selected: How To Play\n");
	system("pause");
	system("cls");

	printf("\t    Welcome to the best math arithmetic program by Dav! You may pick between 5 different levels:\n\n");
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t|       Level        |                             Details                            |\n");
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t|%s   1 - Easy         |     Single digit addition + subtraction up to 3 terms          |\n", WHITE);
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t|%s   2 - Fair         %s|%s     Single digit multiplication up to 2 terms                  %s|\n", GREEN, WHITE, GREEN, WHITE);
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t|%s  3 - Intermediate  %s|%s     Single digit division up to 2 terms                        %s|\n", BLUE, WHITE, BLUE, WHITE);
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t|%s   4 - Hard         %s|%s     Mix of everything, with negative numbers                   %s|\n", RED, WHITE, RED, WHITE);
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("\t\t|%s  5 - Impossible    %s|%s     Mix of everything above, up to 4 terms                     %s|\n", PURPLE, WHITE, PURPLE, WHITE);
	printf("\t\t---------------------------------------------------------------------------------------\n");
	printf("%s", WHITE);
	printf("\n\tYou shall recieve points when you get the correct answer. You will recieve more"
		" points the higher the level \n");
	printf("\n\t\t\t%sWARNING: YOU MUST MANUALLY SAVE IN ORDER TO KEEP TRACK OF PROGRESS\n\n", RED);
	printf("%s", WHITE);
	system("pause");
	system("cls");
	menu();

}

void help_examples(void)
{
	int decision = 0;
	do
	{
		system("cls");
		printf("\n\n\t\t\t\t\t\t        Math Tutorials! ");
		printf("\n\t\t\t------------------------------------------------------------------------------");
		printf("\n\t\t        |                             > 1. Addition			             |");
		printf("\n\t\t        |                             > 2. Subtraction				     |");
		printf("\n\t\t        |                             > 3. Multiplication			     |");
		printf("\n\t\t        |                             > 4. Division      			     |");
		printf("\n\t\t        |                             > 5. Negatives                                 |");
		printf("\n\t\t        |                             > 6. PEMDAS				     |");
		printf("\n\t\t        |                             > 7. Exit				             |");
		printf("\n\t\t\t------------------------------------------------------------------------------\n\n");
		scanf("%d", &decision);

		// if addition
		if (decision == 1)
		{
			system("pause");
			system("cls");
			printf("\n\t\t\t\t\t    You chose to learn: Addition\n\n");
			printf("\n\t\t\t\t\t\t\t -----");
			printf("\n\t\t\t\t\t\t\t 5 + 2");
			printf("\n\t\t\t\t\t\t\t -----\n");
			printf("\n\t\tHere, you see two numbers, 5 and 2. the '+' symbol represents the operation: addition.\n");
			printf("\n\t    If you see the '+' addition symbol, that means you're going to be combining numbers together! \n");
			printf("\n\t         Imagine you had 5 apples and I gave you 2, you would have 7 apples! So, 5 + 2 = 7!\n\n");
			system("pause");
		}
		// if subtraction
		else if (decision == 2)
		{
			system("pause");
			system("cls");
			printf("\n\t\t\t\t\t    You chose to learn: Subtraction\n\n");
			printf("\n\t\t\t\t\t\t\t-----");
			printf("\n\t\t\t\t\t\t\t5 - 2");
			printf("\n\t\t\t\t\t\t\t-----\n");
			printf("\n\t\tHere, you see two numbers, 5 and 2. the '-' symbol represents the operation: subtraction.\n");
			printf("\n\t       If you see the '-' addition symbol, that means you're going to be taking away from numbers\n");
			printf("\n\t    Imagine you had 5 apples and decided to give away 2, you would have 3 apples left. So, 5 - 2 = 3!\n\n");
			system("pause");
		}
		// if multiplication
		else if (decision == 3)
		{
			system("pause");
			system("cls");
			printf("\n\t\t\t\t\t   You chose to learn: Multiplication\n\n");
			printf("\n\t\t\t\t\t\t\t-----");
			printf("\n\t\t\t\t\t\t\t5 x 3");
			printf("\n\t\t\t\t\t\t\t-----\n");
			printf("\n\t\tHere, you see two numbers, 5 and 3. the 'x' symbol represents the operation: multiplication.\n");
			printf("\n\t       If you see the 'x' addition symbol, that means you have to add numbers together multiple times.\n");
			printf("\n\t    Imagine you had 3 boxes with 5 apples in them, you would have 15 apples total. So, 5 x 2 = 15!\n\n");
			system("pause");
		}
		// if division
		else if (decision == 4)
		{
			system("pause");
			system("cls");
			printf("\n\t\t\t\t\t   You chose to learn: Division\n\n");
			printf("\n\t\t\t\t\t\t\t-----");
			printf("\n\t\t\t\t\t\t\t8 / 4");
			printf("\n\t\t\t\t\t\t\t-----\n");
			printf("\n\t\tHere, you see two numbers, 8 and 4. the '/' symbol represents the operation: division.\n");
			printf("\n\t       If you see the 'x' addition symbol, that means you subtract numbers from each other multiple times.\n");
			printf("\n\t  Imagine you had 8 pizza slices and you wanted to split it with evenly with 4 friends, "
				"Each friend would get                              \t\t   2 slices. So, 8 / 4 = 2!\n\n");
			system("pause");
		}
		// if negatives
		else if (decision == 5)
		{
			system("pause");
			system("cls");
			printf("\n\t\t\t\t\t   You chose to learn: Negatives\n\n");
			printf("\n\t\t\t\t\t\t\t-----");
			printf("\n\t\t\t\t\t\t\t -3");
			printf("\n\t\t\t\t\t\t\t-----\n");
			printf("\n\t\t\t\t    -2         -1          0          1          2");
			printf("\n\t\t\t\t     |----------|----------|----------|----------|");
			printf("\n\n\t\t    Here, you see negative 3, represented with '-', the same symbol as subtraction. \n");
			printf("\n\t           If you see the '-' negative symbol next to a number, that's a negative number.\n");
			printf("\n\t       \t\t      Negative numbers are numbers that are less than 0.\n\n");
			system("pause");
		}
		// if pemdas
		else if (decision == 6)
		{
			system("pause");
			system("cls");
			printf("\n\t\t\t\t      You chose to learn: Pemdas (Order of Operations)\n\n");
			printf("\n\t\t\t\t\t\t     ------------------");
			printf("\n\t\t\t\t\t\t      3 + 2 * (10 + 2)");
			printf("\n\t\t\t\t\t\t     ------------------\n");
			printf("\n\t\t\t   Pemdas is the order of operations of which we conduct math equations.\n");

			printf("\n\t\t\t\t\t\t     PEMDAS stands for: \n");
			printf("\n\t\t\t\t\t\t      1) Parathentheis () \n");
			printf("\n\t\t\t\t\t\t      2) Exponents ^ \n");
			printf("\n\t\t\t\t\t\t      3) Multiplication x \n");
			printf("\n\t\t\t\t\t\t      4) Division / \n");
			printf("\n\t\t\t\t\t\t      5) Addition + \n");
			printf("\n\t\t\t\t\t\t      6) Subtraction - \n");

			system("pause");

			printf("\n\t\t\t\t\t\tThe order of these are important. ");
			printf("\n\t\t\t\t\t      First do parenthesis, then exponents.");
			printf("\n\t\t\tMultiplication/Division are equal, these are interchangable when it comes to order");
			printf("\n      Addition / Subtraction is the same as M & D, however are ranked the lowest of the orders, meaning they go last.\n");

			printf("\n\t\t\t                              3 + 2 * (10 + 2)");
			printf("\n\t\t\t                             -----------------\n\n");
			printf("\t\t\t\t      Step 1:       3 + 2 * (12) | Parenthesis first\n");
			printf("\t\t\t\t      Step 2: 3 + 24 | Multiplication since it outranks addition\n");
			printf("\t\t\t\t      Step 3:      27 | Add the rest of the terms up\n");
			printf("\t\t\t\t                    3 + 2 * (10 + 2) = 27!\n");
			system("pause");
		}
		// if exit
		else if (decision == 7)
		{
			system("pause");
			system("cls");
			printf("\n\t\t\t\tYou have decided to exit the get-help math tutorials.\n");
			printf("\t\t\t\t---------------------------------------------------- \n\n");
			system("pause");
			system("cls");
			break;
		}
		// if invalid
		else
		{
			printf("\nInvalid input, please enter 1, 2, 3, or 4. \n\n");
			system("pause");
		}
	} while (decision != 7);
}

void run_intro(Profile* p1)
{
	const char* WHITE = "\033[0m";
	const char* GREEN = "\033[0;32m";
	const char* BLUE = "\033[0;34m";
	const char* RED = "\033[0;31m";
	const char* PURPLE = "\033[0;35m";

	int decision = -1, i = 0;

	system("pause");
	system("cls");
	do
	{
		printf("\t\t\t\t          If you'd like to exit out, enter 0\n\n");
		printf("\t\t---------------------------------------------------------------------------------------\n");
		printf("\t\t|       Level        |                             Details                            |\n");
		printf("\t\t---------------------------------------------------------------------------------------\n");
		printf("\t\t|%s   1 - Easy         |     Single digit addition + subtraction up to 3 terms          |\n", WHITE);
		printf("\t\t---------------------------------------------------------------------------------------\n");
		printf("\t\t|%s   2 - Fair         %s|%s     Single digit multiplication up to 2 terms                  %s|\n", GREEN, WHITE, GREEN, WHITE);
		printf("\t\t---------------------------------------------------------------------------------------\n");
		printf("\t\t|%s  3 - Intermediate  %s|%s     Single digit division up to 2 terms                        %s|\n", BLUE, WHITE, BLUE, WHITE);
		printf("\t\t---------------------------------------------------------------------------------------\n");
		printf("\t\t|%s   4 - Hard         %s|%s     Mix of everything, with negative numbers                   %s|\n", RED, WHITE, RED, WHITE);
		printf("\t\t---------------------------------------------------------------------------------------\n");
		printf("\t\t|%s  5 - Impossible    %s|%s     Mix of everything above, up to 4 terms                     %s|\n", PURPLE, WHITE, PURPLE, WHITE);
		printf("\t\t---------------------------------------------------------------------------------------\n");
		printf("%s", WHITE);

		printf("\t\t\t\tWhich level do you want to play? Pick a number 1-5. \n");
		printf("\t\t\t\t--------------------------------------------------- \n");
		scanf("%d", &decision);
		system("cls");


		if (decision == 0)
		{
			return;
		}
		else if (decision == 1)
		{
			printf("Entering level 1..\n\n");
			system("pause");
			system("cls");
			do
			{
				level1(p1);
				printf("\n");
				i++;
			} while (i < 10);
			i = 0;
			printf("You have successfully completed level 1, congratulations!");
			system("pause");
			system("cls");
		}
		else if (decision == 2)
		{
			printf("Entering level 2..\n\n");
			system("pause");
			system("cls");
			do
			{
				level2(p1);
				printf("\n");
				i++;
			} while (i < 10);
			i = 0;
			printf("You have successfully completed level 2, congratulations!");
			system("pause");
			system("cls");
		}
		else if (decision == 3)
		{
			printf("Entering level 3..\n\n");
			system("pause");
			system("cls");
			do
			{
				level3(p1);
				printf("\n");
				i++;
			} while (i < 10);
			i = 0;
			printf("You have successfully completed level 3, congratulations!");
			system("pause");
			system("cls");
		}
		else if (decision == 4)
		{
			printf("Entering level 4..\n\n");
			system("pause");
			system("cls");
			FILE* infile = fopen("equations.txt", "r");
			do
			{
				rewind(infile);
				level4(infile, p1);
				printf("\n");
				i++;
			} while (i < 10);
			i = 0;
			system("pause");
			system("cls");
			fclose(infile);
		}
		else if (decision == 5)
		{
			printf("Entering level 5..\n\n");
			system("pause");
			system("cls");
			FILE* infile = fopen("equations2.txt", "r");
			do
			{
				rewind(infile);
				level5(infile, p1);
				printf("\n");
				i++;
			} while (i < 10);
			i = 0;
			system("pause");
			system("cls");
		}
		else if (decision == 7)
		{
			help_examples();
		}
		else
		{
			printf("\nInvalid character, please enter a number from 1-5 \n\n ");
			system("pause");
			system("cls");
		}
	} while (decision != 0);

}

void level1(Profile* p1)
{
	int operands[MaxNumOperators + 1];
	int operators[MaxNumOperators];
	int operandCount = rand() % MaxNumOperators + 1;
	int answer = 0;

	operands[0] = rand() % 9 + 1;
	answer = operands[0];

	for (int i = 0; i < operandCount; i++) {
		operands[i + 1] = rand() % operands[i] % 9 + 1;
		operators[i] = rand() % 2;

		if (operators[i] == 0)
		{
			answer += operands[i + 1];
		}
		else
		{
			answer -= operands[i + 1];
		}
	}
	printf("%d ", operands[0]);
	for (int i = 0; i < operandCount; i++) {
		printf("%c %d ", operators[i] == 0 ? '+' : '-', operands[i + 1]);
	}
	printf("= ?\n");

	int userAnswer;
	scanf("%d", &userAnswer);

	if (userAnswer == answer)
	{
		printf("Correct, well done!\n");
		p1->correct++;
		p1->score += 10;
	}
	else
	{
		printf("Incorrect, the answer is: %d\n", answer);
		p1->incorrect++;
		p1->score -= 5;
	}
}

void level2(Profile* p1)
{
	int num1 = 0, num2 = 0, answer, attempt;

	num1 = rand() % 10 + 1;
	num2 = rand() % 10 + 1;

	answer = num1 * num2;
	printf("%d * %d = ? ", num1, num2);
	scanf("%d", &attempt);

	if (attempt == answer)
	{
		printf("Congrats! You got the answer right: %d * %d = %d !\n", num1, num2, answer);
		p1->correct++;
		p1->score += 20;
	}
	else if (attempt != answer)
	{
		printf("Sorry, you got the incorrect answer. \n ");
		p1->incorrect++;
		p1->score -= 10;
	}
	else
	{
		printf("Invalid Input, try again.");
	}
}

void level3(Profile* p1)
{
	int num1 = 0, num2 = 0, answer, attempt, i = 0;

	num1 = (rand() % 6) * 2;
	if (rand() % 3 == 0)
	{
		num1 = 1;
	}
	num2 = rand() % 4;
	if (num2 == 3)
	{
		num2 = 4;
	}

	answer = num1 / num2;
	printf("%d / %d = ? ", num1, num2);
	scanf("%d", &attempt);

	if (attempt == answer)
	{
		printf("Congrats! You got the answer right: %d / %d = %d !\n", num1, num2, answer);
		p1->correct++;
		p1->score += 30;
	}
	else if (attempt != answer)
	{
		printf("Sorry, you got the incorrect answer. \n ");
		p1->incorrect++;
		p1->score -= 20;
	}
	else
	{
		printf("Invalid Input, try again.");
	}
}

void level4(FILE* infile, Profile* p1)
{
	int linestored = rand() % NumOfLines4 + 1;
	int answer = 0, attempt;
	char equation[MaxFileLinesLength];

	if (infile == NULL) {
		printf("Did not read file\n");
		return;
	}

	for (int i = 0; i < linestored; i++)
	{
		if (fgets(equation, MaxFileLinesLength, infile) == NULL)
		{
			printf("Error: Failed to read a line from the file.\n");
			return;
		}
	}

	char noanswer[MaxFileLinesLength] = { 0 };
	if (sscanf(equation, "%[^=]=%d", noanswer, &answer) != 2)
	{
		printf("Error: Failed to parse the equation.\n");
	}

	printf("%s? ", noanswer);
	if (scanf("%d", &attempt) != 1)
	{
		printf("Error: Invalid input.\n");
	}

	if (attempt == answer)
	{
		printf("Congrats! You got the correct answer!\n\n");
		p1->correct++;
		p1->score += 40;
	}
	else
	{
		printf("Sorry, that's incorrect. The correct answer was %d.\n\n", answer);
		p1->incorrect++;
		p1->score -= 30;
	}

}

void level5(FILE* infile, Profile* p1)
{
	int linestored = rand() % NumOfLines5 + 1;
	int answer = 0, attempt;
	char equation[MaxFileLinesLength];

	if (infile == NULL) {
		printf("Did not read file\n");
		return;
	}

	for (int i = 0; i < linestored; i++)
	{
		if (fgets(equation, MaxFileLinesLength, infile) == NULL)
		{
			printf("Error: Failed to read a line from the file.\n");
			return;
		}
	}

	char noanswer[MaxFileLinesLength] = { 0 };
	if (sscanf(equation, "%[^=]=%d", noanswer, &answer) != 2)
	{
		printf("Error: Failed to parse the equation.\n");
	}

	printf("%s? ", noanswer);
	if (scanf("%d", &attempt) != 1)
	{
		printf("Error: Invalid input.\n");
	}

	if (attempt == answer)
	{
		printf("Congrats! You got the correct answer!\n\n");
		p1->correct++;
		p1->score += 50;
	}
	else
	{
		printf("Sorry, that's incorrect. The correct answer was %d.\n\n", answer);
		p1->incorrect++;
		p1->score -= 40;
	}
}
void stats(Profile* p1)
{
	double ratio;

	if (p1->incorrect == 0)
	{
		ratio = p1->correct;
	}
	else
	{
		ratio = (double)p1->correct / p1->incorrect;
	}

	printf("\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t|                            Stats                           |\n");
	printf("\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t|        Name         |                %s                   |\n", p1->name);
	printf("\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t|        Score        |                %d                     |\n", p1->score);
	printf("\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t|   Correct Answers   |                 %d                    |\n", p1->correct);
	printf("\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t|  Incorrect Answers  |                 %d                    |\n", p1->incorrect);
	printf("\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t|      C/I Ratio      |                %.1lf                   |\n", ratio);
	printf("\t\t\t\t--------------------------------------------------------------\n");
	system("pause");
	system("cls");
	menu();
}

void save_stats(Profile* p1, const char* infile)
{
	if (infile == NULL)
	{
		printf("Can't open file. \n");
		return;
	}

	fwrite(p1, sizeof(Profile), 1, infile);

	fclose(infile);
}

void load_stats(Profile* p1, const char* infile)
{
	if (infile == NULL)
	{
		printf("Can't open file. \n");
		return;
	}

	fread(p1, sizeof(Profile), 1, infile);
	fclose(infile);
}

void setname(Profile* p1)
{
	printf("Please enter 3 initials for your name (ex. Dav): ");
	scanf("%s", p1->name);
}

// Added 2/16/25
void achievements(Profile* p1)
{
	// colors
	const char* WHITE = "\033[0m";
	const char* GREEN = "\033[0;32m";
	const char* BLUE = "\033[0;34m";
	const char* RED = "\033[0;31m";
	const char* PURPLE = "\033[0;35m";

	// achievement names
	int bronze = FALSE;
	int silver = FALSE;
	int gold = FALSE;
	int diamond = FALSE;
	int master = FALSE;

	// achievement title
	printf("\t\t\t\t\t\tACHIEVEMENTS\n\n");

	// achievement conditionals
	if (p1->correct <= 10 && p1->correct < 80)
	{
		bronze = TRUE;
		printf("%s1. Bronze - 10 Correct Answers%s\n2. ???\n3. ???\n4. ???\n5. ???\n\n%s", GREEN, RED, WHITE);
	}
	if (p1->correct >= 80 && p1->correct < 150)
	{
		silver = TRUE;
		printf("%s1. Bronze - 10 Correct Answers\n2. Silver - 80 Correct Answers%s\n3. ???\n4. ???\n5. ???\n\n%s", GREEN, RED, WHITE);
	}
	if (p1->correct >= 150 && p1->correct < 300)
	{
		gold = TRUE;
		printf("%s1. Bronze - 10 Correct Answers\n2. Silver - 80 Correct Answers\n3. Gold - 150 Correct Answers%s\n4. ???\n5. ???\n\n%s", GREEN, RED, WHITE);
	}
	if (p1->correct >= 300 && p1->correct < 500)
	{
		diamond = TRUE;
		printf("%s1. Bronze - 10 Correct Answers\n2. Silver - 80 Correct Answers\n3. Gold - 150 Correct Answers\n"
			"4. Diamond - 300 Correct Answers%s\n5. ???\n\n%s", GREEN, RED, WHITE);
	}
	if (p1->correct >= 500)
	{
		master = TRUE;
		printf("%s1. Bronze - 10 Correct Answers\n2. Silver - 80 Correct Answers\n3. Gold - 150 Correct Answers\n"
			"4. Diamond - 300 Correct Answers\n5. Master - 500 Correct Answers%s\n\n%s", GREEN, RED, WHITE);

	}
	system("pause");
	system("cls");
	menu();
}