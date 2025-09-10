#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_num;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float fnum);
		Fixed(const Fixed& other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);

		Fixed& operator=(const Fixed& other);

		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);


#endif