/*
 * @Objective: Print the contents of a stuct called Article.
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/07/21
 */

#include <stdio.h>
#include <string.h>

#ifndef LENGTH
#define LENGTH 20
#endif

struct Article
{
    int number;  // article number
    int quantity;  // quantity
    char description[LENGTH + 1];  // description
};

int main()
{
    struct Article article;  // an instance of the "Article" structure

    // Print the contents of an instancce of the "Article" structure.
    // p_article: a pointer to the instance of the "Article" structure
    void Print(struct Article* p_article);

    // Initialize the contents of article.
    article.number = 1;
    article.quantity = 10;
    strcpy(article.description, "An article about c++");

    // Print the contents of article
    Print(&article);
    
    return 0;
}

void Print(struct Article* p_article)
{
    printf("Article number: %d\n", p_article->number);
    printf("Quantity: %d\n", p_article->quantity);
    printf("Description: %s\n", p_article->description);
}