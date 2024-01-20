#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string _firstName,
					_lastName,
					_nickname,
					_phoneNumber,
					_darkestSecret;
	public:
		const std::string   getFirstName(void),
							getLastName(void),
							getNickname(void),
							getPhoneNumber(void),
							getDarkestSecret(void);
		void	setFirstName(std::string str),
				setLastName(std::string str),
				setNickname(std::string str),
				setPhoneNumber(std::string str),
				setDarkestSecret(std::string str);
};
#endif