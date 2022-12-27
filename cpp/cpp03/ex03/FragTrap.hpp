#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();
		int	get_hit_point();
		int	get_attack_damage();
		void f_a()
		{
			std::cout <<"1" << std::endl;
		}
		FragTrap &		operator=( FragTrap const & rhs );
		void highFivesGuys(void);
};


#endif /* ******************************************************** FRAGTRAP_H */