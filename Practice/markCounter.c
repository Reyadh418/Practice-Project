#include <stdio.h>

int main()
{
    printf("\n\nWelcome to our marks calculator.\n");
    printf("Current marks of only MCQ is countable\n");

    int choice;
    printf("\nDo your exam have negative marking?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Choose:\t");
    scanf("%d", &choice);
    int total_questions, attempted_questions, correct_answers;
    float marks_per_question, total_marks, negative_percentage = 0.0, negative_marks = 0.0;
    printf("\nEnter total number of questions in your exam:\t");
    scanf("%d", &total_questions);
    printf("Enter number of questions you attempted:\t");
    scanf("%d", &attempted_questions);
    printf("Enter number of correct answers:\t");
    scanf("%d", &correct_answers);

    printf("Enter marks per question:\t");
    scanf("%f", &marks_per_question);

    if (choice == 1)
    {
        printf("Enter negative marking percentage per wrong answer (e.g., enter 25 for 25%%):\t");
        scanf("%f", &negative_percentage);
        negative_marks = (negative_percentage / 100.0) * marks_per_question;
    }
    int wrong_answers = attempted_questions - correct_answers;
    total_marks = (correct_answers * marks_per_question) - (wrong_answers * negative_marks);

    if (total_marks < 0)
    {
        total_marks = 0;
    }
    printf("\nYour total marks are: %.2f out of %.2f\n", total_marks, total_questions * marks_per_question);
    return 0;
}