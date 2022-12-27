#ifndef  SCAVTRAP_HPP
# define  SCAVTRAP_HPP

#include "ClapTrap.hpp"

class  ScavTrap : virtual public ClapTrap
{
	protected:
		int mode;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();
		void	guardGate();
		void attack(const std::string& target);
		int	get_energy_point();
		void f_a()
		{
			std::cout <<"1" << std::endl;
		}
		ScavTrap &		operator=( ScavTrap const & rhs );

};


#endif /* *******************************************************  SCAVTRAP_H */