#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap( ClapTrap const & src );
		~ClapTrap();
		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status();
		void set_attack_dmg(int dmg);
		ClapTrap &		operator=( ClapTrap const & rhs );

	private:
	std::string	Name;
	int			hit_point;
	int			energy_point;
	int			attack_damage;

};

#endif /* ******************************************************** CLAPTRAP_H */