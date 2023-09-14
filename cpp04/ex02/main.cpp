#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// std::cout << "\033[32m" << "\nSubject main" << "\033[0m" << std::endl;
	// std::cout << "\033[32m" << "--------------------------------------" << "\033[0m" << std::endl;
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	// const Animal *abstract = new Animal();
	std::cout << "\033[32m" << "\nCreating Animal Classes" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "--------------------------------------" << "\033[0m" << std::endl;
	Animal *cat_dog[6];
	for (int i = 0; i < 6; i++) {
		if (i % 2){
			cat_dog[i] = new Cat();
		}
		else {
			cat_dog[i] = new Dog();
		}
	}

	std::cout << "\033[32m" << "\nMaking sounds" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "--------------------------------------" << "\033[0m" << std::endl;
	for (int i = 0; i < 6; i++)
		cat_dog[i]->makeSound();

	std::cout << "\033[32m" << "\nDeleting Animal Classes" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "--------------------------------------" << "\033[0m" << std::endl;
	for (int i = 0; i < 6; i++)
		delete(cat_dog[i]);

	return(0);
}
