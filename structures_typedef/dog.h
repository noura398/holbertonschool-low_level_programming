#ifndef DOG_H
#define DOG_H

/**
 * struct dog - basic dog structure
 * @name: dog's name (string)
 * @age: dog's age (in years)
 * @owner: owner's name (string)
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
