#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\nCreating Animal Classes" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat;

	std::cout << "\nDisplaing varius type" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrong_animal->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;

	std::cout << "\nMaking sounds" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wrong_animal->makeSound();
	wrong_cat->makeSound();

	std::cout << "\nDeleting Animal Classes" << std::endl;
	delete(meta);
	delete(i);
	delete(j);
	delete(wrong_animal);
	delete(wrong_cat);
	return 0;
}
