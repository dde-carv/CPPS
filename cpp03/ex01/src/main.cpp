#include "ScavTrap.hpp"

int main()
{
	ClapTrap	Bartolomeu("Bartolomeu");
	std::cout << "----- " << Bartolomeu.getName() << " -----\n";
	std::cout << "	Attack: ";
	Bartolomeu.attack("Wall");
	std::cout << "\n	Take damage: ";
	Bartolomeu.takeDamage(2);
	std::cout << "\n	Be repaired: ";
	Bartolomeu.beRepaired(1);
	std::cout << "\n	Hit Points: " << Bartolomeu.getHitPoints();
	std::cout << "\n	Energy Points: " << Bartolomeu.getEnergyPoints() << "\n\n";

	ScavTrap	Rogerio("Rogerio");
	std::cout << "----- " << Rogerio.getName() << " -----\n";
	std::cout << "	Attack: ";
	Rogerio.attack("Wall");
	std::cout << "\n	Take damage: ";
	Rogerio.takeDamage(2);
	std::cout << "\n	Be repaired: ";
	Rogerio.beRepaired(1);
	std::cout << "\n	Guard Gate: ";
	Rogerio.guardGate();
	std::cout << "\n	Hit Points: " << Rogerio.getHitPoints();
	std::cout << "\n	Energy Points: " << Rogerio.getEnergyPoints() << "\n\n";


	ScavTrap	Copycat(Rogerio);

	std::cout << "----- " << Copycat.getName() << " (copycat) -----\n";
	std::cout << "	Attack: ";
	Copycat.attack("Wall");
	std::cout << "\n	Take damage: ";
	Copycat.takeDamage(2);
	std::cout << "\n	Be repaired: ";
	Copycat.beRepaired(1);
	std::cout << "\n	Guard Gate: ";
	Rogerio.guardGate();
	std::cout << "\n	Hit Points: " << Copycat.getHitPoints();
	std::cout << "\n	Energy Points: " << Copycat.getEnergyPoints() << "\n\n";
	Copycat.setName("Rogerio copycat");

	return (0);
}
