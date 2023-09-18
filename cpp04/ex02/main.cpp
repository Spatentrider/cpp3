#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\nCreating Animal Classes" << std::endl;
	Animal *cat_dog[6];
	for (int i = 0; i < 6; i++) {
		if (i % 2){
			cat_dog[i] = new Cat();
		}
		else {
			cat_dog[i] = new Dog();
		}
	}

	std::cout << "\nMaking sounds" << std::endl;
	for (int i = 0; i < 6; i++)
		cat_dog[i]->makeSound();

	std::cout << "\nDeleting Animal Classes" << std::endl;
	for (int i = 0; i < 6; i++)
		delete(cat_dog[i]);

	return(0);
}
