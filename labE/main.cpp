/*********************************************************************
** Program Filename: main.cpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The Main Function of the Filefilter program.
** Input: yeats.txt
** Output: yeatsCopy.txt, yeatsCopy.txt, yeatsEncrypt.txt, yeatsCihper.txt, yeatsUpper.txt
*********************************************************************/


#include "fileFilter.hpp"
#include "copy.hpp"
#include "upper.hpp"
#include "fileEncryption.hpp"
#include "cipherFilter.hpp"

int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	inputFile.open("yeats.txt");
	if(!inputFile.good())
	{
		std::cout << "Bad file name or file not found." << std::endl;
	}

	else
	{
		inputFile.close();
	}


	inputFile.open("yeats.txt");
	outputFile.open("yeatsCopy.txt");
	Copy *copyMe = new Copy();
	copyMe->doFilter(inputFile, outputFile); // Call the function version from Copy.
	inputFile.close();
	outputFile.close();


	// Encryption Time!
	inputFile.open("yeats.txt");
	outputFile.open("yeatsEncrypted.txt");
	FileEncryption *encryptMe = new FileEncryption(5); // This has the character shift. 
	encryptMe->doFilter(inputFile, outputFile);	// Call from the Encryption version of doFilter.
	inputFile.close();
	outputFile.close();

	// Cipher Encryption Time!
	inputFile.open("yeats.txt");
	outputFile.open("yeatsCipher.txt");
	CipherEncrypt *cipherMe = new CipherEncrypt(2); // Just to keep it consistent and see what happens.
	cipherMe->doFilter(inputFile, outputFile);	// Call from the CipherEncryption version of the doFilter.
	inputFile.close();
	outputFile.close();

	// Upper Case
	inputFile.open("yeats.txt");
	outputFile.open("yeatsUpperCase.txt");
	Upper *upperMe = new Upper();
	upperMe->doFilter(inputFile, outputFile);	// Call from the uppercase conversion of doFilter.
	inputFile.close();
	outputFile.close();

	return 0;
}