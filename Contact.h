/**********************************************************
* Name: Ana Garcia
* Student ID: 105903173
* Seneca email: agarcia-caicedo@myseneca.ca
* Date of Completion: 09/07/2018
**********************************************************/
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {

	class Contact {
		
		char m_name[20];
		int long long* m_phone_no;
		int m_count; 
		int m_no; 

		void set(const char* name, const long long* phoneNo, const int no);
		bool validNo(const long long no);

	public:
	
		Contact();
		Contact(const char* name, const long long* phoneNo, const int no);
		Contact(const Contact& src);
		Contact& operator=(const Contact& src);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator+=(const long long no);
	};
}
#endif