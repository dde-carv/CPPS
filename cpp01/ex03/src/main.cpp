#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void test2()
{
	std::cout << "================== Test 2 ==================" << std::endl << std::endl;

	std::cout << "Unlike HumanA, HumanB doesn't get the Weapon at its creation," << std::endl;
	std::cout << "we are going to initialize him and try to attack." << std::endl << std::endl;
	HumanB humanb("Jazinto");
	humanb.attack();
	std::cout << std::endl << "The Weapon in the HumanB needs to be a pointer because" << std::endl;
	std::cout << "we wouldn't be able to initialize it as NULL." << std::endl << std::endl;

	std::cout << "Now we are going to give him a Weapon and check if" << std::endl;
	std::cout << "the behaviour is the same as the one shown in HumanA." << std::endl;
	std::cout << std::endl << "Then we are going to attack with his Weapon, change it to another one" << std::endl \
	<< "and then attack again to check if the Weapon HumanB was holding has changed:" << std::endl << std::endl;
	Weapon club = Weapon("chair");
	humanb.setWeapon(club);
	humanb.attack();
	club.setType("table");
	humanb.attack();
	std::cout << std::endl << "We are still using references to be able to change the Weapon" << std::endl;
	std::cout << "outside the humanA and HumanB classes." << std::endl;
	std::cout << std::endl;
}

void test1()
{
	std::cout << "================== Test 1 ==================" << std::endl << std::endl;

	std::cout << "We are going to initialize a Weapon and pass it to HumanA constructor since he" << std::endl \
	<< "must recieve a reference to a weapon already created and it can't be NULL:" << std::endl << std::endl;

	Weapon weapon = Weapon("spoon");
	HumanA humana("Adelino", weapon);

	std::cout << std::endl << "Then we are going to attack with his Weapon, change it to another one" << std::endl \
	<< "and then attack again to check if the Weapon HumanA was holding has changed:" << std::endl << std::endl;
	humana.attack();
	weapon.setType("stick");
	humana.attack();
	std::cout << std::endl;
}

int main()
{
	test1();
	std::cout << std::endl;
	test2();
	return (0);
}
